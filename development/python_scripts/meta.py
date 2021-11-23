"""Script to run batches of simulations with different configurations"""
import json
import logging
import multiprocessing as mp
import pathlib
from datetime import datetime

TIMESTAMP = datetime.now().strftime('%Y-%m-%d_%H:%M:%S')

# Setup data/logs folders
pathlib.Path("../data/Plots/").mkdir(parents=True, exist_ok=True)
pathlib.Path(f"../logs/{TIMESTAMP}").mkdir(parents=True, exist_ok=True)

# Setup logging
logging.basicConfig(
    format="%(asctime)s - %(name)s - %(levelname)s - %(message)s",
    handlers=[
        logging.FileHandler(f"../logs/{TIMESTAMP}/meta.log"),
        logging.StreamHandler()
    ],
    level=logging.INFO
)

# Configurations to replicate watts model/test effect of distance
CONFIGURATIONS = {
    "runs": [
        {"GLUCOSE": 0, "DISTANCE": 20, "SIMULATION_TIME": 3000},
        {"GLUCOSE": 0, "DISTANCE": 10, "SIMULATION_TIME": 3000},
        {"GLUCOSE": 0, "DISTANCE": 20, "SIMULATION_TIME": 3000},
        {"GLUCOSE": 0, "DISTANCE": 50, "SIMULATION_TIME": 3000},
        {"GLUCOSE": 0, "DISTANCE": 100, "SIMULATION_TIME": 3000},
        {"GLUCOSE": 7, "DISTANCE": 0, "SIMULATION_TIME": 3000},
        {"GLUCOSE": 7, "DISTANCE": 10, "SIMULATION_TIME": 3000},
        {"GLUCOSE": 7, "DISTANCE": 20, "SIMULATION_TIME": 3000},
        {"GLUCOSE": 7, "DISTANCE": 50, "SIMULATION_TIME": 3000},
        {"GLUCOSE": 7, "DISTANCE": 100, "SIMULATION_TIME": 3000},
        {"GLUCOSE": 11, "DISTANCE": 0, "SIMULATION_TIME": 3000},
        {"GLUCOSE": 11, "DISTANCE": 10, "SIMULATION_TIME": 3000},
        {"GLUCOSE": 11, "DISTANCE": 20, "SIMULATION_TIME": 3000},
        {"GLUCOSE": 11, "DISTANCE": 50, "SIMULATION_TIME": 3000},
        {"GLUCOSE": 11, "DISTANCE": 100, "SIMULATION_TIME": 3000},
    ]
}

# # Configurations to test effect of changing composition and size of islet
# CONFIGURATIONS = {'runs': []}
# for percent_betas in range(0, 100, 10):
#     for islet_size in range(3, 120, 15):
        
#         # Create islet configuration
#         islet_configuration = {
#             "type": "probabilistic", 
#             "A": (1-percent_betas/100)*3/8, 
#             "B": percent_betas/100, 
#             "D": (1-percent_betas/100)*5/8, 
#             "num_cells": islet_size
#         }
        
#         # Add configuration for each glucose concentration
#         CONFIGURATIONS['runs'].append(
#             {"GLUCOSE": 0, "DISTANCE": None, "ISLET_CONFIGURATION": islet_configuration}
#         )
#         CONFIGURATIONS['runs'].append(
#             {"GLUCOSE": 7, "DISTANCE": None, "ISLET_CONFIGURATION": islet_configuration}
#         )
#         CONFIGURATIONS['runs'].append(
#             {"GLUCOSE": 11, "DISTANCE": None, "ISLET_CONFIGURATION": islet_configuration}
#         )
        

# Run simulate script with new values
from config import Config
from simulate import Simulate

# Simulations can be run in parallel as separate processes
processes = []

for id, conf in enumerate(CONFIGURATIONS['runs']):
    
    # Store all changed variables from config in new instance
    new_config = Config()
    
    # Include parameters in simulation_id
    simulation_id = str()
    
    for key, value in conf.items():
        setattr(new_config, key, value)
        simulation_id += f"{key.lower()}={value}_"
    
    simulation_id += str(id)
        
    # Set simulation id in config
    setattr(new_config, "SIMULATION_ID", simulation_id)
    
    # Set simulation timestamp in config
    setattr(new_config, "TIMESTAMP", TIMESTAMP)

    # Calculate values depended on those set in parameters above
    new_config.calculate_variables()
    
    logging.info(f"New configuration for {id}: {json.dumps(vars(new_config), indent=4)}")

    # Set new configuration in simulation instance (unique to each run)
    simulation = Simulate(new_config)
        
    # Create processes 
    logging.info(f"Starting simulation {id}")
    process = mp.Process(target=simulation.main)
    processes.append(process)
    process.start()
    
# End simulations
for process in processes:
    process.join()
