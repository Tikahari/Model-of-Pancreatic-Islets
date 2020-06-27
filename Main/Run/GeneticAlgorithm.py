import configparser
import ast
import random
import os
import sys
import pickle
sys.path.append('../Model/')
import Islet
import datetime

# number of unique spatial configurations
sc = 3
# islets per generation
pop = 10
# size of islets
size = [3, 4]
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
        self.generations = {0: []}
        self.scores = []
        self.setTemplates()
        self.parentGen()
        self.run()
    def setTemplates(self):
        self.readInit()
        # create configuration files for every generation
        for i in range(sc):
            # create folder to write config files to and update Islet env variable
            Islet.env['gid'] = str(len(self.generations)) + '_' + str(i)
            print(str(datetime.datetime.now()) + '\tGeneticalgorithm.setTemplates(self) Create islet: gid', Islet.env['gid'])
            # generate islet with random size
            islet = Islet.Islet(probabilities, self.vars, random.randint(size[0], size[1]))
            islet.spatialConfig()
    # read and store mechanisms which will be added to neuron section
    def readInit(self):
        print(str(datetime.datetime.now()) + '\tGeneticAlgorithm.readInit(self) Read initialization file: path', Islet.env['ini'] + '/Values/super.ini')
        config = configparser.ConfigParser()
        config = configparser.ConfigParser(allow_no_value = True)
        config.optionxform = str
        config.read(Islet.env['ini'] + '/Values/super.ini')
        self.vars  = {'Alpha': {}, 'Beta': {}, 'Delta': {}}
        for i in config:
            for j in config[i]:
                self.vars[i][j] = ast.literal_eval(config[i][j])               
    def run(self):
        print(str(datetime.datetime.now()) + '\trunning')
        # run first generation
        self.dispatch()
        while True:
            continue
        # os.system('sbatch --array=0-'+pop+' model.sh')

        while True:
            continue
    def parentGen(self):
        print(str(datetime.datetime.now()) + '\tGeneticAlgorithm.createGen(self) Creating generation: generation', len(self.generations))
        # # first generation
        if len(self.generations) == 1:
            # fill out population
            for i in range(pop):
                instance = 'Islet_' + str(len(self.generations)) + '_' + str(i)
                os.system('mkdir ../../Configuration/Values/'+instance)
                # randomly choose one of templates
                r = random.randint(0,sc-1)
                os.system('touch ../../Configuration/Values'+instance+'/template_'+str(r))
                config = configparser.ConfigParser()
                config = configparser.ConfigParser(allow_no_value= True)
                config.optionxform = str
                config.read('../../Configuration/Values/Template_' + str(r) + '/config.txt')
                for j in config['Data']:
                    file = '../../Configuration/Values/' + instance + '/' + j + '.ini'
                    os.system('touch  ' + file)
                    # write configuration file
                    types = {'A': 'Alpha', 'B': 'Beta', 'D': 'Delta'}
                    with open(file, 'w') as ini:
                        ini.write('[' + types[j[0].upper()] + ']\n')
                        for z in self.vars[types[j[0].upper()]]:
                            if(type(self.vars[types[j[0].upper()]][z]) is list):
                                val = random.random() * (self.vars[types[j[0].upper()]][z][0] - self.vars[types[j[0].upper()]][z][1]) + self.vars[types[j[0].upper()]][z][0]
                            else:
                                val = self.vars[types[j[0].upper()]][z]
                            print(str(datetime.datetime.now()) + '\tGeneticAlgorithm.createGen(self) Write to configuration file: instance', Islet.env['gid'], 'Write initialization file:', z + ' = ' + str(val), 'cell type', types[j[0].upper()], 'file', file)
                            ini.write(z + ' = ' + str(val) + '\n')
                        ini.write('position = ' + config['Data'][j])
        return   
    def dispatch(self):
        f = open('model.sbatch', 'r+')
        new = ''
        lines = f.readlines()
        for line in lines:
            if 'Model.py' in line:
                new += 'python Model.py ' + str(len(self.generations)) + '_$SLURM_ARRAY_TASK_ID\n'
            elif 'echo' in line:
                new += "echo 'Run islet $SLURM_ARRAY_TASK_ID for generation " + str(len(self.generations))
            else:
                new += line
        f.seek(0)
        f.write(new)
        f.close()
        print(str(datetime.datetime.now()) + '\tGeneticAlgorithm.dispatch(self) Dispatch array job: generation', len(self.generations))
        os.system('sbatch --array=0-' + str(pop-1) + ' model.sbatch')
    def breed(self, path):
        f = pickle.load('')
        return
GA()

