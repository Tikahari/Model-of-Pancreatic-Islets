import configparser
import ast
import random
import os
import sys
import pickle
import datetime
import sqlite3
import Islet

# run number
r = 0
# number of unique spatial configurations
sc = 3
# islets per generation
pop = 5
# size of islets
size = 2
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
        self.setDatabase()
        self.setOrientation()
        self.run()
    def setDatabase(self):
        conn = sqlite3.connect(Islet.env['wd'] + 'run_' + str(r) + '.db')
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
        # create template orientations
        for i in range(sc):
            # create folder to write config files to and update Islet env variable
            Islet.env['gid'] = str(len(self.generations)) + '_' + str(i)
            print(str(datetime.datetime.now()) + '\tGeneticalgorithm.setTemplates(self) Create islet: gid', Islet.env['gid'])
            # generate islet with random size
            islet = Islet.Islet(probabilities, None, size)
            islet.spatialConfig()         
    # configure parent generation (mod and initialization files)
    def createGen(self):
        print(str(datetime.datetime.now()) + '\tGeneticAlgorithm.createGen(self) Creating generation: generation', len(self.generations))
        # read and store mechanisms and their initial values that will be written to mod files
        self.readInit()
        for i in range(pop):
            instance = 'Islet_' + str(len(self.generations)) + '_' + str(i)
            # create initialization and run folders for islet
            os.system('mkdir -p ' + Islet.env['config'] + 'Values/' + instance)
            os.system('mkdir -p ' + Islet.env['config'] + 'Mechanisms/' + instance)
            os.system('mkdir -p ' + Islet.env['wd'] + instance)
            # randomly choose one of templates
            r = random.randint(0,sc-1)
            os.system('touch ' + Islet.env['config'] + 'Values/'+instance+'/template_'+str(r+1))
            config = configparser.ConfigParser()
            config = configparser.ConfigParser(allow_no_value= True)
            config.optionxform = str
            config.read(Islet.env['config'] + 'Values/Template_' + str(r) + '/config.txt')
            # only one synapse mechanism should be loaded
            syn = {'A': False, 'B': False, 'D': False}
            for j in config['Data']:
                file_v = Islet.env['config'] + 'Values/' + instance + '/' + j + '.ini'
                file_m = Islet.env['config'] + 'Mechanisms/' + instance + '/' + j + '.ini'
                folder_m = Islet.env['wd'] + instance + '/' + j + '/'
                # create configuration file and mechanism folder for cell
                os.system('touch  ' + file_v)
                os.system('touch ' + file_m)
                os.system('mkdir -p ' + folder_m)
                # copy mod files (copy Syn mechanims for first a/b/d cell)
                if syn[j[0].upper()] == False:
                    os.system('rsync ' + Islet.env['mech'] + '/' + j[0].upper() + '*mod ' + folder_m)
                    print('COPY ', 'rsync ' + Islet.env['mech'] + '/' + j[0].upper() + '*mod ' + folder_m)
                    syn[j[0].upper()] = True
                else:
                    os.system('rsync ' + Islet.env['mech'] + '/' + j[0].upper() + '*mod ' + folder_m + ' --exclude *Syn*')
                    print('COPY ', 'rsync ' + Islet.env['mech'] + '/' + j[0].upper() + '*mod ' + folder_m + ' --exclude *Syn*')
                # write configuration file (mechanisms and the value of their variables)
                types = {'A': 'Alpha', 'B': 'Beta', 'D': 'Delta'}
                with open(file_v, 'w') as values, open(file_m, 'w') as mechanisms:
                    values.write('[' + types[j[0].upper()] + ']\n')
                    # iterate through all variables for cell type
                    for z in self.vars[types[j[0].upper()]]:
                        if(type(self.vars[types[j[0].upper()]][z]) is list):
                            val = random.random() * (self.vars[types[j[0].upper()]][z][1] - self.vars[types[j[0].upper()]][z][0]) + self.vars[types[j[0].upper()]][z][0]
                        else:
                            val = self.vars[types[j[0].upper()]][z]
                        print(str(datetime.datetime.now()) + '\tGeneticAlgorithm.createGen(self) Write to configuration file: instance', Islet.env['gid'], 'Write initialization file:', z + ' = ' + str(val), 'cell type', types[j[0].upper()], 'file_v', file_v, 'file_m', file_m)
                        values.write(z + ' = ' + str(val) + '\n')
                    values.write('position = ' + config['Data'][j])
                    # iterate through mechanisms and add cell id where appropriate
                    mech = ""
                    print(j)
                    num = str(j.split('_'))[1] 
                    for k in self.mechs:
                        if '=' in k:
                            mech += k.replace('=', str(j.split('_')[1] + '='))
                        elif '[' not in k:
                            mech += k.rstrip() + str(j.split('_')[1]) + '\n'
                        else:
                            mech += k
                    mechanisms.write(mech)
    def readInit(self):
        print(str(datetime.datetime.now()) + '\tGeneticAlgorithm.readInit(self) Read initialization file: path', Islet.env['config'] + '/Values/super.ini')
        config = configparser.ConfigParser()
        config = configparser.ConfigParser(allow_no_value = True)
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
        print(str(datetime.datetime.now()) + '\tRunning')
        # run first generation
        self.createGen()
        # self.dispatch()
        c = 1
        while c < glimit:
            # check if all models finished
            self.spinLock()
            # breed
            # mutate
            # dispatch
            self.generations[c] = []
            # self.dispatch()
            c += 1
            continue
        # os.system('sbatch --array=0-'+pop+' model.sh')
    def dispatch(self):
        # set up model.sbatch script
        f = open('Model.sbatch', 'r+')
        f1 = open('Model_temp.sbatch', 'w')
        lines = f.readlines()
        for i in lines:
            j = i.replace('ZZ', Islet.env['gid'].split('_')[1])
            j = j.replace('ZY', str(len(self.generations)))
            j = j.replace('ZX', str(r))
            j = j.replace('ZW', str(probabilities[0]))
            j = j.replace('ZV', str(probabilities[1]))
            j = j.replace('ZU', str(max(size)))
            j = j.replace('YZ', Islet.env['wd'] + 'Islet_' + str(len(self.generations)))
            f1.write(j)
        f.close()
        f1.close()
        print(str(datetime.datetime.now()) + '\tGeneticAlgorithm.dispatch(self) Dispatch array job: generation', len(self.generations))
        os.system('sbatch --array=0-' + str(pop-1) + ' model_temp.sbatch')
        # os.system('rm model_temp.sbatch')
    def spinLock(self):
        fin = False
        while True:
            self.c.execute('SELECT * FROM COMPLETED WHERE GENERATION = '+str(len(self.generations)))
            rows = self.c.fetchall()
            print(str(datetime.datetime.now()) + '\tQuery',  'SELECT * FROM COMPLETED WHERE GENERATION = '+str(len(self.generations)), 'Result', list(rows), 'Length', len([x for x in list(rows[0]) if x is not None]))
            print(str(datetime.datetime.now()) + '\tGeneticAlgorithm.spinLock(self) Check if all models done running: done', fin)
            if len([x for x in list(rows[0]) if x is not None]) == pop + 1:
                break
    def breed(self, path):
        f = pickle.load('')
        return
GA()

