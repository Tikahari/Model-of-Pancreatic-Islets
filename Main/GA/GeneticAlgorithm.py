"""This is the main program. All relevant initialization details can be set here (however, the path must be set in Islet.py)"""
import configparser
import ast
import random
import os
import sys
import pickle
import time
import datetime
import sqlite3
import numpy as np
import re
import Islet
from Helper import *

# run number
run = 2
# number of unique spatial configurations
spatial_configurations = 3
# islets per generation
pop = 6
# size of islets
size = 4
# max number of generations
glimit = 100
# path to experimental data
data = Islet.path + 'Main/Run/data/fridlyand_VCell_vp.csv'
# loss function parameters
mean = 400
threshold = 20
slope = 1
# percent of breeded generation that will be selected based on score
nonrandom_selection = 40
breeding = 40
random_selection = 20
# mutation rate
mutation_rate = 0.05
# default probability of each cell type [P(A), P(A) + P(B)]
probabilities = [0.15, 0.75]
# spin lock interval (minutes)
spin_lock_interval = 10

class GA:
    def __init__(self):
        """Initialize genetic algorithm"""
        # hold scores for all islets of each generation
        self.generations = {0: []}
        self.setDatabase()
        self.setOrientation()
        self.parentGen()
        self.run()
    def setDatabase(self):
        """Create and initialize the tables that will be updated by model instances"""
        print(str(datetime.datetime.now()) + '\tGeneticAlgorithm.setDatabase Create and write to database')
        # run id will allow for multiple instances of the genetic algorithm to be run simultaneously (different configuration folders for the same islets of different runs)
        Islet.env['rid'] = str(run)
        conn = sqlite3.connect(Islet.env['wd'] + 'run_' + str(run) + '.db')
        self.c = conn.cursor() 
        # create tables for to keep track of scores and which instances have completed their simulation
        cols = ""
        for i in range(pop):
            cols += "ISLET_" + str(i) + " INTEGER"
            if i + 1 < pop:
                cols += ", "
        self.c.execute("CREATE TABLE SCORES (GENERATION INTEGER PRIMARY KEY," + cols + ")")
        self.c.execute("CREATE TABLE COMPLETED (GENERATION INTEGER PRIMARY KEY," + cols + ")")
        # add values for generation column
        for i in range(glimit):
            self.c.execute("INSERT INTO SCORES(GENERATION) VALUES(" + str(i) + ")")
            conn.commit()
            self.c.execute("INSERT INTO COMPLETED(GENERATION) VALUES(" + str(i) + ")")
            conn.commit()
    def setOrientation(self):
        """Create template orientations which will determine the spatial configuration of each islet"""
        print(str(datetime.datetime.now()) + '\tGeneticAlgorithm.setOrientation Create template orientations') 
        template_path = Islet.env['config'] + 'Values/Template_' + Islet.env['rid'] + '_'
        for i in range(spatial_configurations):
            # create folder to write config files to and update Islet env variable
            os.system('mkdir -p ' + template_path + str(i+1))
            Islet.env['gid'] = str(len(self.generations)) + '_' + str(i)
            # generate islet with random size
            islet = Islet.Islet(probabilities, None, size)
            islet.spatialConfig(i+1)
            print(str(datetime.datetime.now()) + '\tGeneticalgorithm.setTemplates Create islet: gid', Islet.env['gid'])
    def parentGen(self):
        """Create initial generation"""
        print(str(datetime.datetime.now()) + '\tGeneticAlgorithm.parentGen Creating generation: generation', len(self.generations))
        # read and store mechanisms and their initial values that will be written to mod files
        mechanisms_config_path = Islet.env['config'] + 'Mechanisms/'
        values_config_path = Islet.env['config'] + 'Values/'
        template_path = Islet.env['config'] + 'Values/Template_' + Islet.env['rid'] + '_'
        run_islet_path = Islet.env['wd']
        self.values, self.mechanisms = readInit(values_config_path + 'super.ini', mechanisms_config_path + 'super.ini')
        for islet in range(pop):
            instance = 'Islet_' + str(run) + '_' + str(len(self.generations)) + '_' + str(islet)
            # create initialization and run folders for this islet
            os.system('mkdir -p ' + mechanisms_config_path + instance)
            os.system('mkdir -p ' + values_config_path + instance)
            os.system('mkdir -p ' + run_islet_path + instance)
            # randomly choose one of the orientation templates
            rand = random.randint(1, spatial_configurations)
            os.system('touch ' + values_config_path + instance + '/template_' + str(rand))
            config_cells = configparser.ConfigParser()
            config_cells = configparser.ConfigParser(allow_no_value= True)
            config_cells.optionxform = str
            config_cells.read(template_path + str(rand) + '/config.txt')
            # iterate through cell types for this islet
            for cell in config_cells['Data']:
                file_values = values_config_path + instance + '/' + cell + '.ini'
                file_mechanisms = mechanisms_config_path + instance + '/' + cell + '.ini'
                folder_mods = run_islet_path + instance + '/' + cell + '/'
                # create initialization file and run folders for this cell
                os.system('touch  ' + file_values)
                os.system('touch ' + file_mechanisms)
                os.system('mkdir -p ' + folder_mods)
                # copy appropriate mod files into run folder
                os.system('rsync ' + Islet.env['mech'] + cell[0].upper() + '*mod ' + folder_mods)
                # write parameters and mechanisms
                writeValuesCell(file_values, self.values, cell, config_cells)
                writeMechanismsCell(file_mechanisms, self.mechanisms, cell)
    def run(self):
        """Main loop"""
        print(str(datetime.datetime.now()) + '\tEnter main loop')
        # run first generation
        self.dispatch()
        c = 1
        while c < glimit:
            # check if all models finished
            self.spinLock()
            # breed
            self.newGen()
            # mutate
            self.mutate()
            # dispatch
            self.dispatch()
            c += 1
    def dispatch(self):
        """Write and dispatch batch file that will run model instance"""
        template = open('Model.sbatch', 'r')
        dispatch = open('Model_temp.sbatch', 'w')
        lines = template.readlines()
        # replace tokens accordingly
        tokens = {'$Generation': str(len(self.generations)), '$Run': str(run), '$Alpha_probability': str(probabilities[0]), '$Alpha_Beta_probability': str(probabilities[1]), '$Dimensions':str(size), '$Output': Islet.env['wd'] + 'GA_MOPI_' + str(run) + '_' + str(len(self.generations)) + '_%j.log', '$Data': data, '$Mean': str(mean), '$Threshold': str(threshold), '$Slope': str(slope)}
        for old_line in lines:
            new_line = old_line
            for token in tokens:
                new_line = new_line.replace(token, tokens[token])
            dispatch.write(new_line)
        template.close()
        dispatch.close()
        print(str(datetime.datetime.now()) + '\tGeneticAlgorithm.dispatch Dispatch array job: generation', len(self.generations))
        os.system('sbatch --array=0-' + str(pop-1) + ' Model_temp.sbatch')
        os.system('squeue -u tikaharikhanal')
    def spinLock(self):
        """Check that all threads (model instances) have completed"""
        while True:
            self.c.execute('SELECT * FROM COMPLETED WHERE GENERATION = '+str(len(self.generations)))
            rows = self.c.fetchall()
            print(str(datetime.datetime.now()) + '\tGeneticAlgorithm.spinLock Check status of islet instances: status (1=completed)',  list(rows[0]), 'number completed', str(len([x for x in list(rows[0]) if x is not None])-1) + '/' +  str(len(list(rows[0]))-1), 'generation', str(len(self.generations)))
            if len([x for x in list(rows[0]) if x is not None]) == pop + 1:
                break
            # check status periodically (given interval)
            time.sleep(spin_lock_interval * 60)
    def newGen(self):
        """Create next generation"""
        print(str(datetime.datetime.now()) + '\tGeneticAlgorithm.newGen')
        # get all scores
        scores = []
        for generation_output in os.listdir(Islet.env['output']):
            if os.path.isdir(Islet.env['output'] + generation_output):
                for islet_score in os.listdir(Islet.env['output'] + generation_output):
                    if '.pl' in islet_score:
                        [score, all] = pickle.load(open(Islet.env['output'] + generation_output + '/' + islet_score, 'rb'))
                        scores.append([score, Islet.env['output'] + generation_output + '/' + islet_score])
        # sort scores in ascending order
        scores.sort()
        # update the scores for this generation and add 1 to 'generations' size
        self.generations[len(self.generations)-1].append(scores)
        self.generations[len(self.generations)] = []
        print(str(datetime.datetime.now()) + '\tGeneticAlgorithm.newGen all generation scores', self.generations, len(self.generations))
        # get number of nonrandom, breeding, and random islets in next generation
        nonrandom_gen = int(round(len(scores) * nonrandom_selection/100))
        breeding_gen = int(round(len(scores) * breeding/ 100))
        random_gen = len(scores) - breeding_gen - nonrandom_gen
        # split list such that islets at beginning of the list will pass on to next generation unchanged
        split_list = [nonrandom_gen]
        split = [scores[i : j] for i, j in zip([0] + split_list, split_list + [None])] 
        print(str(datetime.datetime.now()) + '\tGeneticAlgorithm.newGen scores split into', split)
        # write configuration of unchanged islets and store current islet number ('curr')
        paths = [Islet.env['config'] + 'Values/', Islet.env['config'] + 'Mechanisms/',  Islet.env['wd'], Islet.env['mech'], Islet.env['config'] + 'Values/Template_' + Islet.env['rid'] + '_']
        simulation_variables = [self.generations, self.values, self.mechanisms, run, spatial_configurations]
        curr = writeConfigurationDirect(split[0], paths, simulation_variables)
        # breed and write configuration of islets
        count = 0
        # dictionary of islets that have already been bred
        bred = {}
        while count < breeding_gen:
            # randomly select islets to be bread
            p1, p2 = getRandom(len(scores)-1)
            # only use each pair once
            if p1 in bred and bred[p1] == p2 or p2 in bred and bred[p2] == p1:
                print(str(datetime.datetime.now()) + '\tGeneticAlgorithm.newGen continue')
                continue
            bred[p1] = p2
            print(str(datetime.datetime.now()) + '\tGeneticAlgorithm.newGen random indices are', p1, p2, '\nbred', bred, '\nscores', scores, '\nlength of scores', len(scores))
            # breed
            writeConfigurationBreed(scores[p1], scores[p2], curr, paths, simulation_variables)
            count += 1
            curr += 1
        # write configuration of randomly generated islets
        writeConfigurationRandom(curr, random_gen, paths, simulation_variables)
    def mutate(self):
        """Mutate parameters of each islet according to a set mutation probability"""
        print(str(datetime.datetime.now()) + '\tGeneticAlgorithm.mutate Mutate variables subject to change')
        values_path = Islet.env['config'] + 'Values/'
        islet_generation = 'Islet_' + str(run) + '_' + str(len(self.generations))
        types = {'A': 'Alpha', 'B': 'Beta', 'D': 'Delta'}
        for islet in os.listdir(values_path):
            if islet_generation in islet:
                for cell in os.listdir(values_path + islet):
                    if 'ini' in cell:
                        config_cell = configparser.ConfigParser()
                        config_cell = configparser.ConfigParser(allow_no_value= True)
                        config_cell.optionxform = str
                        config_cell.read(values_path + '/' + islet + '/' + cell)
                        for cell_type in config_cell:
                            for val in config_cell[cell_type]:
                                if val in self.values[cell_type] and type(self.values[cell_type][val]) == list:
                                    # mutate with given frequency
                                    rand = random.random()
                                    if rand < mutation_rate:
                                        config_cell[cell_type][val] = str(random.random() * (self.values[cell_type][val][1] - self.values[cell_type][val][0]) + self.values[cell_type][val][0])
                                        print(str(datetime.datetime.now()) + '\tGeneticAlgorithm.mutate Mutate', config_cell[cell_type][val], cell, islet)
                        config_cell.write(open(values_path + '/' + islet + '/' + cell, 'r+'))

GA()
