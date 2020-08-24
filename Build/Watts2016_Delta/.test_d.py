"""This script reads mechanisms to be added from 'mechs.ini' and 
initial values from 'Alpha.ini' and records simulation data in a csv"""
import configparser
import csv
import mod
import os
import ast
import datetime
from matplotlib import pyplot
import sys
import re

# read mechanism configuration files for cell types (mech.ini files)
config = configparser.ConfigParser(allow_no_value= True)
config.optionxform = str
config.read('mechd.ini')

# Set up a .ini file to use at end of script to constrain the output in the csv files 
# to variables that change throughout the simulation and to not include constants
configc = configparser.ConfigParser(allow_no_value= True)
configc.optionxform = str
configc.read('constants.ini')


# set up mechanisms according to parameters for cell type (eg, beta.ini)
mechs = {'Alpha': [], 'Beta': [], 'Delta': []}


# # Alpha mechanisms
# mechsa = {}
pointers = {'Alpha': {}, 'Beta': {}, 'Delta': {}}

cells = {"Alpha", "Beta", "Delta"}
for i in config:
    for j in config[i]:
        mechs[i].append(j)
        if config[i][j] is not None:
            pointers[i][j] = ast.literal_eval(config[i][j])
        # mod.writeMod(i + '.ini', i + '_' + j + '.mod')

# create a section for each cell type and add all corresponding mechanisms
from neuron import h, rxd
h.load_file('stdrun.hoc')

# Alpha cell
d = h.Section('delta')
d.pt3dadd(-20,0,0,10)
d.pt3dadd(-10,0,0,10)
for i in mechs['Delta']:
    print(str(datetime.datetime.now()) + '\tinsert D_' + i)
    d.insert('D_'+i)

# print(str(datetime.datetime.now()) + '\tinsert watts_delta_v')
# d.insert('watts_delta_v')
# simulation parameter
d.cm = 5e6
print(str(datetime.datetime.now()) + '\td.cm ', d.cm)

# add point processes
# gluc_syn = h.A_Glucagon(a(0.5))
sst_syn = h.D_Somatostatin(d(0.5))
h.setpointer(d(0.5)._ref_mcapqd_D_CaPQ, "mcapqd", sst_syn)
h.setpointer(d(0.5)._ref_hcapqd_D_CaPQ, "hcapqd", sst_syn)

# ins_syn = h.B_Insulin(b(0.5))
pp = [sst_syn]

# syn = h.IClamp(a(0))
# syn.amp = 999
# syn.dur = 1
# syn.delay = 1000

# Alpha
ta = []
va = []
recd = {}
headerd = []


print(str(datetime.datetime.now()) + '\tset pointers')
# set pointers
mp = {"Delta": d}
for i in pointers:
    for j in pointers[i]:
        for k in pointers[i][j]:
            print(i,j,k)
            for seg in mp[i]:
                temp = k.split('_')
                point_to = i[0].upper() + "_" + j
                point_from = "_ref_"+temp[0]
                print(str(datetime.datetime.now()) + '\t' + point_to + "_" + temp[0],  "points to", point_from)
                from_ = getattr(sst_syn, point_from)
                to_ = getattr(seg, point_to)
                h.setpointer(from_, temp[0], to_)


print(str(datetime.datetime.now()) + '\tset recording variables')
# Record mechanisms
# Delta
for i in d.psection()['density_mechs']:
    for j in d.psection()['density_mechs'][i]:
        if j not in configc['Delta']:
            headerd.append(i+'_'+j)
            recd[str(i+'_'+j)] = []
            # record variables of every mechanism in every segment
            for k in d:
                va.append(h.Vector().record(k._ref_v))
                mechRecorda = getattr(k, '_ref_'+j+'_'+i)
                recd[str(i+'_'+j)].append(h.Vector().record(mechRecorda))
                print(str(datetime.datetime.now()) + '\tdelta mechanisms record ' + i + '_' + j)

exclude = ['loc', 'get_segment', 'Sstpnt']
_exclude = True
# point processes
pp_names = ['pp_somatostatin']
for i, n in zip(pp, pp_names):
    for j in vars(i):
        print(i, n, j)
        _exclude = True
        for ex in exclude:
            if ex in j:
                print('ex in j', ex, j)
                _exclude = False
        if(_exclude):
            headerd.append(n+'_'+j)
            molecule = getattr(i, '_ref_' + j)
            recd[str(n + '_' + j)] = []
            recd[str(n + '_' + j)].append(h.Vector().record(molecule))
            print(str(datetime.datetime.now()) + '\tpoint process record ' + n + '_' + j)


# set up rxd

# the intracellular spaces
cyt = rxd.Region(h.allsec(), name='cyt', nrn_region='i')

