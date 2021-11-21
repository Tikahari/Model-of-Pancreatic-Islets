from neuron import h, units, rxd, load_mechanisms
import neuron
import matplotlib
from matplotlib import pyplot as plt
h.load_file("stdrun.hoc")
from itertools import product
import pandas as pd
import os
import numpy as np
import math
import re
import pickle
from timeit import default_timer as timer
import psutil
import logging
import coloredlogs


logging.basicConfig(level=logging.DEBUG)
coloredlogs.install()

class Islet:
    def __init__(self, id, prob_alpha, prob_beta, islet_radius, num_cells):
        """Initialize islet instance"""
        # path to initialization file, mechanisms, output, and generation identifier
        self._id = id
        self.islet_radius = islet_radius
        self.num_cells = num_cells
        self.prob_alpha = prob_alpha
        self.prob_beta = prob_beta
        self.num_betas = math.floor(self.num_cells * self.prob_beta)
        self.num_alphas = math.ceil(self.num_cells * self.prob_alpha)
        self.num_deltas = self.num_cells - self.num_betas - self.num_alphas
        self.cell_rec = dict()
    
    
    def __repr__(self):
        return 'Islet[{}]'.format(self._id)

    def spatial_setup(self):
        nx, ny, nz = (10,10,10)
        # The below statements take a line from -radius to radius and chops it up into n segments
        x_coords = np.linspace(-self.islet_radius, self.islet_radius, nx)
        y_coords = np.linspace(-self.islet_radius, self.islet_radius, ny)
        z_coords = np.linspace(-self.islet_radius, self.islet_radius, nz)
        self.locations = []
        count = 0
        while count < self.num_cells:
            # Select a random value for x, y, and z coordinates
            x,y,z = np.random.choice(x_coords, 1), np.random.choice(y_coords, 1), np.random.choice(z_coords, 1)
            # Check if the point is within the islet sphere
            if math.sqrt(x**2 + y**2 + z**2) < self.islet_radius:
                # Check if random coordinates chosen are unique so not two cells have the same location
                if any(location == [x[0],y[0],z[0]] for location in self.locations): 
                    continue
                else:
                    # If location unique, append it to the locations list
                    self.locations.append((x[0],y[0],z[0]))
                    count+=1

    def populate_cells(self):
        # Create cell dictionary containing all the sections in the islet
        self.cells = {}
       # Create the sections, which can be accessed by their name in the cells dictionary
        for i in range(self.num_alphas):
            self.cells["A_" + str(i)] = h.Section(name = "A_" + str(i))
        for i in range(self.num_betas):
            self.cells["B_" + str(i)] = h.Section(name = "B_" + str(i))
        for i in range(self.num_deltas):
            self.cells["D_" + str(i)] = h.Section(name = "D_" + str(i))
        # Insert one mechanism into each cell. In future make this like original setup
        # with config file and mechanism names for each cell type.
        for cell in self.cells:
            self.cells[cell].insert('one')

    def set_cell_locations(self):
        # Separate the cells dictionary into lists for each cell type
        # This is accomplished by using the search criteria of if "A", "B", or "D"
        # is in cell name
        alpha_sections = [val for key, val in self.cells.items() if "A" in key]
        beta_sections = [val for key, val in self.cells.items() if "B" in key]
        delta_sections = [val for key, val in self.cells.items() if "D" in key]
        count = 0
        for i in range(self.num_cells):
            while count < self.num_alphas:
                # print("Setting alpha cell locations")
                alpha_sections[i].pt3dclear()
                alpha_sections[i].pt3dadd(self.locations[i][0], self.locations[i][1], self.locations[i][2], 7)
                alpha_sections[i].pt3dadd(self.locations[i][0] + 7, self.locations[i][1], self.locations[i][2], 7)
                count+=1
            while self.num_alphas <= count < self.num_alphas + self.num_betas:
                # print("Setting beta cell locations")
                beta_sections[i].pt3dclear()
                beta_sections[i].pt3dadd(self.locations[i][0], self.locations[i][1], self.locations[i][2], 15.5)
                beta_sections[i].pt3dadd(self.locations[i][0] + 15.5, self.locations[i][1], self.locations[i][2], 15.5)
                count+=1
            while self.num_alphas + self.num_betas <= count < self.num_cells:
                # print("Setting delta cell locations")
                delta_sections[i].pt3dclear()
                delta_sections[i].pt3dadd(self.locations[i][0], self.locations[i][1], self.locations[i][2], 7)
                delta_sections[i].pt3dadd(self.locations[i][0] + 7, self.locations[i][1], self.locations[i][2], 7)   
                count+=1    
    
    def record_values(self):
        for cell in self.cells:
            self.cell_rec[cell] = dict()
            for mechanism in self.cells[cell].psection()['density_mechs']:
                for variable in self.cells[cell].psection()['density_mechs'][mechanism]:
                    #if variable in rec_vars:
                    head = re.split("[0-9]", mechanism)[0]
                    self.cell_rec[cell][str(head + '_' + variable)] = []
                    # record variables of every mechanism in every segment
                    for k in self.cells[cell]:
                        mechRecord = getattr(k, '_ref_'+variable+'_'+mechanism)
                        self.cell_rec[cell][str(head + '_' + variable)].append(h.Vector().record(mechRecord))        

