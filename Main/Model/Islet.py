"""The 'Islet' object will provide a high level interface that will allow the GA to perform the major steps in the simulation (set up islet, simulate, and write data)"""
import os
import csv
import datetime
import numpy as np
import Space
import neuron
from neuron import rxd

# path to initialization file, mechanisms, output, and generation identifier
path = "/blue/lamb/robert727/temp/Model-of-Pancreatic-Islets/"
# path = "/home/tk/Desktop/Model-of-Pancreatic-Islets/"
# path = "/home/tikaharikhanal/lamb_tikaharikhanal/Model-of-Pancreatic-Islets/"
env = {'config': path + "Configuration/", 'id': "", 'mech': path + "Mechanisms/", 'output': path + "Outputs/", 'wd': path + "Main/Run/" }
# 0 to glucose_changes[1] represents the interval over which glucose level is 1mM, glucose_changes[1] to glucose_changes[2] represents the interval over which the glucose level is 7mM, and glucose_changes[2] to simtime 11mM
glucose_changes = [999999999, 999999999]
 
class Islet:
    def __init__(self, probabilities, config, islet_radius, num_cells, compile=False, simulation_time=0):
        """Initialize islet instance"""
        # path to initialization file, mechanisms, output, and generation identifier
        self.env = env
        self.islet_radius = islet_radius
        self.num_cells = num_cells
        self.simulation_time = simulation_time
        neuron.h.load_file('stdrun.hoc')
        # when compile option is set, cell instances will be made
        if compile:
            print(str(datetime.datetime.now()) + '\tIslet.init Compile mod files: wd', self.env['wd'])
            self.space = Space.Space(probabilities, config, islet_radius, num_cells, compile)
            self.space.configSetup()
        else:
            dll = self.env['wd'] + '.r/'
            ret = neuron.load_mechanisms(dll)
            print(str(datetime.datetime.now()) + '\tIslet.init  Load mechanisms: path', dll, ret)
            print(str(datetime.datetime.now()) + '\tIslet.init Normal islet setup (no compile)')
            self.space = Space.Space(probabilities, config, islet_radius, num_cells)
    def run(self):
        """Simulate and write data for this islet"""
        print(str(datetime.datetime.now()) + '\tIslet.run Run islet instance')
        self.space.configSetup()
        self.space.rxd()
        print(str(datetime.datetime.now()) + '\tIslet.run Initialize neuron mechanisms: path', os.getcwd())
        neuron.h.finitialize()
        print(str(datetime.datetime.now()) + '\tIslet.run Run simulation')
        for i in range(40 * self.simulation_time):
            neuron.h.fadvance()
            # change glucose level according to: https://github.com/artielbm/artielbm.github.io/blob/master/Models/BAD/Figures3-5.ode
            if i in glucose_changes:
                self.space.setGlucose(glucose_changes, i)
            # output time every 500ms
            if i%(250) == 0:
                print(str(datetime.datetime.now()) + '\t' + str(i/40) + 'ms')
        print(str(datetime.datetime.now()) + '\tIslet.run Write data')
        self.space.writeDataPhysiology()
        # self.space.plot()
    def spatialConfig(self):
        """Create templates/spatial configuration and write result, but do not create cells"""
        print(str(datetime.datetime.now()) + '\tIslet.spatialConfig Enter robert setup')
        # change with robert setup
        self.space.robert_setup()
        self.space.writeDataOrientation()
if __name__ == '__main__':
    # test
    # python Islet.py
    # run id
    r_id = '0'
    # Islet id
    i_id = '1_0'
    # dimension of islets (will determine size of box that will enclose islet)
    islet_radius = 5
    # default probability of cell (60% chance of b-cell, 30% of a-cell, 10% of d-cell)
    probabilities = [0.15, 0.75]
    # set environment
    env['wd'] += 'Islet_' + r_id + '_' + i_id + '/'
    islet = Islet(probabilities, None, islet_radius, i_id)
    islet.run()
    # islet.clean()
