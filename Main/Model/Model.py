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
        Islet.env['wd'] += 'Islet_' + self.gid + '/'
        os.chdir(Islet.env['wd'])
        # create and run islet instance
        print(str(datetime.datetime.now()) + '\tModel.init Create islet', Islet.env['wd'])
        self.islet = Islet.Islet([float(alpha), float(beta)], None, int(n), self.gid)
        self.islet.run()
        # self.clean()
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
