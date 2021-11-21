"""Main simulation script"""
import logging
import os
import pickle
from timeit import default_timer as timer

import coloredlogs
import psutil
from neuron import h

import Islet
from Helper import *

# Load neuron?
h.load_file("stdrun.hoc")


# Global Variables (potentially modify before each run)
# Suffix of mechanism in mod file
MECHANISM = "one"
OUTPUT_FOLDER = "Test"
SIMULATION_TIME = 10000
ISLET_ID = "one_islet"
ISLET_RADIUS = 1

# Setup logging
logging.basicConfig(level=logging.DEBUG)
coloredlogs.install()

# TEST: create islet based on number of cells per type
cells = {
    "type": "deterministic", 
    "A": 1, 
    "B": 1, 
    "D": 1
}

# TEST: create islet based on probabilities of difference cell types and total number of cells
cells = {
    "type": "probabilistic", 
    "A": 0.3, 
    "B": 0.2, 
    "D": 0.5, 
    "num_cells": 10
}

# Create islet
test_islet = Islet(
    id=ISLET_ID, 
    mechanism=MECHANISM, 
    islet_radius=ISLET_RADIUS, 
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
        
        # Perform logging and variable dumps every 4000 timesteps (.025 * 10^-3 * 4 * 10^3 = .1 seconds)
        if i % 4000 == 0:
            
            # Simulation time elapsed in seconds
            simulation_time_elapsed = (0.025 * i) / 1000

            # Get memory usage statistics
            pid = os.getpid()
            python_process = psutil.Process(pid)
            memory_use_gb = python_process.memory_info()[0]/2.**30 
            memory_use_percent = psutil.virtual_memory().available * 100 / psutil.virtual_memory().total
            
            # Log
            logging.info(f"Simulation time: {simulation_time_elapsed}. Real time: {timer()-real_start_time}. Memory Usage: {memory_use_gb}GB / {memory_use_percent}%")
            
            # Dump variables            

# Write serialized (pickled) object containing all values from simulation
with open('distance_matrix.pkl', 'wb') as f:
    logging.info(f"Serializing object...")
    pickle.dump(test_islet.cell_rec, f)
    logging.info(f"Object dumped")
            

# Setup plotting results folder
os.system(f"mkdir -p Plots/{OUTPUT_FOLDER}")
cell_plot_path = f"Plots/{OUTPUT_FOLDER}/{id}"

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
    mV_C_horm(test_islet.cell_rec[cell], variables_to_plot[cell[0]], cell_plot_path.format(id=cell))
