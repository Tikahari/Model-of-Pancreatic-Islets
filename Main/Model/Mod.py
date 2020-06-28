"""Handles writing of initial block of mod file according to corresponding ini file (i.e. Beta.ini, Beta_KATP.mod)"""
import configparser
import sys
import datetime

def getTokens(line):
    key = ""
    val = ""
    tokens = {'{', "'", '\n', '}'}
    eq = False
    for i in line:
        if eq == True and i not in tokens:
            val += i
        elif eq == False and i not in tokens:
            key += i
        if i == '=':
            eq = True
            key = key[:-1]
    return {key: val}
        
def writeMod(ini, mod):
    types = ['Alpha', 'Beta', 'Delta']
    typ = ''
    for i in types:
        if i in str(mod):
            typ = i
    config = configparser.ConfigParser()
    config.optionxform = str
    config.read(ini)
    filer = open(mod, 'r')
    lines = filer.readlines()
    st = ''
    new = ''
    count = 0
    # stop when any of these keywords/characters are reached
    stop = {'ASSIGNED', 'BREAKPOINT', 'STATE', 'PARAMETER', 'DERIVATIVE', '}'}
    init = False
    for line in lines:
        for k in stop:
            if k in line:
                init = False
        if init == True:
            vars = getTokens(line)
            # check if variable to be initialized is set in the ini file
            for i in vars:
                # print(i)
                count += 1
                # if so, set line appropriately
                print(str(datetime.datetime.now()) + '\tMod.writeMod(ini, mod) ini =', ini, 'mod =', mod, 'variable to write is', i)
                if(i.strip() in config[typ]):
                    new += i.strip() + ' = ' + str(config[typ][i.strip()]) + '\n'
                else:
                    new += line
            continue
        # begin when 'INITIAL' keyword is reached
        if 'INITIAL' in line:
            init = True
        new += line
    filer.close()
    filew = open(mod, 'w')
    filew.write(new)
    filew.close()
if __name__ == '__main__':
    # test
    writeMod(sys.argv[1], sys.argv[2])
