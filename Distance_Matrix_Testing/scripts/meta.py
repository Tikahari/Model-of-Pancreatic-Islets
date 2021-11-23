"""Script to run batches of simulations with different configurations"""

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

for config in CONFIGURATIONS['runs']:
    for key, value in config.items():
        setattr(simulate, key, value)
    
    # Run simulation
    simulate.main()