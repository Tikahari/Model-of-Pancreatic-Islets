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

    # Nyquist frequency
    nyq = sampling_rate / 2

    # width of transition band
    width = 0.01

    # The desired attenuation in the stop band, in dB.
    ripple_db = 20.0

    # Compute the order and Kaiser parameter for the FIR filter.
    N, beta = kaiserord(ripple_db, width)

    # The cutoff frequency of the filter.
    cutoff_hz = 6.0

    # Use firwin with a Kaiser window to create a lowpass FIR filter.
    taps = firwin(N, cutoff_hz/nyq, window=('kaiser', beta))
    # print('coefficients', taps)
    w, h = freqz(taps, worN=100)
    
    # Find peaks
    p, _ = find_peaks(data['Vp'])
    # print(str(datetime.datetime.now()) + '\tpeaks', p, len(p))
    # Calculate prominence
    prominence = peak_prominences(data['Vp'], p)
    # print(str(datetime.datetime.now()) + '\tprominences', prominence)
    fig = plt.figure()
    plt.xlabel('Time (ms)')  
    plt.ylabel('Membrane Potential (mV)')  
    plt.title("Spikes in Membrane Potential vs Time")
    plt.plot(data['Vp'])
    plt.plot(p, data['Vp'][p], "x")
    fig.savefig(re.split('\.csv', file)[0] + '.png')
    pickle.dump([p, list(prominence)[0], data['Vp']],open(re.split('\.csv', file)[0] + '_data.pl', 'wb'))
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
    # Filter signal
    filtered_data = lfilter(b, a, data['VC0'])
    # Find peaks
    p, _ = find_peaks(data['VC0'])
    # print(str(datetime.datetime.now()) + '\tpeaks', p, len(p))
    # Calculate prominence
    prominence = peak_prominences(data['VC0'], p)
    # print(str(datetime.datetime.now()) + '\tprominences', prominence)

    fig = plt.figure()
    plt.xlabel('Time (ms)')  
    plt.ylabel('Membrane Potential (mV)')  
    plt.title("Spikes in Membrane Potential vs Time")
    plt.plot(data['VC0'])
    plt.plot(p, data['VC0'][p], "x")
    fig.savefig(re.split('\.csv', cell)[0] + '.png')
    pickle.dump([p, list(prominence)[0], data['VC0']], open(re.split('\.csv', cell)[0] + '_data.pl', 'wb'))
def scoreRun(file, cell):
    print(str(datetime.datetime.now()) + '\tscore run for', cell, 'with', file)
    # distinguish between different types of data
    ids = ['peaks', 'promeninces', 'data']
    score = []
    # load reference and cell data from file into memory
    data_1 = pickle.load(open(re.split('.csv', file)[0] + '_data.pl', 'rb'))
    data_2 = pickle.load(open(re.split('.csv', cell)[0] + '_data.pl', 'rb'))
    c = 0
    for i, j in zip(data_1, data_2):
        score.append(getValue(i, j, ids[c]))
        c += 1
    print(str(datetime.datetime.now()) + '\tscore is', score)
    # write value
    pickle.dump([sum(score)/len(score), score, ids], open(re.split('\.csv', cell)[0] + '_score.pl', 'wb'))
def getValue(a, b, id):
    print(str(datetime.datetime.now()) + '\tgetValue', id)
    score = -1
    tolerance = {}
    # list of headings in tuple output of 'describe'
    desc_h = ['nobs', 'minmax', 'mean', 'variance', 'skewness', 'kurtosis']
    # store output of 'describe' for reference data and cell data
    desc_oref = {}
    desc_ocell = {}
    # 5 point penalty for every 10 points of variation (tolerance is linear)
    p = 100
    for i in range(10):
        tolerance[i/10] = p
        p += -5
    d1 = describe(a)
    d2 = describe(b)
    # print(str(datetime.datetime.now()) + '\t1', d1)
    # print(str(datetime.datetime.now()) + '\td2', d2)
    # print(str(datetime.datetime.now()) + '\tbegin')
    # counter, variance, mean
    c = 0
    v = -1
    m = -1
    a = []
    for i, j in zip(d1, d2):
        # add to output arrays
        desc_oref[desc_h[c]] = i
        desc_ocell[desc_h[c]] = j
        c += 1
    # print(str(datetime.datetime.now()) + '\toutputs', desc_ocell, desc_oref)
    # score based on tolerance
    c = 0
    for i in desc_ocell:
        percent_diff = 0
        # score outputs with multiple values (minmax)
        if type(desc_ocell[i]) == tuple:
            percent_diff = abs(float((list(desc_oref[i])[0] - list(desc_ocell[i])[0]) / list(desc_oref[i])[0]))
            percent_diff += abs(float((list(desc_oref[i])[1] - list(desc_ocell[i])[1]) / list(desc_oref[i])[1]))
            percent_diff /= 2
            print(str(datetime.datetime.now()) + '\ttuple', desc_oref[i], desc_ocell[i])
        # other cases (number of peaks, variance, mean)
        elif c != 0 or id == 'prominences':
            percent_diff = abs(float((desc_oref[i] - desc_ocell[i]) / desc_oref[i]))
            print(str(datetime.datetime.now()) + '\tother cases', desc_oref[i], desc_ocell[i])
        print(str(datetime.datetime.now()) + '\tpercent diff', percent_diff)
        c += 1
        # add to appropriate penalty to score
        if round(percent_diff, 1) in tolerance:
            add = tolerance[round(percent_diff, 1)]
        else:
            add = 0
        score += add
        print(str(datetime.datetime.now()) + '\tscore is', score, 'added', add)
    return score
def scoreIslet(folder):
    # get all scores of cells
    scores = []
    for i in os.listdir(os.getcwd()):
        if len(re.split('pl', i)) > 1 and '_score' in re.split('pl', i)[0]:
            [avg, score, id] = pickle.load(open(i, 'rb'))
            print(str(datetime.datetime.now()) + '\tavgs', avg, 'scores', scores, 'ids', id)
            scores.append(pickle.load(open(i, 'rb'))[0])
    print(str(datetime.datetime.now()) + '\tislet scores', scores)
    pickle.dump([sum(scores)/len(scores), scores, id], open('islet.pl', 'wb'))
def main():
    # read data
    data = 'data_1.csv'
    readData(data)
    ctypes = {'a': [], 'b': [], 'c': []}
    for i in os.listdir(os.getcwd()):
        if i[0] in ctypes and 'csv' in i:
            readCell(i)
            scoreRun(data, i)
    scoreIslet(os.getcwd())
main()