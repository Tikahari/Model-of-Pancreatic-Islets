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
    def __init__(self, id, x, y, z, typ, setup=False, writeMod=False, insulin=None, glucagon=None, sst=None):
        """Initialize NEURON section with relevant mechanisms and parameters"""
        self.id = id
        self.type = typ
        [self.x, self.y, self.z] = [x, y, z]
        self.cell = Islet.neuron.h.Section(name = str(self.type) + str(self.id))
        self.cell.pt3dadd(3,x,y,z)
        self.cell.pt3dadd(3,x+1,y+1,z+1)
        secretion_pointer = {'A': 'Gpnt', 'B': 'Inspnt', 'D': 'Sstpnt'}
        self.sp = secretion_pointer[self.type]
        self.compile = writeMod
        # for plotting
        if typ == "A":
            self.diam = 8
        elif typ == "D":
            self.diam = 8
        else:
            self.diam = 15.5
        self.insulin = insulin
        self.glucagon = glucagon
        self.sst = sst
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
        ini_path = Islet.env['config'] + 'Values/Islet_' + Islet.env['id'] + '/' + self.type.lower() + '_' + str(self.id) + '.ini'
        config_path = Islet.env['config'] + '/Mechanisms/Islet_' + Islet.env['id'] + '/' + self.type.lower() + '_' + str(self.id) + '.ini'
        print(str(datetime.datetime.now()) + '\tCells.readData Reading from configuration: configuration file', config_path)
        # read mechanism configuration
        config = configparser.ConfigParser(allow_no_value= True)
        config.optionxform = str
        config.read(config_path)
        types = {'A':'Alpha', 'B': 'Beta', 'D':'Delta'}
        print(str(datetime.datetime.now())+ '\tself type', self.type)
        for i in config[types[self.type]]:
            print(str(datetime.datetime.now()) + '\tCells.readData Writing "INITIAL" blocks of appropriate mod files for mechanisms: mechanism', i, 'cell type', self.type, types[self.type])
            if re.split('[0-9]',i)[0] not in ['Glucagon', 'Somatostatin', 'Insulin']: 
                self.mechs.append(i)
            # add pointers in config files to self.pointers
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
        # manually set point processes, reaction diffusion variables, and capacitances of each cell
        if self.type == 'A':
            glucagon = getattr(Islet.neuron.h, 'A_Glucagon' + self.id)
            self.pp = glucagon(self.cell(0.5))
            Islet.neuron.h.setpointer(self.glucagon.nodes[0]._ref_concentration, 'Gpnt', self.pp)
            #self.cell.cm = 0.000005 # Was 5 pF (watts) now is in microfarads
            self.cell.cm = 201.06176
        elif self.type == 'B':
            insulin = getattr(Islet.neuron.h, 'B_Insulin' + self.id)
            self.pp = insulin(self.cell(0.5))
            Islet.neuron.h.setpointer(self.insulin.nodes[0]._ref_concentration, 'Inspnt', self.pp)
            #self.cell.cm = 0.0053 # Was 5300 pF (watts) now is in microfarads
            self.cell.cm = 754.8
        else:
            somatostatin = getattr(Islet.neuron.h, 'D_Somatostatin' + self.id)
            self.pp = somatostatin(self.cell(0.5))
            Islet.neuron.h.setpointer(self.sst.nodes[0]._ref_concentration, 'Sstpnt', self.pp)
            #self.cell.cm = 0.000005 # Was 5 pF (watts) now is in microfarads
            self.cell.cm = 201.06176
        for i in self.mechs:
            print(str(datetime.datetime.now()) + '\tCells.addMechanisms Adding mechanisms: cell type', self.type, 'mechanism', i, 'cwd', os.getcwd())
            self.cell.insert(self.type+'_'+i)
    def setPointers(self):
        """Set NEURON pointers"""
        for i in self.pointers:
            for j in self.pointers[i]:
                for k in self.cell:
                    point_to = self.type+"_"+i
                    point_from = "_ref_"+j
                    print(str(datetime.datetime.now()) + '\tCells.setPointers Setting pointers: point from', point_from, 'to', point_to, 'with pointer name', j)
                    from_ = getattr(self.pp, point_from)
                    to_ = getattr(k, point_to)
                    Islet.neuron.h.setpointer(from_, j, to_)
        # delta cells have additional pointers
        if self.type == 'D':
            from_ = getattr(self.cell(0.5), '_ref_mcapqd_D_CaPQ' + self.id)
            Islet.neuron.h.setpointer(from_, 'mcapqd', self.pp)
            from_ = getattr(self.cell(0.5), '_ref_hcapqd_D_CaPQ' + self.id)
            Islet.neuron.h.setpointer(from_, 'hcapqd', self.pp)
    def record(self):
        """Set recording variables"""
        print(str(datetime.datetime.now()) + '\tCell.record(self) Add recording variables')
        for i in self.cell.psection()['density_mechs']:
            for j in self.cell.psection()['density_mechs'][i]:
                head = re.split("[0-9]", i)[0]
                self.header.append(head + '_' + j + '_' + self.id)
                self.rec[str(head + '_' + j + '_' + self.id)] = []
                # record variables of every mechanism in every segment
                for k in self.cell:
                    self.v.append(Islet.neuron.h.Vector().record(k._ref_v))
                    mechRecord = getattr(k, '_ref_'+j+'_'+i)
                    self.rec[str(head + '_' + j + '_' + self.id)].append(Islet.neuron.h.Vector().record(mechRecord))
        # fix header / record voltage of every segment
        count = 0
        for i in self.cell:
            # temp = self.type+'_Vm_'+self.id+str(count) 
            temp = self.type+'_Vm_'+self.id
            # ease writing to csv by keeping same format even though it is not necessary
            self.rec[temp] = []
            self.rec[temp].append(Islet.neuron.h.Vector().record(i._ref_v))
            count += 1
        self.header.append(temp)
        self.t = Islet.neuron.h.Vector().record(Islet.neuron.h._ref_t)
        # point processes
        exclude = ['loc', 'get_segment', 'Inspnt']
        _exclude = True
        pp_names = ['pp']
        pp = [self.pp]
        for i, n in zip(pp, pp_names):
            for j in vars(i):
                _exclude = True
                for ex in exclude:
                    if ex in j:
                        _exclude = False
                if(_exclude):
                    self.header.append(self.type + '_' + n + '_'+ j + '_' + self.id)
                    molecule = getattr(i, '_ref_' + j)
                    self.rec[str(self.type + '_' + n + '_'+ j + '_' + self.id)] = []
                    self.rec[str(self.type + '_' + n + '_'+ j + '_' + self.id)].append(Islet.neuron.h.Vector().record(molecule))
                    print(str(datetime.datetime.now()) + '\tCells.record Record point process ' + self.type + '_' + n + '_'+ j + '_' + self.id)
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
    Islet.env['id'] = i_id
    dll = Islet.env['wd'] + '.r/'
    ret = Islet.neuron.load_mechanisms(dll)
    print(str(datetime.datetime.now()) + '\tCells.py Load mechanisms: path', dll, ret)
    cell = Cell(0, 1, 2, 3, 'B', True)
