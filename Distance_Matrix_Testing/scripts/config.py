# Define global variables

# Size of cells
ALPHA_SIZE = DELTA_SIZE = 7
BETA_SIZE = 15.5

# Number of 'segments' to divide islet space into
SEGMENT_SIZE = 10

# Suffix of mechanism in mod file
MECHANISM = "one"

# Folder to write plots to (path will be ./Plots/<OUTPUT FOLDER>/)
OUTPUT_FOLDER = "Test"

# Time of simulation in ms
SIMULATION_TIME = 1000

# Interval over which variables will be dumped/logs will print
SIMULATION_UPDATE = 4000

# ID of islet
ISLET_ID = "one_islet"

# Radius of islet
ISLET_RADIUS = 1

# Temporary csv to write recording dictionary (cell_rec) to if DUMP is True
TEMP_CSV = '.temp_1.csv'

# Determines whether or not the recording dictionary (cell_rec) will be dumped perioidically
DUMP = True