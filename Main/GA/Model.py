"""The 'Model' object will be used to configure and run a simulation for one islet. Instances are intended to be run in parallel and update a database file upon completion"""
import pickle
import configparser
import ast
import sys
import os
import sqlite3
import datetime
import numpy as np
import re
from matplotlib import pyplot as plt
import Loss
import Islet
from Helper import *

# headers for data
reference = ['t', 'Vp']
simulated = ['Time', 'VC0']

class Model:
    def __init__(self, gid, run, alpha, beta, n, data, mean, threshold, slope):
        """Initialize model instance"""
        print(str(datetime.datetime.now()) + '\tModel.init')
        # set object variables
        self.gid = gid
        self.data = data
        self.mean = mean
        self.slope = slope
        self.threshold = threshold
        self.db = Islet.env['wd'] + 'run_' + run + '.db'
        # set environment variables
        Islet.env['rid'] = run
        Islet.env['gid'] = gid
        Islet.env['wd'] += 'Islet_' + run + '_' + self.gid + '/'
        os.chdir(Islet.env['wd'])
        # create and run islet instance
        print(str(datetime.datetime.now()) + '\tModel.init Create islet', Islet.env['wd'])
        self.islet = Islet.Islet([float(alpha), float(beta)], None, int(n), self.gid)
        self.islet.run()
        self.score()
        self.updateDatabase()
        self.clean()
    def score(self):
        """Score model"""
        print(str(datetime.datetime.now()) + '\tModel.score Score instance')
        scores = []
        # load reference data
        ref = np.genfromtxt(self.data, delimiter=',', names=True)
        # initialize loss function
        path = self.data.split('/')[:len(self.data.split('/'))-1]
        path = '/'.join(path) + '/Loss.png'
        loss = Loss.Loss(int(self.mean), int(self.slope), int(self.threshold), path)
        output_islet_path = Islet.env['output'] + 'Islet_' + Islet.env['rid'] + '_' + self.gid + '/'
        for output in os.listdir(output_islet_path ):
            if 'csv' in output:
                # load simulated data
                sim = np.genfromtxt(output_islet_path+ '/' + output, delimiter=',', names=True)
                print(str(datetime.datetime.now()) + '\tModel.score Length of reference and experimental data', len(ref[reference[1]]), len(sim[simulated[1]]))
                # normalize data to timescale with larger steps and shorter interval
                # determine smaller time step
                multiple = getMultiple(ref[reference[0]], sim[simulated[0]])
                sim_normalized = sim[simulated[1]][::int(multiple)]
                print(str(datetime.datetime.now()) + '\tModel.score Large time step / small time step', multiple, 'length of normalized smaller time step data', len(sim_normalized), len(ref[reference[0]]))
                # determine smaller sample size
                size_normalized = getSize(ref[reference[0]], sim_normalized)
                print(str(datetime.datetime.now()) + '\tModel.score Minimum sample size', len(ref[reference[1]]), len(sim_normalized), size_normalized)
                # cut off simulated and reference data at same place
                ref[reference[1]] = ref[reference[1]][:size_normalized]
                sim_normalized = sim_normalized[:size_normalized]
                print(str(datetime.datetime.now()) + '\tModel.score Lengths of reference and simulated data after normalization', len(ref[reference[1]]), len(sim_normalized))
                # subtract one array from the other
                output_data = []
                for val in range(len(ref[reference[1]])):
                    output_data.append(ref[reference[1]][val] - sim_normalized[val])
                save =  Islet.env['wd'] + re.split('\.csv', output)[0] + '.png'
                print(str(datetime.datetime.now()) + '\tModel.score Path to save difference plot', save)
                # plt.clf()
                # plt.title('Difference Between Reference and Simulated Data')
                # plt.xlabel('Time (ms)')
                # plt.ylabel('Membrane Potential (mV)')
                # plt.plot(output_data)
                # plt.savefig(save)
                scores.append(loss.getLoss(sum(output_data)))
                print(str(datetime.datetime.now()) + '\tModel.score Cell score', scores)
        print(str(datetime.datetime.now()) + '\tModel.score Islet score', sum(scores)/len(scores))
        # save data to appropriate file
        output_generation_path =  Islet.env['output'] + 'Islets_' + Islet.env['rid'] + '_' + self.gid.split('_')[0]
        output_generation_file = '/Islet_' + Islet.env['rid'] + '_' + self.gid + '.pl'
        os.system('mkdir -p ' + output_generation_path)
        dump = open(output_generation_path + output_generation_file, 'wb')
        pickle.dump([sum(scores)/len(scores), scores], dump)
    def updateDatabase(self):
        """Update database so that GA is aware that this process has concluded"""
        print(str(datetime.datetime.now()) + '\tModel.updateDatabase Update database: islet', self.gid)
        conn = sqlite3.connect(self.db)
        c = conn.cursor()
        generation = sys.argv[1].split('_')[0]
        islet = sys.argv[1].split('_')[1]
        c.execute('UPDATE COMPLETED SET ISLET_' + islet + ' = 1 WHERE GENERATION = ' + generation)
        conn.commit()
        c.close()
    def clean(self):
        """Compress and remove folders"""
        print(str(datetime.datetime.now()) + '\tModel.clean Compress folders: output folder', Islet.env['output'] + 'Islet_' + Islet.env['rid'] + '_' + self.gid, 'run folder', Islet.env['wd'][:len(Islet.env['wd'])-1])
        output_islet_path = Islet.env['output'] + 'Islet_' + Islet.env['rid'] + '_' + self.gid
        run_islet_path = Islet.env['wd'][:len(Islet.env['wd'])-1]
        # output folder
        os.system('tar -zcvf ' + output_islet_path + '.tar.gz ' + output_islet_path)
        # run folder
        os.system('tar -zcvf ' + run_islet_path + '.tar.gz ' + run_islet_path)
        print(str(datetime.datetime.now()) + '\tModel.clean Compressed folders')
        # reduce size of output and run folders
        os.system('rm -r ' + output_islet_path)
        os.system('rm -r ' + run_islet_path)
if __name__ == '__main__':
    # run from command line
    # python Model.py 1_0 0 0.15 0.75 4 /blue/lamb/tikaharikhanal/Model-of-Pancreatic-Islets/Main/Run/data/fridlyand_VCell_vp.csv -40 20 1
    Model(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4], sys.argv[5], sys.argv[6], sys.argv[7], sys.argv[8], sys.argv[9])
