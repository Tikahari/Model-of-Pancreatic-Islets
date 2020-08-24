"""This script will write to and compile mod files for each cell of the islet and prepare the appropriate folder for a simulation"""
import datetime
import sys
import os
import Islet

def Compile(islet_id, run_id, dimensions):
    """Compile and move all mod files for all cells such that an islet instance can be run from one library"""
    # create temp folder for mods
    Islet.env['wd'] += 'Islet_' + run_id + '_' + islet_id + '/'
    Islet.env['rid'] = run_id
    print(str(datetime.datetime.now()) + '\tCompile.py Compile mod files in: wd', Islet.env['wd'])
    # create islet instance with compile set to true
    islet = Islet.Islet([1 , 1], None, int(dimensions), islet_id, True)
    for cell in os.listdir(Islet.env['wd']):
        # create '.r' folder that will contain all mechanisms of an islet instance
        os.system('mkdir -p ' + Islet.env['wd'] + '.r/')
        # change directories so compiled library will exist in desired folder
        os.chdir(Islet.env['wd'] + cell)
        # compile mod files
        os.system('nrnivmodl *mod > ' + Islet.env['wd'] + cell + '/compile_' + islet_id + ' 2>&1')
        # copy mechanisms to '.r' folder
        os.system('cp ' + Islet.env['wd'] + cell + '/*mod ' + Islet.env['wd'] + '.r/')
        print(str(datetime.datetime.now()) + '\tCompile.py Compiled', Islet.env['wd'] + cell)
    # compile '.r' folder appropriately
    os.chdir(Islet.env['wd'] + '.r/')
    os.system('nrnivmodl *mod > ' + Islet.env['wd'] + '.r/compile 2>&1')
    print(str(datetime.datetime.now()) + '\tCompile.py Compiled', Islet.env['wd'] + '.r')
if __name__ == '__main__':
    # python Compile.py 1_0 0 4
    Compile(sys.argv[1], sys.argv[2], sys.argv[3])