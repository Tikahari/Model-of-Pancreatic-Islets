"""Script containing functions used to perform calculations/simulations."""
import logging

import copy
import math
import os

import numpy as np
import pandas as pd
from matplotlib import pyplot as plt
from scipy.signal import find_peaks

from config import *
from islet import Islet

# Setup logging
logger = logging.getLogger(f"{__name__}_{SIMULATION_ID}")

def create_dist_matrices(islet_name: str):
    """
    This function first creates a matrix that contains the distance between each cell.
    Each row of this matrix corresponds to a cell.
    Say there are k alpha cells, l beta cells, and m delta cells.
    And let n=k+l+m be the total number of cells.
    The first k rows correspond to alpha cells.
    Rows k+1 to k+l correspond to beta cells.
    Rows k+l+1 to n correspond to delta cells.
    This matrix will then be subsetted into different matrices
    One for beta cells affecting alphas that will contain the rows corresponding to 
    beta cells and the columns corresponding to alpha cells (D_ba).
    One for delta cells affecting alphas that will contain the rows corresponding to 
    delta cells and the columns corresponding to alpha cells (D_da).
    One for alpha cells affecting betas that will contain the rows corresponding to 
    alpha cells and the columns corresponding to beta cells (D_ab).
    One for delta cells affecting betas that will contain the rows corresponding to 
    delta cells and the columns corresponding to beta cells (D_db).
    One for beta cells affecting deltas that will contain the rows corresponding to 
    beta cells and the columns corresponding to delta cells (D_bd).

    Args:
        islet_name (str): islet id.

    Returns:
        (dict): dictionary indexed by id of matrix to be returned (contains total dist_matrix and all subsets used in calculations).
    """
    logger.debug("Setting up distance matrix")
    
    # Create a numpy array containing the distance between each cell
    dist_matrix = np.array([1/math.dist((location_1['x'], location_1['y'], location_1['z']), (location_2['x'], location_2['y'], location_2['z'])) if math.dist((location_1['x'], location_1['y'], location_1['z']), (location_2['x'], location_2['y'], location_2['z'])) != 0 else 0 for location_1 in islet_name.locations for location_2 in islet_name.locations])
    
    # Reshape the array to be nxn where each row corresponds to a single cell and the 
    # distances between itself and all other cells
    dist_matrix = np.reshape(dist_matrix, (islet_name.num_cells, islet_name.num_cells))
    
    # TEST: use ordered list to test logic used to create the subsets below
    # dist_matrix = np.arange(100)
    # dist_matrix.shape = (10,10)
    # logger.info("TEST CASE: using sorted list (np.arrange)")
    
    # TEST: use zero matrix to reproduce watts model
    if DISTANCE == 0:
        dist_matrix = np.zeros((10,10))
        logger.info("TEST CASE: using zero matrix (reproduce watts model)")
        
    # TEST: use ones matrix to modify watts model via increasing distances between cells (all cells will be the same distance apart in this case)
    else:
        dist = DISTANCE
        dist_matrix = np.ones((10,10)) * dist
        logger.info("TEST CASE: using scalar multiple of ones matrix (module watts model with uniform distance)")
        
    # Create D_ba
    D_ba = dist_matrix[0:islet_name.num_alphas, islet_name.num_alphas:islet_name.num_alphas+islet_name.num_betas]
    # Create D_da
    D_da = dist_matrix[0:islet_name.num_alphas, islet_name.num_alphas+islet_name.num_betas:islet_name.num_cells]
    # Create D_ab
    D_ab = dist_matrix[islet_name.num_alphas:islet_name.num_alphas+islet_name.num_betas, 0:islet_name.num_alphas]
    # Create D_db
    D_db = dist_matrix[islet_name.num_alphas:islet_name.num_alphas+islet_name.num_betas, islet_name.num_alphas+islet_name.num_betas:islet_name.num_cells]
    # Create D_bd
    D_bd = dist_matrix[islet_name.num_alphas+islet_name.num_betas:islet_name.num_cells, islet_name.num_alphas:islet_name.num_alphas+islet_name.num_betas]
    # Create D_ad
    D_ad = dist_matrix[islet_name.num_alphas+islet_name.num_betas:islet_name.num_cells, 0:islet_name.num_alphas]
    
    return {
        "distance_matrix": dist_matrix,
        "beta_affecting_alpha": D_ba,
        "beta_affecting_delta": D_bd,
        "delta_affecting_alpha": D_da,
        "delta_affecting_beta": D_db,
        "alpha_affecting_beta": D_ab,
        "alpha_affecting_delta": D_ad
        }


