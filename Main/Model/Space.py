"""The 'Space' object is used to determine the probability and spatial distribution of cells. A probability object is introduced to handle non-uniform distributions."""
import numpy as np
from matplotlib import pyplot as plt
from matplotlib import patches as mpatches
from mpl_toolkits.mplot3d import Axes3D
import configparser
import random
import math
import ast
import sys
import pickle
import csv
import Cell
import os
import re
import datetime
import Islet

center_prob = 1

# wrapper class to store probability a point is alpha/beta/delta
class Probability:
    def __init__(self, a, a_plus_b, radius):
        """Initialize probability for point"""
        # set object variables
        self.b = a_plus_b - a
        # ratio of delta to alpha cells
        d = 1 - a_plus_b
        self.ratio = d / a
        self.radius = radius
    def getProbability(self):
        """Get probability at point"""
        # uniform distribution
        return [(1-self.b)/(1+self.ratio), self.b + (1-self.b)/(1+self.ratio)]

class Space:
    def __init__(self, cell_probabilities, config, islet_radius, num_cells, compile=False):
        """Initialize Space instance"""
        # set object variables
        self.cell_probabilities = cell_probabilities
        self.config = config
        self.islet_radius = islet_radius
        self.num_cells = num_cells
        self.compile = compile
        self.cells = [[[None for i in range(self.islet_radius)] for j in range(self.islet_radius)] for k in range(self.islet_radius)]
        self.cells_and_locations = []	
    def robert_setup(self):
        """Set cells, probabilities and plotting variables"""
        # Hard coding these for now. 
        # nx. ny, nz decides how many possible location points we want in each dimension
        prob_beta = self.cell_probabilities[1]
        prob_alpha = self.cell_probabilities[0]
        nx, ny, nz = (50,50,50)
        # The below statements take a line from -radius to radius and chops it up into n segments
        x_coords = np.linspace(-self.islet_radius, self.islet_radius, nx)
        y_coords = np.linspace(-self.islet_radius, self.islet_radius, ny)
        z_coords = np.linspace(-self.islet_radius, self.islet_radius, nz)
        num_betas = math.floor(self.num_cells * prob_beta)
        num_alphas = math.ceil(self.num_cells * prob_alpha)
        num_deltas = self.num_cells - num_betas - num_alphas
        betas = ["B"] * num_betas
        alphas = ["A"] * num_alphas
        deltas = ["D"] * num_deltas
        cells = betas + alphas + deltas
        locations = []
        cells_and_locations = []
        count = 0
        while count < self.num_cells:
            # Select a random value for x, y, and z coordinates
            x,y,z = np.random.choice(x_coords, 1), np.random.choice(y_coords, 1), np.random.choice(z_coords, 1)
            # Check if the point is within the islet sphere
            if math.sqrt(x**2 + y**2 + z**2) < self.islet_radius:
                # Check if random coordinates chosen are unique so not two cells have the same location
                if any(location == [x[0],y[0],z[0]] for location in locations): 
                    continue
                else:
                    # If location unique, append it to the locations list
                    locations.append((x[0],y[0],z[0]))
                    # If location unique, append it along with its' cell type to cells_and_locations list
                    cell_obj = Cell.Cell(count, x[0], y[0], z[0], cells[count]) 
                    cells_and_locations.append([count, x[0], y[0], z[0], cells[count], cell_obj])
                    count += 1
        self.cells_and_locations = cells_and_locations
        # for i in cells_and_locations:
        #     cell_obj = Cell.Cell(i[0], i[1], i[2], i[3], i[4])
        #     self.cells[i[1]][i[2]][i[3]] = cell_obj
    def radialSetup(self):
        """Set up the islet such that the distance of any cell from the center is one-half the radius"""
        [k, c] = [0, 0]
        for i in range(self.dimensions):
            for j in range(self.dimensions):
                while k < self.dimensions:
                    # only create cells if within some distance of the center
                    if(math.sqrt((self.dimensions/2-i)**2+(self.dimensions/2-j)**2+(self.dimensions/2-k)**2) > self.dimensions/2):
                        k += 1
                        continue
                    typ = self.getCell(random.random(), i, j, k)
                    # if position is vacant, add cell to space
                    # create cell
                    cell_obj = Cell.Cell(c, i, j, k, typ)
                    print(str(datetime.datetime.now()) + '\tSpace.RadialSetup Added cell to islet: id', cell_obj)
                    self.cells[i][j][k] = cell_obj
                    # store type and position
                    self.cell_positions.append([typ, i, j, k])
                    self.cell_sizes.append(cell_obj.diam)
                    c += 1
                    k += 1
                k = 0
                
    def configSetup(self):
        """Set up the islet from configuration file"""
        print(str(datetime.datetime.now()) + '\tSpace.configSetup Create islet instance: id', Islet.env['id'], 'wd', Islet.env['wd'])
        self.rxd()
        owd = Islet.env['wd']
        for cell in os.listdir(Islet.env['wd']):
            # print
            if os.path.isdir(Islet.env['wd'] + cell) and 'Islet_' in (Islet.env['wd'] + cell):
                values_cell_path = Islet.env['config'] + 'Values/Islet_' + Islet.env['id'] + '/' + cell + '.ini'
                print('path', values_cell_path)
                config = configparser.ConfigParser()
                config = configparser.ConfigParser(allow_no_value= True)
                config.optionxform = str
                config.read(values_cell_path)
                for cell_type in config:
                    # get cell number
                    cell_num = re.split('_|\.', cell)[1]
                    # every cell will have 'position' variable in configuration file
                    if 'position' in config[cell_type]:
                        pos = ast.literal_eval(config[cell_type]['position'])
                        Islet.env['wd'] = owd + cell.split('.')[0] + '/'
                        print(str(datetime.datetime.now()) + '\tSpace.configSetup Set up cell from configuration file: configuration file', cell, 'cell type', cell_type, 'id', cell_num, 'position', pos, 'wd', Islet.env['wd'])
                        cell_obj = Cell.Cell(cell_num, pos[0], pos[1], pos[2], cell_type[0].upper(), True, self.compile, self.insulin, self.glucagon, self.sst)
                        # cell_obj = Cell.Cell(cell_num, pos[0], pos[1], pos[2], cell_type[0].upper(), True)
                        self.cells_and_locations.append([cell_num, pos[0], pos[1], pos[2], cell_type[0].upper(), cell_obj])
                        # store type and position
                        #self.cell_positions.append([cell_type[0].upper(), pos[0], pos[1], pos[2]])
                        #self.cell_sizes.append(cell_obj.diam)
            Islet.env['wd'] = owd       
        # self.rxd()
    def rxd(self):
        print(str(datetime.datetime.now()) + '\tSpace.rxd Set up reaction diffusion')
        # the intracellular spaces
        cyt = Islet.neuron.rxd.Region(Islet.neuron.h.allsec(), name='cyt', nrn_region='i')

        # plasma membrane 
        mem = Islet.neuron.rxd.Region(Islet.neuron.h.allsec(), name='mem', geometry=Islet.neuron.rxd.membrane)

        # the extracellular space
        ecs = Islet.neuron.rxd.Extracellular(-20, -5, -5, 45, 5, 5, dx=1, volume_fraction=0.2, tortuosity=1.6)

        # glucagon
        glucagon = Islet.neuron.rxd.Species([cyt, ecs], name='glucagon', charge=0, d=1.0, initial=31)
        gcyt = glucagon[cyt]
        gecs = glucagon[ecs]
        self.glucagon = glucagon
        # somatostatin
        sst = Islet.neuron.rxd.Species([cyt, ecs], name='sst', charge=1, d=1.0, initial=19)
        sstcyt = sst[cyt]
        sstecs = sst[ecs]
        self.sst = sst

        # insulin
        insulin = Islet.neuron.rxd.Species([cyt, ecs], name='insulin', charge=0, d=1.0, initial=48)
        # insulin = Islet.neuron.rxd.Species([cyt, ecs], name='insulin', charge=0, d=1.0, initial=lambda n: 48 if hasattr(n, 'sec') and n.segment in 'B' else 0)
        inscyt = insulin[cyt]
        insecs = insulin[ecs]
        self.insulin = insulin

        # # production
        # gluc_param = Islet.neuron.rxd.Parameter(cyt, initial=1)
        # createX = Islet.neuron.rxd.Rate(gcyt, gluc_param[cyt] * 1.0/(10.0 + gcyt))


        # # uptake and release
        # R = 1e1     # release rate [molecules per square micron per ms]
        # U = 1e1     # uptake rate [molecules per square micron per ms]


        # rrateg = R*gcyt     
        # urateg = U*gecs     
        # glucagon_release = Islet.neuron.rxd.MultiCompartmentReaction(gcyt, gecs, rrateg, urateg,
        #                                                 membrane=mem, 
        #                                                 custom_dynamics=True)
        # # Islet.neuron.h.setpointer(glucagon.nodes[0]._ref_concentration, 'Gpnt', gluc_syn)

        # rratei = R*inscyt     
        # uratei = U*insecs     
        # insulin_release = Islet.neuron.rxd.MultiCompartmentReaction(inscyt, insecs, rratei, uratei,
        #                                                 membrane=mem, 
        #                                                 custom_dynamics=True)
        # # Islet.neuron.h.setpointer(insulin.nodes[0]._ref_concentration, 'Inspnt', ins_syn)


        # rrates = R*sstcyt    
        # urates = U*sstecs     
        # somatostatin_release = Islet.neuron.rxd.MultiCompartmentReaction(sstcyt, sstecs, rrates, urates,
        #                                                 membrane=mem, 
        #                                                 custom_dynamics=True)  
        # Islet.neuron.h.setpointer(sst.nodes[0]._ref_concentration, 'Sstpnt', sst_syn)  
    def setGlucose(self, glucose_changes, i):
        print(str(datetime.datetime.now()) + '\tSpace.setGlucose: time = ' + str(i) + 'ms')       
        # change glucose to 7mM
        if glucose_changes[0] == i:
            print(str(datetime.datetime.now()) + '\tGlucose set to 7mM')
            for i in range(self.dimensions):
                for j in range(self.dimensions):
                    for k in range(self.dimensions):
                        if self.cells[i][j][k] is not None and self.cells[i][j][k].type == 'A':
                            gkatpa = getattr(self.cells[i][j][k].cell, 'gkatpbara_A_KATP' + self.cells[i][j][k].id)
                            gkatpa = 0.6
                            ksercaa = getattr(self.cells[i][j][k].pp, 'ksercaa')
                            ksercaa = 0.5
                        elif self.cells[i][j][k] is not None and self.cells[i][j][k].type == 'B':
                            gkatpb = getattr(self.cells[i][j][k].pp, 'gkatpb')
                            gkatpb = 85         
                        elif self.cells[i][j][k] is not None:
                            gkatpbard = getattr(self.cells[i][j][k].cell, 'gkatpbard_D_KATP' + self.cells[i][j][k].id)        
                            gkatpbard = 0.27           
        else:
            print(str(datetime.datetime.now()) + '\tGlucose set to 11mM')
            for i in range(self.dimensions):
                for j in range(self.dimensions):
                    for k in range(self.dimensions):
                        if self.cells[i][j][k] is not None and self.cells[i][j][k].type == 'A':
                            gkatpa = getattr(self.cells[i][j][k].cell, 'gkatpbara_A_KATP' + self.cells[i][j][k].id)
                            gkatpa = 0.15
                            ksercaa = getattr(self.cells[i][j][k].pp, 'ksercaa')
                            ksercaa = 0.5
                        elif self.cells[i][j][k] is not None and self.cells[i][j][k].type == 'B':
                            gkatpb = getattr(self.cells[i][j][k].pp, 'gkatpb')
                            gkatpb = 25     
                        elif self.cells[i][j][k] is not None:
                            gkatpbard = getattr(self.cells[i][j][k].cell, 'gkatpbard_D_KATP' + self.cells[i][j][k].id)        
                            gkatpbard = 0.18
    def writeDataOrientation(self):
        """Write a template orienation"""
        print(str(datetime.datetime.now()) + '\tSpace.writeDataOrientation Write orientation data: number of cells', len(self.cells_and_locations))
        template_config_path = Islet.env['config'] + 'Values/Template_' + Islet.env['id'] + '/config.txt'
        # write template orientations
        probabilities = ''
        sizes = ''
        c = [0, ['A', 'B', 'D']]
        cells_p = ['Probability_Alpha', 'Probability_Beta', 'Probability_Delta']
        cells_s = ['Size_Alpha', 'Size_Beta', 'Size_Delta']
        # for i in range(len(self.cells)):
        #     x = self.cells[i]*100 - c[0]
        #     c[0] += x
        #     probabilities += cells_p[i] + ' = ' + str(x) + '\n'
        # spatial_configuration = '[Config]\n'+\
        # 'dimensions=' + str(self.islet_radius) + '\n' + probabilities + sizes
        spatial_data = '[Data]\n'
        id = 0
        for cell_position in self.cells_and_locations:
            spatial_data += cell_position[4].lower() + '_' + str(cell_position[0]) + ' = [' + str(cell_position[1])+', '+str(cell_position[2])+', '+str(cell_position[3])+']\n'
            id += 1
        # write to text    
        template_config_file = open(template_config_path, 'w')
        #template_config_file.write(spatial_configuration)
        template_config_file.write(spatial_data)
        template_config_file.close()
    def writeDataPhysiology(self):
        """Write physiological data for each cell"""
        print(str(datetime.datetime.now()) + '\tSpace.writeDataPhysiology Write physiology data: number of columns in 3d matrix of cells', len(self.cells), 'number of rows in x direction', len(self.cells[0]), 'number of rows in y direction', len(self.cells[0][0]))
        print(str(datetime.datetime.now()) + '\tSpace.writeDataPhysiology Output folder: ' + Islet.env['output'] + 'Islet_' + Islet.env['id'])
        output_islet_path = Islet.env['output'] + 'Islet_' + Islet.env['id']
        # Exclude variables that change throughout the simulation and to not include constants
        configc = configparser.ConfigParser(allow_no_value= True)
        configc.optionxform = str
        configc.read(Islet.env['config'] + '/Values/constants.ini')
        # create output folder
        os.system('mkdir -p ' + output_islet_path)
        # Create plots folder
        os.system('mkdir -p ' + output_islet_path + "/Plots")
        # Create subfolders for different types of plots
        os.system('mkdir -p ' + output_islet_path + "/Plots/" + "Voltage")
        os.system('mkdir -p ' + output_islet_path + "/Plots/" + "Currents")
        os.system('mkdir -p ' + output_islet_path + "/Plots/" + "Calcium")
        os.system('mkdir -p ' + output_islet_path + "/Plots/" + "Hormones")
        data = []
        t = []
        # get time variable
        for i in self.cells_and_locations:
            # get time
            if int(i[5].id) == 0:
                t = i[5].t
                print(str(datetime.datetime.now()) + '\tSpace.writeDataPhysiology Obtained reference to time variable: length', len(t))
        for i in self.cells_and_locations:
            if i[5] is not None:
                # get header
                header = ['Time']
                header.extend(i[5].header)
                output_cell_path = i[5].type.lower() + '_' + i[5].id + '.csv'
                # write to csv
                with open(output_islet_path + '/' + output_cell_path,'w+') as file:
                    writer = csv.writer(file, quoting = csv.QUOTE_NONE,escapechar=' ')
                    writer.writerow(header)
                    for z in range(len(t)):
                        data = [t[z]]
                        for q in i[5].rec:
                            data.append(i[5].rec[q][0][z])
                        writer.writerow(data)
                print(str(datetime.datetime.now()) + '\tSpace.writeDataPhysiology Wrote data: cell', i[5], 'islet Islet_' + Islet.env['id'], 'path', Islet.env['output'] + 'Islet_' + Islet.env['id'] + '/' + i[5].type.lower() + '_' + i[5].id + '.csv')
    def getCell(self, rand, x, y, z):
        """Randomly select one cell"""
        print(str(datetime.datetime.now()) + '\tSpace.getCell rand =', rand, 'x =', x, 'y =', y, 'z =', z, 'Probability of alpha/beta at this x/y/z position', self.probabilities[x][y][z])
        if rand <= self.probabilities[x][y][z][0]:
            return 'A'
        elif rand <= self.probabilities[x][y][z][1]:
            return 'B'
        return 'D'
if __name__ == '__main__':
    # test
    # python Space.py
    # run id
    r_id = '0'
    # Islet id
    i_id = '1_0'
    # set environment
    Islet.env['wd'] += 'Islet_' + r_id + '_' + i_id + '/'
    dll = Islet.env['wd'] + '.r/'
    ret = Islet.neuron.load_mechanisms(dll)
    print('Space.py test loaded dll', ret)
    # dimension of islets (will determine size of box that will enclose islet)
    n = 5
    # default probability of cell (60% chance of b-cell, 30% of a-cell, 10% of d-cell)
    probabilities = [0.15, 0.75]
    # initialize distribution
    space = Space(probabilities, None, n)
    space.radialSetup()
    # space.configSetup('1_0')
    space.writeDataOrientation(4)
    # space.plot()
