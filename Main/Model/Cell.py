"""The 'Cell' object will store information unique to each cell, the reference to corresponding NEURON segment, and the values of all relevant variables associated with that segment"""
from neuron import h, gui
import configparser
import ast
import random
import Islet
import Mod

class Cell:
    def __init__(self, id, x, y, z, typ):
        self.id = id
        self.type = typ
        [self.x, self.y, self.z] = [x, y, z]
        self.cell = h.Section(name = str(self.type) + str(self.id), cell = self)
        self.diam = 1
        # set properties
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
        # self.record()
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
        # print('self type', self.type)
        for i in config[types[self.type]]:
            # print('i in j is', i, 'in', self.type, types[self.type])
            self.mechs.append(i)
            if config[types[self.type]][i] is not None:
                self.pointers[i] = ast.literal_eval(config[types[self.type]][i])
            Mod.writeMod(Islet.env['ini'] + '/Values/' + ini, Islet.env['mech'] + types[self.type] + '_' + i + '.mod')
    def addMechanisms(self):
        for i in self.mechs:
            # print('type, i', self.type, i)
            self.cell.insert(self.type+'_'+i)
    def setPointers(self):
        for i in self.pointers:
            for j in self.pointers[i]:
                for k in self.cell:
                    temp = j.split('_')
                    point_to = self.type+"_"+i
                    point_from = "_ref_"+temp[0]+"_"+self.type+"_"+temp[2]
                    # print('point from', point_from, "point to", point_to)
                    from_ = getattr(k, point_from)
                    to_ = getattr(k, point_to)
                    h.setpointer(from_, temp[2], to_)
    def record(self):
        for i in self.cell.psection()['density_mechs']:
            for j in self.cell.psection()['density_mechs'][i]:
                self.header.append(i+'_'+j)
                self.rec[str(i+'_'+j)] = []
                # record variables of every mechanism in every segment
                for k in self.cell:
                    self.v.append(h.Vector().record(k._ref_v))
                    mechRecord = getattr(k, '_ref_'+j+'_'+i)
                    self.rec[str(i+'_'+j)].append(h.Vector().record(mechRecord))
        # fix header / record voltage of every segment
        count = 0
        for i in self.cell:
            temp = 'VC'+str(count)
            # ease writing to csv by keeping same format even though it is not necessary
            self.rec[temp] = []
            self.rec[temp].append(h.Vector().record(i._ref_v))
            count += 1
        self.header.append(temp)
        if self.id == 0 and self.type == 'B':
            self.t = h.Vector().record(h._ref_t)
    def __repr__(self):
        return '{} cell: {}'.format(self.type, self.id)
if __name__ == '__main__':
    # test
    cell = Cell(0, 1, 2, 3, 'A')
    
# self.diam = random.randint(math.floor(sizes[self.typ]-sizes[self.typ]*random.random()/10), math.ceil(sizes[self.typ]+sizes[self.typ]*random.random()*10))
