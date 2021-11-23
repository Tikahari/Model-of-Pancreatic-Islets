"""Main simulation script"""
import logging
import re

from config import Config

import os
from timeit import default_timer as timer

import psutil
from neuron import h

from islet import Islet
from utils import *

class Simulate():
    def __init__(self, config=None):
        # Set CONFIG from constructor if passed
        self.CONFIG = config if config else Config()  
             
    def main(self):
        """Main simulation function"""
    
        # Set configurations for run in other scripts
        import islet
        import utils
        islet.CONFIG = self.CONFIG
        utils.CONFIG = self.CONFIG
        
        # Reset logging
        logging.basicConfig(
            format="%(asctime)s - %(name)s - %(levelname)s - %(message)s",
            handlers=[
                logging.FileHandler(f"debug_{self.CONFIG.SIMULATION_ID}.log"),
                logging.StreamHandler()
            ],
            level=getattr(logging, self.CONFIG.LEVEL)
        )
        LOGGER = logging.getLogger(f"simulation_{self.CONFIG.SIMULATION_ID}")
        islet.LOGGER = logging.getLogger(f"islet_{self.CONFIG.SIMULATION_ID}")
        utils.LOGGER = logging.getLogger(f"utils_{self.CONFIG.SIMULATION_ID}")
            
        LOGGER.debug(globals())
        
        # Load neuron?
        h.load_file("stdrun.hoc")
        
        # Create islet
        test_islet = Islet(
            id=self.CONFIG.ISLET_ID, 
            mechanism=self.CONFIG.MECHANISM, 
            islet_radius=self.CONFIG.ISLET_RADIUS, 
            simulation_update=self.CONFIG.SIMULATION_UPDATE,
            cells=self.CONFIG.ISLET_CONFIGURATION
        )
        test_islet.spatial_setup()
        test_islet.populate_cells()
        test_islet.record_values()
        test_islet.set_cell_locations()
        LOGGER.info(f"{test_islet} created")

        # Set time variable per dictionary recording each cell when variables are not dumped periodically
        # TODO: modify, did out of convenience
        if not self.CONFIG.DUMP:
            for cell in test_islet.cell_rec:
                test_islet.cell_rec[cell]['Time'] =  h.Vector().record(h._ref_t)
            
        # Run initial block of mod file
        h.finitialize()

        # Create distance matrix and subsets corresponding to effect of cell x on y (to be used in matrix multiplication)
        matrices = create_dist_matrices(test_islet)

        # Keep track of real time elapsed since simulation started
        real_start_time = timer()
        for i in range(40 * self.CONFIG.SIMULATION_TIME):

                # Advance one time step
                h.fadvance()
                
                # Perform matrix math to calculate new secretion rates
                calculate_secretion_rate_matrix(test_islet, matrices)
                
                # Change glucose level according to: https://github.com/artielbm/artielbm.github.io/blob/master/Models/BAD/Figures3-5.ode
                if i in self.CONFIG.GLUCOSE_MODULATION['interval']:
                    modulate_glucose(test_islet.cells, i, self.CONFIG.GLUCOSE_MODULATION)
                
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
                    LOGGER.info(f"Simulation time: {simulation_time_elapsed}. Real time: {timer()-real_start_time}. Memory Usage: {memory_use_gb}GB / {memory_use_percent}%")
                    
                    # Dump variables at this interval          
                    dump_variables(test_islet, self.CONFIG.TEMP_CSV, i) if self.CONFIG.DUMP else None
                
        # Dump variables at conclusion of simulation
        dump_variables(test_islet, self.CONFIG.TEMP_CSV, -1, last=True) if self.CONFIG.DUMP else None
                    
        # Read csv and reset the cell_rec variable if variables have been periodically dumped
        if self.CONFIG.DUMP:
            df = pd.read_csv(self.CONFIG.TEMP_CSV)
            # Use columns to rewrite cell_rec object
            for column in df.columns:
                match = re.search(r'((?:A|B|D)_[0-9])_(.*)', column)
                if match is not None:
                    cell, var = list(match.groups())
                    test_islet.cell_rec[cell][var] = df[column].to_list()
                    

        # Setup plotting results folder
        os.system(f"mkdir -p Plots/{self.CONFIG.OUTPUT_FOLDER}")
        cell_plot_path = "Plots/{output_folder}/{cell_id}"

        # Plot each cell
        for cell in test_islet.cell_rec:
            LOGGER.info(f"Plotting cell: {cell}")
            
            # Note that 'cell[0]' will be one of 'A'/'B'/'D'
            # When not using dump_variables use the following
            plot_parameters(
                test_islet.cell_rec[cell], 
                self.CONFIG.VARIABLES_TO_PLOT[cell[0]], 
                cell_plot_path.format(output_folder=self.CONFIG.OUTPUT_FOLDER, cell_id=cell)
            )
            
            # Create metrics table
            create_metrics_table(
                test_islet.cell_rec[cell], 
                self.CONFIG.VARIABLES_TO_PLOT[cell[0]], 
                cell_plot_path.format(output_folder=self.CONFIG.OUTPUT_FOLDER, cell_id=cell)
            )

if __name__ == '__main__':
    simulation = Simulate()
    simulation.main()