"""Script to run batches of simulations with different configurations"""
import multiprocessing

# Configurations to modify/run
CONFIGURATIONS = {
    "runs": [
        {"GLUCOSE": 0, "DISTANCE": 0, "SIMULATION_TIME": 10000},
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
import simulate

# Simulations can be run in parallel as separate processes
processes = []

for id, config in enumerate(CONFIGURATIONS['runs']):
    for key, value in config.items():
        setattr(simulate, key, value)
        setattr(simulate, "SIMULATION_ID", id)
    
    # Create processes 
    processes.append(multiprocessing.Process(target=simulate.main()))
    
# Start and end simulations
for process in processes:
    process.start()

for process in processes:
    process.join()