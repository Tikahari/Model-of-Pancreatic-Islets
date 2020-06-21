import configparser
import ast
import random
import os
import sys
sys.path.append('../Model/')
import Islet

# islets per generation
pop = 10
# size of islets
islet = [9, 14]
# max number of generations
glimit = 100
# fitness cutoff (average increase for last 3 generations)
flimit = 100


# variables for islet
# cell sizes
sizes = {'A': 10, 'B': 10, 'D': 10}
# default probability of cell (60% chance of b-cell, 30% of a-cell, 10% of d-cell)
probabilities = [0.15, 0.75]

class GA:
    def __init__(self):
        # relevant info about all generations
        self.generations = [0]
        # relevant info about current generation
        self.curr = []
        self.parentGen()
    def parentGen(self):
        self.readInit()
        # create configuration files for parent generation
        for i in range(pop):
            s = self.writeInit('Isl_' + str(len(self.generations)) + '_' + str(i))
            islet = Islet.Islet(probabilities, sizes, s)
            self.curr.append(islet)
    def readInit(self):
        print('GeneticAlgorithm(self) Read initialization file: path', Islet.env['ini'] + '/Values/super.ini')
        config = configparser.ConfigParser()
        config = configparser.ConfigParser(allow_no_value= True)
        config.optionxform = str
        config.read(Islet.env['ini'] + '/Values/super.ini')
        self.vars  = {'Alpha': {}, 'Beta': {}, 'Delta': {}}
        for i in config:
            for j in config[i]:
                self.vars[i][j] = ast.literal_eval(config[i][j])
                # print('vars', vars)
    def writeInit(self, instance):
        # create folder to write config files to and update Islet env variable
        os.system('mkdir ../../Configuration/Values/' + instance)
        # randomly generate islet size
        s = random.randint(islet[0], islet[1])
        # write 's' configurations for each type of cell
        c = 0
        for i in ['Alpha', 'Beta', 'Delta']:
            c = 0
            for j in range(s):
                with open('../../Configuration/Values/' + instance + '/' + i[0].lower() + '_' + str(c) + '.ini', 'w') as ini:
                    ini.write('[' + i + ']\n')
                    for k in self.vars[i]:
                        if(type(self.vars[i][k]) is list):
                            val = random.random() * (self.vars[i][k][0] - self.vars[i][k][1]) + self.vars[i][k][0]
                        else:
                            val = self.vars[i][k]
                        print('GeneticAlgorithm.writeInit(self, instance) instance =', instance, 'Write initializtion file:', k + ' = ' + str(val), 'cell type', i, 'cell number', j)
                c += 1
        return s       
    def step(self):
        return             
GA()