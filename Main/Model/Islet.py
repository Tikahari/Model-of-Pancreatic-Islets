"""The 'Islet' object will provide a high level interface that will allow the GA to perform the major steps in the simulation (set up islet, simulate, and write data)"""
import os
import csv
import datetime
import numpy as np
import Space
import neuron
from neuron import rxd

# path to initialization file, mechanisms, output, and generation identifier
path = "/blue/lamb/tikaharikhanal/Model-of-Pancreatic-Islets/"
env = {'config': path + "Configuration/", 'gid': "1_0", 'mech': path + "Mechanisms/", 'output': path + "Outputs/", 'rid': "0", 'wd': path + "Main/Run/" }

class Islet:
    def __init__(self, probabilities, config, n, id=-1, compile=False):
        """Initialize islet instance"""
        # path to initialization file, mechanisms, output, and generation identifier
        self.env = env
        self.id = id
        self.n = n
        neuron.h.load_file('stdrun.hoc')
        print('wd is', self.env['wd'])
        # when compile option is set, cell instances will be made
        if compile:
            print(str(datetime.datetime.now()) + '\tIslet.init Compile mod files: wd', self.env['wd'])
            self.space = Space.Space(probabilities, config, n, compile)
            self.space.configSetup(self.id)
        else:
            dll = self.env['wd'] + '.r/'
            ret = neuron.load_mechanisms(dll)
            print(str(datetime.datetime.now()) + '\tIslet.init  Load mechanisms: path', dll, ret)
            print(str(datetime.datetime.now()) + '\tIslet.init Normal islet setup (no compile)')
            self.space = Space.Space(probabilities, config, n)
    def run(self):
        """Simulate and write data for this islet"""
        print(str(datetime.datetime.now()) + '\tIslet.run Run islet instance')
        self.space.configSetup(self.id)
        self.space.rxd()
        print(str(datetime.datetime.now()) + '\tIslet.run Initialize neuron mechanisms: path', os.getcwd())
        neuron.h.finitialize()
        print(str(datetime.datetime.now()) + '\tIslet.run Write header')
        print(str(datetime.datetime.now()) + '\tIslet.run Run simulation')
        for i in range(500):
            neuron.h.fadvance()
            self.space.writeDataPhysiology()
        print(str(datetime.datetime.now()) + '\tIslet.run Write data')
        self.space.writeDataPhysiology()
        # self.space.plot()
    def spatialConfig(self, temp):
        """Create templates/spatial configuration and write result, but do not create cells"""
        print(str(datetime.datetime.now()) + '\tIslet.spatialConfig Enter radial setup')
        self.space.radialSetup()
        self.space.writeDataOrientation(temp)
if __name__ == '__main__':
    # test
    # python Islet.py
    # run id
    r_id = '0'
    # Islet id
    i_id = '1_0'
    # dimension of islets (will determine size of box that will enclose islet)
    n = 5
    # default probability of cell (60% chance of b-cell, 30% of a-cell, 10% of d-cell)
    probabilities = [0.15, 0.75]
    # set environment
    env['wd'] += 'Islet_' + r_id + '_' + i_id + '/'
    islet = Islet(probabilities, None, n, i_id)
    islet.run()
    # islet.clean()