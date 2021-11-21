"""Script containing functions used to perform calculations/simulations."""
import logging
# Setup logging
logger = logging.getLogger(__name__)

import math
import os

import numpy as np
import pandas as pd
from matplotlib import pyplot as plt

from Islet import Islet


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
    dist_matrix = np.array([math.dist((location_1['x'], location_1['y'], location_1['z']), (location_2['x'], location_2['y'], location_2['z'])) for location_1 in islet_name.locations for location_2 in islet_name.locations])
    
    # Reshape the array to be nxn where each row corresponds to a single cell and the 
    # distances between itself and all other cells
    dist_matrix = np.reshape(dist_matrix, (islet_name.num_cells, islet_name.num_cells))
    
    # TEST: use ordered list to test logic used to create the subsets below
    dist_matrix = np.arange(100)
    dist_matrix.shape = (10,10)
    logger.info("TEST CASE: using sorted list (np.arrange)")
    
    # TEST: use zero matrix to reproduce watts model
    dist_matrix = np.zeros((10,10))
    logger.info("TEST CASE: using zero matrix (reproduce watts model)")
    
    # TEST: use ones matrix to modify watts model via increasing distances between cells (all cells will be the same distance apart in this case)
    dist = 100
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
    
    Time = cell_rec_dict['Time']
    for var in vars:
        parameter = cell_rec_dict[var][0]
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
    # logger.debug("Plotting...")
    Time = cell_rec_dict['Time']
    fig, axes = plt.subplots(nrows = 3, sharex = True)
    fig.suptitle(f"{' '.join(vars.upper())}")
    for idx, var in enumerate(vars):
        axes[idx].plot(Time, cell_rec_dict[var][0])
        axes[0].set_ylabel(f"{var}")
    fig.savefig(plot_path)

def dump_variables(islet: Islet, temporary_path: str, step: int):
    """
    Function to dump variables to csv, clear memory and resume simulation.

    Args:
        islet (Islet): main islet object.
        temporary_path (str): path of temporary csv file.
        step (int): step number in simulation.
    """
    logger.debug("Dumping variables..")
    # Create pandas dataframe using dictionary of recorded values.
    final_dict = dict()
    for cell in islet.cell_rec:
        header_field = cell
        for var in islet.cell_rec[cell]:
            
            # Set time field
            if var == 'Time' and 'Time' not in final_dict:
                final_dict[var] = islet.cell_rec[cell][var]
            
            header_field += f"_{var}"
            
            # Note that list is stored at index 0 of the h.Vector() object
            final_dict[header_field] = islet.cell_rec[cell][var][0]
            
    # Create and write pandas dataframe
    df = pd.DataFrame({key: pd.Series(value) for key, value in final_dict.items()})
    if step == 0:
        # Remove the file if it exists
        os.system(f"rm {temporary_path}")
        df.to_csv(temporary_path, index=False)
    else:
        df.to_csv(temporary_path, mode='a', index=False, header=False)
    logger.debug("Appended to temporary csv")
    
    # Reset variables
    islet.record_values()
    logger.debug("Reset variables")
