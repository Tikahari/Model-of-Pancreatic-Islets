import re
from neuron import h
import pickle
import pandas as pd
from scipy.signal import find_peaks
import os
import numpy as np
# import logging, coloredlogs
# coloredlogs.install(level='DEBUG')
import matplotlib.pyplot as plt

class Cell:
    def __init__(self, gid, x, y, z, mechs):
        self._gid = gid
        self._setup_morphology()
        self.all = self.cell.wholetree()
        self._setup_biophysics(mechs)
        self.x, self.y, self.z = (0,0,0)
        h.define_shape()
        #self._rotate_z(theta)
        self._set_position(x,y,z)
        self.rec = {"Time": h.Vector().record(h._ref_t)}
    
    def __repr__(self):
        return '{}[{}]'.format(self.name, self._gid)
    
    def _set_position(self, x, y, z):
        for sec in self.all:
            for i in range(sec.n3d()):
                sec.pt3dchange(i,
                               x - self.x + sec.x3d(i),
                               y - self.y + sec.y3d(i),
                               z - self.z + sec.z3d(i),
                               sec.diam3d(i))
        self.x, self.y, self.z = (0,0,0)


class Alpha(Cell):
    name = 'Alpha'
    def _setup_morphology(self):
        self.cell = h.Section(name='soma', cell=self)
        self.cell.L = self.cell.diam = 14
    def _setup_biophysics(self, mechs):
        self.mechs = mechs
        for sec in self.all:
            sec.Ra = 100    # Axial resistance in Ohm * cm
            sec.cm = 3.24806     # Membrane capacitance in micro Farads / cm^2
        for mech in mechs: 
            self.cell.insert(mech)

# Function to setup recording variables and to pickle simulation output.
# To write, set write to True, to just record set it to False.
def record_or_write(cell_name, write, outputPath = None):
    if write:
        with open(outputPath, 'wb') as f:
            pickle.dump(cell_name.rec, f)
    else:
        for mechanism in cell_name.cell.psection()['density_mechs']:
            for variable in cell_name.cell.psection()['density_mechs'][mechanism]:
                #if variable in rec_vars:
                head = re.split("[0-9]", mechanism)[0]
                cell_name.rec[str(head + '_' + variable)] = []
                # record variables of every mechanism in every segment
                for k in cell_name.cell:
                    mechRecord = getattr(k, '_ref_'+variable+'_'+mechanism)
                    cell_name.rec[str(head + '_' + variable)].append(h.Vector().record(mechRecord))


# Simple function that allows us to use cells recording dictionary to visualize one parameter versus time.
def visualize_parameter(cell_rec_dict,var, plot_path):
    Time = cell_rec_dict['Time']
    parameter = cell_rec_dict[var][0]
    fig = plt.figure()
    plt.plot(Time, parameter)
    plt.xlabel("Time (ms)")
    plt.ylabel(var)
    fig.savefig(plot_path)

# Function to calculate spike frequencies and average height an minimum for the peaks for membrane potential 
# With a timestep of 0.025 ms there are 40 steps per ms, I want to only show stats for last 2000 ms (2 seconds) of simulation
def find_spike_frequency(cell_rec_dict, simulation_time, time_step):
    steps_per_ms = int(1/time_step)
    total_steps = int(simulation_time/time_step)
    steps_in_last_2_secs = int(steps_per_ms * 2000)
    total_spikes = [] 
    spike_frequency = []
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
        peaks, props = find_peaks(param, height = [min(param), max(param)])
        total_spikes.append(len(peaks))
        # Find frequency of spikes in last two seconds
        spike_frequency.append(len(peaks)/2)
    return total_spikes, spike_frequency

def find_min_max_of_spikes(cell_rec_dict, simulation_time, time_step):
    steps_per_ms = int(1/time_step)
    total_steps = int(simulation_time/time_step)
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



def BAD_model_metrics_table(cell_rec_dict, simulation_time, time_step, df_path):
    steps_per_ms = int(1/time_step)
    keys = {"Parameter": ["Voltage_B", "Calcium_B", "Insulin", "Voltage_D", "Calcium_D", "Sst", "Voltage_A", "Calcium_A", "Glucagon"], "Total Spikes": [], "Spike Frequency": [], "Max Value": [], "Avg. Spike Max": [], "Min Value": [], "Avg. Spike Min": []}
    total_spikes, spike_frequency = find_spike_frequency(cell_rec_dict, simulation_time, time_step)
    max_value, avg_spike_max, min_value, avg_spike_min = find_min_max_of_spikes(cell_rec_dict, simulation_time, time_step)
    total_spikes = [round(value, 4) for value in total_spikes]
    spike_frequency = [round(value, 4) for value in spike_frequency]
    max_value = [round(value, 4) for value in max_value]
    avg_spike_max = [round(value, 4) for value in avg_spike_max]
    min_value = [round(value, 4) for value in min_value]
    avg_spike_min = [round(value, 4) for value in avg_spike_min]
    values = [total_spikes, spike_frequency, max_value, avg_spike_max, min_value, avg_spike_min]
    count = 0
    for key in keys:
        if key == "Parameter":
            continue
        keys[key] = values[count]
        count += 1
    df = pd.DataFrame(keys)
    #define figure and axes
    fig, ax = plt.subplots()
    #hide the axes
    fig.patch.set_visible(False)
    ax.axis('off')
    ax.axis('tight')
    #create table
    table = ax.table(cellText=df.values, colLabels=df.columns, loc='center')
    table.auto_set_font_size(False)
    table.set_fontsize(7)
    table.scale(1.25, 1.0)
    #display table
    plt.show()
    fig.savefig(df_path, dpi = 300)


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



if __name__ == '__main__':
    # output file path
    simulation_setup = "BAD_figs_3-5_1mM_Glucose_10_min_dt_0.025"
    simulation_output = "Data/" + simulation_setup + ".pkl"
    os.system("mkdir Plots/" + simulation_setup)
    alpha_plot_path = 'Plots/' + simulation_setup + '/alpha.png'
    beta_plot_path = 'Plots/' + simulation_setup + '/beta.png'
    delta_plot_path = 'Plots/' + simulation_setup + '/delta.png'
    df_path = 'Plots/' + simulation_setup + '/metrics.png' 
    # simulation time steps (.025ms each)
    simulation_time = 2000
    alpha_mechs = ['one']
    alpha = Alpha('cell', 0, 0, 0, alpha_mechs)
    print("Set up recording variables")
    record_or_write(alpha, write = False)
    h.load_file('stdrun.hoc')
    # cvode = h.CVode()
    # cvode.active(False)
    # cvode.atol(1.0E-10)
    # cvode.rtol(1.0E-10)
    # cvode.debug_event(1)
    #h.dt = 0.0250
    h.finitialize()
    # h.t = -1000
    #h.secondorder = 2
    for i in range(40 * simulation_time):
        h.fadvance()
        if i%40000 == 0:
            temp = (0.025 * i)/1000 
            print("Simulation time: " + str(temp) + " seconds")
    # print("Pickle simulation data")
    # record_or_write(alpha, write = True, outputPath = simulation_output)
    print("Create plots and metrics table.")
    mV_C_horm(alpha.rec, 'one_va', "one_ca", 'one_G', alpha_plot_path)
    mV_C_horm(alpha.rec, 'one_vb', "one_c", 'one_I', beta_plot_path)
    mV_C_horm(alpha.rec, 'one_vd', "one_cd", 'one_S', delta_plot_path)
    BAD_model_metrics_table(alpha.rec, simulation_time, 0.025, df_path)
