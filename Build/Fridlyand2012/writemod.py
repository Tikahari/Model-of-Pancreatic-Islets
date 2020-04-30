# write outline of mod file from configuration file from configuration.py
import configparser
import sys

# make writer a class so we can keep a set which will keep track of which variables have been added to the mod file so far
class Writer():
    def __init__(self, file, type, name):
        self.file = file
        self.type = type
        self.name = name
        # possible types of mechanisms
        self.types = ['SUFFIX', 'POINT_PROCESS']
        self.f = ''
        if self.type in self.types:
            self.f += "NEURON{\n"+ self.type + " " + self.name + "\n}"
        else:
            print('Error no such type exists\nUsage: python writemod.py <modfile> <type> <name>')
            sys.exit()
        # outline
        self.f += "\n\nPARAMETER{\n\n}\n\nASSIGNED{\n\n}\n\nSTATE{\n\n}\n\nINITIAL{\n}\n\nBREAKPOINT{\n\n}\n"
        # print(self.f)
        self.vars = set()
        self.tripls = []
        self.initialize_block = ""
    # write outline / format
    def format(self):
        file = open(self.file, 'w')
        # print(self.f)
        file.write(self.f)
        file.close()
    # write all range variables in the NEURON block with the appropriate heading
    def neuronvars(self):
        filer = open(self.file, 'r')
        lines = filer.readlines()
        st = ''
        new = ''
        for line in lines:
            if 'SUFFIX' in line:
                initial = True
                for i in self.tripls:
                    st += 'RANGE '
                    for j in range(len(i)):
                        st += i[j]
                        if j + 1 < len(i):
                            st += ', '
                    st += '\n'
                line += st
            new += line
        filer.close()
        filew = open(self.file, 'w')
        filew.write(new)
        filew.close()
    def parameters(self):
        filer = open(self.file, 'r')
        lines = filer.readlines()
        st = ''
        vars = list(self.vars)
        for i in vars:
            st += i + '\n'
        new = ''
        for line in lines:
            if 'PARAMETER' in line:
                line += st
            new += line
        filer.close()
        filew = open(self.file, 'w')
        filew.write(new)
        filew.close()
    def initialize(self):
        filer = open(self.file, 'r')
        lines = filer.readlines()
        st = ''
        new = ''
        for line in lines:
            if 'INITIAL' in line:
                line += self.initialize_block
            new += line
        filer.close()
        filew = open(self.file, 'w')
        filew.write(new)
        filew.close()
    def writeMod(self):
        # format mod file
        self.format()
        config = configparser.ConfigParser()
        config.read('fridlyand.ini')
        # keep track of where we are in the list self.tripls
        j = 0
        tripl = []
        # get tripls, vars, and initialization info from .ini file
        for i in config['Beta']:
            if i not in self.vars:
                self.vars.add(i)
                # through globals per row (arbitrary)
                tripl.append(i)
                self.initialize_block += i + " = " + config['Beta'][i] + '\n'
                if len(tripl) == 3:
                    self.tripls.append(tripl)
                    tripl = []
                    j += 1
        # printFile(self.file)
        self.neuronvars()
        self.initialize()
        self.parameters()
def printFile(file):
    f = open(file, 'r')
    for line in f:
        print(line)
    f.close()
if __name__ == '__main__':
    if len(sys.argv) != 4:
        print('Incorrect number of argumets\nUsage: python writemod.py <modfile> <type> <name>')
        sys.exit()
    writer = Writer(sys.argv[1], sys.argv[2], sys.argv[3])
    writer.writeMod()
