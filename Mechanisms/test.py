"""This script reads mechanisms to be added from 'mechs.ini' and 
initial values from 'Alpha.ini' and records simulation data in a csv"""
import configparser
import csv
import mod
import os
import ast

# read mechanism configuration files for cell types (mech.ini files)
config = configparser.ConfigParser(allow_no_value= True)
config.optionxform = str
config.read('mech.ini')

# Set up a .ini file to use at end of script to constrain the output in the csv files 
# to variables that change throughout the simulation and to not include constants
configc = configparser.ConfigParser(allow_no_value= True)
configc.optionxform = str
configc.read('constants.ini')


# set up mechanisms according to parameters for cell type (eg, beta.ini)

# Alpha mechanisms
mechsa = []
pointers = {'Alpha': {}, 'Beta': {}, 'Delta': {}}

for i in config['Alpha']:
    mechsa.append(i)
    if config['Alpha'][i] is not None:
        pointers['Alpha'][i] = ast.literal_eval(config['Alpha'][i])
    mod.writeMod('Alpha.ini', 'Alpha_'+i+'.mod')

# Beta mechanisms
mechsb = []
for i in config['Beta']:
    mechsb.append(i)
    if config['Beta'][i] is not None:
        pointers['Beta'][i] = ast.literal_eval(config['Beta'][i])
    mod.writeMod('Beta.ini', 'Beta_'+i+'.mod')

# Delta mechanisms
mechsd = []
for i in config['Delta']:
    mechsd.append(i)
    if config['Delta'][i] is not None:
        pointers['Delta'][i] = ast.literal_eval(config['Delta'][i])
    mod.writeMod('Delta.ini', 'Delta_'+i+'.mod')

# compile mod files
os.system('nrnivmodl *mod > compile 2>&1')


# create a section for each cell type and add all corresponding mechanisms
from neuron import h, gui

# Alpha cell
a = h.Section()
for i in mechsa:
    a.insert('A_'+i)
# simulation parameter
a.cm = 9990

# Beta cell
b = h.Section()
for i in mechsb:
    b.insert('B_'+i)
# simulation parameter
b.cm = 9990

# Delta cell
d = h.Section()
for i in mechsd:
    d.insert('D_'+i)
# simulation parameter
d.cm = 9990

# variables to store data
# Alpha
ta = []
va = []
reca = {}
headera = []

# Beta
tb = []
vb = []
recb = {}
headerb = []

# Delta
td = []
vd = []
recd = {}
headerd = []

# set pointers
mp = {'Alpha': a, "Beta": b, "Delta": d}
for i in pointers:
    for j in pointers[i]:
        for k in pointers[i][j]:
            for seg in mp[i]:
                temp = k.split('_')
                point_to = i[0].upper() + "_"+j
                point_from = "_ref_"+temp[0]+"_" + i[0].upper() + "_"+temp[2]
                print('create pointer which points from', point_from, 'to', temp[0], 'in', point_to)
                from_ = getattr(seg, point_from)
                to_ = getattr(seg, point_to)
                h.setpointer(from_, temp[0], to_)



# Record mechanisms
# Alpha
for i in a.psection()['density_mechs']:
    for j in a.psection()['density_mechs'][i]:
        headera.append(i+'_'+j)
        reca[str(i+'_'+j)] = []
        # record variables of every mechanism in every segment
        for k in a:
            va.append(h.Vector().record(k._ref_v))
            mechRecorda = getattr(k, '_ref_'+j+'_'+i)
            reca[str(i+'_'+j)].append(h.Vector().record(mechRecorda))

# Beta
for i in b.psection()['density_mechs']:
    for j in b.psection()['density_mechs'][i]:
        headerb.append(i+'_'+j)
        recb[str(i+'_'+j)] = []
        # record variables of every mechanism in every segment
        for k in b:
            vb.append(h.Vector().record(k._ref_v))
            mechRecordb = getattr(k, '_ref_'+j+'_'+i)
            recb[str(i+'_'+j)].append(h.Vector().record(mechRecordb))

