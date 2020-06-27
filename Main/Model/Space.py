"""The 'Space' object is used to determine the probability and spatial distribution of cells. A probability object is introduced to handle non-uniform distributions."""
import numpy as np
from matplotlib import pyplot as plt
from matplotlib import patches as mpatches
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
        # beta cell probability
        self.b = b - a
        # ratio of delta to alpha cells
        d = 1 - b
        self.ratio = d / a
        self.radius = radius
        self.getDescent(center_prob)
    # m (y=mx+b => m = -2*b/(x^2) from 0 to 1/3rd radius where b is 85 (85% probability of beta cell in center))
    # interval = -(b-c)+-sqrt((b-c)^2-4*(m/2)*(c*r-r*p(beta)))/m
    # average probability of cell type must be as defined in cell_type (calculate sum of piecewise from 1/2 radius out)
    def getDescent(self, c_p):
        # beta cell has constant probability of 0.4 from 1/2 radius out
        # self.b -= 0.2
        self.m = (self.b*self.radius - self.b * (self.radius/2) - c_p * (self.radius/2)) * 2 / ((self.radius/2)**2) 
        # self.m = 0
        # self.b = 0
    def getProbability(self, x, y, z):
        # uniform distribution
        return [(1-self.b)/(1+self.ratio), self.b + (1-self.b)/(1+self.ratio)]
        ret = []
        dist = math.sqrt((self.radius-x)**2 + (self.radius-y)**2 + (self.radius-z)**2)
        # piecewise
        if(dist > self.radius / 3):
            alpha = (1 - self.b)/ (1 + self.ratio)
            delta = 1- self.b - alpha
            return [alpha, self.b + alpha]
        # calculate probabilities of alpha/beta/delta in this position
        beta = self.m * dist + center_prob
        alpha = (1 - beta)/ (1 + self.ratio)
        delta = 1 - beta - alpha
        return [alpha, beta + alpha]

