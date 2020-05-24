"""This script determines the position of an alpha/beta/delta cell and handles their representation"""
import numpy as np
from matplotlib import pyplot as plt
from matplotlib import patches as mpatches
from scipy.stats import expon, uniform
import random
import math
import sys
import pickle 

center_prob = 1
# cell sizes
sizes = {'A': 10, 'B': 10, 'D': 10}
# dimension of islets (will determine size of box that will enclose islet)
n = 10
# default probability of cell (60% chance of b-cell, 30% of a-cell, 10% of d-cell)
probabilities = [0.15, 0.75]

# wrapper class to store type and dimensions of cell
class Cell:
    def __init__(self, typ):
        # within 10% of desired size
        if(typ is None):
            self.diam = -1
            self.typ = "Z"
        self.typ = typ
        # diameter within 10% of given
        self.diam = random.randint(math.floor(sizes[self.typ]-sizes[self.typ]*random.random()/10), math.ceil(sizes[self.typ]+sizes[self.typ]*random.random()*10))
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
        # self.m = (self.b*self.radius - self.b * (self.radius/2) - c_p * (self.radius/2)) * 2 / ((self.radius/2)**2) 
        self.m = 0
        self.b = 0
    def getProbability(self, x, y, z):
        ret = []
        dist = math.sqrt((self.radius-x)**2 + (self.radius-y)**2 + (self.radius-z)**2)
        print('dist', dist, x, y, z, self.radius)
        # piecewise
        if(dist > self.radius / 2):
            alpha = (1 - self.b)/ (1 + self.ratio)
            delta = 1- self.b - alpha
            # alpha = (1 - 0)/ (1 + self.ratio)
            # delta = 1- 0 - alpha
            print('m', self.m, 'ratio', self.ratio, 'radius', self.radius)
            print((1-self.b)/(1+self.ratio), self.b, self.ratio*(1-self.b)/(1+self.ratio), delta + alpha + self.b)
            # print((1-0)/(1+self.ratio), 0, self.ratio*(1-0)/(1+self.ratio), delta + alpha + 0)
            return [alpha, self.b + alpha]
            # return [alpha, alpha]
        # calculate probabilities of alpha/beta/delta in this position
        beta = self.m * dist + center_prob
        print(self.m, dist, self.m*dist, center_prob)
        alpha = (1 - beta)/ (1 + self.ratio)
        delta = 1 - beta - alpha
        print('m', self.m, 'ratio', self.ratio, 'radius', self.radius)
        print('descent', alpha, beta + alpha, delta, delta + alpha + beta)
        return [alpha, beta + alpha]

# 3D matrix and accompanying operations that represent the spatial relationship between cells
class Space:
    def __init__(self, cell_p, cell_s, dimen, f):
        # file where data will be written to
        self.f = f
        # probability alpha/beta/delta
        self.cell_type = cell_p
        self.cell_s = cell_s
        self.d = dimen
        self.setup()
    def setup(self):
        # distribution for beta cells, 
        # relative abundance according to cell_type
        # piecewise, linear decrease in beta cell probability from center to 1/3rd radius, constant probability after
        self.dist = Probability(self.cell_type[0], self.cell_type[1], self.d/2)
        # position of cells
        self.cpos = []
        # size of cells
        self.csize = []
        print('setting cells')
        # 3d matrix of cells
        self.cs = [[[[None] for i in range(self.d)] for j in range(self.d)] for k in range(self.d)]
        print('setting probabilities')
        # 3d matrix of probabilities
        self.ps = [[[[None] for i in range(self.d)] for j in range(self.d)] for k in range(self.d)]
        self.setProbabilities()
    def setProbabilities(self):
        a = 0 
        for i in range(self.d):
            for j in range(self.d):
                for k in range(self.d):
                    a += 1
                    print(a, sep=' ')
                    self.ps[i][j][k] = self.dist.getProbability(i,j,k)
    # fill islet randomly
    def mainLoop_A(self):
        c = 0
        while c < self.d:
            typ = self.getCell(random.random())
            # x/y/z coordinates
            pos = random.sample(range(0, self.d), 3)
            # check if cell exists
            if(self.cs[pos[0]][pos[1]][pos[2]] == None):
                continue
            # if position is vacant, add cell to space
            cell = Cell(typ)
            self.cs[pos[0]][pos[1]][pos[2]] = cell
            # store type and position
            self.cpos.append([typ, pos[0], pos[1], pos[2]])
            # store cell size
            self.csize.append(cell.diam)
            c += 1
        return
    # fill islet radially
    def mainLoop_B(self):
        # radius = self.d /4
        i = 0
        j = 0
        k = 0
        c = 0
        while i < self.d:
            while j < self.d:
                while k < self.d:
                    if(self.cs[i][j][k] == None or math.sqrt((self.d/2-i)**2+(self.d/2-j)**2+(self.d/2-k)**2) > self.d/2):
                        k += 1
                        continue
                    typ = self.getCell(random.random(), i, j, k)
                    # if position is vacant, add cell to space
                    cell = Cell(typ)
                    self.cs[i][j][k] = cell
                    # store type and position
                    self.cpos.append([typ, i, j, k])
                    self.csize.append(cell.diam)
                    c += 1
                    k += 1
                j += 1
                k = 0
                # k = math.floor(self.d/2 - radius)
            i += 1
            j = 0
            # j = math.floor(self.d//2 - radius)
    def plot(self):
        print('m', self.dist.m)
        print('plotting')
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
        f_plt = open('distributions/'+sys.argv[2] +'.plt', 'wb')
        f_dat = open('distributions/'+sys.argv[2] +'.dat', 'wb')
        pickle.dump(fig, f_plt)
        pickle.dump(dat, f_dat)
        # plt.show()
    def writeData(self):
        prob = ''
        siz = ''
        c = [0, ['A', 'B', 'D']]
        cells_p = ['Probability_Alpha', 'Probability_Beta', 'Probability_Delta']
        cells_s = ['Size_Alpha', 'Size_Beta', 'Size_Delta']
        for i in range(len(self.cell_type)):
            x = self.cell_type[i]*100 - c[0]
            c[0] += x
            prob += cells_p[i] + ' = ' + str(x) + '\n'
            siz += cells_s[i] + ' = ' + str(self.cell_s[c[1][i]]) + '\n'
        config = '[Config]\n'+\
        'dimensions='+str(self.d)+'\n'+prob+siz
        data = '[Data]\n'
        for i in self.cpos:
            data += str(i[0])+' '+str(i[1])+' '+str(i[2])+' '+str(i[3])+'\n'
        file = open('data/'+self.f, 'w')
        file.write(config)
        file.write(data)
        file.close()
    def getCell(self, r, x, y, z):
        print('probability at',x,y,z,r,math.sqrt((self.d/2-x)**2 +(self.d/2-y)**2 +(self.d/2-z)**2), self.d/6, self.ps[x][y][z])
        if r <= self.ps[x][y][z][0]:
            return 'A'
        elif r <= self.ps[x][y][z][1]:
            return 'B'
        return 'D'

# how alpha cell in one position affects the probability a beta cell will be near it and so on
mult = [[0.03,0.0,0.0],[0.0,0.03,0.0],[0.0,0.0,0.02]]
# initialize distribution
dist = Space(probabilities, sizes, n, sys.argv[1])
dist.mainLoop_B()
dist.plot()
dist.writeData()