def calculate_secretion_rate_matrix(islet_name: str, matrices: dict):
    """
    Function to make column vectors of JIS, JGS, and JSS values.
    These vectors will need to be populated with new values at each time step

    Args:
        islet_name (str): islet id.
        matrices (dict): dictionary indexed by id of matrix to be returned (contains total dist_matrix and all subsets used in calculations).
    """
    # logger.debug("Calculate secretion rate matrix")
    
    # Create list of cell names by accessing keys in cell
    # dictionary
    cell_names = list(sorted(islet_name.cells.keys()))
    
    # Initialize column vectors
    JIS_col_matrix = []
    JGS_col_matrix = []
    JSS_col_matrix = []
    
    # Add JIS, JGS, JSS values to corresponding vector based on name
    for cell in cell_names:
        if "B" in cell:
            JIS_col_matrix.append(islet_name.cells[cell](0.5).one.JIS)
        if "A" in cell:
            JGS_col_matrix.append(islet_name.cells[cell](0.5).one.JGS)
        if "D" in cell:
            JSS_col_matrix.append(islet_name.cells[cell](0.5).one.JSS)
    
    # logger.debug("insulin from beta cell")
    # logger.debug(JIS_col_matrix)
    # logger.debug("glucagon from alpha cell")
    # logger.debug(JGS_col_matrix)
    # logger.debug("somatostatin from delta cell")
    # logger.debug(JSS_col_matrix)
    # input()
    
    # Calculate new secretion rates
    JGS_col_d = list(np.matmul(matrices["alpha_affecting_delta"], JGS_col_matrix))
    JGS_col_b = list(np.matmul(matrices["alpha_affecting_beta"], JGS_col_matrix))
    JIS_col_a = list(np.matmul(matrices["beta_affecting_alpha"], JIS_col_matrix))
    JIS_col_d = list(np.matmul(matrices["beta_affecting_delta"], JIS_col_matrix))
    JSS_col_a = list(np.matmul(matrices["delta_affecting_alpha"], JSS_col_matrix))
    JSS_col_b = list(np.matmul(matrices["delta_affecting_beta"], JSS_col_matrix))
    
    # logger.debug("insulin")
    # logger.debug(JIS_col_a)
    # logger.debug(JIS_col_d)
    # logger.debug("glucagon")
    # logger.debug(JGS_col_d)
    # logger.debug(JGS_col_b)
    # logger.debug("somatostatin")
    # logger.debug(JSS_col_a)
    # logger.debug(JSS_col_b)
    # input()
    
    # Set secretion rates
    for cell in sorted(islet_name.cells):
        if "A" in cell:
            islet_name.cells[cell](0.5).one.JIS = JIS_col_a[0] + islet_name.cells[cell](0.5).one.JIS
            JIS_col_a.pop(0)
            islet_name.cells[cell](0.5).one.JSS = JSS_col_a[0] + islet_name.cells[cell](0.5).one.JSS
            JSS_col_a.pop(0)
            # logger.debug(f"{cell} "set JSS {islet_name.cells[cell](0.5).one.JSS} JIS {islet_name.cells[cell](0.5).one.JIS}")
        elif "B" in cell:
            islet_name.cells[cell](0.5).one.JGS = JGS_col_b[0] + islet_name.cells[cell](0.5).one.JGS
            JGS_col_b.pop(0)
            islet_name.cells[cell](0.5).one.JSS = JSS_col_b[0] + islet_name.cells[cell](0.5).one.JSS
            JSS_col_b.pop(0)
            # logger.debug(f"{cell} set JGS {islet_name.cells[cell](0.5).one.JGS} JSS {islet_name.cells[cell](0.5).one.JSS}")
        elif "D" in cell:
            islet_name.cells[cell](0.5).one.JIS = JIS_col_d[0] + islet_name.cells[cell](0.5).one.JIS
            JIS_col_d.pop(0)
            islet_name.cells[cell](0.5).one.JGS = JGS_col_d[0] + islet_name.cells[cell](0.5).one.JGS
            JGS_col_d.pop(0)
            # logger.debug(f"{cell} set JIS {islet_name.cells[cell](0.5).one.JIS} JGS {islet_name.cells[cell](0.5).one.JGS}")
        