# 3D matrix and accompanying operations that represent the spatial relationship between cells
class Space:
    def __init__(self, cell_p, config, dimen):
        # probability alpha/beta/delta
        self.cell_type = cell_p
        self.config = config
        self.d = dimen
        self.setup()
    def setup(self):
        # distribution for beta cells, 
        # relative abundance according to cell_type
        # piecewise, linear decrease in beta cell probability from center to 1/3rd radius, constant probability after
        self.dist = Probability(self.cell_type[0], self.cell_type[1], self.d/2)
        # the following two variables simplify plotting
        # position of cells
        self.cpos = []
        # size of cells
        self.csize = []
        # 3d matrix of cells
        self.cs = [[[None for i in range(self.d)] for j in range(self.d)] for k in range(self.d)]
        # 3d matrix of probabilities
        self.ps = [[[None for i in range(self.d)] for j in range(self.d)] for k in range(self.d)]
        self.setProbabilities()
    def setProbabilities(self):
        for i in range(self.d):
            for j in range(self.d):
                for k in range(self.d):
                    self.ps[i][j][k] = self.dist.getProbability(i,j,k)
    # fill islet randomly
    def RandomSetup(self):
        c = 0
        while c < self.d:
            # x/y/z coordinates
            pos = random.sample(range(0, self.d), 3)
            # check if cell exists
            if(self.cs[pos[0]][pos[1]][pos[2]] == None):
                continue
            # if position is vacant, add cell to space
            typ = self.getCell(random.random(), x, y, z)
            cell = Cell.Cell(c, pos[0], pos[1], pos[2], typ)
            self.cs[pos[0]][pos[1]][pos[2]] = cell
            # store type and position
            self.cpos.append([typ, pos[0], pos[1], pos[2]])
            # store cell size
            self.csize.append(cell.diam)
            c += 1
        return
    # fill islet radially
    def RadialSetup(self):
        # radius = self.d /4
        i = 0
        j = 0
        k = 0
        c = 0
        while i < self.d:
            while j < self.d:
                while k < self.d:
                    if(math.sqrt((self.d/2-i)**2+(self.d/2-j)**2+(self.d/2-k)**2) > self.d/2):
                        k += 1
                        continue
                    typ = self.getCell(random.random(), i, j, k)
                    # if position is vacant, add cell to space
                    # write configuration file
                    types = {'A': 'Alpha', 'B': 'Beta', 'D': 'Delta'}
                    # with open('../../Configuration/Values/Template_' + Islet.env['gid'][2] + '/' + types[typ][0].lower() + '_' + str(c) + '.ini', 'w') as ini:
                    #     ini.write('[' + types[typ] + ']\n')
                    #     for z in self.config[types[typ]]:
                    #         if(type(self.config[types[typ]][z]) is list):
                    #             val = random.random() * (self.config[types[typ]][z][0] - self.config[types[typ]][z][1]) + self.config[types[typ]][z][0]
                    #         else:
                    #             val = self.config[types[typ]][z]
                    #         print(str(datetime.datetime.now()) + '\tSpace.RadialSetup(self) Write to configuration file: instance', Islet.env['gid'], 'Write initialization file:', z + ' = ' + str(val), 'cell type', types[typ], 'cell number', c)
                    #         ini.write(z + ' = ' + str(val) + '\n')
                    # create cell
                    cell = Cell.Cell(c, i, j, k, typ)
                    print(str(datetime.datetime.now()) + '\tSpace.RadialSetup(self) Added cell to islet: id', cell)
                    self.cs[i][j][k] = cell
                    # store type and position
                    self.cpos.append([typ, i, j, k])
                    self.csize.append(cell.diam)
                    c += 1
                    k += 1
                j += 1
                k = 0
            i += 1
            j = 0
    def configSetup(self, id):
        print(str(datetime.datetime.now()) + '\tSpace.configSetup(self, config) config=', id, 'Create islet instance')
        Islet.env['gid'] = id
        for i in os.listdir('../../Configuration/Values/Islet_'+id):
            # with open('../../Configuration/Values/Islet_'+ id + '/' + i, 'r'):
            config = configparser.ConfigParser()
            config = configparser.ConfigParser(allow_no_value= True)
            config.optionxform = str
            config.read('../../Configuration/Values/Islet_'+ id + '/' + i)
            for a in config:
                # get cell number
                cnum = re.split('_|\.', i)
                cnum = cnum[1]
                if 'position' in config[a]:
                    pos = ast.literal_eval(config[a]['position'])
                    print(str(datetime.datetime.now()) + '\tSpace.configSetup(self, id) id =', id, 'Set up islet from configuration file: configuration file', i, 'cell type', a, 'id', cnum, 'position', pos)
                    cell = Cell.Cell(cnum, pos[0], pos[1], pos[2], i[0].upper(), True)
                    self.cs[pos[0]][pos[1]][pos[2]] = cell
                    # store type and position
                    self.cpos.append([i[0].upper(), pos[0], pos[1], pos[2]])
                    self.csize.append(cell.diam)
                    self.connectCell(cell)                    
    def connectCell(self, i):
        self.nc = {'AB': [], 'BA': [], 'AD': [], 'DA': [], 'BD': [], 'DB': []}
        # connect all cells to all other cells using NetCon object and synapse
        temp = np.array(self.cs)
        temp = temp.flatten()
        print(str(datetime.datetime.now()) + '\tSpace.connectCell(self, i) i =', i, ': Added cells', temp, 'number of added cells', len(temp))
        if i.type == 'A':
            syn = Islet.neuron.h.A_Syn(i.cell(0))
        elif i.type == 'B':
            syn = Islet.neuron.h.B_Syn(i.cell(0))
        else:
            syn = Islet.neuron.h.D_Syn(i.cell(0))
        for j in temp:
            if j is None or i.type == j.type:
                continue
            if i.type == 'A' and j.type == 'D':
                print(str(datetime.datetime.now()) + '\tSpace.connectCell(self, i) i =', i, 'Connecting delta cell to alpha cell: cell ids', j, i)
                # set netcon object
                nc_temp = Islet.neuron.h.NetCon(j.cell(1)._ref_t__D_Somatostatin, syn, 2, 0, 6, sec=j.cell)
                nc_record = Islet.neuron.h.Vector()
                nc_temp.record(nc_record)
                self.nc['DA'].append(nc_record)
                # set pointers
                Islet.neuron.h.setpointer(j.cell(1)._ref_som_D_Somatostatin, "Sst_send", syn)
                Islet.neuron.h.setpointer(j.cell(1)._ref_temp_D_Somatostatin, "Ins_send", syn)
                Islet.neuron.h.setpointer(i.cell(0)._ref_Sst_A_Glucagon, "Sst_receive", syn)
                Islet.neuron.h.setpointer(i.cell(0)._ref_Ins_A_Glucagon, "Ins_receive", syn)
            elif i.type == 'D' and j.type == 'A':
                print(str(datetime.datetime.now()) + '\tSpace.connectCell(self, i) i =', i, 'Connecting alpha cell to delta cell: cell ids', j, i)
                # set netcon object
                nc_temp = Islet.neuron.h.NetCon(j.cell(1)._ref_t__A_Glucagon, syn, 2, 0, 6, sec=j.cell)
                nc_record = Islet.neuron.h.Vector()
                nc_temp.record(nc_record)
                self.nc['AD'].append(nc_record)
                # set pointers
                Islet.neuron.h.setpointer(j.cell(1)._ref_G_A_Glucagon, "Gluc_send", syn)
                Islet.neuron.h.setpointer(j.cell(1)._ref_temp_A_Glucagon, "Ins_send", syn)
                Islet.neuron.h.setpointer(i.cell(0)._ref_G_D_Somatostatin, "Gluc_receive", syn)
                Islet.neuron.h.setpointer(i.cell(0)._ref_Ins_D_Somatostatin, "Ins_receive", syn)                   
            elif i.type == 'A' and j.type == 'B':
                print(str(datetime.datetime.now()) + '\tSpace.connectCell(self, i) i =', i, 'Connecting beta cell to alpha cell: cell ids', j, i)
                # set netcon object
                nc_temp = Islet.neuron.h.NetCon(j.cell(1)._ref_t__B_Insulin, syn, 2, 0, 6, sec=j.cell)
                nc_record = Islet.neuron.h.Vector()
                nc_temp.record(nc_record)
                self.nc['BA'].append(nc_record)
                # set pointers
                Islet.neuron.h.setpointer(j.cell(1)._ref_Ins_B_Insulin, "Ins_send", syn)
                Islet.neuron.h.setpointer(j.cell(1)._ref_temp_B_Insulin, "Sst_send", syn)
                Islet.neuron.h.setpointer(i.cell(0)._ref_Ins_A_Glucagon, "Ins_receive", syn)
                Islet.neuron.h.setpointer(i.cell(0)._ref_Sst_A_Glucagon, "Sst_receive", syn)  
            elif i.type == 'B' and j.type == 'A':
                print(str(datetime.datetime.now()) + '\tSpace.connectCell(self, i) i =', i, 'Connecting alpha cell to delta cell: cell ids', j, i)
                # set netcon object
                nc_temp = Islet.neuron.h.NetCon(j.cell(1)._ref_t__A_Glucagon, syn, 2, 0, 6, sec=j.cell)
                nc_record = Islet.neuron.h.Vector()
                nc_temp.record(nc_record)
                self.nc['AB'].append(nc_record)
                # set pointers
                Islet.neuron.h.setpointer(j.cell(1)._ref_G_A_Glucagon, "Gluc_send", syn)
                Islet.neuron.h.setpointer(j.cell(1)._ref_temp_A_Glucagon, "Sst_send", syn)
                Islet.neuron.h.setpointer(i.cell(0)._ref_G_B_Insulin, "Gluc_receive", syn)
                Islet.neuron.h.setpointer(i.cell(0)._ref_Sst_B_Insulin, "Sst_receive", syn)                    
            elif i.type == 'B' and j.type == 'D':
                print(str(datetime.datetime.now()) + '\tSpace.connectCell(self, i) i =', i, 'Connecting delta cell to beta cell: cell ids', j, i)
                # set netcon object
                nc_temp = Islet.neuron.h.NetCon(j.cell(1)._ref_t__D_Somatostatin, syn, 2, 0, 6, sec=j.cell)
                nc_record = Islet.neuron.h.Vector()
                nc_temp.record(nc_record)
                self.nc['DB'].append(nc_record)
                # set pointers
                Islet.neuron.h.setpointer(j.cell(1)._ref_Sst_D_Somatostatin, "Sst_send", syn)
                Islet.neuron.h.setpointer(j.cell(1)._ref_temp_D_Somatostatin, "Gluc_send", syn)
                Islet.neuron.h.setpointer(i.cell(0)._ref_Sst_B_Insulin, "Sst_receive", syn)
                Islet.neuron.h.setpointer(i.cell(0)._ref_G_B_Insulin, "Gluc_send", syn)                       
            elif i.type == 'D' and j.type == 'B': 
                print(str(datetime.datetime.now()) + '\tSpace.connectCell(self, i) i =', i, 'Connecting beta cell to delta cell: cell ids', j, i)
                # set netcon object
                nc_temp = Islet.neuron.h.NetCon(j.cell(1)._ref_t__B_Insulin, syn, 2, 0, 6, sec=j.cell)
                nc_record = Islet.neuron.h.Vector()
                nc_temp.record(nc_record)
                self.nc['BD'].append(nc_record)
                # set pointers
                Islet.neuron.h.setpointer(j.cell(1)._ref_Ins_B_Insulin, "Ins_send", syn)
                Islet.neuron.h.setpointer(j.cell(1)._ref_temp_B_Insulin, "Gluc_send", syn)
                Islet.neuron.h.setpointer(i.cell(0)._ref_Ins_D_Somatostatin, "Ins_receive", syn) 
                Islet.neuron.h.setpointer(i.cell(0)._ref_G_D_Somatostatin, "Gluc_receive", syn)
    def plot(self):
        print(str(datetime.datetime.now()) + '\tSpace.plot(self) Plotting:')
        x = {'A': [], 'B': [], 'D': []}
        y = {'A': [], 'B': [], 'D': []}
        z = {'A': [], 'B': [], 'D': []}
        s = {'A': [], 'B': [], 'D': []}
        for i in self.cpos:
            x[i[0]].append(i[1])
            y[i[0]].append(i[2])
            z[i[0]].append(i[3])
            s[i[0]].append(self.cs[i[1]][i[2]][i[3]].diam)
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
        dat = [x, y, z, s, self.dist.m, self.dist.ratio, self.dist.radius, center_prob, self.dist.b]
        # plt.savefig('distributions/'+sys.argv[2])
        f_plt = open(Islet.env['output'] + '/orientation/' + Islet.env['gid'] + '.plt', 'wb')
        f_dat = open(Islet.env['ouput'] + '/orientation/' + Islet.env['gid'] + '.dat', 'wb')
        pickle.dump(fig, f_plt)
        pickle.dump(dat, f_dat)
        plt.show()
    def writeDataOrientation(self):
        # write template orientations
        sc = 3
        for z in range(sc):
            prob = ''
            siz = ''
            c = [0, ['A', 'B', 'D']]
            cells_p = ['Probability_Alpha', 'Probability_Beta', 'Probability_Delta']
            cells_s = ['Size_Alpha', 'Size_Beta', 'Size_Delta']
            for i in range(len(self.cell_type)):
                x = self.cell_type[i]*100 - c[0]
                c[0] += x
                prob += cells_p[i] + ' = ' + str(x) + '\n'
                # siz += cells_s[i] + ' = ' + str(self.cell_s[c[1][i]]) + '\n'
            config = '[Config]\n'+\
            'dimensions='+str(self.d)+'\n'+prob+siz
            data = '[Data]\n'
            print(str(datetime.datetime.now()) + '\tSpace.writeDataOrientation(self): Number of cells', len(self.cpos))
            id = 0
            for i in self.cpos:
                data += str(i[0]).lower() + '_' + str(id) + ' = [' + str(i[1])+', '+str(i[2])+', '+str(i[3])+']\n'
                id += 1
            # write to text    
            os.system('mkdir ' + Islet.env['ini'] + '/Values/Template_' + str(z))
            file = open(Islet.env['ini'] + '/Values/Template_' + str(z) + '/config.txt', 'w')
            file.write(config)
            file.write(data)
            file.close()
    def writeDataPhysiology(self):
        print(str(datetime.datetime.now()) + '\tSpace.writeDataPhysiology(self): Number of columns in 3d matrix of cells', len(self.cs), 'number of rows in x direction', len(self.cs[0]), 'number of rows in y direction', len(self.cs[0][0]))
        header = ['Time', 'ID']
        data = []
        types = {'A': [False, 0], 'B': [False, 0], 'D': [False, 0]}
        t = []
        index = 0
        #get header
        for i in range(len(self.cs)):
            for j in range(len(self.cs[i])):
                for k in range(len(self.cs[i][j])):
                    if self.cs[i][j][k] is not None:
                        # each cell type is going to have a different header
                        if self.cs[i][j][k].type in types and types[self.cs[i][j][k].type][0] == False:
                            types[self.cs[i][j][k].type][0] = True
                            types[self.cs[i][j][k].type][1] = index
                            index += len(self.cs[i][j][k].header)
                            print(str(datetime.datetime.now()) + '\tSpace.writeDataPhysiology(self) Added elements of ', self.cs[i][j][k].type, 'cell to header: length', len(self.cs[i][j][k].rec['VC0'][0]), 'at index', index, ': for cell type', self.cs[i][j][k].type, 'types now', types[self.cs[i][j][k].type])
                            header.extend(self.cs[i][j][k].header)
                        # get time
                        if self.cs[i][j][k].id == 0:
                            t = self.cs[i][j][k].t
                            print(str(datetime.datetime.now()) + '\tSpace.writeDataPhysiology(self) Obtained reference to time variable: length', len(t))
        # write to csv
        with open(Islet.env['output'] + '/physiology/' + Islet.env['gid'] + '.csv','w+') as file:
            writer = csv.writer(file,quoting = csv.QUOTE_NONE,escapechar=' ')
            writer.writerow(header)
            # get data and header
            for i in range(len(self.cs)):
                for j in range(len(self.cs[i])):
                    for k in range(len(self.cs[i][j])):
                        if self.cs[i][j][k] is not None:
                            temp = []
                            temp.extend([t, str(self.cs[i][j][k].type) + str(self.cs[i][j][k].id)])
                            print(str(datetime.datetime.now()) + '\tSpace.writeDataPhysiology(self) Added initial elements of data matrix: elements', temp)
                            # add nothing if not appropriate cell type
                            for q in range(types[self.cs[i][j][k].type][1]):
                                temp.append(-1)
                            print(str(datetime.datetime.now()) + '\tSpace.writeDataPhysiology(self) Added "filler" elements to data matrix to set data at offset corresponding to header: elements', len(temp))
                            for q in self.cs[i][j][k].rec:
                                temp.extend(self.cs[i][j][k].rec[q][0])
                            print(str(datetime.datetime.now()) + '\tSpace.writeDataPhysiology(self) Added rest of data to data matrix: length of matrix', len(temp))
                            # data.append(temp)
                            # print(str(datetime.datetime.now()) + 'extend data', len(data))
                            for i in range(len(t)):
                                writer.writerow(temp)
                                print(str(datetime.datetime.now()) + '\tSpace.writeDataPhysiology(self) Wrote row of csv: row number', i)
    def getCell(self, r, x, y, z):
        print(str(datetime.datetime.now()) + '\tSpace.getCell(self, r, x, y, z) r =', r, 'x =', x, 'y =', y, 'z =', z, 'Probability of alpha/beta at this x/y/z position', self.ps[x][y][z])
        if r <= self.ps[x][y][z][0]:
            return 'A'
        elif r <= self.ps[x][y][z][1]:
            return 'B'
        return 'D'

if __name__ == '__main__':
    # cell sizes
    sizes = {'A': 10, 'B': 10, 'D': 10}
    # dimension of islets (will determine size of box that will enclose islet)
    n = 10
    # default probability of cell (60% chance of b-cell, 30% of a-cell, 10% of d-cell)
    probabilities = [0.15, 0.75]
    # initialize distribution
    dist = Space(probabilities, sizes, n, sys.argv[1])
    dist.RadialSetup()
    dist.plot()
    dist.writeDataOrientation()
