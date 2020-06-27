from neuron import h
import pickle
import configparser
import ast
import sys
sys.path.append('../Model/')
import Islet

# cell sizes
sizes = {'A': 10, 'B': 10, 'D': 10}
# dimension of islets (will determine size of box that will enclose islet)
n = 7
# default probability of cell (60% chance of b-cell, 30% of a-cell, 10% of d-cell)
probabilities = [0.15, 0.75]

class Model:
    def __init__(self, id):
        self.id = id
        # initial values of variables in '.ini' have already been set so no need to pass config variable to islet
        self.islet = Islet.Islet(probabilities, None, n, self.id)
        self.islet.run()
        self.score()
    def score(self):
        dump = open('.temp/Islet_'+self.id+'.pl', 'wb')
        pickle.dump([1,1,1], dump)
        return [1,1,1]

if __name__ == '__main__':
    #test
    Model(sys.argv[1])