# Store global variables as members of class

class Config():
    
    
    def __init__(self):
        """Constructor containing simulation parameter definitions"""
        
        # Simulation id
        self.SIMULATION_ID = 0

        # Size of cells
        self.ALPHA_SIZE = self.DELTA_SIZE = 7
        self.BETA_SIZE = 15.5

        # Number of 'segments' to divide islet space into
        self.SEGMENT_SIZE = 10

        # Suffix of mechanism in mod file
        self.MECHANISM = "one"

        # Glucose concentration
        self.GLUCOSE = 0

        # Distance between cells
        self.DISTANCE = 0

        # Folder to write plots to (path will be ./Plots/<OUTPUT FOLDER>/)
        self.OUTPUT_FOLDER = f"{self.GLUCOSE}mM_{self.DISTANCE}D"

        # Number of digits to round to spike table output
        self.ROUND = 4

        # File to load data from (should be set in meta.py or simulate.py)
        self.LOAD = f"stabilized_glucose={self.GLUCOSE}mM_distance={self.DISTANCE}.csv"
        
        # Option to load data from previous run
        self.LOAD_PREVIOUS = True
        
        # Option to write stabilized output from current run (note that DUMP needs to be set to True for the option to be meaningful)
        self.LOAD_CURRENT = True
        
        # Plot time series and calculate spikes for the following variables for each cell
        self.VARIABLES_TO_PLOT = {
            "A": ["va", "ca", "G"],
            "B": ["vb", "c", "I"],
            "D": ["vd", "cd", "S"]
        }

        # Time of simulation in ms
        self.SIMULATION_TIME = 1000

        # Step size for simulation
        self.STEP_SIZE = 0.025

        # Interval over which variables will be dumped/logs will print
        self.SIMULATION_UPDATE = 4000

        # ID of islet
        self.ISLET_ID = "one_islet"

        # Radius of islet
        self.ISLET_RADIUS = 1

        # Islet configuration
        # deterministic
        self.ISLET_CONFIGURATION = {
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
        self.TEMP_CSV = f".temp_glucose={self.GLUCOSE}mM_distance={self.DISTANCE}.csv"

        # Determines whether or not the recording dictionary (cell_rec) will be dumped perioidically
        self.DUMP = True

        # Define logging level
        self.LEVEL = "INFO"


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
        # Assume glucose will be changed once at the beginning of the simulation through to the end
        interval = [0, -1]
        modulation = None
        if self.GLUCOSE == 7:
            modulation = modulation_7_mM
        elif self.GLUCOSE == 11:
            modulation = modulation_11_mM
        # If glucose is 0 or not an accepted value, do not change it during the simulation
        else:
            interval = [-1, -1]
            
        # Final glucose modulation
        self.GLUCOSE_MODULATION = {
            "interval": interval,
            "modulations": modulation,
            "temporary": None
        }


    def calculate_variables(self):
        """Function to calculate global variables (in case they are individually defined i.e. meta.py)"""
        
        # Temporary csv to write recording dictionary (cell_rec) to if DUMP is True
        self.TEMP_CSV = f".temp_glucose={self.GLUCOSE}mM_distance={self.DISTANCE}.csv"
        
        # Folder to write plots to (path will be ./Plots/<OUTPUT FOLDER>/)
        self.OUTPUT_FOLDER = f"{self.GLUCOSE}mM_{self.DISTANCE}D"
        
        # File to load data from (should be set in meta.py or simulate.py)
        self.LOAD = f"stabilized_{self.GLUCOSE}mM_{self.DISTANCE}_.csv"
        
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
        # Assume glucose will be changed once at the beginning of the simulation through to the end
        interval = [0, -1]
        modulation = None
        if self.GLUCOSE == 7:
            modulation = modulation_7_mM
        elif self.GLUCOSE == 11:
            modulation = modulation_11_mM
        # If glucose is 0 or not an accepted value, do not change it during the simulation
        else:
            interval = [-1, -1]
            
        # Final glucose modulation
        self.GLUCOSE_MODULATION = {
            "interval": interval,
            "modulations": modulation,
            "temporary": None
        }
        
        # TODO: don't hard code returned variable names
        return {
            "TEMP_CSV": self.TEMP_CSV, 
            "OUTPUT_FOLDER": self.OUTPUT_FOLDER, 
            "GLUCOSE_MODULATION": self.GLUCOSE_MODULATION
        }