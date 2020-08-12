"""The 'Cell' object will store information unique to each cell, the reference to corresponding NEURON segment, and the values of all relevant variables associated with that segment"""
import configparser
import ast
import random
import datetime
import os
import re
import Islet
import Mod

class Cell:
    def __init__(self, id, x, y, z, typ, setup=False, writeMod=False):
        """Initialize NEURON section with relevant mechanisms and parameters"""
        self.id = id
        self.type = typ
        [self.x, self.y, self.z] = [x, y, z]
        self.cell = Islet.neuron.h.Section(name = str(self.type) + str(self.id))
        self.compile = writeMod
        # for plotting
        self.diam = 1
        # add mechanisms + record on configSetup but not radialSetup
        if setup:
            self.setup()
    def setup(self):
        """Set mechanisms, parameters, and recording variables"""
        # variables to store data
        self.v = []
        self.rec = {}
        self.header = []
        self.mechs = []
        self.pointers = {}
        # get properties from ini
        self.readData()
        if not self.compile:
            print(str(datetime.datetime.now()) + '\tCells.setup Do not compile/Do run')
            self.addMechanisms()
            self.setPointers()
            self.record()
    def readData(self):
        """Read mechanisms and parameters for this cell from its configuration file"""
        ini_path = Islet.env['config'] + 'Values/Islet_' + Islet.env['rid'] + '_' + Islet.env['gid'] + '/' + self.type.lower() + '_' + str(self.id) + '.ini'
        config_path = Islet.env['config'] + '/Mechanisms/Islet_' + Islet.env['rid'] + '_' + Islet.env['gid'] + '/' + self.type.lower() + '_' + str(self.id) + '.ini'
        print(str(datetime.datetime.now()) + '\tCells.readData Reading from configuration: configuration file', config_path)
        # read mechanism configuration
        config = configparser.ConfigParser(allow_no_value= True)
        config.optionxform = str
        config.read(config_path)
        types = {'A':'Alpha', 'B': 'Beta', 'D':'Delta'}
        # print(str(datetime.datetime.now())+ '\tself type', self.type)
        for i in config[types[self.type]]:
            print(str(datetime.datetime.now()) + '\tCells.readData Writing "INITIAL" blocks of appropriate mod files for mechanisms: mechanism', i, 'cell type', self.type, types[self.type])
            self.mechs.append(i)
            if config[types[self.type]][i] is not None:
                self.pointers[i] = ast.literal_eval(config[types[self.type]][i])
            # only write mod files when those mod files will be compiled
            if self.compile:
                print(str(datetime.datetime.now()) + '\tCells.readData Write mod file: cell', self.cell)
                modname = re.split('1|2|3|4|5|6|7|8|9|0', i)[0]
                mod_path = Islet.env['wd'] + types[self.type] + '_' + modname + '.mod'
                Mod.writeMod(ini_path, mod_path)
    def addMechanisms(self):
        """Add mechanism to section"""
        for i in self.mechs:
            print(str(datetime.datetime.now()) + '\tCells.addMechanisms Adding mechanisms: cell type', self.type, 'mechanism', i, 'cwd', os.getcwd())
            self.cell.insert(self.type+'_'+i)
        self.cell.cm = 9990000
    def setPointers(self):
        """Set NEURON pointers"""
        for i in self.pointers:
            for j in self.pointers[i]:
                for k in self.cell:
                    temp = j.split('_')
                    point_to = self.type+"_"+i
                    point_from = "_ref_"+temp[0]+"_"+self.type+"_"+temp[2]
                    print(str(datetime.datetime.now()) + '\tCells.setPointers Setting pointers: point from', point_from, 'to', point_to, 'with pointer name', temp[0])
                    from_ = getattr(k, point_from)
                    to_ = getattr(k, point_to)
                    Islet.neuron.h.setpointer(from_, temp[0], to_)
    def record(self):
        """Set recording variables"""
        print(str(datetime.datetime.now()) + '\tCell.record(self) Add recording variables')
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
        self.t = Islet.neuron.h.Vector().record(Islet.neuron.h._ref_t)
    def __repr__(self):
        return '{}{}'.format(self.type, self.id)
if __name__ == '__main__':
    # test
    # python Cells.py
    # run id
    r_id = '0'
    # Islet id
    i_id = '1_0'
    # set environment
    Islet.env['wd'] += 'Islet_' + r_id + '_' + i_id + '/'
    Islet.env['rid'] = r_id
    Islet.env['gid'] = i_id
    dll = Islet.env['wd'] + '.r/'
    ret = Islet.neuron.load_mechanisms(dll)
    print(str(datetime.datetime.now()) + '\tCells.py Load mechanisms: path', dll, ret)
    cell = Cell(0, 1, 2, 3, 'B', True)