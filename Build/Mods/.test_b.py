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
config.read('mechb.ini')

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

# Beta cell
b = h.Section('beta')
b.pt3dadd(-20,0,0,10)
b.pt3dadd(-10,0,0,10)
# for i in mechs['Beta']:
#     print(str(datetime.datetime.now()) + '\tinsert B_' + i)
#     b.insert('B_'+i)
print(str(datetime.datetime.now()) + '\tinsert watts_beta')
b.insert('watts_beta')
# simulation parameter
b.cm = 1
print(str(datetime.datetime.now()) + '\tb.cm ', b.cm)

# add point processes
# ins_syn = h.B_Insulin(a(0.5))
# sst_syn = h.D_Somatostatin(d(0.5))
# ins_syn = h.B_Insulin(b(0.5))
# pp = [ins_syn]

# syn = h.IClamp(a(0))
# syn.amp = 999
# syn.dur = 1
# syn.delay = 1000

# Alpha
ta = []
va = []
recb = {}
headerb = []


# print(str(datetime.datetime.now()) + '\tset pointers')
# # set pointers
# mp = {'Beta': ins_syn}
# for i in pointers:
#     for j in pointers[i]:
#         for k in pointers[i][j]:
#             print(i,j,k)
#             # for seg in mp[i]:
#             temp = k.split('_')
#             point_to = i[0].upper() + "_" + j
#             point_from = "_ref_"+temp[0]
#             print(str(datetime.datetime.now()) + '\t' + point_to + "_" + temp[0],  "points to", point_from)
#             from_ = getattr(ins_syn, point_from)
#             to_ = getattr(b(0.5), point_to)
#             h.setpointer(from_, temp[0], to_)


print(str(datetime.datetime.now()) + '\tset recording variables')
# Record mechanisms
# Beta
for i in b.psection()['density_mechs']:
    for j in b.psection()['density_mechs'][i]:
        if j not in configc['Beta']:
            headerb.append(i+'_'+j)
            recb[str(i+'_'+j)] = []
            # record variables of every mechanism in every segment
            for k in b:
                va.append(h.Vector().record(k._ref_v))
                mechRecorda = getattr(k, '_ref_'+j+'_'+i)
                recb[str(i+'_'+j)].append(h.Vector().record(mechRecorda))
                print(str(datetime.datetime.now()) + '\tbeta mechanisms record ' + i + '_' + j)

exclude = ['loc', 'get_segment', 'Inspnt']
_exclude = True
# point processes
# pp_names = ['pp_insulin']
# for i, n in zip(pp, pp_names):
#     for j in vars(i):
#         print(i, n, j)
#         _exclude = True
#         for ex in exclude:
#             if ex in j:
#                 print('ex in j', ex, j)
#                 _exclude = False
#         if(_exclude):
#             headerb.append(n+'_'+j)
#             molecule = getattr(i, '_ref_' + j)
#             recb[str(n + '_' + j)] = []
#             recb[str(n + '_' + j)].append(h.Vector().record(molecule))
#             print(str(datetime.datetime.now()) + '\tpoint process record ' + n + '_' + j)


# # set up rxd

# # the intracellular spaces
# cyt = rxd.Region(h.allsec(), name='cyt', nrn_region='i')

# # plasma membrane 
# mem = rxd.Region(h.allsec(), name='mem', geometry=rxd.membrane)

# # the extracellular space
# ecs = rxd.Extracellular(-20, -5, -5, 45, 5, 5, dx=1, volume_fraction=0.2, tortuosity=1.6)

# # glucagon
# glucagon = rxd.Species([cyt, ecs], name='glucagon', charge=0, d=1.0, initial=lambda nd: 31 if hasattr(nd, 'sec') and nd.segment in b else 0)
# gcyt = glucagon[cyt]
# gecs = glucagon[ecs]

# # somatostatin
# sst = rxd.Species([cyt, ecs], name='sst', charge=1, d=1.0, initial=lambda nd: 19 if hasattr(nd, 'sec') and nd.segment in b else 0)
# sstcyt = sst[cyt]
# sstecs = sst[ecs]

