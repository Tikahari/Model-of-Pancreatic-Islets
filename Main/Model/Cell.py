"""The 'Cell' object will store information unique to each cell, the reference to corresponding NEURON segment, and the values of all relevant variables associated with that segment"""
import configparser
import ast
import random
import datetime
import Islet
import Mod

class Cell:
    def __init__(self, id, x, y, z, typ, setup=False):
        self.id = id
        self.type = typ
        [self.x, self.y, self.z] = [x, y, z]
        self.cell = Islet.neuron.h.Section(name = str(self.type) + str(self.id))
        self.diam = 1
        # add mechanisms + record on configSetup but not radialSetup
        if setup:
            self.setup()
    def setup(self):
        # variables to store data
        self.v = []
        self.rec = {}
        self.header = []
        self.mechs = []
        self.pointers = {}
        # get properties from ini
        self.readData()
        self.addMechanisms()
        self.setPointers()
        self.record()
    def readData(self):
        # set up mechanisms according to parameters for cell type
        # set initialization file
        if Islet.env['gid'] == "":
            ini = 'super.ini'
        else:
            ini = Islet.env['gid']+'.ini'
        # read mechanism configuration
        config = configparser.ConfigParser(allow_no_value= True)
        config.optionxform = str
        config.read(Islet.env['ini'] + '/Mechanisms/super.ini')
        types = {'A':'Alpha', 'B': 'Beta', 'D':'Delta'}
        # print(str(datetime.datetime.now())+ '\tself type', self.type)
        for i in config[types[self.type]]:
            print(str(datetime.datetime.now()) + '\tCells.readData(self) Writing "INITIAL" blocks of appropriate mod files for mechanisms: mechanism', i, 'cell type', self.type, types[self.type])
            self.mechs.append(i)
            if config[types[self.type]][i] is not None:
                self.pointers[i] = ast.literal_eval(config[types[self.type]][i])
            Mod.writeMod(Islet.env['ini'] + '/Values/Islet_' + Islet.env['gid'] + '/' + self.type.lower() + '_' + str(self.id) + '.ini', Islet.env['mech'] + types[self.type] + '_' + i + '.mod')
    def addMechanisms(self):
        for i in self.mechs:
            print(str(datetime.datetime.now()) + '\tCells.addMechanisms(self) Adding mechanisms: cell type', self.type, 'mechanism', i)
            self.cell.insert(self.type+'_'+i)
    def setPointers(self):
        for i in self.pointers:
            for j in self.pointers[i]:
                for k in self.cell:
                    temp = j.split('_')
                    point_to = self.type+"_"+i
                    point_from = "_ref_"+temp[0]+"_"+self.type+"_"+temp[2]
                    print(str(datetime.datetime.now()) + '\tCells.setPointers(self) Setting pointers: point from', point_from, 'to', point_to, 'with pointer name', temp[0])
                    from_ = getattr(k, point_from)
                    to_ = getattr(k, point_to)
                    Islet.neuron.h.setpointer(from_, temp[0], to_)
    def record(self):
        a = self.cell
        # print(str(datetime.datetime.now()) + '\tCell.record(self) Add recording variables: recording variables', a.psection())
        for i in self.cell.psection()['density_mechs']:
            for j in self.cell.psection()['density_mechs'][i]:
                self.header.append(i+'_'+j)
                self.rec[str(i+'_'+j)] = []
                # record variables of every mechanism in every segment
                for k in self.cell:
                    self.v.append(Islet.neuron.h.Vector().record(k._ref_v))
                    mechRecord = getattr(k, '_ref_'+j+'_'+i)
                    self.rec[str(i+'_'+j)].append(Islet.neuron.h.Vector().record(mechRecord))
        # fix header / record voltage of every segment
        count = 0
        for i in self.cell:
            temp = 'VC'+str(count)
            # ease writing to csv by keeping same format even though it is not necessary
            self.rec[temp] = []
            self.rec[temp].append(Islet.neuron.h.Vector().record(i._ref_v))
            count += 1
        self.header.append(temp)
        #only first cell will record time
        if self.id == 0:
            self.t = Islet.neuron.h.Vector().record(Islet.neuron.h._ref_t)
    def __repr__(self):
        return '{}{}'.format(self.type, self.id)
if __name__ == '__main__':
    # test
    cell = Cell(0, 1, 2, 3, 'A')
    
# self.diam = random.randint(matIslet.neuron.h.floor(sizes[self.typ]-sizes[self.typ]*random.random()/10), matIslet.neuron.h.ceil(sizes[self.typ]+sizes[self.typ]*random.random()*10))
