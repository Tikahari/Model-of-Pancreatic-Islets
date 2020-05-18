"""This script determines the position of an alpha/beta/delta cell and handles their representation"""
import numpy as np
from matplotlib import pyplot as plt
from matplotlib import patches as mpatches
from scipy.stats import expon, uniform
import random
import math
import sys

# cell sizes
sizes = {'A': 10, 'B': 10, 'D': 10}
# dimension of islets (will determine size of box that will enclose islet)
n = 7
# default probability of cell (60% chance of b-cell, 30% of a-cell, 10% of d-cell)
ct = [0.6, 0.85, 1]
# scaling factor (percentage of total volume the islet will occupy)
sc = 0.7

# wrapper class to store type and dimensions of cell
class Cell:
    def __init__(self, typ):
        # within 10% of desired size
        if(typ is None):
            self.d = -1
            self.typ = "Z"
        self.typ = typ
        # diameter within 10% of given
        self.diam = random.randint(math.floor(sizes[self.typ]-sizes[self.typ]*random.random()/10), math.ceil(sizes[self.typ]+sizes[self.typ]*random.random()*10))
# wrapper class to store probability a point is alpha/beta/delta
class Probability:
    def __init__(self, a, b, d):
        if a is None or b is None or d is None:
            self.a = -1
            self.b = - 1
            self.d = -1
            return
        self.a = a
        self.b = b
        self.d = d
# 3D matrix and accompanying operations that represent the spatial relationship between cells
class Space:
    def __init__(self, cell_type, dimen, sc, f):
        # file where data will be written to
        self.f = f
        # scaling factor
        self.sc = sc
        # probability alpha/beta/delta
        self.cell_type = cell_type
        self.d = dimen
        self.setup()
    def setup(self):
        # exponential distribution for beta cells (uniform for alpha, delta)
        self.b_dist = expon()
        # position of cells
        self.cpos = []
        print('setting cells')
        # 3d matrix of cells
        self.cs = [[[[None] for i in range(self.d)] for j in range(self.d)] for k in range(self.d)]
        print('setting probabilities')
        # 3d matrix of probabilities
        self.ps = [[[[None] for i in range(self.d)] for j in range(self.d)] for k in range(self.d)]
        self.setProbabilities()
    def setProbabilities(self):
        for i in range(self.d):
            for j in range(self.d):
                for k in range(self.d):
                    self.ps[i][j][k] = Probability(self.cell_type[0], self.cell_type[1], self.cell_type[2])
    # fill islet randomly
    def mainLoop_A(self):
        c = 0
        while c < self.d:
            typ = getCell(random.random())
            # x/y/z coordinates
            pos = random.sample(range(0, self.d), 3)
            # check if cell exists
            if(self.cs[pos[0]][pos[1]][pos[2]] == None):
                continue
            # if position is vacant, add cell to space
            self.cs[pos[0]][pos[1]][pos[2]] = Cell(typ)
            # store type and position
            self.cpos.append([typ, pos[0], pos[1], pos[2]])
            c += 1
        return
    # fill islet radially
    def mainLoop_B(self):
        radius = self.d /4
        i = math.floor(self.d/2 - radius)
        j = math.floor(self.d/2 - radius)
        k = math.floor(self.d/2 - radius)
        c = 0
        while i < self.d/2 + radius:
            while j < self.d/2 + radius:
                while k < self.d/2 + radius:
                    if(self.cs[i][j][k] == None or math.sqrt((self.d/2-i)**2+(self.d/2-j)**2+(self.d/2-k)**2) > radius):
                        k += 1
                        continue
                    typ = getCell(random.random())
                    # if position is vacant, add cell to space
                    self.cs[i][j][k] = Cell(typ)
                    # store type and position
                    self.cpos.append([typ, i, j, k])
                    c += 1
                    k += 1
                j += 1
                k = math.floor(self.d/2 - radius)
            i += 1
            j = math.floor(self.d//2 - radius)
    def plot(self):
        print('plotting')
        x = {'A': [], 'B': [], 'D': []}
        y = {'A': [], 'B': [], 'D': []}
        z = {'A': [], 'B': [], 'D': []}
        for i in self.cpos:
            x[i[0]].append(i[1])
            y[i[0]].append(i[2])
            z[i[0]].append(i[3])
        fig = plt.figure()
        a = mpatches.Patch(color='red', label='Alpha')
        b = mpatches.Patch(color='blue', label='Beta')
        d = mpatches.Patch(color='green', label='Delta')
        ax = fig.add_subplot(111, projection='3d')
        ax.legend(handles=[a,b,d])
        ax.set_title('Spatial Representation of Islet')
        ax.axis('off')
        ax.scatter(x['A'], y['A'], z['A'], c='red')
        ax.scatter(x['B'], y['B'], z['B'], c='blue')
        ax.scatter(x['D'], y['D'], z['D'], c='green')
        plt.savefig('distributions/'+sys.argv[2])
        plt.show()
    def writeData(self):
        prob = ''
        c = 0
        cells = ['Probability_Alpha', 'Probability_Beta', 'Probability_Delta']
        for i in range(len(self.cell_type)):
            x = self.cell_type[i]*100 - c
            c += x
            prob += cells[i] + ' = ' + str(x) + '\n'
        print(prob)
        config = '[Config]\n'+\
        'dimensions='+str(self.d)+'\n'+\
        'scaling_factor='+str(self.sc)+'\n'+\
        prob
        data = '[Data]\n'
        for i in self.cpos:
            data += str(i[0])+' '+str(i[1])+' '+str(i[2])+' '+str(i[3])+'\n'
        file = open('data/'+self.f, 'w')
        file.write(config)
        file.write(data)
        file.close()
def getCell(r):
    if r <= ct[0]:
        return 'A'
    elif r <= ct[1]:
        return 'B'
    return 'D'

# normalizes distance between cells (nice add-on, not necessary)
def normalize():
    return

# how alpha cell in one position affects the probability a beta cell will be near it and so on
mult = [[0.03,0.0,0.0],[0.0,0.03,0.0],[0.0,0.0,0.02]]
# initialize distribution
dist = Space(ct, n, sc, sys.argv[1])
dist.mainLoop_B()
dist.plot()
dist.writeData()