# # insulin
# insulin = rxd.Species([cyt, ecs], name='insulin', charge=0, d=1.0, initial=lambda nd: 48 if hasattr(nd, 'sec') and nd.segment in b else 0)
# inscyt = insulin[cyt]
# insecs = insulin[ecs]


# # production
# gluc_param = rxd.Parameter(cyt, initial=lambda node: 1.0 if node.segment.sec == b else 0)
# createX = rxd.Rate(gcyt, gluc_param[cyt] * 1.0/(10.0 + gcyt))


# # uptake and release
# R = 1e1     # release rate [molecules per square micron per ms]
# U = 1e1     # uptake rate [molecules per square micron per ms]


# rrateg = R*gcyt     
# urateg = U*gecs     
# glucagon_release = rxd.MultiCompartmentReaction(gcyt, gecs, rrateg, urateg,
#                                                 membrane=mem, 
#                                                 custom_dynamics=True)


# rratei = R*inscyt     
# uratei = U*insecs     
# insulin_release = rxd.MultiCompartmentReaction(inscyt, insecs, rratei, uratei,
#                                                 membrane=mem, 
#                                                 custom_dynamics=True)
# h.setpointer(insulin.nodes[0]._ref_concentration, 'Inspnt', ins_syn)


# rrates = R*sstcyt    
# urates = U*sstecs     
# somatostatin_release = rxd.MultiCompartmentReaction(sstcyt, sstecs, rrates, urates,
#                                                 membrane=mem, 
#                                                 custom_dynamics=True)


# # record the concentrations in the cells
# t_vec = h.Vector()
# t_vec.record(h._ref_t)

# gl_cell1 = h.Vector().record(b(0.5)._ref_glucagoni)
# gl_ecs = h.Vector().record(gecs.node_by_location(0,0,0)._ref_concentration)

# ins_cell1 = h.Vector().record(b(0.5)._ref_insulini)
# ins_ecs = h.Vector().record(insecs.node_by_location(0,0,0)._ref_concentration)

# sst_cell1 = h.Vector().record(b(0.5)._ref_ssti)
# sst_ecs = h.Vector().record(sstecs.node_by_location(0,0,0)._ref_concentration)

# recb['sst_ecs'] = []
# recb['sst_ecs'].append(sst_ecs)
# headerb.append('sst_ecs')

# recb['sst_cyt'] = []
# recb['sst_cyt'].append(sst_cell1)
# headerb.append('sst_cyt')

# recb['gl_ecs'] = []
# recb['gl_ecs'].append(gl_ecs)
# headerb.append('gl_ecs')

# recb['gl_cyt'] = []
# recb['gl_cyt'].append(gl_cell1)
# headerb.append('gl_cyt')

# recb['ins_ecs'] = []
# recb['ins_ecs'].append(ins_ecs)
# headerb.append('ins_ecs')

# recb['ins_cyt'] = []
# recb['ins_cyt'].append(ins_cell1)
# headerb.append('ins_cyt')

# Alpha
headb = ['Time']
counta = 0
for i in b:
    tempa = 'VC'+str(counta)
    # ease writing to csv by keeping same format even though it is not necessary
    recb[tempa] = []
    recb[tempa].append(h.Vector().record(i._ref_v))
    counta += 1
headb.extend(headerb)
headb.append(tempa)

t = h.Vector().record(h._ref_t)
print(str(datetime.datetime.now()) + '\tinitialize')
h.finitialize()
print(str(datetime.datetime.now()) + '\tsimulate')
h.continuerun(2000)

# Write results to 3 csv's. One for each cell type
print(str(datetime.datetime.now()) + '\twrite data')
# Alpha
with open('data/watts_Beta.csv','w') as file:
    writer = csv.writer(file,quoting = csv.QUOTE_NONE,escapechar=' ')
    writer.writerow(headb)
    for i in range(len(t)):
        out = [t[i]]
        for q in recb:
            out.append(recb[q][0][i])
        # print(len(rec), len(out), len(header))
        writer.writerow(out)
print(str(datetime.datetime.now()) + '\twrote beta')