"""This script writes a mod file according to the values in 'Alpha.ini'"""
import configparser
import sys

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
        
def writeMod(init, mod):
    config = configparser.ConfigParser()
    config.optionxform = str
    config.read(init)
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
                print(i)
                count += 1
                # if so, set line appropriately
                if(i.strip() in config['Beta']):
                    new += i.strip() + ' = ' + str(config['Beta'][i.strip()]) + '\n'
            continue
        # begin when 'INITIAL' keyword is reached
        if 'INITIAL' in line:
            init = True
        new += line
    filer.close()
    # filew = open(mod, 'w')
    # filew.write(new)
    # filew.close()

if __name__ == '__main__':
    # test
    writeMod('Beta.ini', sys.argv[1])
