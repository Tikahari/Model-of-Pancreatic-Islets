"""Script to run batches of simulations with different configurations"""
import json
import logging
import multiprocessing as mp

# Setup logging
logging.basicConfig(
    format="%(asctime)s - %(name)s - %(levelname)s - %(message)s",
    handlers=[
        logging.FileHandler(f"debug_meta.log"),
        logging.StreamHandler()
    ],
    level=logging.INFO
)

# Configurations to modify/run
CONFIGURATIONS = {
    "runs": [
        {"GLUCOSE": 0, "DISTANCE": 20, "SIMULATION_TIME": 10000},
        {"GLUCOSE": 0, "DISTANCE": 10, "SIMULATION_TIME": 10000},
        {"GLUCOSE": 0, "DISTANCE": 20, "SIMULATION_TIME": 10000},
        {"GLUCOSE": 0, "DISTANCE": 50, "SIMULATION_TIME": 10000},
        {"GLUCOSE": 0, "DISTANCE": 100, "SIMULATION_TIME": 10000},
        {"GLUCOSE": 7, "DISTANCE": 0, "SIMULATION_TIME": 10000},
        {"GLUCOSE": 7, "DISTANCE": 10, "SIMULATION_TIME": 10000},
        {"GLUCOSE": 7, "DISTANCE": 20, "SIMULATION_TIME": 10000},
        {"GLUCOSE": 7, "DISTANCE": 50, "SIMULATION_TIME": 10000},
        {"GLUCOSE": 7, "DISTANCE": 100, "SIMULATION_TIME": 10000},
        {"GLUCOSE": 11, "DISTANCE": 0, "SIMULATION_TIME": 10000},
        {"GLUCOSE": 11, "DISTANCE": 10, "SIMULATION_TIME": 10000},
        {"GLUCOSE": 11, "DISTANCE": 20, "SIMULATION_TIME": 10000},
        {"GLUCOSE": 11, "DISTANCE": 50, "SIMULATION_TIME": 10000},
        {"GLUCOSE": 11, "DISTANCE": 100, "SIMULATION_TIME": 10000},
    ]
}

import config
# Run simulate script with new values
import simulate

# Simulations can be run in parallel as separate processes
processes = []

for id, conf in enumerate(CONFIGURATIONS['runs']):
    
    # Get all changed variables from config
    for key, value in conf.items():
        setattr(config, key, value)

    calculated_variables = config.calculate_variables()
    
    # Store all new configuration variables
    new_configuration = {**conf, **calculated_variables}
    logging.info(f"New configuration: {json.dumps(new_configuration, indent=4)}")

    # Set new configuration in simulation
    for key, value in new_configuration.items():
        setattr(simulate, key, value)

    # Create processes 
    logging.info(f"Starting simulation {id}")
    process = mp.Process(target=simulate.main)
    processes.append(process)
    process.start()
    
# End simulations
for process in processes:
    process.join()