# Delta
for i in d.psection()['density_mechs']:
    for j in d.psection()['density_mechs'][i]:
        headerd.append(i+'_'+j)
        recd[str(i+'_'+j)] = []
        # record variables of every mechanism in every segment
        for k in d:
            vd.append(h.Vector().record(k._ref_v))
            mechRecordd = getattr(k, '_ref_'+j+'_'+i)
            recd[str(i+'_'+j)].append(h.Vector().record(mechRecordd))

# connect cells
nc = {'AB': [], 'BA': [], 'AD': [], 'DA': [], 'BD': [], 'DB': []}

# # Delta to Alpha
# print('connect delta to alpha')
# syn = h.A_Syn(a(0))
# nc_temp = h.NetCon(d(1)._ref_t__D_Somatostatin, syn, 2, 0, 6, sec=d)
# nc_record = h.Vector()
# nc_temp.record(nc_record)
# nc['DA'].append(nc_record)
# # define pointers
# h.setpointer(d(1)._ref_Sst_D_Somatostatin, "Sst_send", syn)
# h.setpointer(a(0)._ref_Sst_A_Glucagon, "Sst_receive", syn)
# h.setpointer(d(1)._ref_temp_D_Somatostatin, "Ins_send", syn)
# h.setpointer(d(1)._ref_temp_D_Somatostatin, "Ins_receive", syn)

# Beta to Alpha
print('connect beta to alpha')
syn = h.A_Syn(a(0))
nc_temp = h.NetCon(b(1)._ref_t__B_Insulin, syn, 2, 0, 6, sec=b)
nc_record = h.Vector()
nc_temp.record(nc_record)
nc['BA'].append(nc_record)
# set pointers
h.setpointer(b(1)._ref_Ins_B_Insulin, "Ins_send", syn)
h.setpointer(a(0)._ref_Ins_A_Glucagon, "Ins_receive", syn)  
h.setpointer(b(1)._ref_temp_B_Insulin, "Sst_send", syn)
h.setpointer(b(1)._ref_temp_B_Insulin, "Sst_receive", syn)

# Alpha to Beta
print('connect alpha to beta')
syn = h.B_Syn(b(0))
nc_temp = h.NetCon(a(1)._ref_t__A_Glucagon, syn, 2, 0, 6, sec=a)
nc_record = h.Vector()
nc_temp.record(nc_record)
nc['AB'].append(nc_record)
# set pointers
h.setpointer(a(1)._ref_G_A_Glucagon, "Gluc_send", syn)
h.setpointer(b(0)._ref_G_B_Insulin, "Gluc_receive", syn)        
h.setpointer(a(1)._ref_temp_A_Glucagon, "Sst_send", syn)
h.setpointer(a(1)._ref_temp_A_Glucagon, "Sst_receive", syn)

# # Delta to Beta
# print('connect delta to beta')
# syn = h.B_Syn(b(0))
# nc_temp = h.NetCon(d(1)._ref_t__D_Somatostatin, syn, 2, 0, 6, sec=d)
# nc_record = h.Vector()
# nc_temp.record(nc_record)
# nc['DB'].append(nc_record)
# # set pointers
# h.setpointer(d(1)._ref_Sst_D_Somatostatin, "Sst_send", syn)
# h.setpointer(b(0)._ref_Sst_B_Insulin, "Sst_receive", syn)     
# h.setpointer(d(1)._ref_temp_D_Somatostatin, "Gluc_send", syn)
# h.setpointer(d(1)._ref_temp_D_Somatostatin, "Gluc_receive", syn)

# # Alpha to Delta
# print('connect alpha to delta')
# syn = h.D_Syn(d(0))
# nc_temp = h.NetCon(a(1)._ref_t__A_Glucagon, syn, 2, 0, 6, sec=a)
# nc_record = h.Vector()
# nc_temp.record(nc_record)
# nc['AD'].append(nc_record)
# # set pointers
# h.setpointer(a(1)._ref_G_A_Glucagon, "Gluc_send", syn)
# h.setpointer(d(0)._ref_G_D_Somatostatin, "Gluc_receive", syn)
# h.setpointer(a(1)._ref_temp_A_Glucagon, "Ins_send", syn)
# h.setpointer(a(1)._ref_temp_A_Glucagon, "Ins_receive", syn)

