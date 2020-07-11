"""The 'Model' class will be used to configure and run a simulation for one islet. Instances are intended to be run in parallel and update a database file upon completion"""
import pickle
import configparser
import ast
import sys
import os
import sqlite3
import datetime
import numpy as np
import re
import Loss
import Islet
import Loss
from matplotlib import pyplot as plt

class Model:
    def __init__(self, gid, run, alpha, beta, n, data, mean, threshold, slope):
        """Initialize model instance"""
        print(str(datetime.datetime.now()) + '\tModel.init')
        self.gid = gid
        self.db = Islet.env['wd'] + 'run_' + run + '.db'
        self.data = data
        self.mean = mean
        self.slope = slope
        self.threshold = threshold
        # set environment variables
        Islet.env['rid'] = run
        Islet.env['wd'] += 'Islet_' + run + '_' + self.gid + '/'
        os.chdir(Islet.env['wd'])
        print('wd', Islet.env['wd'])
        self.islet = Islet.Islet([float(alpha), float(beta)], None, int(n), self.gid)
        self.islet.run()
        self.score()
        self.updateDatabase()
        self.clean()
    def score(self):
        """Score model"""
        print(str(datetime.datetime.now()) + '\tModel.score Score instance')
        scores = [55]
        # load reference data
        ref = np.genfromtxt(self.data, delimiter=',', names=True)
        # initialize loss function
        path = self.data.split('/')[:len(self.data.split('/'))-1]
        path = '/'.join(path) + '/Loss.png'
        loss = Loss.Loss(int(self.mean), int(self.slope), int(self.threshold), path)
        # loss.plot()
        for i in os.listdir(Islet.env['output'] + 'Islet_' + Islet.env['rid'] + '_' + self.gid + '/' ):
            if 'csv' in i:
                # load simulated data
                sim = np.genfromtxt(Islet.env['output'] + 'Islet_' + Islet.env['rid'] + '_' + self.gid + '/' + i, delimiter=',', names=True)
                print(str(datetime.datetime.now()) + '\tModel.score length of reference and experimental data', len(ref), len(sim))
                # normalize data to timescale with larger steps and shorter interval
                # get smaller time step
                min_tstep = -1
                if ref['t'][1] - ref['t'][0] > sim['Time'][1] - sim['Time'][0]:
                    min_tstep = 0
                else:
                    min_tstep = 1
                print(str(datetime.datetime.now()) + '\tModel.score minimum time step', min_tstep, ref['t'][1] - ref['t'][0], sim['Time'][1] - sim['Time'][0])
                steps = [sim['Time'][1] - sim['Time'][0], ref['t'][1] - ref['t'][0]]
                multiple = round(steps[not min_tstep] / steps[min_tstep])
                print(str(datetime.datetime.now()) + '\tModel.score large time step / small time step', multiple)
                sim_normalized = sim['VC0'][::int(multiple)]
                print(str(datetime.datetime.now()) + '\tModel.score length of normalized smaller time step data', len(sim_normalized))
                # plt.clf()
                # get smaller size
                min_tsize = -1
                if len(ref['Vp']) > len(sim_normalized):
                    min_tsize = 0
                else:
                    min_tsize = 1
                print(str(datetime.datetime.now()) + '\tModel.score minimum time size', min_tsize, len(ref['Vp']), len(sim_normalized))
                # cut off simulated and reference data at same place
                ref['Vp'] = ref['Vp'][:[len(sim_normalized), len(ref['Vp'])][min_tsize]]
                sim_normalized = sim_normalized[:[len(sim_normalized), len(ref['Vp'])][min_tsize]]
                print(str(datetime.datetime.now()) + '\tModel.score lengths of reference and simulated data after normalization', len(ref['Vp']), len(sim_normalized))
                # subtract one array from the other
                output = []
                for j in range(len(ref['Vp'])):
                    output.append(ref['Vp'][j] - sim_normalized[j])
                save =  Islet.env['wd'] + re.split('\.csv', i)[0] + '.png'
                print(str(datetime.datetime.now()) + '\tModel.score path to save difference plot', save)
                # plt.title('Difference Between Reference and Simulated Data')
                # plt.xlabel('Time (ms)')
                # plt.ylabel('Membrane Potential (mV)')
                # plt.plot(output)
                # plt.savefig(save)
                scores.append(loss.getLoss(sum(output)))
                print(str(datetime.datetime.now()) + '\tModel.score cell score', scores)
        print(str(datetime.datetime.now()) + '\tModel.score islet score', sum(scores)/len(scores))
        os.system('mkdir -p ' + Islet.env['output'] + 'Islets_' + Islet.env['rid'] + '_' + self.gid.split('_')[0])
        dump = open(Islet.env['output'] + 'Islets_' + Islet.env['rid'] + '_' + self.gid.split('_')[0] + '/Islet_' + Islet.env['rid'] + '_' + self.gid + '.pl', 'wb')
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
        # output folder
        os.system('tar -zcvf ' + Islet.env['output'] + 'Islet_' + Islet.env['rid'] + '_' + self.gid + '.tar.gz ' + Islet.env['output'] + 'Islet_' + Islet.env['rid'] + '_' + self.gid)
        # run folder
        os.system('tar -zcvf ' + Islet.env['wd'][:len(Islet.env['wd'])-1] + 'tar.gz ' + Islet.env['wd'])
        print(str(datetime.datetime.now()) + '\tModel.clean compressed folders')
        os.system('rm -r ' + Islet.env['output'] + 'Islet_' + Islet.env['rid'] + '_' + self.gid)
        os.system('ls ' + Islet.env['wd'] + '..')
        os.system('rm -r ' + Islet.env['wd'])
if __name__ == '__main__':
    Model(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4], sys.argv[5], sys.argv[6], sys.argv[7], sys.argv[8], sys.argv[9])
