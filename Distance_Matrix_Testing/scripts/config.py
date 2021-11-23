# Define global variables

# Size of cells
ALPHA_SIZE = DELTA_SIZE = 7
BETA_SIZE = 15.5

# Number of 'segments' to divide islet space into
SEGMENT_SIZE = 10

# Suffix of mechanism in mod file
MECHANISM = "one"

# Glucose concentration
GLUCOSE = 0

# Distance between cells
DISTANCE = 0

# Folder to write plots to (path will be ./Plots/<OUTPUT FOLDER>/)
OUTPUT_FOLDER = f"{GLUCOSE}mM_{DISTANCE}D"

# Number of digits to round to spike table output
ROUND = 4

# Plot time series and calculate spikes for the following variables for each cell
VARIABLES_TO_PLOT = {
    "A": ["va", "ca", "G"],
    "B": ["vb", "c", "I"],
    "D": ["vd", "cd", "S"]
}

# Time of simulation in ms
SIMULATION_TIME = 3000

# Step size for simulation
STEP_SIZE = 0.025

# Interval over which variables will be dumped/logs will print
SIMULATION_UPDATE = 4000

# ID of islet
ISLET_ID = "one_islet"

# Radius of islet
ISLET_RADIUS = 1

# Islet configuration
# deterministic
ISLET_CONFIGURATION = {
    "type": "deterministic", 
    "A": 1, 
    "B": 1, 
    "D": 1
}
# probabilistic
# ISLET_CONFIGURATION = {
#     "type": "probabilistic", 
#     "A": 0.3, 
#     "B": 0.2, 
#     "D": 0.5, 
#     "num_cells": 10
# }

# Temporary csv to write recording dictionary (cell_rec) to if DUMP is True
TEMP_CSV = f".temp_glucose={GLUCOSE}mM_distance={DISTANCE}.csv"

# Determines whether or not the recording dictionary (cell_rec) will be dumped perioidically
DUMP = True

# Define logging level
LEVEL = "INFO"


# Time points at which glucose level will be modulated and the variables to modify
# 7mm glucose changes
modulation_7_mM = {
    "A":
        {
            "ksercaa": 0.5,
            "gkatpbara": 0.6
        },
    "B": 
        {
            "gkatpb": 85
        },
    "D":
        {
            "gkatpbard": 0.27
        }
}
# 11mm glucose changes
modulation_11_mM = {
    "A":
        {
            "ksercaa": 0.5,
            "gkatpbara": 0.15
        },
    "B": 
        {
            "gkatpb": 25
        },
    "D":
        {
            "gkatpbard": 0.18
        }
}
# Select glucose modulation/interval
interval = [0, -1]
modulation = None
if GLUCOSE == 7:
    modulation = modulation_7_mM
elif GLUCOSE == 1:
    modulation = modulation_11_mM
else:
    interval = [-1, -1]
    
# Final glucose modulation
GLUCOSE_MODULATION = {
    "interval": interval,
    "modulations": modulation
}