# This function first creates a matrix that contains the distance between each cell.
# Each row of this matrix corresponds to a cell.
# Say there are k alpha cells, l beta cells, and m delta cells.
# And let n=k+l+m be the total number of cells.
# The first k rows correspond to alpha cells.
# Rows k+1 to k+l correspond to beta cells.
# Rows k+l+1 to n correspond to delta cells.
# This matrix will then be subsetted into different matrices
# One for beta cells affecting alphas that will contain the rows corresponding to 
# beta cells and the columns corresponding to alpha cells (D_ba).
# One for delta cells affecting alphas that will contain the rows corresponding to 
# delta cells and the columns corresponding to alpha cells (D_da).
# One for alpha cells affecting betas that will contain the rows corresponding to 
# alpha cells and the columns corresponding to beta cells (D_ab).
# One for delta cells affecting betas that will contain the rows corresponding to 
# delta cells and the columns corresponding to beta cells (D_db).
# One for beta cells affecting deltas that will contain the rows corresponding to 
# beta cells and the columns corresponding to delta cells (D_bd).
def create_dist_matrices(islet_name):
    # Create a numpy array containing the distance between each cell
    dist_matrix = np.array([math.dist(location_1, location_2) for location_1 in islet_name.locations for location_2 in islet_name.locations])
    # Reshape the array to be nxn where each row corresponds to a single cell and the 
    # distances between itself and all other cells
    dist_matrix = np.reshape(dist_matrix, (islet_name.num_cells, islet_name.num_cells))
    # TEST: use ordered list to test logic used to create the subsets below
    dist_matrix = np.arange(100)
    dist_matrix.shape = (10,10)
    # TEST: use zero matrix to reproduce watts model
    dist_matrix = np.zeros((10,10))
    # TEST: use ones matrix to modify watts model via increasing distances between cells
    dist = 100
    dist_matrix = np.ones((10,10)) * dist
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



