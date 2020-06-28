import pickle
import configparser
import ast
import sys
import os
import sqlite3
import datetime
import Islet

class Model:
    def __init__(self, id, run, alpha, beta, n):
        self.id = id
        self.db = Islet.env['wd'] + 'run_' + run + '.db'
        # initial values of variables in '.ini' have already been set so no need to pass config variable to islet
        Islet.env['wd'] += 'Islet_' + self.id + '/'
        os.chdir(Islet.env['wd'])
        print('wd', Islet.env['wd'])
        # self.islet = Islet.Islet([float(alpha), float(beta)], None, int(n), self.id)
        # self.islet.run()
        # self.score()
        self.updateDatabase()
    def score(self):
        print(str(datetime.datetime.now()) + '\tModel.score(self) Score instance')
        dump = open(Islet.env['wd'] + 'Islet_' + self.id + '.pl', 'wb')
        pickle.dump([1,1,1], dump)
        return [1,1,1]
    def updateDatabase(self):
        print(str(datetime.datetime.now()) + '\tModel.updateDatabase(self) Update database: islet', self.id)
        conn = sqlite3.connect(self.db)
        c = conn.cursor()
        generation = sys.argv[1].split('_')[0]
        islet = sys.argv[1].split('_')[1]
        c.execute('UPDATE COMPLETED SET ISLET_' + islet + ' = 1 WHERE GENERATION = ' + generation)
        conn.commit()
        c.close()
if __name__ == '__main__':
    Model(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4], sys.argv[5])