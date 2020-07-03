import numpy as np
from matplotlib import pyplot as plt
from scipy.signal import butter, lfilter, find_peaks, peak_prominences
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
    # print('prominences', prominence)
    # print(_, p)
    # plt.plot(filtered_data)
    fig = plt.figure()
    plt.xlabel('Time (ms)')  
    plt.ylabel('Membrane Potential (mV)')  
    plt.title("Spikes in Membrane Potential vs Time")
    plt.plot(data['Vp'])
    plt.plot(p, data['Vp'][p], "x")
    fig.savefig(re.split('\.csv', file)[0] + '.png')
    pickle.dump([_, p, prominence, data],open(re.split('\.csv', file)[0] + '.pl', 'wb'))
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
    # print('prominences', prominence)
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
    pickle.dump([_, p, prominence, data], open(re.split('.csv', cell)[0] + '.pl', 'wb'))
def scoreRun(file, cell):
    print(str(datetime.datetime.now()) + '\tscore run for', cell, 'with', file)
    _, p, prominence, data = pickle.load(open(re.split('.csv', file)[0] + '.pl', 'rb'))
    _2, p2, prominence2, data2 = pickle.load(open(re.split('.csv', cell)[0] + '.pl', 'rb'))
    # print('peaks', p, '\nprominence', prominence, '\npeak prop', _)
    # print('peaks2', p2, '\nprominence2', prominence2, '\npeak prop2', _2)

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