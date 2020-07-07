import numpy as np
from matplotlib import pyplot as plt
from scipy.signal import butter, lfilter, find_peaks, peak_prominences
from scipy.stats import *
import pickle
import os
import re
import datetime

def readData(file):
    print(str(datetime.datetime.now()) + '\tread data for', file)
    data = np.genfromtxt(file, delimiter=',', names=True)

    # Determine Nyquist frequency/sampling rate
    sf = 1
    nyq = sf/2
    # Set bands
    low = 500
    high = 9000
    low = low/nyq
    high = high/nyq

    # Calculate coefficients
    b, a = butter(2, 0.5)
    # print(b, a)
    # Filter signal
    filtered_data = lfilter(b, a, data['Vp'])
    # Find peaks
    p, _ = find_peaks(data['Vp'])
    # Calculate prominence
    prominence = peak_prominences(data['Vp'], p)
    print('prominences', prominence)
    # print(_, p)
    # plt.plot(filtered_data)
    fig = plt.figure()
    plt.xlabel('Time (ms)')  
    plt.ylabel('Membrane Potential (mV)')  
    plt.title("Spikes in Membrane Potential vs Time")
    plt.plot(data['Vp'])
    plt.plot(p, data['Vp'][p], "x")
    fig.savefig(re.split('\.csv', file)[0] + '.png')
    pickle.dump([p, prominence, data['Vp']],open(re.split('\.csv', file)[0] + '.pl', 'wb'))
def readCell(cell):
    print(str(datetime.datetime.now()) + '\tread cell for', cell)
    data = np.genfromtxt(cell, delimiter=',', names=True)
    # Determine Nyquist frequency/sampling rate
    sf = 1
    nyq = sf/2
    # Set bands
    low = 500
    high = 9000
    low = low/nyq
    high = high/nyq

    # Calculate coefficients
    b, a = butter(2, 0.5)
    # print(b, a)
    # Filter signal
    filtered_data = lfilter(b, a, data['VC0'])
    # Find peaks
    p, _ = find_peaks(data['VC0'])
    # Calculate prominence
    prominence = peak_prominences(data['VC0'], p)
    print('prominences', prominence)
    # print(_, p)
    # plt.plot(filtered_data)
    # print('max', max(data['VC0']))
    fig = plt.figure()
    plt.xlabel('Time (ms)')  
    plt.ylabel('Membrane Potential (mV)')  
    plt.title("Spikes in Membrane Potential vs Time")
    plt.plot(data['VC0'])
    plt.plot(p, data['VC0'][p], "x")
    fig.savefig(re.split('\.csv', cell)[0] + '.png')
    pickle.dump([p, prominence, data['VC0']], open(re.split('.csv', cell)[0] + '.pl', 'wb'))
def scoreRun(file, cell):
    print(str(datetime.datetime.now()) + '\tscore run for', cell, 'with', file)
    data_1 = pickle.load(open(re.split('.csv', file)[0] + '.pl', 'rb'))
    data_2 = pickle.load(open(re.split('.csv', cell)[0] + '.pl', 'rb'))
    for i, j in zip(data_1, data_2):
        if len(i) > 0 and len(j) > 0:
            getValue(i, j)
    # print('peaks', p, '\nprominence', prominence, '\npeak prop', _)
    # print('peaks2', p2, '\nprominence2', prominence2, '\npeak prop2', _2)
def getValue(a, b):
    tolerance = {}
    # 5 point penalty for every 10 points of variation
    p = 0
    for i in range(10):
        tolerance[i/10] = p
        p += 5
    d1 = describe(a)
    d2 = describe(b)
    print('d1', d1)
    print('d2', d2)
    print('begin')
    # counter, variance, mean
    c = 0
    v = -1
    m = -1
    a = []
    for i, j in zip(d1, d2):
        # get mean
        if c == 2:
            m = i
        # get variance, z-scores
        if c == 3:
            v = i
            tol = []
            k = c - 2 * v
            while k < c + 2 * v and k > c - 2 * v:
                # z-score
                z[k] = k / 2 * v
                k += 1
    # score based on tolerance/z-score
    for i, j in zip(d1, d2):
        print('d1, d2', i, j)     
        c += 1
def main():
    # read data
    data = 'data_1.csv'
    readData(data)
    ctypes = {'a': [], 'b': [], 'c': []}
    for i in os.listdir(os.getcwd()):
        if i[0] in ctypes and 'csv' in i:
            readCell(i)
            scoreRun(data, i)
main()