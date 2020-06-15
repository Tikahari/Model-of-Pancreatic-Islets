"""The 'Islet' object will provide a high level interface that will allow the GA to perform the major steps in the simulation (set up islet, simulate, and write data)"""
import os
import csv
import Space
import neuron
import importlib
# path to initialization file, mechanisms, output, and generation identifier
env = {'ini': "/ufrc/lamb/tikaharikhanal/Model-of-Pancreatic-Islets/Configuration/", 'mech': "/ufrc/lamb/tikaharikhanal/Model-of-Pancreatic-Islets/Mechanisms/", 'output':"/ufrc/lamb/tikaharikhanal/Model-of-Pancreatic-Islets/Outputs/", 'gid': "test"}

class Islet:
    def __init__(self, probabilities, sizes, n):
        self.getLib()
        self.space = Space.Space(probabilities, sizes, n)
        self.space.RadialSetup()
    def getLib(self):
        os.system('rm -r x86_64/')
        os.system('module load intel/2019')
        os.system('module load openmpi')
        os.system('cp ' + env['mech'] + '*mod .; nrnivmodl *mod > compile 2>&1')
        # os.system('cp -r' + env['mech'] + '/x86_64/{.,}* x86_64; cp -r ' + env['mech'] + '/x86_64/.libs* x86_64')
        os.system('rm *mod')
        importlib.reload(neuron)
    def run(self):
        self.t = neuron.h.Vector().record(neuron.h._ref_t)
        neuron.h.finitialize()
        neuron.h.continuerun(5000)
    def writeData(self):
        # self.space.plot()
        self.space.writeDataOrientation()
        self.space.writeDataPhysiology()
    def clean(self):
        os.system('rm -r x86_64')
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
    islet.writeData()
    islet.clean()