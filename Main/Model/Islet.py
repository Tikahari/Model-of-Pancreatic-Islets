"""The 'Islet' object will provide a high level interface that will allow the GA to perform the major steps in the simulation (set up islet, simulate, and write data)"""
import os
import csv
import datetime
import Space
import neuron
import neuron.gui
import importlib
# path to initialization file, mechanisms, output, and generation identifier
env = {'ini': "/ufrc/lamb/tikaharikhanal/Model-of-Pancreatic-Islets/Configuration/", 'mech': "/ufrc/lamb/tikaharikhanal/Model-of-Pancreatic-Islets/Mechanisms/", 'output':"/ufrc/lamb/tikaharikhanal/Model-of-Pancreatic-Islets/Outputs/", 'gid': "1_0"}

class Islet:
    def __init__(self, probabilities, config, n, id=-1):
        self.id = id
        # path to initialization file, mechanisms, output, and generation identifier
        self.env = env
        self.setFolder()
        print(str(datetime.datetime.now()) + '\tIslet.init(self, probabilities, config, n) Set up spatial relationships in islet')
        self.space = Space.Space(probabilities, config, n)
    def setFolder(self):
        os.system('rm -r x86_64/')
        os.system('module load intel/2019')
        os.system('module load openmpi')
        os.system('cp ' + env['mech'] + '*mod .; nrnivmodl *mod > compile 2>&1')
        # os.system('cp -r' + env['mech'] + '/x86_64/{.,}* x86_64; cp -r ' + env['mech'] + '/x86_64/.libs* x86_64')
        os.system('rm *mod')
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
        self.space.RadialSetup()
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