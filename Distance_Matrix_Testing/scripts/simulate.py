"""Main simulation script"""
import logging
import re

import coloredlogs

# Setup logging (needs to be done before any file imports)
# coloredlogs.install()
logging.basicConfig(
    format="%(asctime)s - %(name)s - %(levelname)s - %(message)s",
    handlers=[
        logging.FileHandler("debug.log"),
        logging.StreamHandler()
    ],
    level=logging.INFO
)

import os
from timeit import default_timer as timer

import psutil
from neuron import h

from Helper import *
from Islet import Islet

# Load neuron?
h.load_file("stdrun.hoc")


# Global Variables (potentially modify before each run)
# Suffix of mechanism in mod file
MECHANISM = "one"
OUTPUT_FOLDER = "Test"
SIMULATION_TIME = 1000000
# Interval over which variables will be dumped/logs will print
SIMULATION_UPDATE = 4000
ISLET_ID = "one_islet"
ISLET_RADIUS = 1
TEMP_CSV = '.temp.csv'


# TEST: create islet based on number of cells per type
cells = {
    "type": "deterministic", 
    "A": 1, 
    "B": 1, 
    "D": 1
}
logging.info("TEST CASE: determinstic input")

# TEST: create islet based on probabilities of difference cell types and total number of cells
# cells = {
#     "type": "probabilistic", 
#     "A": 0.3, 
#     "B": 0.2, 
#     "D": 0.5, 
#     "num_cells": 10
# }
# logging.info("TEST CASE: probabilistic input")

# Create islet
test_islet = Islet(
    id=ISLET_ID, 
    mechanism=MECHANISM, 
    islet_radius=ISLET_RADIUS, 
    simulation_update=SIMULATION_UPDATE,
    cells=cells
)
test_islet.spatial_setup()
test_islet.populate_cells()
test_islet.record_values()
test_islet.set_cell_locations()
logging.info(f"{test_islet} created")

# Set time variable per dictionary recording each cell
# TODO: modify, did out of convenience
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
            dump_variables(test_islet, TEMP_CSV, i)
           
# Dump variables at conclusion of simulation
dump_variables(test_islet, TEMP_CSV, -1, last=True)
            
# Read csv and reset the cell_rec variable
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

# Plot time series for the following variables for each cell
variables_to_plot = {
    "A": ["va", "ca", "G"],
    "B": ["vb", "c", "I"],
    "D": ["vd", "cd", "S"]
    }

# Plot each cell
for cell in test_islet.cell_rec:
    logging.info(f"Plotting cell: {cell}")
    
    # Note that 'cell[0]' will be one of 'A'/'B'/'D'
    # When not using dump_variables use the following
    plot_parameters(test_islet.cell_rec[cell], variables_to_plot[cell[0]], cell_plot_path.format(output_folder=OUTPUT_FOLDER, cell_id=cell), mechanism=MECHANISM)
    