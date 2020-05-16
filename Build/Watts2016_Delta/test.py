"""This script reads mechanisms to be added from 'mechs.ini' and 
initial values from 'Delta.ini' and records simulation data in a csv"""
import configparser
import csv
import mod
import os
# read mechanism configuration (mech.ini)
config = configparser.ConfigParser(allow_no_value= True)
config.optionxform = str
config.read('mech.ini')
# set up mechanisms according to parameters for cell type (Beta.ini)
mechs = []
for i in config['Delta']:
    mechs.append(i)
    mod.writeMod('Delta.ini', 'Delta_'+i+'.mod')
# compile mod files
os.system('nrnivmodl *mod > compile 2>&1')
# variables to store data
t = []
v = []
rec = {}
header = []

# create section and add all mechanisms
from neuron import h, gui
a = h.Section()
for i in mechs:
    a.insert('D_'+i)
# simulation parameter
a.cm = 9990

# a.nseg = 5

# set pointers for appropriate mechanisms
# for k in a:
#     h.setpointer(k._ref_S_A_GIRK, 'S', k._ref_v)
#     h.setpointer(k._ref_I_A_KATP, 'I', k._ref_v)

# record mechanisms
for i in a.psection()['density_mechs']:
    for j in a.psection()['density_mechs'][i]:
        header.append(i+'_'+j)
        rec[j] = []
        # record variables of every mechanism in every segment
        for k in a:
            v.append(h.Vector().record(k._ref_v))
            mechRecord = getattr(k, '_ref_'+j+'_'+i)
            rec[j].append(h.Vector().record(mechRecord))

# fix header / record voltage of every segment
head = ['Time']
count = 0
for i in a:
    temp = 'VC'+str(count)
    # ease writing to csv by keeping same format even though it is not necessary
    # rec[temp] = []
    # rec[temp].append(h.Vector().record(i._ref_v))
    head.append(temp)
    count += 1
head.extend(header)

t = h.Vector().record(h._ref_t)
h.finitialize(-62)
h.continuerun(200)

with open('data/watts.csv','w') as file:
    writer = csv.writer(file,quoting = csv.QUOTE_NONE,escapechar=' ')
    writer.writerow(head)
    for i in range(len(t)):
        rec_csv = ''
        for j in rec:
            rec_csv += str(rec[j][0][i]) +','
        rec_csv = rec_csv[:len(rec_csv)-1] + ' '
        writer.writerow([t[i], v[0][i], rec_csv])