"""The 'Model' class will be used to configure and run a simulation for one islet. Instances are intended to be run in parallel and update a database file upon completion"""
import pickle
import configparser
import ast
import sys
import os
import sqlite3
import datetime
import Islet

class Model:
    def __init__(self, gid, run, alpha, beta, n):
        """Initialize model instance"""
        print(str(datetime.datetime.now()) + '\tModel.init')
        self.gid = gid
        self.db = Islet.env['wd'] + 'run_' + run + '.db'
        # set environment variables
        Islet.env['rid'] = run
        Islet.env['wd'] += 'Islet_' + run + '_' + self.gid + '/'
        os.chdir(Islet.env['wd'])
        print('wd', Islet.env['wd'])
        self.islet = Islet.Islet([float(alpha), float(beta)], None, int(n), self.gid)
        self.islet.run()
        # self.score()
        self.updateDatabase()
        self.clean()
    def score(self):
        """Score model"""
        print(str(datetime.datetime.now()) + '\tModel.score Score instance')
        dump = open(Islet.env['wd'] + 'Islet_' + self.gid + '.pl', 'wb')
        pickle.dump([1,1,1], dump)
        return [1,1,1]
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
        print(str(datetime.datetime.now()) + '\tModel.clean Compress folders: output folder', Islet.env['output'] + 'Islet_' + Islet.env['rid'] + '_' + self.gid, 'run folder', Islet.env['wd'][:len(Islet.env['wd']-2)])
        # output folder
        os.system('tar -zcvf ' + Islet.env['output'] + 'Islet_' + Islet.env['rid'] + '_' + self.gid + '.tar.gz ' + Islet.env['output'] + 'Islet_' + Islet.env['rid'] + '_' + self.gid)
        # run folder
        os.system('tar -zcvf ' + Islet.env['wd'][:len(Islet.env['wd'])-2] + 'tar.gz ' + Islet.env['wd'])
        print(str(datetime.datetime.now()) + '\tModel.clean compressed folders')
        os.system('rm -r ' + Islet.env['output'] + 'Islet_' + Islet.env['rid'] + '_' + self.gid)
        os.system('ls ' + Islet.env['wd'] + '..')
        # os.system('rm -r ' + Islet.env['wd'])
if __name__ == '__main__':
    Model(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4], sys.argv[5])