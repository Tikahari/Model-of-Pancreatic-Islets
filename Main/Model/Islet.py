"""The 'Islet' object will provide a high level interface that will allow the GA to perform the major steps in the simulation (set up islet, simulate, and write data)"""
import os
import csv
import datetime
import Space
import neuron
import neuron.gui

# path to initialization file, mechanisms, output, and generation identifier
path = "/ufrc/lamb/tikaharikhanal/Model-of-Pancreatic-Islets/"
env = {'config': path + "Configuration/", 'gid': "1_0", 'mech': path + "Mechanisms/", 'output': path + "Outputs/", 'wd': path + "Main/Run/" }

class Islet:
    def __init__(self, probabilities, config, n, id=-1, compile=False):
        # path to initialization file, mechanisms, output, and generation identifier
        self.env = env
        self.id = id
        if compile:
            print(str(datetime.datetime.now()) + '\tIslet.init(self, probabilities, config, n) Compile mod files: wd', self.env['wd'])
            self.space = Space.Space(probabilities, config, n, compile)
            self.space.configSetup(self.id)
        else:
            print(str(datetime.datetime.now()) + '\tIslet.init(self, probabilities, config, n) Normal islet setup (no compile)')
            self.space = Space.Space(probabilities, config, n)
    def run(self):
        self.space.configSetup(self.id)
        self.t = neuron.h.Vector().record(neuron.h._ref_t)
        neuron.h.finitialize()
        print(str(datetime.datetime.now()) + '\tIslet.run(self) Run simulation')
        neuron.h.continuerun(5000)
        print(str(datetime.datetime.now()) + '\tIslet.run(self) Write data')
        self.space.writeDataPhysiology()
    def clean(self):
        os.system('rm -r x86_64')
    def spatialConfig(self):
        print(str(datetime.datetime.now()) + '\tIslet.spatialConfig(self, probabilities, config, n) Enter radial setup')
        self.space.radialSetup()
        self.space.writeDataOrientation()

if __name__ == '__main__':
    #test
    # cell sizes
    sizes = {'A': 10, 'B': 10, 'D': 10}
    # dimension of islets (will determine size of box that will enclose islet)
    n = 3
    # default probability of cell (60% chance of b-cell, 30% of a-cell, 10% of d-cell)
    probabilities = [0.15, 0.75]
    islet = Islet(probabilities, sizes, n)
    islet.run()
    islet.clean()