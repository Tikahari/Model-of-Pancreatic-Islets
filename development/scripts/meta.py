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

# Run simulate script with new values
from config import Config
from simulate import Simulate

# Simulations can be run in parallel as separate processes
processes = []

for id, conf in enumerate(CONFIGURATIONS['runs']):
    
    # Store all changed variables from config in new instance
    new_config = Config()
    for key, value in conf.items():
        setattr(new_config, key, value)
        
    # Set simulation id in config
    setattr(new_config, "SIMULATION_ID", id)

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