# Function to make column vectors of JIS, JGS, and JSS values
# These vectors will need to be populated with new values at each time step
def calculate_secretion_rate_matrix(islet_name, matrices):
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
    
    # print("insulin from beta cell")
    # print(JIS_col_matrix)
    # print("glucagon from alpha cell")
    # print(JGS_col_matrix)
    # print("somatostatin from delta cell")
    # print(JSS_col_matrix)
    # input()
    
    # Calculate new secretion rates
    JGS_col_d = list(np.matmul(matrices["alpha_affecting_delta"], JGS_col_matrix))
    JGS_col_b = list(np.matmul(matrices["alpha_affecting_beta"], JGS_col_matrix))
    JIS_col_a = list(np.matmul(matrices["beta_affecting_alpha"], JIS_col_matrix))
    JIS_col_d = list(np.matmul(matrices["beta_affecting_delta"], JIS_col_matrix))
    JSS_col_a = list(np.matmul(matrices["delta_affecting_alpha"], JSS_col_matrix))
    JSS_col_b = list(np.matmul(matrices["delta_affecting_beta"], JSS_col_matrix))
    
    # print("insulin")
    # print(JIS_col_a)
    # print(JIS_col_d)
    # print("glucagon")
    # print(JGS_col_d)
    # print(JGS_col_b)
    # print("somatostatin")
    # print(JSS_col_a)
    # print(JSS_col_b)
    # input()
    
    # Set secretion rates
    for cell in sorted(islet_name.cells):
        if "A" in cell:
            islet_name.cells[cell](0.5).one.JIS = JIS_col_a[0] + islet_name.cells[cell](0.5).one.JIS
            JIS_col_a.pop(0)
            islet_name.cells[cell](0.5).one.JSS = JSS_col_a[0] + islet_name.cells[cell](0.5).one.JSS
            JSS_col_a.pop(0)
            # print(cell, "set JSS", islet_name.cells[cell](0.5).one.JSS, "JIS", islet_name.cells[cell](0.5).one.JIS)
        elif "B" in cell:
            islet_name.cells[cell](0.5).one.JGS = JGS_col_b[0] + islet_name.cells[cell](0.5).one.JGS
            JGS_col_b.pop(0)
            islet_name.cells[cell](0.5).one.JSS = JSS_col_b[0] + islet_name.cells[cell](0.5).one.JSS
            JSS_col_b.pop(0)
            # print(cell, "set JGS", islet_name.cells[cell](0.5).one.JGS, "JSS", islet_name.cells[cell](0.5).one.JSS)
        elif "D" in cell:
            islet_name.cells[cell](0.5).one.JIS = JIS_col_d[0] + islet_name.cells[cell](0.5).one.JIS
            JIS_col_d.pop(0)
            islet_name.cells[cell](0.5).one.JGS = JGS_col_d[0] + islet_name.cells[cell](0.5).one.JGS
            JGS_col_d.pop(0)
            # print(cell, "set JIS", islet_name.cells[cell](0.5).one.JIS, "JGS", islet_name.cells[cell](0.5).one.JGS)
        

########## Plotting Functions from big_cell.py ########## 


# Simple function that allows us to use cells recording dictionary to visualize one parameter versus time.
def visualize_parameter(cell_rec_dict,var, plot_path):
    Time = cell_rec_dict['Time']
    parameter = cell_rec_dict[var][0]
    fig = plt.figure()
    plt.plot(Time, parameter)
    plt.xlabel("Time (ms)")
    plt.ylabel(var)
    fig.savefig(plot_path)

# Function to compare plots from our simulations to those from the BAD model. Uses rec dictionary from the cell
def mV_C_horm(cell_rec_dict, var0, var1, var2, plot_path):
    Time = cell_rec_dict['Time']
    fig, axes = plt.subplots(nrows = 3, sharex = True)
    fig.suptitle("Membrane Potential, Calcium, and Hormone.")
    axes[0].plot(Time, cell_rec_dict[var0][0])
    axes[0].set_ylabel("Vm (mV)")
    axes[1].plot(Time, cell_rec_dict[var1][0])
    axes[1].set_ylabel("C ($\mu$M)")
    axes[2].plot(Time, cell_rec_dict[var2][0])
    axes[2].set_ylabel("Hormone (pM)")
    axes[2].set_xlabel("Time (ms)")
    fig.savefig(plot_path)




################## Continue distance_matrix.py ################## 
simulation_setup = "Test"
simulation_output = "Data/" + simulation_setup + ".pkl"
os.system("mkdir -p Plots/" + simulation_setup)
cell_plot_path = 'Plots/' + simulation_setup + '/{id}.png'
df_path = 'Plots/' + simulation_setup + '/metrics_{id}.png' 
for cell in test_islet.cell_rec:
    print(f"Plotting cell: {cell}")
    if cell.startswith('A'):
        mV_C_horm(test_islet.cell_rec[cell], 'one_va', "one_ca", 'one_G', cell_plot_path.format(id=cell))
    elif cell.startswith('B'):
        mV_C_horm(test_islet.cell_rec[cell], 'one_vb', "one_c", 'one_I', cell_plot_path.format(id=cell))
    else:
        mV_C_horm(test_islet.cell_rec[cell], 'one_vd', "one_cd", 'one_S', cell_plot_path.format(id=cell))