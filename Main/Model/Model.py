"""The 'Model' object will be used to configure and run a simulation for one islet. Instances are intended to be run in parallel and update a database file upon completion"""
import sys
import os
import datetime
import Islet
from Helper import *

class Model: 
    def __init__(self, islet_id, islet_radius, num_cells, simulation_time, alpha, beta):
        """Initialize model instance"""
        print(str(datetime.datetime.now()) + '\tModel.init')
        # set environment variables
        Islet.env['id'] = islet_id
        #Islet.env['wd'] += 'Islet_' + Islet.env['id'] + '/'
        os.chdir(Islet.env['wd'])
        # create and run islet instance
        print(str(datetime.datetime.now()) + '\tModel.init Create islet', Islet.env['wd'])
        self.islet = Islet.Islet([float(alpha), float(beta)], None, int(islet_radius), int(num_cells), False, int(simulation_time))
        self.islet.run()
        # self.clean()
    # Function clean here in case files get too big, it clears out unnecesary files before finishing the simulation.
    def clean(self):
        """Compress and remove folders"""
        print(str(datetime.datetime.now()) + '\tModel.clean Compress folders: output folder', Islet.env['output'] + 'Islet_' + Islet.env['id'], 'run folder', Islet.env['wd'][:len(Islet.env['wd'])-1])
        output_islet_path = Islet.env['output'] + 'Islet_' + Islet.env['id']
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
    # python Model.py 500 1_0 5 0.15 0.75
    Model(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4], sys.argv[5], sys.argv[6])