# # Beta to Delta
# print('connect beta to delta')
# syn = h.D_Syn(d(0))
# nc_temp = h.NetCon(b(1)._ref_t__B_Insulin, syn, 2, 0, 6, sec=b)
# nc_record = h.Vector()
# nc_temp.record(nc_record)
# nc['BD'].append(nc_record)
# # set pointers
# h.setpointer(b(1)._ref_Ins_B_Insulin, "Ins_send", syn)
# h.setpointer(d(0)._ref_Ins_D_Somatostatin, "Ins_receive", syn) 
# h.setpointer(b(1)._ref_temp_B_Insulin, "Gluc_send", syn)
# h.setpointer(b(1)._ref_temp_B_Insulin, "Gluc_receive", syn)

# fix header / record voltage of every segment for each cell type

# Alpha
heada = ['Time']
counta = 0
for i in a:
    tempa = 'VC'+str(counta)
    # ease writing to csv by keeping same format even though it is not necessary
    reca[tempa] = []
    reca[tempa].append(h.Vector().record(i._ref_v))
    counta += 1
heada.extend(headera)
heada.append(tempa)

# Beta
headb = ['Time']
countb = 0
for i in b:
    tempb = 'VC'+str(countb)
    # ease writing to csv by keeping same format even though it is not necessary
    recb[tempb] = []
    recb[tempb].append(h.Vector().record(i._ref_v))
    countb += 1
headb.extend(headerb)
headb.append(tempb)

# Delta
headd = ['Time']
countd = 0
for i in d:
    tempd = 'VC'+str(countd)
    # ease writing to csv by keeping same format even though it is not necessary
    recd[tempd] = []
    recd[tempd].append(h.Vector().record(i._ref_v))
    countd += 1
headd.extend(headerd)
headd.append(tempd)

t = h.Vector().record(h._ref_t)
print('initialize')
h.finitialize()
print('simulate')
h.continuerun(2500)

# Write results to 3 csv's. One for each cell type
print('write data')
# Alpha
with open('data/watts_Alpha.csv','w') as file:
    writer = csv.writer(file,quoting = csv.QUOTE_NONE,escapechar=' ')
    writer.writerow(heada)
    for i in range(len(t)):
        out = [t[i]]
        for q in reca:
            if q not in configc['Alpha']: 
                out.append(reca[q][0][i])
        # print(len(rec), len(out), len(header))
        writer.writerow(out)

# Beta
with open('data/watts_Beta.csv','w') as file:
    writer = csv.writer(file,quoting = csv.QUOTE_NONE,escapechar=' ')
    writer.writerow(headb)
    for i in range(len(t)):
        out = [t[i]]
        for q in recb:
            if q not in configc['Beta']: 
                out.append(recb[q][0][i])
        # print(len(rec), len(out), len(header))
        writer.writerow(out)

# Delta
with open('data/watts_Delta.csv','w') as file:
    writer = csv.writer(file,quoting = csv.QUOTE_NONE,escapechar=' ')
    writer.writerow(headd)
    for i in range(len(t)):
        out = [t[i]]
        for q in recd:
            if q not in configc['Delta']: 
                out.append(recd[q][0][i])
        # print(len(rec), len(out), len(header))
        writer.writerow(out)

# Netcon
m = 0
for i in nc:
    if len(nc[i]) > 1 and len(nc[i][0]) > m:
        m = len(nc[i][0])
    print(m, 'm')
headnet = ['DA', 'BA', 'AB', 'DB', 'AD', 'BD']

with open('data/netcon.csv', 'w') as file:
    writer = csv.writer(file,quoting = csv.QUOTE_NONE,escapechar=' ')
    writer.writerow(headnet)
    for i in range(m):
        out = []
        for j in nc:
            if len(nc[j][0]) > i:
                out.append(nc[j][0][i])
        writer.writerow(out)