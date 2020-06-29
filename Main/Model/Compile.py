import datetime
import sys
import os
import Islet

if __name__ == '__main__':
    # create temp folder for mods
    Islet.env['wd'] += 'Islet_' + sys.argv[2] + '_' + sys.argv[1] + '/'
    print(str(datetime.datetime.now()) + '\tCompile.py Compile mod files in: wd', Islet.env['wd'])
    islet = Islet.Islet([1 , 1], None, int(sys.argv[3]), sys.argv[1], True)
    for i in os.listdir(Islet.env['wd']):
        os.system('mkdir -p ' + Islet.env['wd'] + '.r/')
        os.chdir(Islet.env['wd'] + i)
        os.system('nrnivmodl *mod > ' + Islet.env['wd'] + i + '/compile_' + sys.argv[1] + ' 2>&1')
        os.system('cp ' + Islet.env['wd'] + i + '/*mod ' + Islet.env['wd'] + '.r/')
        print(str(datetime.datetime.now()) + '\tCompile.py Compiled', Islet.env['wd'] + i)
    os.chdir(Islet.env['wd'] + '.r/')
    os.system('nrnivmodl *mod > ' + Islet.env['wd'] + '.r/compile 2>&1')
    print(str(datetime.datetime.now()) + '\tCompile.py Compiled', Islet.env['wd'] + '.r')