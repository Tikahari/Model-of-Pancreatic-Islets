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
    def __init__(self, a, b, radius):
        """Initialize probability for point"""
        # set object variables
        self.b = b - a
        # ratio of delta to alpha cells
        d = 1 - b
        self.ratio = d / a
        self.radius = radius
    def getProbability(self, x, y, z):
        """Get probability at point"""
        # uniform distribution
        return [(1-self.b)/(1+self.ratio), self.b + (1-self.b)/(1+self.ratio)]

class Space:
    def __init__(self, cell_probabilities, config, dimensions, compile=False):
        """Initialize Space instance"""
        # set object variables
        self.cell_types = cell_probabilities
        self.config = config
        self.dimensions = dimensions
        self.compile = compile
        self.setup()
    def setup(self):
        """Set cells, probabilities and plotting variables"""
        # probability distribution
        self.distribution = Probability(self.cell_types[0], self.cell_types[1], self.dimensions/2)
        # the following two variables simplify plotting
        # position of cells
        self.cell_positions = []
        # size of cells
        self.cell_sizes = []
        # 3d matrix of cells (initialized to None)
        self.cells = [[[None for i in range(self.dimensions)] for j in range(self.dimensions)] for k in range(self.dimensions)]
        # 3d matrix of probabilities (initialized to None then whatever probability is given by the distribution at the corresponding point)
        self.probabilities = [[[None for i in range(self.dimensions)] for j in range(self.dimensions)] for k in range(self.dimensions)]
        for i in range(self.dimensions):
            for j in range(self.dimensions):
                for k in range(self.dimensions):
                    self.probabilities[i][j][k] = self.distribution.getProbability(i,j,k)
    def randomSetup(self):
        """Set up the islet such that the position of each cell is random"""
        c = 0
        while c < self.dimensions:
            # x/y/z coordinates
            pos = random.sample(range(0, self.dimensions), 3)
            # check if cell exists
            if(self.cells[pos[0]][pos[1]][pos[2]] == None):
                continue
            # if position is vacant, add cell to space
            typ = self.getCell(random.random(), x, y, z)
            cell = Cell.Cell(c, pos[0], pos[1], pos[2], typ)
            self.cells[pos[0]][pos[1]][pos[2]] = cell
            # store type and position
            self.cell_positions.append([typ, pos[0], pos[1], pos[2]])
            self.cell_sizes.append(cell.diam)
            c += 1
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
    def configSetup(self, id):
        """Set up the islet from configuration file"""
        print(str(datetime.datetime.now()) + '\tSpace.configSetup Create islet instance: id', id, 'wd', Islet.env['wd'])
        Islet.env['gid'] = id
        owd = Islet.env['wd']
        for cell in os.listdir(Islet.env['wd']):
            if os.path.isdir(Islet.env['wd'] + cell) and 'Islet_' in (Islet.env['wd'] + cell):
                values_cell_path = Islet.env['config'] + 'Values/Islet_'+ Islet.env['rid'] + '_' + str(id) + '/' + cell + '.ini'
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
                        cell_obj = Cell.Cell(cell_num, pos[0], pos[1], pos[2], cell_type[0].upper(), True, self.compile)
                        self.cells[pos[0]][pos[1]][pos[2]] = cell_obj
                        # store type and position
                        self.cell_positions.append([cell_type[0].upper(), pos[0], pos[1], pos[2]])
                        self.cell_sizes.append(cell_obj.diam)
            Islet.env['wd'] = owd                  
    def plot(self):
        """Visualize the islet"""
        print(str(datetime.datetime.now()) + '\tSpace.plot Plotting:')
        plot_path = Islet.env['output'] + 'Islet_' + Islet.env['rid'] + '_' + Islet.env['gid'].split('_')[0] + '/Islet_'
        x = {'A': [], 'B': [], 'D': []}
        y = {'A': [], 'B': [], 'D': []}
        z = {'A': [], 'B': [], 'D': []}
        s = {'A': [], 'B': [], 'D': []}
        for i in self.cell_positions:
            x[i[0]].append(i[1])
            y[i[0]].append(i[2])
            z[i[0]].append(i[3])
            s[i[0]].append(self.cells[i[1]][i[2]][i[3]].diam)
        fig = plt.figure()
        a = mpatches.Patch(color='red', label='Alpha')
        b = mpatches.Patch(color='blue', label='Beta')
        d = mpatches.Patch(color='green', label='Delta')
        ax = fig.add_subplot(111, projection='3d')
        ax.legend(handles=[a,b,d])
        ax.set_title('Spatial Representation of Islet')
        # ax.axis('off')
        ax.scatter(x['A'], y['A'], z['A'], c='red', s=s['A'])
        ax.scatter(x['B'], y['B'], z['B'], c='blue', s=s['B'])
        ax.scatter(x['D'], y['D'], z['D'], c='green', s=s['D'])
        dat = [x, y, z, s]
        plt.savefig(plot_path + Islet.env['gid'] + '.png', 'w')
        f_plt = open(plot_path + Islet.env['gid'] + '.plt', 'wb')
        f_dat = open(plot_path + Islet.env['gid'] + '.dat', 'wb')
        pickle.dump(fig, f_plt)
        pickle.dump(dat, f_dat)
        # plt.show()
    def writeDataOrientation(self, temp):
        """Write a template orienation"""
        print(str(datetime.datetime.now()) + '\tSpace.writeDataOrientation Write orientation data: number of cells', len(self.cell_positions))
        template_config_path = Islet.env['config'] + 'Values/Template_' + Islet.env['rid'] + '_' + str(temp) + '/config.txt'
        # write template orientations
        probabilities = ''
        sizes = ''
        c = [0, ['A', 'B', 'D']]
        cells_p = ['Probability_Alpha', 'Probability_Beta', 'Probability_Delta']
        cells_s = ['Size_Alpha', 'Size_Beta', 'Size_Delta']
        for i in range(len(self.cell_types)):
            x = self.cell_types[i]*100 - c[0]
            c[0] += x
            probabilities += cells_p[i] + ' = ' + str(x) + '\n'
        spatial_configuration = '[Config]\n'+\
        'dimensions=' + str(self.dimensions) + '\n' + probabilities + sizes
        spatial_data = '[Data]\n'
        id = 0
        for cell_position in self.cell_positions:
            spatial_data += str(cell_position[0]).lower() + '_' + str(id) + ' = [' + str(cell_position[1])+', '+str(cell_position[2])+', '+str(cell_position[3])+']\n'
            id += 1
        # write to text    
        template_config_file = open(template_config_path, 'w')
        template_config_file.write(spatial_configuration)
        template_config_file.write(spatial_data)
        template_config_file.close()
    def writeDataPhysiology(self):
        """Write physiological data for each cell"""
        print(str(datetime.datetime.now()) + '\tSpace.writeDataPhysiology Write physiology data: number of columns in 3d matrix of cells', len(self.cells), 'number of rows in x direction', len(self.cells[0]), 'number of rows in y direction', len(self.cells[0][0]))
        print( Islet.env['output'], 'Islet_', Islet.env['rid'], Islet.env['gid'])
        output_islet_path = Islet.env['output'] + 'Islet_' + Islet.env['rid'] + '_' + Islet.env['gid']
        # create output folder
        os.system('mkdir -p ' + output_islet_path)
        data = []
        t = []
        # get time variable
        for i in range(len(self.cells)):
            for j in range(len(self.cells[i])):
                for k in range(len(self.cells[i][j])):
                    # get time
                    if self.cells[i][j][k] is not None and int(self.cells[i][j][k].id) == 0:
                            t = self.cells[i][j][k].t
                            print(str(datetime.datetime.now()) + '\tSpace.writeDataPhysiology Obtained reference to time variable: length', len(t))
        for i in range(len(self.cells)):
                for j in range(len(self.cells[i])):
                    for k in range(len(self.cells[i][j])):
                        if self.cells[i][j][k] is not None:
                            # get header
                            header = ['Time']
                            header.extend(self.cells[i][j][k].header)
                            output_cell_path = self.cells[i][j][k].type.lower() + '_' + self.cells[i][j][k].id + '.csv'
                            # write to csv
                            with open(output_islet_path + '/' + output_cell_path,'w+') as file:
                                writer = csv.writer(file, quoting = csv.QUOTE_NONE,escapechar=' ')
                                writer.writerow(header)
                                for z in range(len(t)):
                                    data = [t[z]]
                                    for q in self.cells[i][j][k].rec:
                                        data.append(self.cells[i][j][k].rec[q][0][z])
                                    writer.writerow(data)
                            print(str(datetime.datetime.now()) + '\tSpace.writeDataPhysiology Wrote data: cell', self.cells[i][j][k], 'islet Islet_' + Islet.env['gid'], 'path', Islet.env['output'] + 'Islet_' + Islet.env['rid'] + '_' + Islet.env['gid'] + '/' + self.cells[i][j][k].type.lower() + '_' + self.cells[i][j][k].id + '.csv')
    def getCell(self, rand, x, y, z):
        """Randomly select one cell"""
        # print(str(datetime.datetime.now()) + '\tSpace.getCell rand =', rand, 'x =', x, 'y =', y, 'z =', z, 'Probability of alpha/beta at this x/y/z position', self.probabilities[x][y][z])
        # if rand <= self.probabilities[x][y][z][0]:
        #     return 'A'
        # elif rand <= self.probabilities[x][y][z][1]:
        #     return 'B'
        # return 'D'
        return 'B'
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