# plasma membrane 
mem = rxd.Region(h.allsec(), name='mem', geometry=rxd.membrane)

# the extracellular space
ecs = rxd.Extracellular(-20, -5, -5, 45, 5, 5, dx=1, volume_fraction=0.2, tortuosity=1.6)

# glucagon
glucagon = rxd.Species([cyt, ecs], name='glucagon', charge=1, d=1.0, initial=lambda nd: 31 if hasattr(nd, 'sec') and nd.segment in d else 0)
gcyt = glucagon[cyt]
gecs = glucagon[ecs]

# somatostatin
sst = rxd.Species([cyt, ecs], name='sst', charge=1, d=1.0, initial=lambda nd: 250 if hasattr(nd, 'sec') and nd.segment in d else 0)
sstcyt = sst[cyt]
sstecs = sst[ecs]

# insulin
insulin = rxd.Species([cyt, ecs], name='insulin', charge=1, d=1.0, initial=lambda nd: 48 if hasattr(nd, 'sec') and nd.segment in d else 0)
inscyt = insulin[cyt]
insecs = insulin[ecs]


# production
gluc_param = rxd.Parameter(cyt, initial=lambda node: 1.0 if node.segment.sec == d else 0)
createX = rxd.Rate(gcyt, gluc_param[cyt] * 1.0/(10.0 + gcyt))


# uptake and release
R = 1e1     # release rate [molecules per square micron per ms]
U = 1e1     # uptake rate [molecules per square micron per ms]


rrateg = R*gcyt     
urateg = U*gecs     
glucagon_release = rxd.MultiCompartmentReaction(gcyt, gecs, rrateg, urateg,
                                                membrane=mem, 
                                                custom_dynamics=True)


rratei = R*inscyt     
uratei = U*insecs     
insulin_release = rxd.MultiCompartmentReaction(inscyt, insecs, rratei, uratei,
                                                membrane=mem, 
                                                custom_dynamics=True)

rrates = R*sstcyt    
urates = U*sstecs     
somatostatin_release = rxd.MultiCompartmentReaction(sstcyt, sstecs, rrates, urates,
                                                membrane=mem, 
                                                custom_dynamics=True)
h.setpointer(sst.nodes[0]._ref_concentration, 'Sstpnt', sst_syn)

# record the concentrations in the cells
t_vec = h.Vector()
t_vec.record(h._ref_t)

gl_cell1 = h.Vector().record(d(0.5)._ref_glucagoni)
gl_ecs = h.Vector().record(gecs.node_by_location(0,0,0)._ref_concentration)

ins_cell1 = h.Vector().record(d(0.5)._ref_insulini)
ins_ecs = h.Vector().record(insecs.node_by_location(0,0,0)._ref_concentration)

sst_cell1 = h.Vector().record(d(0.5)._ref_ssti)
sst_ecs = h.Vector().record(sstecs.node_by_location(0,0,0)._ref_concentration)

recd['sst_ecs'] = []
recd['sst_ecs'].append(sst_ecs)
headerd.append('sst_ecs')

recd['sst_cyt'] = []
recd['sst_cyt'].append(sst_cell1)
headerd.append('sst_cyt')

recd['gl_ecs'] = []
recd['gl_ecs'].append(gl_ecs)
headerd.append('gl_ecs')

recd['gl_cyt'] = []
recd['gl_cyt'].append(gl_cell1)
headerd.append('gl_cyt')

recd['ins_ecs'] = []
recd['ins_ecs'].append(ins_ecs)
headerd.append('ins_ecs')

recd['ins_cyt'] = []
recd['ins_cyt'].append(ins_cell1)
headerd.append('ins_cyt')

# Alpha
headd = ['Time']
counta = 0
for i in d:
    tempa = 'VC'+str(counta)
    # ease writing to csv by keeping same format even though it is not necessary
    recd[tempa] = []
    recd[tempa].append(h.Vector().record(i._ref_v))
    counta += 1
headd.extend(headerd)
headd.append(tempa)

# set initial membrane potential
d.v = 0

t = h.Vector().record(h._ref_t)
print(str(datetime.datetime.now()) + '\tinitialize')
h.finitialize()
print(str(datetime.datetime.now()) + '\tsimulate')
h.continuerun(2000)

# Write results to 3 csv's. One for each cell type
print(str(datetime.datetime.now()) + '\twrite data')
# Alpha
with open('data/watts_Delta.csv','w') as file:
    writer = csv.writer(file,quoting = csv.QUOTE_NONE,escapechar=' ')
    writer.writerow(headd)
    for i in range(len(t)):
        out = [t[i]]
        for q in recd:
            out.append(recd[q][0][i])
        # print(len(rec), len(out), len(header))
        writer.writerow(out)
print(str(datetime.datetime.now()) + '\twrote delta')