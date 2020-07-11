"""This is the main program. All relevant initialization details can be set here (the path must be set in Islet.py, however)"""
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

path = "/blue/lamb/tikaharikhanal/Model-of-Pancreatic-Islets/"
# run number
run = 0
# number of unique spatial configurations
sc = 3
# islets per generation
pop = 6
# size of islets
size = 4
# max number of generations
glimit = 100
# fitness cutoff (average increase for last 3 generations)
flimit = 100
# path to experimental data
Islet.path = path
data = path + "Main/Run/data/fridlyand_VCell_vp.csv"
# loss function parameters
mean = -40
threshold = 20
slope = 1
# percent of breeded generation that will be selected based on score
nonrandom_selection = 40
breeding = 40
random_selection = 20
# mutation rate
mutation_rate = 0.05

# default probability of cell (60% chance of b-cell, 30% of a-cell, 10% of d-cell)
probabilities = [0.15, 0.75]

class GA:
    def __init__(self):
        """Initialize genetic algorithm"""
        # relevant info about all generations
        self.generations = {0: []}
        self.scores = []
        self.setDatabase()
        self.setOrientation()
        self.parentGen()
        self.run()
    def setDatabase(self):
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
        for i in range(glimit):
            self.c.execute("INSERT INTO SCORES(GENERATION) VALUES(" + str(i) + ")")
            conn.commit()
            self.c.execute("INSERT INTO COMPLETED(GENERATION) VALUES(" + str(i) + ")")
            conn.commit()
    def setOrientation(self):
        """Create template orientations which will determine the spatial configuration of each islet"""
        for i in range(sc):
            # create folder to write config files to and update Islet env variable
            os.system('mkdir -p ' + Islet.env['config'] + 'Values/Template_' + Islet.env['rid'] + '_' + str(i+1))
            Islet.env['gid'] = str(len(self.generations)) + '_' + str(i)
            print(str(datetime.datetime.now()) + '\tGeneticalgorithm.setTemplates Create islet: gid', Islet.env['gid'])
            # generate islet with random size
            islet = Islet.Islet(probabilities, None, size)
            islet.spatialConfig(i+1)         
    def parentGen(self):
        """Create initial generation"""
        print(str(datetime.datetime.now()) + '\tGeneticAlgorithm.parentGen Creating generation: generation', len(self.generations))
        # read and store mechanisms and their initial values that will be written to mod files
        self.readInit()
        for i in range(pop):
            instance = 'Islet_' + str(run) + '_' + str(len(self.generations)) + '_' + str(i)
            # create initialization and run folders for islet
            os.system('mkdir -p ' + Islet.env['config'] + 'Values/' + instance)
            os.system('mkdir -p ' + Islet.env['config'] + 'Mechanisms/' + instance)
            os.system('mkdir -p ' + Islet.env['wd'] + instance)
            # randomly choose one of templates
            r = random.randint(0, sc)
            os.system('touch ' + Islet.env['config'] + 'Values/'+instance+'/template_'+str(r+1))
            config = configparser.ConfigParser()
            config = configparser.ConfigParser(allow_no_value= True)
            config.optionxform = str
            config.read(Islet.env['config'] + 'Values/Template_' + Islet.env['rid'] + '_' + str(r) + '/config.txt')
            # only one synapse mechanism should be loaded
            syn = {'A': False, 'B': False, 'D': False}
            for j in config['Data']:
                file_v = Islet.env['config'] + 'Values/' + instance + '/' + j + '.ini'
                file_m = Islet.env['config'] + 'Mechanisms/' + instance + '/' + j + '.ini'
                folder_m = Islet.env['wd'] + instance + '/' + j + '/'
                os.system('touch  ' + file_v)
                os.system('mkdir -p ' + folder_m)
                # copy mod files (copy Syn mechanims for first a/b/d cell)
                if syn[j[0].upper()] == False:
                    os.system('rsync ' + Islet.env['mech'] + j[0].upper() + '*mod ' + folder_m)
                    print('COPY ', 'rsync ' + Islet.env['mech'] + j[0].upper() + '*mod ' + folder_m)
                    syn[j[0].upper()] = True
                else:
                    os.system('rsync ' + Islet.env['mech'] + j[0].upper() + '*mod ' + folder_m + ' --exclude *Syn*')
                    print('COPY ', 'rsync ' + Islet.env['mech'] + j[0].upper() + '*mod ' + folder_m + ' --exclude *Syn*')
                types = {'A': 'Alpha', 'B': 'Beta', 'D': 'Delta'}
                with open(file_v, 'w') as values, open(file_m, 'w') as mechanisms:
                    values.write('[' + types[j[0].upper()] + ']\n')
                    # iterate through all variables for cell type
                    for z in self.vars[types[j[0].upper()]]:
                        if(type(self.vars[types[j[0].upper()]][z]) is list):
                            val = random.random() * (self.vars[types[j[0].upper()]][z][1] - self.vars[types[j[0].upper()]][z][0]) + self.vars[types[j[0].upper()]][z][0]
                        else:
                            val = self.vars[types[j[0].upper()]][z]
                        values.write(z + ' = ' + str(val) + '\n')
                    values.write('position = ' + config['Data'][j])
                    # write mechanism initialization for this cell in islet
                    mech = ""
                    print(j)
                    num = str(j.split('_'))[1]
                    types = {'A': 'Alpha', 'B': 'Beta', 'D': 'Delta'}
                    write = False
                    for k in self.mechs:
                        # only write correct cell type
                        if types[j[0].upper()] in k:
                            write = True
                            types[j[0].upper()] = 'NA/past'
                        for i in types:
                            if types[i] in k:
                                write = False
                        if write:
                            if '=' in k:
                                temp = k.replace('=', str(j.split('_')[1]) + '=')
                                temp = temp.replace('"]', str(j.split('_')[1]) + '"]')
                                mech += temp
                            elif '[' not in k:
                                mech += k.rstrip() + str(j.split('_')[1]) + '\n'
                            else:
                                mech += k
                    mechanisms.write(mech)
    def readInit(self):
        """Read the 'super' initialization files which include all mechanisms and parameters of all cells of an islet"""
        config = configparser.ConfigParser()
        config.optionxform = str
        # get all variables
        config.read(Islet.env['config'] + '/Values/super.ini')
        self.vars  = {'Alpha': {}, 'Beta': {}, 'Delta': {}}
        for i in config:
            for j in config[i]:
                self.vars[i][j] = ast.literal_eval(config[i][j])
        # get all mechanisms
        self.mechs = ''
        with open(Islet.env['config'] + '/Mechanisms/super.ini') as f:
            self.mechs = f.readlines()
    def run(self):
        """Main loop"""
        print(str(datetime.datetime.now()) + '\tRunning')
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
            continue

    def dispatch(self):
        f = open('Model.sbatch', 'r+')
        f1 = open('Model_temp.sbatch', 'w')
        lines = f.readlines()
        # replace tokens accordingly
        tokens = {'$Generation': str(len(self.generations)), '$Run': str(run), '$Alpha_probability': str(probabilities[0]), '$Alpha_Beta_probability': str(probabilities[1]), '$Dimensions':str(size), '$Output': Islet.env['wd'] + 'GA_MOPI_' + str(run) + '_' + str(len(self.generations)) + '_%j.log', '$Data': data, '$Mean': str(mean), '$Threshold': str(threshold), '$Slope': str(slope)}
        for i in lines:
            l = i
            for j in tokens:
                l = l.replace(j, tokens[j])
            f1.write(l)
        f.close()
        f1.close()
        print(str(datetime.datetime.now()) + '\tGeneticAlgorithm.dispatch Dispatch array job: generation', len(self.generations))
        os.system('sbatch --array=0-' + str(pop-1) + ' Model_temp.sbatch')
        os.system('squeue -u tikaharikhanal')
        # os.system('rm model_temp.sbatch')
    def spinLock(self):
        """Check that all threads (model instances) have completed"""
        while True:
            self.c.execute('SELECT * FROM COMPLETED WHERE GENERATION = '+str(len(self.generations)))
            rows = self.c.fetchall()
            print(str(datetime.datetime.now()) + '\tGeneticAlgorithm.spinLock Check status of islet instances: status (1=completed)',  list(rows[0]), 'number completed', str(len([x for x in list(rows[0]) if x is not None])-1) + '/' +  str(len(list(rows[0]))-1), 'generation', str(len(self.generations)))
            if len([x for x in list(rows[0]) if x is not None]) == pop + 1:
                break
            # check status every 10 minutes
            time.sleep(600)
    def newGen(self):
        print(str(datetime.datetime.now()) + '\tGeneticAlgorithm.newGen')
        # get paths to all scores
        score_paths = []
        for i in os.listdir(Islet.env['output']):
            if os.path.isdir(Islet.env['output'] + i):
                for j in os.listdir(Islet.env['output'] + i):
                    if '.pl' in j:
                        score_paths.append(Islet.env['output'] + i + '/' + j)
        # get scores from paths
        scores = []
        for i in score_paths:
            print('open', i)
            [score, all] = pickle.load(open(i, 'rb'))
            scores.append([score, i])
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
        print(str(datetime.datetime.now()) + '\tGeneticAlgorithm.newGen split list of length', len(scores), 'at', split_list)
        split = [scores[i : j] for i, j in zip([0] + split_list, split_list + [None])] 
        print(str(datetime.datetime.now()) + '\tGeneticAlgorithm.newGen scores split into', split)
        # write configuration of unchanged islets and store current islet number ('curr')
        curr = self.writeConfigurationPass(split[0])
        # breed and write configuration of islets
        count = 0
        # dictionary of islets that have already been bread
        bred = {}
        while count < breeding_gen:
            # randomly select islets to be bread
            p1, p2 = self.getRandom(len(scores)-1)
            # only use each pair once
            if p1 in bred and bred[p1] == p2 or p2 in bred and bred[p2] == p1:
                print(str(datetime.datetime.now()) + '\tGeneticAlgorithm.newGen continue')
                continue
            bred[p1] = p2
            print(str(datetime.datetime.now()) + '\tGeneticAlgorithm.newGen random indices are', p1, p2, '\nbred', bred, '\nscores', scores, '\nlength of scores', len(scores))
            # breed
            self.writeConfigrationBreed(scores[p1], scores[p2], curr)
            count += 1
            curr += 1
        self.writeConfigurationRandom(curr, random_gen)
    def writeConfigurationPass(self, islets):
        print(str(datetime.datetime.now()) + '\tGeneticAlgorithm.writeConfiguration Write configuration of randomly selected islets that will be passed to the next generation')
        count = 0
        for i in islets:
            old = 'Islet_' + str(run) + '_' + str(len(self.generations)-1) + '_' + str(count)
            new = 'Islet_' + str(run) + '_' + str(len(self.generations)) + '_' + str(count)
            print(str(datetime.datetime.now()) + '\tGeneticAlgorithm.writeConfiguration configure for', i)
            # make configuration folders
            os.system('mkdir -p ' + Islet.env['config'] + 'Values/' + new)
            os.system('mkdir -p ' + Islet.env['config'] + 'Mechanisms/' + new)
            os.system('mkdir -p ' + Islet.env['wd'] + new)
            # copy mechanisms and values
            os.system('cp -r ' + Islet.env['config'] + 'Values/' + old + '/* ' + Islet.env['config'] + 'Values/' + new)
            os.system('cp -r ' + Islet.env['config'] + 'Mechanisms/' + old + '/* ' + Islet.env['config'] + 'Mechanisms/' + new)
            count += 1
            # prepare run folder
            # get appropriate orientation template
            template = -1
            for k in os.listdir(Islet.env['config'] + 'Values/' + old):
                if 'template' in k:
                    template = re.split('\.txt|_', k)[1]
            print(str(datetime.datetime.now()) + '\tGeneticAlgorithm.writeConfiguration template is', template, 'in', old)
            config = configparser.ConfigParser()
            config = configparser.ConfigParser(allow_no_value= True)
            config.optionxform = str
            config.read(Islet.env['config'] + 'Values/Template_' + Islet.env['rid'] + '_' + str(int(template)-1) + '/config.txt')
            # create folder for each cell and copy appropriate mod files there
            for j in config['Data']:
                folder_m = Islet.env['wd'] + new + '/' + j + '/'
                os.system('mkdir -p ' + folder_m)
                os.system('rsync ' + Islet.env['mech'] + '/' + j[0].upper() + '*mod ' + folder_m)
        return count
    def writeConfigrationBreed(self, p1, p2, curr):
        print(str(datetime.datetime.now()) + '\tGeneticAlgorithm.writeConfigurationBreed Breed and write configuration of islets that will be passed to the next generation', p1, p2)
        # get paths to configuration and run folders
        old_1 = re.split('.pl|\/', p1[1])[len(re.split('.pl|\/', p1[1]))-2]
        old_2 = re.split('.pl|\/', p2[1])[len(re.split('.pl|\/', p2[1]))-2]
        print(str(datetime.datetime.now()) + '\tGeneticAlgorithm.writeConfigurationBreed parent islet 1', old_1, 'parent islet 2', old_2)
        new = 'Islet_' + str(run) + '_' + str(len(self.generations)) + '_' + str(curr)
        print(str(datetime.datetime.now()) + '\tGeneticAlgorithm.writeConfigurationBreed new', new)
        # make configuration folders
        os.system('mkdir -p ' + Islet.env['config'] + 'Values/' + new)
        os.system('mkdir -p ' + Islet.env['config'] + 'Mechanisms/' + new)
        os.system('mkdir -p ' + Islet.env['wd'] + new)
        # copy mechanisms and values then modify values (determine which parent will pass on its template at random)
        rand = random.random()
        print(str(datetime.datetime.now()) + '\tGeneticAlgorithm.writeConfigurationBreed random number to determine which parent passes on template', rand)
        if rand > 0.5:
            os.system('cp -r ' + Islet.env['config'] + 'Mechanisms/' + old_1 + '/* ' + Islet.env['config'] + 'Mechanisms/' + new)
            os.system('cp -r ' + Islet.env['config'] + 'Values/' + old_1 + '/* ' + Islet.env['config'] + 'Values/' + new)
        else:
            os.system('cp -r ' + Islet.env['config'] + 'Mechanisms/' + old_2 + '/* ' + Islet.env['config'] + 'Mechanisms/' + new)
            os.system('cp -r ' + Islet.env['config'] + 'Values/' + old_2 + '/* ' + Islet.env['config'] + 'Values/' + new)
        for i in os.listdir(Islet.env['config'] + 'Values/' + new):
            if 'ini' in i:
                print(str(datetime.datetime.now()) + '\tGeneticAlgorithm.writeConfigurationBreed cell', i, 'islet', new)
                with open(Islet.env['config'] + 'Values/' + old_1 + '/' + i) as old_1_cell, open(Islet.env['config'] + 'Values/' + old_2 + '/' + i) as old_2_cell, open(Islet.env['config'] + 'Values/' + new + '/' + i, 'r+') as new_cell:
                    # read the 3 corresponding configuration files
                    config_1 = configparser.ConfigParser()
                    config_1.optionxform = str
                    config_1.read(Islet.env['config'] + 'Values/' + old_1 + '/' + i)
                    config_2 = configparser.ConfigParser()
                    config_2.optionxform = str
                    config_2.read(Islet.env['config'] + 'Values/' + old_2 + '/' + i)
                    config_new = configparser.ConfigParser()
                    config_new.optionxform = str
                    config_new.read(Islet.env['config'] + 'Values/' + new + '/' + i)
                    # iterate through values within the new files, updating them with a value from parent 1 or 2 at random
                    for cell_type in config_new:
                        for val in config_new[cell_type]:
                            # randomly select value to write from parents
                            rand = random.random()
                            if rand > 0.5:
                                config_new[cell_type][val] = config_1[cell_type][val]
                            else:
                                config_new[cell_type][val] = config_2[cell_type][val]
                    # with open(Islet.env['config'] + 'Values/' + new + '/' + i, 'w') as new_cell:
                    config_new.write(new_cell)
        # prepare run folder
        # get appropriate orientation template
        template = -1
        for k in os.listdir(Islet.env['config'] + 'Values/' + new):
            if 'template' in k:
                template = re.split('\.txt|_', k)[1]
        print(str(datetime.datetime.now()) + '\tGeneticAlgorithm.writeConfigurationBreed template is', template, 'in', new)
        config = configparser.ConfigParser()
        config = configparser.ConfigParser(allow_no_value= True)
        config.optionxform = str
        config.read(Islet.env['config'] + 'Values/Template_' + Islet.env['rid'] + '_' + str(int(template)-1) + '/config.txt')
        # create folder for each cell and copy appropriate mod files there
        for j in config['Data']:
            folder_m = Islet.env['wd'] + new + '/' + j + '/'
            os.system('mkdir -p ' + folder_m)
            os.system('rsync ' + Islet.env['mech'] + '/' + j[0].upper() + '*mod ' + folder_m)
    def writeConfigurationRandom(self, curr, random_gen):
        print(str(datetime.datetime.now()) + '\tGeneticAlgorithm.writeConfigurationRandom Write configuration of islets that will be passed to the next generation current islet', curr, 'number of randomly generated islets', random_gen)
        # same as parent generation but number islets according to current islet number ('curr')
        self.readInit()
        count = 0
        while count < random_gen:
            instance = 'Islet_' + str(run) + '_' + str(len(self.generations)) + '_' + str(curr)
            # create initialization and run folders for islet
            os.system('mkdir -p ' + Islet.env['config'] + 'Values/' + instance)
            os.system('mkdir -p ' + Islet.env['config'] + 'Mechanisms/' + instance)
            os.system('mkdir -p ' + Islet.env['wd'] + instance)
            # randomly choose one of templates
            r = random.randint(0, sc-1)
            os.system('touch ' + Islet.env['config'] + 'Values/'+instance+'/template_'+str(r+1))
            config = configparser.ConfigParser()
            config = configparser.ConfigParser(allow_no_value= True)
            config.optionxform = str
            print('template random config', r, 'path', Islet.env['config'] + 'Values/Template_' + Islet.env['rid'] + '_' + str(r) + '/config.txt')
            config.read(Islet.env['config'] + 'Values/Template_' + Islet.env['rid'] + '_' + str(r) + '/config.txt')
            # only one synapse mechanism should be loaded
            syn = {'A': False, 'B': False, 'D': False}
            for j in config['Data']:
                file_v = Islet.env['config'] + 'Values/' + instance + '/' + j + '.ini'
                file_m = Islet.env['config'] + 'Mechanisms/' + instance + '/' + j + '.ini'
                folder_m = Islet.env['wd'] + instance + '/' + j + '/'
                os.system('touch  ' + file_v)
                os.system('mkdir -p ' + folder_m)
                # copy mod files (copy Syn mechanims for first a/b/d cell)
                if syn[j[0].upper()] == False:
                    os.system('rsync ' + Islet.env['mech'] + j[0].upper() + '*mod ' + folder_m)
                    print('COPY ', 'rsync ' + Islet.env['mech'] + j[0].upper() + '*mod ' + folder_m)
                    syn[j[0].upper()] = True
                else:
                    os.system('rsync ' + Islet.env['mech'] + j[0].upper() + '*mod ' + folder_m + ' --exclude *Syn*')
                    print('COPY ', 'rsync ' + Islet.env['mech'] + j[0].upper() + '*mod ' + folder_m + ' --exclude *Syn*')
                types = {'A': 'Alpha', 'B': 'Beta', 'D': 'Delta'}
                with open(file_v, 'w') as values, open(file_m, 'w') as mechanisms:
                    values.write('[' + types[j[0].upper()] + ']\n')
                    # iterate through all variables for cell type
                    for z in self.vars[types[j[0].upper()]]:
                        if(type(self.vars[types[j[0].upper()]][z]) is list):
                            val = random.random() * (self.vars[types[j[0].upper()]][z][1] - self.vars[types[j[0].upper()]][z][0]) + self.vars[types[j[0].upper()]][z][0]
                        else:
                            val = self.vars[types[j[0].upper()]][z]
                        values.write(z + ' = ' + str(val) + '\n')
                    values.write('position = ' + config['Data'][j])
                    # write mechanism initialization for this cell in islet
                    mech = ""
                    print(j)
                    num = str(j.split('_'))[1]
                    types = {'A': 'Alpha', 'B': 'Beta', 'D': 'Delta'}
                    write = False
                    for k in self.mechs:
                        # only write correct cell type
                        if types[j[0].upper()] in k:
                            write = True
                            types[j[0].upper()] = 'NA/past'
                        for i in types:
                            if types[i] in k:
                                write = False
                        if write:
                            if '=' in k:
                                temp = k.replace('=', str(j.split('_')[1]) + '=')
                                temp = temp.replace('"]', str(j.split('_')[1]) + '"]')
                                mech += temp
                            elif '[' not in k:
                                mech += k.rstrip() + str(j.split('_')[1]) + '\n'
                            else:
                                mech += k
                    mechanisms.write(mech)
            curr += 1
            count += 1
    def mutate(self):
        print(str(datetime.datetime.now()) + '\tGeneticAlgorithm.mutate Mutate variables subject to change')
        types = {'A': 'Alpha', 'B': 'Beta', 'D': 'Delta'}
        for i in os.listdir(Islet.env['config'] + 'Values/'):
            if 'Islet_' + str(run) + '_' + str(len(self.generations)) in i:
                print('i in mutate is', i)
                for cell in os.listdir(Islet.env['config'] + 'Values/' + i):
                    if 'ini' in cell:
                        # print('cell is', cell)
                        config = configparser.ConfigParser()
                        config = configparser.ConfigParser(allow_no_value= True)
                        config.optionxform = str
                        config.read(Islet.env['config'] + 'Values/' + i + '/' + cell)
                        for cell_type in config:
                            for val in config[cell_type]:
                                if val in self.vars[cell_type] and type(self.vars[cell_type][val]) == list:
                                    # mutate with given frequency
                                    rand = random.random()
                                    print('is variable', val, cell, i)
                                    if rand < mutation_rate:
                                        config[cell_type][val] = str(random.random() * (self.vars[cell_type][val][1] - self.vars[cell_type][val][0]) + self.vars[cell_type][val][0])
                                        print('val is', config[cell_type][val])
                        config.write(open(Islet.env['config'] + 'Values/' + i + '/' + cell, 'r+'))
        return
    def getRandom(self, upper):
        x = random.randint(0, upper)
        y = random.randint(0, upper)
        if x == y:
            return self.getRandom(upper)
        return x, y
GA()
