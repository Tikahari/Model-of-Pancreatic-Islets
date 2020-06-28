import datetime
import sys
import os
import Islet

if __name__ == '__main__':
    Islet.env['wd'] += 'Islet_' + sys.argv[1] + '/'
    # os.chdir(Islet.env['wd'])
    print(str(datetime.datetime.now()) + '\tCompile.py Compile mod files in: wd', Islet.env['wd'])
    islet = Islet.Islet([1 , 1], None, int(sys.argv[2]), sys.argv[1], True)
    for i in os.listdir(Islet.env['wd']):
        os.chdir(Islet.env['wd'] + i)
        os.system('nrnivmodl *mod > ' + Islet.env['wd'] + i + '/compile_' + sys.argv[1] + ' 2>&1')
        print(str(datetime.datetime.now()) + '\tCompile.py Compiled', Islet.env['wd'] + i)