# Define global variables

# Size of cells
ALPHA_SIZE = DELTA_SIZE = 7
BETA_SIZE = 15.5

# Number of 'segments' to divide islet space into
SEGMENT_SIZE = 10

# Suffix of mechanism in mod file
MECHANISM = "one"

# Folder to write plots to (path will be ./Plots/<OUTPUT FOLDER>/)
OUTPUT_FOLDER = "11mM_30D"

# Number of digits to round to spike table output
ROUND = 4

# Plot time series and calculate spikes for the following variables for each cell
VARIABLES_TO_PLOT = {
    "A": ["va", "G", "ca"],
    "B": ["vb", "c", "I"],
    "D": ["vd", "cd", "S"]
}

# Time of simulation in ms
SIMULATION_TIME = 100

# Step size for simulation
STEP_SIZE = 0.025

# Interval over which variables will be dumped/logs will print
SIMULATION_UPDATE = 4000

# ID of islet
ISLET_ID = "one_islet"

# Radius of islet
ISLET_RADIUS = 1

# Temporary csv to write recording dictionary (cell_rec) to if DUMP is True
TEMP_CSV = '.temp_glucose=11mM_distance=30.csv'

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
GLUCOSE_MODULATION = {
    "interval": [0, -1],
    "modulations": modulation_11_mM
}