def visualize_parameter(cell_rec_dict: dict, vars: list, plot_path: str):
    """
    Simple function that allows us to use cells recording dictionary to visualize one parameter versus time.

    Args:
        cell_rec_dict (dict): dictionary indexed by variable name containing h.Vector() objects containing recorded variable values.
        vars (list): variables to plot.
        plot_path (str): path to which plot will be saved.
    """
    logger.debug("Visualizing parameter")
    
    # Initialize time
    Time = None if DUMP else cell_rec_dict['Time']
    
    for var in vars:
        
        # Set time list if variables have been periodically dumped
        if DUMP:
            Time = [x*STEP_SIZE for x in range(len(cell_rec_dict[f"{MECHANISM}_{var}"]))]
            parameter = cell_rec_dict[f"{MECHANISM}_{var}"]

        # When not dumping variable            
        else:   
            parameter = cell_rec_dict[var][0]
        
        # Generate plots
        fig = plt.figure()
        plt.plot(Time, parameter)
        plt.xlabel("Time (ms)")
        plt.ylabel(var)
        fig.savefig(f"{plot_path}_{var}.png")


def plot_parameters(cell_rec_dict: dict, vars: list, plot_path: str):
    """
    Function to compare plots from our simulations to those from the BAD model. Uses rec dictionary from the cell.

    Args:
        cell_rec_dict (dict): dictionary indexed by variable name containing h.Vector() objects containing recorded variable values.
        vars (list): variables to plot.
        plot_path (str): path to which plot will be saved.
    """
    logger.debug("Plotting...")
    
    # Initialize time
    Time = None if DUMP else cell_rec_dict['Time']
    
    fig, axes = plt.subplots(nrows = len(vars), sharex = True)
    fig.suptitle(f"{' '.join(vars)} vs Time")
    for idx, var in enumerate(vars):
        
        # Set time list if variables have been periodically dumped
        if DUMP:
            Time = [x*STEP_SIZE for x in range(len(cell_rec_dict[f"{MECHANISM}_{var}"]))]
            axes[idx].plot(Time, cell_rec_dict[f"{MECHANISM}_{var}"])
        
        # Use 0 index when not dumping variable
        else:
            axes[idx].plot(Time, cell_rec_dict[f"{MECHANISM}_{var}"][0])
        
        
        axes[idx].set_ylabel(f"{var}")
        
    # Save plot
    fig.savefig(f"{plot_path}.png")
    
    logger.debug(f"Completed plot")


def dump_variables(islet: Islet, temporary_path: str, step: int, last: bool = False):
    """
    Function to dump variables to csv, clear memory and resume simulation.

    Args:
        islet (Islet): main islet object.
        temporary_path (str): path of temporary csv file.
        step (int): step number in simulation.
        last (bool): boolean set to True only when dump_variables is called outside of the main simulation loop.
    """
    logger.debug("Dumping variables..")
    # Create pandas dataframe using dictionary of recorded values.
    final_dict = dict()
    for cell in islet.cell_rec:
        for var in islet.cell_rec[cell]:
            
            header_field = f"{cell}_{var}"
            
            # Note that list is stored at index 0 of the h.Vector() object
            final_dict[header_field] = islet.cell_rec[cell][var][0]
            
    # Create and write pandas dataframe
    df = pd.DataFrame({key: pd.Series(value) for key, value in final_dict.items()})
    logger.debug(f"Dataframe size: {str(df.size)}")
    # input()
    if step == 0:
        
        # Remove the file if it exists
        logger.debug("Replacing temporary file..")
        os.system(f"rm {temporary_path}")
        df.to_csv(temporary_path, index=False)
    else:
        logger.debug("Appending to temporary file..")
        with open(temporary_path, 'a') as temporary_file:
            df.to_csv(temporary_file, index=False, header=False)
        logger.debug("Appended to temporary csv")
        
        # Reset variables each time other than last
        if not last:
            islet.reset_values()
            logger.debug("Reset variables")


