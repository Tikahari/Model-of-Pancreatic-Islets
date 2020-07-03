"""This script reads mechanisms to be added from 'mechs.ini', initial values from 'Beta.ini' and records simulation data in a csv"""
import configparser
import csv
import mod
import os
import sys
import ast
import datetime

# read mechanism configuration (mech.ini)
config = configparser.ConfigParser(allow_no_value= True)
config.optionxform = str
config.read('mech.ini')
# set up mechanisms according to parameters for cell type (Beta.ini)
mechs = []
pointers = {}
for i in config['Beta']:
    mechs.append(i)
    if config['Beta'][i] is not None:
        pointers[i] = ast.literal_eval(config['Beta'][i])
    mod.writeMod('Beta.ini', 'Beta_'+i+'.mod')
# compile mod files
os.system('nrnivmodl *mod > compile 2>&1')
# variables to store data
t = []
v = []
rec = {}
header = []

print(str(datetime.datetime.now()) + '\tcreating section')
# create section and add all mechanisms
from neuron import h, gui
a = h.Section()
for i in mechs:
    a.insert('B_'+i)
# simulation parameter
a.cm = 9990000
print(str(datetime.datetime.now()) + '\tsetting pointers')
# set pointers
for i in pointers:
    for j in pointers[i]:
        for k in a:
            temp = j.split('_')
            point_to = "B_"+i
            point_from = "_ref_"+temp[0]+"_B_"+temp[2]
            print(str(datetime.datetime.now()) + '\t' + point_to, "points to", point_from)
            from_ = getattr(k, point_from)
            to_ = getattr(k, point_to)
            h.setpointer(from_, temp[2], to_)

# a.nseg = 5
# record mechanisms
print(str(datetime.datetime.now()) + '\tsetting recording variables')
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
    rec[temp] = []
    rec[temp].append(h.Vector().record(i._ref_v))
    count += 1
head.extend(header)
head.append(temp)

t = h.Vector().record(h._ref_t)
print(str(datetime.datetime.now()) + '\trunning simulation')
h.finitialize(-62)
h.continuerun(5000)
print(str(datetime.datetime.now()) + '\twriting data')
with open('data/'+sys.argv[1],'w') as file:
    writer = csv.writer(file,quoting = csv.QUOTE_NONE,escapechar=' ')
    writer.writerow(head)
    for i in range(len(t)):
        out = [t[i]]
        for q in rec:
            out.append(rec[q][0][i])
        # print(len(rec), len(out), len(header))
        writer.writerow(out)
print(str(datetime.datetime.now()) + '\tcomplete')
