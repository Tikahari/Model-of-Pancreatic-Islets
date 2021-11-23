"""Main simulation script"""
import logging
import re

from config import *

# Setup logging (needs to be done before any file imports)
logging.basicConfig(
    format="%(asctime)s - %(name)s - %(levelname)s - %(message)s",
    handlers=[
        logging.FileHandler("debug.log"),
        logging.StreamHandler()
    ],
    level=getattr(logging, LEVEL)
)

import os
from timeit import default_timer as timer

import psutil
from neuron import h

from islet import Islet
from utils import *


def main():
    """Main simulation function"""
    logging.debug(globals())
    
    # Load neuron?
    h.load_file("stdrun.hoc")

    # Create islet
    test_islet = Islet(
        id=ISLET_ID, 
        mechanism=MECHANISM, 
        islet_radius=ISLET_RADIUS, 
        simulation_update=SIMULATION_UPDATE,
        cells=ISLET_CONFIGURATION
    )
    test_islet.spatial_setup()
    test_islet.populate_cells()
    test_islet.record_values()
    test_islet.set_cell_locations()
    logging.info(f"{test_islet} created")

    # Set time variable per dictionary recording each cell when variables are not dumped periodically
    # TODO: modify, did out of convenience
    if not DUMP:
        for cell in test_islet.cell_rec:
            test_islet.cell_rec[cell]['Time'] =  h.Vector().record(h._ref_t)
        
    # Run initial block of mod file
    h.finitialize()

    # Create distance matrix and subsets corresponding to effect of cell x on y (to be used in matrix multiplication)
    matrices = create_dist_matrices(test_islet)

    # Keep track of real time elapsed since simulation started
    real_start_time = timer()
    for i in range(40 * SIMULATION_TIME):

            # Advance one time step
            h.fadvance()
            
            # Perform matrix math to calculate new secretion rates
            calculate_secretion_rate_matrix(test_islet, matrices)
            
            # Change glucose level according to: https://github.com/artielbm/artielbm.github.io/blob/master/Models/BAD/Figures3-5.ode
            if i in GLUCOSE_MODULATION['interval']:
                modulate_glucose(test_islet.cells, i)
            
            # Perform logging and variable dumps every SIMULATION_UPDATE timesteps (.025 * 10^-3 * 4 * 10^3 = .1 seconds if SIMULATION_UPDATE = 4 * 10^3)
            if i % SIMULATION_UPDATE == 0:
                
                # Simulation time elapsed in seconds
                simulation_time_elapsed = (0.025 * i) / 1000

                # Get memory usage statistics
                pid = os.getpid()
                python_process = psutil.Process(pid)
                memory_use_gb = python_process.memory_info()[0]/2.**30 
                memory_use_percent = psutil.virtual_memory().available * 100 / psutil.virtual_memory().total
                
                # Log
                logging.info(f"Simulation time: {simulation_time_elapsed}. Real time: {timer()-real_start_time}. Memory Usage: {memory_use_gb}GB / {memory_use_percent}%")
                
                # Dump variables at this interval          
                dump_variables(test_islet, TEMP_CSV, i) if DUMP else None
            
    # Dump variables at conclusion of simulation
    dump_variables(test_islet, TEMP_CSV, -1, last=True) if DUMP else None
                
    # Read csv and reset the cell_rec variable if variables have been periodically dumped
    if DUMP:
        df = pd.read_csv(TEMP_CSV)
        # Use columns to rewrite cell_rec object
        for column in df.columns:
            match = re.search(r'((?:A|B|D)_[0-9])_(.*)', column)
            if match is not None:
                cell, var = list(match.groups())
                test_islet.cell_rec[cell][var] = df[column].to_list()
                

    # Setup plotting results folder
    os.system(f"mkdir -p Plots/{OUTPUT_FOLDER}")
    cell_plot_path = "Plots/{output_folder}/{cell_id}"

    # Plot each cell
    for cell in test_islet.cell_rec:
        logging.info(f"Plotting cell: {cell}")
        
        # Note that 'cell[0]' will be one of 'A'/'B'/'D'
        # When not using dump_variables use the following
        plot_parameters(
            test_islet.cell_rec[cell], 
            VARIABLES_TO_PLOT[cell[0]], 
            cell_plot_path.format(output_folder=OUTPUT_FOLDER, cell_id=cell)
        )
        
        # Create metrics table
        create_metrics_table(
            test_islet.cell_rec[cell], 
            VARIABLES_TO_PLOT[cell[0]], 
            cell_plot_path.format(output_folder=OUTPUT_FOLDER, cell_id=cell)
        )

if __name__ == '__main__':
    main()