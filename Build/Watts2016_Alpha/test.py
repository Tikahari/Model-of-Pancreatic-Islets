"""This script reads mechanisms to be added from 'mechs.ini' and 
initial values from 'Alpha.ini' and records simulation data in a csv"""
import configparser
import csv
import mod
import os
import datetime

# read mechanism configuration (mech.ini)
config = configparser.ConfigParser(allow_no_value= True)
config.optionxform = str
config.read('mech.ini')
# set up mechanisms according to parameters for cell type (Beta.ini)
mechs = []
for i in config['Alpha']:
    mechs.append(i)
    mod.writeMod('Alpha.ini', 'Alpha_'+i+'.mod')
# compile mod files
os.system('nrnivmodl *mod > compile 2>&1')
# variables to store data
t = []
v = []
rec = {}
header = []

print(str(datetime.datetime.now()) + '\tadd mechanims')
# create section and add all mechanisms
from neuron import h, gui
a = h.Section()
for i in mechs:
    a.insert('A_'+i)
# simulation parameter
a.cm = 9990

# a.nseg = 5

# set pointers for appropriate mechanisms
# for k in a:
#     h.setpointer(k._ref_S_A_GIRK, 'S', k._ref_v)
#     h.setpointer(k._ref_I_A_KATP, 'I', k._ref_v)
print(str(datetime.datetime.now()) + '\tset recording variables')
# record mechanisms
for i in a.psection()['density_mechs']:
    for j in a.psection()['density_mechs'][i]:
        header.append(i+'_'+j)
        rec[str(i+'_'+j)] = []
        # record variables of every mechanism in every segment
        for k in a:
            v.append(h.Vector().record(k._ref_v))
            mechRecord = getattr(k, '_ref_'+j+'_'+i)
            rec[str(i+'_'+j)].append(h.Vector().record(mechRecord))

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
print(str(datetime.datetime.now()) + '\tinitialize')
h.finitialize(-62)
print(str(datetime.datetime.now()) + '\tsimulate')
h.continuerun(200)

print(str(datetime.datetime.now()) + '\twrite data')
with open('data/watts.csv','w') as file:
    writer = csv.writer(file,quoting = csv.QUOTE_NONE,escapechar=' ')
    writer.writerow(head)
    for i in range(len(t)):
        out = [t[i]]
        for q in rec:
            out.append(rec[q][0][i])
        # print(len(rec), len(out), len(header))
        writer.writerow(out)
print(str(datetime.datetime.now()) + '\tcompleted')