def modulate_glucose(cells: dict, simulation_idx: int, GLUCOSE_MODULATION: str):
    """
    Function to modify simulation variables corresponding to glucose changes at a given simulation index.

    Args:
        cells (dict): dictionary of with values being hoc section objects.
        simulation_idx (int): simulation index.
    """
    logger.info(f"Modulating glucose at {simulation_idx}")
    
    # Determine whether modulation is beggining or ending
    start = True if simulation_idx == GLUCOSE_MODULATION['interval'][0] else False
    # If the simulation index is the beginning of the modulation interval:
    # Iterate through cells and modify values according to GLUCOSE_MODULATION global variable
    if start:
        
        # Store old values in 'temporary' key of dictionary (will overwrite values in copy of 'modulations')
        GLUCOSE_MODULATION['temporary'] = copy.deepcopy(GLUCOSE_MODULATION['modulations'])
        
        for cell in cells:
            type = cell[0]
            for modulation in GLUCOSE_MODULATION['modulations'][type]:
                
                # Save old value
                GLUCOSE_MODULATION['temporary'][type][modulation] = getattr(cells[cell](0.5), f"{modulation}_{MECHANISM}")
                
                # Write new value
                setattr(cells[cell](0.5), f"{modulation}_{MECHANISM}", GLUCOSE_MODULATION['modulations'][type][modulation])
                
                logger.info(f"Changed {modulation} from {GLUCOSE_MODULATION['temporary'][type][modulation]} to {GLUCOSE_MODULATION['modulations'][type][modulation]}")
    
    
    # If the simulation index is the end of the modulation interval:
    # Restore values
    else:
        for cell in cells:
            type = cell[0]
            for modulation in GLUCOSE_MODULATION['temporary'][type]:
                
                # Store old value for logging
                old_value = getattr(cells[cell](0.5), f"{modulation}_{MECHANISM}")
                
                # Restore value
                setattr(cells[cell](0.5), f"{modulation}_{MECHANISM}",  GLUCOSE_MODULATION['temporary'][type][modulation])
                
                logger.info(f"Restored {modulation} from {old_value} to {GLUCOSE_MODULATION['temporary'][type][modulation]}")
                
    logger.info("Completed modulation")

"""Spike counter/evaluation"""

def determine_metrics(cell_rec_dict: dict, plot_dict: dict, vars: list):
    """
    Function to calculate spike frequencies and average height an minimum for the peaks for membrane potential 
    With a timestep of 0.025 ms there are 40 steps per ms, I want to only show stats for last 2000 ms (2 seconds) of simulation

    Args:
        cell_rec_dict (dict): dictionary indexed by variable name containing h.Vector() objects containing recorded variable values.
        plot_dict (dict): dictionary holding keys to transform to table
        vars (list): variables to plot.
    """
    logger.debug("Determining metrics")

    for var in vars:
        
        # Recording dictionary indexed differently depending on whether dumping was implemented
        param = f"{MECHANISM}_{var}"
        if DUMP:
            param = cell_rec_dict[param]
        else:
            param = cell_rec_dict[param][0]
        
        # Find indices where spikes occur and at what value (heights)
        peaks, props = find_peaks(param, height = [min(param), max(param)])
        
        # To find the minimum points of peaks, multiply negative one to all values in the parameter vector
        # and then find peaks
        neg_param = [item * -1 for item in param]
        peaks_min, props_min = find_peaks(neg_param, height = [min(neg_param), max(neg_param)])
        
        
        # Add metrics to plotting dict
        plot_dict['Total Spikes'].append(len(peaks))
        plot_dict['Spike Frequency'].append(len(peaks)/2)
        plot_dict['Max Value'].append(max(peaks))
        plot_dict['Min Value'].append(min(peaks))
        plot_dict['Avg. Spike Max'].append(np.mean(peaks))
        plot_dict['Avg. Spike Min'].append(-np.mean(peaks_min))
    
    logger.debug("Metrics calculated")


