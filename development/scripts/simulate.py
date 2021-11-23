"""Main simulation script/object"""
import logging
import os
import re
import sys
from timeit import default_timer as timer

import psutil
from neuron import h

from config import Config
from islet import Islet
from utils import *


class Simulate():
    
    
    def __init__(self, config: Config = None):
        """
        Constructor

        Args:
            config (Config, optional): Config object to setup logging and global variables for islet and util modules. Defaults to None.
        """
        
        # Set CONFIG from constructor if passed
        self.CONFIG = config if config else Config()
        self._setup()
    
    
    def _setup(self):
        """Set configurations for run in other scripts (CONFIG/LOGGER variables)"""
        
        # Import entire modules to reset
        import islet
        import utils
        islet.CONFIG = self.CONFIG
        utils.CONFIG = self.CONFIG
        
        # Reset logging per simulation
        simulation_file_handle = logging.FileHandler(f"debug_{self.CONFIG.SIMULATION_ID}.log")
        simulation_console_handle = logging.StreamHandler(sys.stdout)
        
        simulation_formatter = logging.Formatter("%(asctime)s - %(name)s - %(levelname)s - %(message)s")
        
        simulation_file_handle.setFormatter(simulation_formatter)
        simulation_console_handle.setFormatter(simulation_formatter)
        
        self.LOGGER = logging.getLogger(f"simulation_{self.CONFIG.SIMULATION_ID}")
        self.LOGGER.setLevel(getattr(logging, self.CONFIG.LEVEL))
        self.LOGGER.addHandler(simulation_file_handle)
        self.LOGGER.addHandler(simulation_console_handle)
        
        islet.LOGGER = logging.getLogger(f"islet_{self.CONFIG.SIMULATION_ID}")
        islet.LOGGER.addHandler(simulation_file_handle)
        islet.LOGGER.addHandler(simulation_console_handle)
        
        utils.LOGGER = logging.getLogger(f"utils_{self.CONFIG.SIMULATION_ID}")
        utils.LOGGER.addHandler(simulation_file_handle)
        utils.LOGGER.addHandler(simulation_console_handle)
        
        # Load neuron?
        h.load_file("stdrun.hoc")
        
        self.LOGGER.debug(globals())
        self.LOGGER.debug("Initial setup complete")


    def _load_stabilized_simulation(self):
        """Set mechanism variables according to last entry of file at CONFIG.LOAD"""
        
        # Verify that file exists
        if self.CONFIG.LOAD and not os.path.exists(self.CONFIG.LOAD):
            raise Exception(f"File missing: {os.getcwd()}/{self.CONFIG.LOAD}")
        
        # Load from CONFIG.TEMP_CSV if CONFIG.LOAD not specified
        if not self.CONFIG.LOAD:
            self.CONFIG.LOAD = self.CONFIG.TEMP_CSV
        
        # Read csv and reset the appropriate mechanism variables
        df = pd.read_csv(self.CONFIG.TEMP_CSV)
        
        # Dictionary containing new values to set mechanism variables to
        new_values = {
            'A': {},
            'B': {},
            'D': {}
        }
        
        # Get and organize names of variables/mechanism
        for column in df.columns:
            
            # Match will give (cell_type), (mechanism_name), (variable_name)
            match = re.search(r'(A|B|D)_[0-9]_(.*?)_(.*)', column)
            if match is not None:
                cell, mechanism, var = list(match.groups())
                
                # Store variable value in new_values dict
                if f"{var}_{mechanism}" not in new_values[cell]:
                    new_values[cell][f"{var}_{mechanism}"] = df[column].tail(1).to_list()[0]

        # Iterate through all cells and fill values according to values in new_values dict
        for cell in self.islet.cells:
            
            # Note that cell will be of the format (A|B|D)_[0-9]
            cell_type = cell.split('_')[0]
            for var_mechanism in new_values[cell_type]:
                
                # Store old value
                old_value = getattr(self.islet.cells[cell](0.5), var_mechanism)
                
                # Set new value
                setattr(self.islet.cells[cell](0.5), var_mechanism, new_values[cell_type][var_mechanism])
                
                self.LOGGER.info(f"Changed {var_mechanism} from {old_value} to {new_values[cell_type][var_mechanism]} in {cell}")
        
    
    def _reset_records(self):
        """Reset cell_rec object in islet class according to dumped data (if applicable)"""

        # Verify that file exists
        if not os.path.exists(self.CONFIG.TEMP_CSV):
            raise Exception(f"File missing: {os.getcwd()}/{self.CONFIG.LOAD}")
        
        # Read csv and reset the cell_rec variable if variables have been periodically dumped
        df = pd.read_csv(self.CONFIG.TEMP_CSV)
        
        # Use columns to rewrite cell_rec object
        for column in df.columns:
            match = re.search(r'((?:A|B|D)_[0-9])_(.*)', column)
            if match is not None:
                cell, var = list(match.groups())
                self.islet.cell_rec[cell][var] = df[column].to_list()
                
                
    def setup_islet(self):
        """Create islet and perform initialization (h.finitialize(), create distance matrix)"""
        
        # Create islet
        self.islet = Islet(
            id=self.CONFIG.ISLET_ID, 
            mechanism=self.CONFIG.MECHANISM, 
            islet_radius=self.CONFIG.ISLET_RADIUS, 
            simulation_update=self.CONFIG.SIMULATION_UPDATE,
            cells=self.CONFIG.ISLET_CONFIGURATION
        )
        self.islet.spatial_setup()
        self.islet.populate_cells()
        self.islet.record_values()
        self.islet.set_cell_locations()
        self.LOGGER.info(f"{self.islet} created")

        # Set time variable per dictionary recording each cell when variables are not dumped periodically
        # TODO: modify, did out of convenience
        if not self.CONFIG.DUMP:
            for cell in self.islet.cell_rec:
                self.islet.cell_rec[cell]['Time'] =  h.Vector().record(h._ref_t)
            
        # Run initial block of mod file
        h.finitialize()
        
        # Load values from csv if applicable
        if self.CONFIG.LOAD or os.path.exists(self.CONFIG.TEMP_CSV):
            self._load_stabilized_simulation()

        # Create distance matrix and subsets corresponding to effect of cell x on y (to be used in matrix multiplication)
        self.matrices = create_dist_matrices(self.islet)
        
        self.LOGGER.debug("Islet setup complete")
    
    
    def run_simulation(self):
        """Run actual simulation"""
        
        # Keep track of real time elapsed since simulation started
        real_start_time = timer()
        for i in range(40 * self.CONFIG.SIMULATION_TIME):

                # Advance one time step
                h.fadvance()
                
                # Perform matrix math to calculate new secretion rates
                calculate_secretion_rate_matrix(self.islet, self.matrices)
                
                # Change glucose level according to: https://github.com/artielbm/artielbm.github.io/blob/master/Models/BAD/Figures3-5.ode
                if i in self.CONFIG.GLUCOSE_MODULATION['interval']:
                    modulate_glucose(self.islet.cells, i)
                
                # Perform logging and variable dumps every SIMULATION_UPDATE timesteps (.025 * 10^-3 * 4 * 10^3 = .1 seconds if SIMULATION_UPDATE = 4 * 10^3)
                if i % self.CONFIG.SIMULATION_UPDATE == 0:
                    
                    # Simulation time elapsed in seconds
                    simulation_time_elapsed = (0.025 * i) / 1000

                    # Get memory usage statistics
                    pid = os.getpid()
                    python_process = psutil.Process(pid)
                    memory_use_gb = python_process.memory_info()[0]/2.**30 
                    memory_use_percent = psutil.virtual_memory().available * 100 / psutil.virtual_memory().total
                    
                    # Log
                    self.LOGGER.info(f"Simulation time: {simulation_time_elapsed}. Real time: {timer()-real_start_time}. Memory Usage: {memory_use_gb}GB / {memory_use_percent}%")
                    
                    # Dump variables at this interval          
                    dump_variables(self.islet, self.CONFIG.TEMP_CSV, i) if self.CONFIG.DUMP else None
                
        # Dump variables at conclusion of simulation
        dump_variables(self.islet, self.CONFIG.TEMP_CSV, -1, last=True) if self.CONFIG.DUMP else None

        if self.CONFIG.DUMP:
           self._reset_records()
        
     
    def create_plots(self):
        """Generate metrics table and plots according to VARIABLES_TO_PLOT configuration"""
        
        # Setup plotting results folder
        os.system(f"mkdir -p Plots/{self.CONFIG.OUTPUT_FOLDER}")
        cell_plot_path = "Plots/{output_folder}/{cell_id}"

        # Plot each cell
        for cell in self.islet.cell_rec:
            self.LOGGER.info(f"Plotting cell: {cell}")
            
            # Note that 'cell[0]' will be one of 'A'/'B'/'D'
            plot_parameters(
                self.islet.cell_rec[cell], 
                self.CONFIG.VARIABLES_TO_PLOT[cell[0]], 
                cell_plot_path.format(output_folder=self.CONFIG.OUTPUT_FOLDER, cell_id=cell)
            )
            
            # Create metrics table
            create_metrics_table(
                self.islet.cell_rec[cell], 
                self.CONFIG.VARIABLES_TO_PLOT[cell[0]], 
                cell_plot_path.format(output_folder=self.CONFIG.OUTPUT_FOLDER, cell_id=cell)
            )
        
        
    def main(self):
        """Main simulation function"""
        
        # Self explanatory
        self.setup_islet()
        self.run_simulation()
        self.create_plots()


if __name__ == '__main__':
    """When run directly from command line (i.e. `python3 simulate.py`)"""
    simulation = Simulate()
    
    # Testing load from csv function
    # simulation.CONFIG.LOAD = ".temp_glucose=0mM_distance=0.csv"
    
    simulation.main()