def find_min_max_of_spikes(cell_rec_dict: dict, plot_dict: dict, vars: list):
    """
    Function to determine the in and maxes of recorded spikes.

    Args:
        cell_rec_dict (dict): dictionary indexed by variable name containing h.Vector() objects containing recorded variable values.
        plot_dict (dict): dictionary holding keys to transform to table
        vars (list): variables to plot.
    """
    logger.debug("Determining")
    
    steps_per_ms = int(1/STEP_SIZE)
    total_steps = int(SIMULATION_TIME/STEP_SIZE)
    steps_in_last_2_secs = int(steps_per_ms * 2000)
    min_value = []
    avg_spike_min = []
    max_value = []
    avg_spike_max = []
    Voltage_B = cell_rec_dict['one_vb'][0]
    Calcium_B = cell_rec_dict['one_c'][0]
    Insulin = cell_rec_dict['one_I'][0]
    Voltage_D = cell_rec_dict['one_vd'][0]
    Calcium_D = cell_rec_dict['one_cd'][0]
    Sst = cell_rec_dict['one_S'][0]
    Voltage_A = cell_rec_dict['one_va'][0]
    Calcium_A = cell_rec_dict['one_ca'][0]
    Glucagon = cell_rec_dict['one_G'][0]
    params = [Voltage_B, Calcium_B, Insulin, Voltage_D, Calcium_D, Sst, Voltage_A, Calcium_A, Glucagon]
    
    # Restrict data to only the last 2000 ms to allow simulation to stabilize
    params = [list(param)[(total_steps - steps_in_last_2_secs):] for param in params]
    
    for param in params:
        # Find indices where spikes occur and at what value (heights)
        peaks_max, props_max = find_peaks(param, height = [min(param), max(param)])
        # To find the minimum points of peaks, multiply negative one to all values in the parameter vector
        # and then find peaks
        neg_param = [item * -1 for item in param]
        peaks_min, props_min = find_peaks(neg_param, height = [min(neg_param), max(neg_param)])
        # Find frequency of spikes in last two seconds
        max_value.append(max(param))
        avg_spike_max.append(np.mean(props_max["peak_heights"]))
        min_value.append(min(param))
        avg_spike_min.append(-np.mean(props_min["peak_heights"]))
    return max_value, avg_spike_max, min_value, avg_spike_min


def create_metrics_table(cell_rec_dict: dict, vars: list, plot_path: str):
    """
    Function to create metrics table with spike statistics.

    Args:
        cell_rec_dict (dict): dictionary indexed by variable name containing h.Vector() objects containing recorded variable values.
        vars (list): variables to plot.
        plot_path (str): path to which plot will be saved.ß
    """
    logger.debug("Generating metrics table")
    
    # Variables to plot (in table format)
    plot_dict = {
        "Parameters": [], 
        "Total Spikes": [], 
        "Spike Frequency": [], 
        "Max Value": [], 
        "Avg. Spike Max": [], 
        "Min Value": [], 
        "Avg. Spike Min": []
    }
    
    # Add vars to plotting dict
    for var in vars:
        plot_dict['Parameters'].append(var)
    
    # Determine metrics
    determine_metrics(cell_rec_dict, plot_dict, vars)
    
    # Round values
    for key, values in plot_dict.items():
        if key != 'Parameters':
            rounded_values = []
            for value in values:
                rounded_values.append(
                    round(value, ROUND)
                )
            plot_dict[key] = rounded_values

    # Convert to pandas dataframe
    df = pd.DataFrame(plot_dict)
    
    # Define figure and axes
    fig, ax = plt.subplots()
    
    # Hide the axes
    fig.patch.set_visible(False)
    ax.axis('off')
    ax.axis('tight')
    
    # Create table
    table = ax.table(cellText=df.values, colLabels=df.columns, loc='center')
    table.auto_set_font_size(False)
    table.set_fontsize(7)
    table.scale(1.25, 1.0)

    # Save table
    fig.savefig(f"{plot_path}_metrics.png", dpi = 300)
    
    logger.debug("Metrics table generated")
