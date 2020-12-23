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
config.read('mech.ini')

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

# for i in config['Alpha']:
#     mechsa.append(i)
#     if config['Alpha'][i] is not None:
#         pointers['Alpha'][i] = ast.literal_eval(config['Alpha'][i])
#     mod.writeMod('Alpha.ini', 'Alpha_'+i+'.mod')

# # Beta mechanisms
# mechsb = []
# for i in config['Beta']:
#     mechsb.append(i)
#     if config['Beta'][i] is not None:
#         pointers['Beta'][i] = ast.literal_eval(config['Beta'][i])
#     mod.writeMod('Beta.ini', 'Beta_'+i+'.mod')

# # Delta mechanisms
# mechsd = []
# for i in config['Delta']:
#     mechsd.append(i)
#     if config['Delta'][i] is not None:
#         pointers['Delta'][i] = ast.literal_eval(config['Delta'][i])
#     mod.writeMod('Delta.ini', 'Delta_'+i+'.mod')

cells = {"Alpha", "Beta", "Delta"}
for i in config:
    for j in config[i]:
        mechs[i].append(j)
        if config[i][j] is not None:
            pointers[i][j] = ast.literal_eval(config[i][j])
        # mod.writeMod(i + '.ini', i + '_' + j + '.mod')


# compile mod files
os.system('nrnivmodl *mod > compile 2>&1')


# create a section for each cell type and add all corresponding mechanisms
from neuron import h, rxd
h.load_file('stdrun.hoc')

# Alpha cell
a = h.Section('alpha')
a.pt3dadd(-20,0,0,10)
a.pt3dadd(-10,0,0,10)
for i in mechs['Alpha']:
    a.insert('A_'+i)
# simulation parameter
a.cm = 9000

# Beta cell
b = h.Section('beta')
b.pt3dadd(30,0,0,15)
b.pt3dadd(45,0,0,15)
for i in mechs['Beta']:
    b.insert('B_'+i)
# simulation parameter
b.cm = 9990000

# Delta cell
d = h.Section('delta')
d.pt3dadd(0,0,0,15)
d.pt3dadd(15,0,0,15)
for i in mechs['Delta']:
    d.insert('D_'+i)


# add point processes
gluc_syn = h.A_Glucagon(a(0.5))
# sst_syn = h.D_Somatostatin(d(0.5))
# ins_syn = h.B_Insulin(b(0.5))
pp = [gluc_syn]

# simulation parameter
d.cm = 9000


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

print(str(datetime.datetime.now()) + '\tset pointers')
# set pointers
mp = {'Alpha': a, "Beta": b, "Delta": d}
for i in pointers:
    for j in pointers[i]:
        for k in pointers[i][j]:
            for seg in mp[i]:
                temp = k.split('_')
                point_to = i[0].upper() + "_" + j
                point_from = "_ref_"+temp[0]+"_" + i[0].upper() + "_"+temp[2]
                print(str(datetime.datetime.now()) + '\t' + point_to, "points to", point_from)
                from_ = getattr(seg, point_from)
                to_ = getattr(seg, point_to)
                h.setpointer(from_, temp[0], to_)


print(str(datetime.datetime.now()) + '\tset recording variables')
# Record mechanisms
# Alpha
for i in a.psection()['density_mechs']:
    for j in a.psection()['density_mechs'][i]:
        if j not in configc['Alpha']:
            headera.append(i+'_'+j)
            reca[str(i+'_'+j)] = []
            # record variables of every mechanism in every segment
            for k in a:
                va.append(h.Vector().record(k._ref_v))
                mechRecorda = getattr(k, '_ref_'+j+'_'+i)
                reca[str(i+'_'+j)].append(h.Vector().record(mechRecorda))
                print(str(datetime.datetime.now()) + '\talpha mechanisms record ' + i + '_' + j)
# # ions
# for i in a.psection()['ions']:
#     for j in a.psection()['ions'][i]:
#         for z in a.psection()['ions'][i][j]:
#             print(i, j, z)
#             headera.append(i+'_'+j)
#             reca[str(i+'_'+j)] = []
#             # record variables of every mechanism in every segment
#             for k in a:
#                 mechRecord_i = getattr(k, '_ref_'+i+'i')
#                 mechRecord_o = getattr(k, '_ref_'+i+'o')
#                 reca[str(i+'_'+j)].append(h.Vector().record(mechRecord_i))
#                 reca[str(i+'_'+j)].append(h.Vector().record(mechRecord_o))
#                 print(str(datetime.datetime.now()) + '\talpha ions record ' + i + '_' + j)

# Beta
for i in b.psection()['density_mechs']:
    for j in b.psection()['density_mechs'][i]:
        if j not in configc['Beta']:
            headerb.append(i+'_'+j)
            recb[str(i+'_'+j)] = []
            # record variables of every mechanism in every segment
            for k in b:
                vb.append(h.Vector().record(k._ref_v))
                mechRecordb = getattr(k, '_ref_'+j+'_'+i)
                recb[str(i+'_'+j)].append(h.Vector().record(mechRecordb))
                print(str(datetime.datetime.now()) + '\tbeta mechanisms record ' + i + '_' + j)
# # ions
# for i in b.psection()['ions']:
#     for j in b.psection()['ions'][i]:
#         for z in b.psection()['ions'][i][j]:
#             headerb.append(i+'_'+j)
#             recb[str(i+'_'+j)] = []
#             # record variables of every mechanism in every segment
#             for k in b:
#                 mechRecord_i = getattr(k, '_ref_'+i+'i')
#                 mechRecord_o = getattr(k, '_ref_'+i+'o')
#                 recb[str(i+'_'+j)].append(h.Vector().record(mechRecord_i))
#                 recb[str(i+'_'+j)].append(h.Vector().record(mechRecord_o))
#                 print(str(datetime.datetime.now()) + '\tbeta ions record ' + i + '_' + j)

# Delta
for i in d.psection()['density_mechs']:
    for j in d.psection()['density_mechs'][i]:
        if j not in configc['Delta']:
            headerd.append(i+'_'+j)
            recd[str(i+'_'+j)] = []
            # record variables of every mechanism in every segment
            for k in d:
                vd.append(h.Vector().record(k._ref_v))
                mechRecordd = getattr(k, '_ref_'+j+'_'+i)
                recd[str(i+'_'+j)].append(h.Vector().record(mechRecordd))
                print(str(datetime.datetime.now()) + '\tdelta mechanisms record ' + i + '_' + j)
# # ions
# for i in d.psection()['ions']:
#     for j in d.psection()['ions'][i]:
#         for z in d.psection()['ions'][i][j]:
#             headerd.append(i+'_'+j)
#             recd[str(i+'_'+j)] = []
#             # record variables of every mechanism in every segment
#             for k in d:
#                 mechRecord_i = getattr(k, '_ref_'+i+'i')
#                 mechRecord_o = getattr(k, '_ref_'+i+'o')
#                 recd[str(i+'_'+j)].append(h.Vector().record(mechRecord_i))
#                 recd[str(i+'_'+j)].append(h.Vector().record(mechRecord_o))
#                 print(str(datetime.datetime.now()) + '\tdelta ions record ' + i + '_' + j)

# point processes
pp_names = ['pp_glucagon']
for i, n in zip(pp, pp_names):
    for j in vars(i):
        print(i, n, j, k)
        if('loc' not in j and 'get_segment' not in j):
            headera.append(n+'_'+j)
            molecule = getattr(i, '_ref_' + j)
            reca[str(n + '_' + j)] = []
            reca[str(n + '_' + j)].append(h.Vector().record(molecule))
            print(str(datetime.datetime.now()) + '\tpoint process record ' + n + '_' + j)

# set up rxd

# the intracellular spaces
cyt = rxd.Region(h.allsec(), name='cyt', nrn_region='i')

# plasma membrane 
mem = rxd.Region(h.allsec(), name='mem', geometry=rxd.membrane)

# the extracellular space
ecs = rxd.Extracellular(-20, -5, -5, 45, 5, 5, dx=1, volume_fraction=0.2, tortuosity=1.6)

# glucagon
glucagon = rxd.Species([cyt, ecs], name='glucagon', charge=0, d=1.0, initial=lambda nd: 31 if hasattr(nd, 'sec') and nd.segment in a else 0)
gcyt = glucagon[cyt]
gecs = glucagon[ecs]

# somatostatin
sst = rxd.Species([cyt, ecs], name='sst', charge=1, d=1.0, initial=lambda nd: 19 if hasattr(nd, 'sec') and nd.segment in d else 0)
sstcyt = sst[cyt]
sstecs = sst[ecs]

# insulin
insulin = rxd.Species([cyt, ecs], name='insulin', charge=0, d=1.0, initial=lambda nd: 48 if hasattr(nd, 'sec') and nd.segment in b else 0)
inscyt = insulin[cyt]
insecs = insulin[ecs]

# production
gluc_param = rxd.Parameter(cyt, initial=lambda node: 1.0 if node.segment.sec == a else 0)
createX = rxd.Rate(gcyt, gluc_param[cyt] * 1.0/(10.0 + gcyt))

ins_param = rxd.Parameter(cyt, initial=lambda node: 1.0 if node.segment.sec == b else 0)
createX = rxd.Rate(inscyt, ins_param[cyt] * 1.0/(10.0 + inscyt))

sst_param = rxd.Parameter(cyt, initial=lambda node: 1.0 if node.segment.sec == d else 0)
createX = rxd.Rate(sstcyt, sst_param[cyt] * 1.0/(10.0 + sstcyt))


# uptake and release
R = 1e1     # release rate [molecules per square micron per ms]
U = 1e1     # uptake rate [molecules per square micron per ms]


rrateg = R*gcyt     
urateg = U*gecs     
glucagon_release = rxd.MultiCompartmentReaction(gcyt, gecs, rrateg, urateg,
                                                membrane=mem, 
                                                custom_dynamics=True)
h.setpointer(glucagon.nodes[0]._ref_concentration, 'JGS', gluc_syn)
h.setpointer(a(0.5)._ref_G_A_Glucagon, 'JGS', gluc_syn)

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

# record the concentrations in the cells
t_vec = h.Vector()
t_vec.record(h._ref_t)

gl_cell1 = h.Vector().record(a(0.5)._ref_glucagoni)
gl_ecs = h.Vector().record(gecs.node_by_location(0,0,0)._ref_concentration)

ins_cell1 = h.Vector().record(b(0.5)._ref_insulini)
ins_ecs = h.Vector().record(insecs.node_by_location(0,0,0)._ref_concentration)

sst_cell1 = h.Vector().record(d(0.5)._ref_ssti)
sst_ecs = h.Vector().record(sstecs.node_by_location(0,0,0)._ref_concentration)

recd['sst_ecs'] = []
recd['sst_ecs'].append(sst_ecs)
headerd.append('sst_ecs')

recd['sst_cyt'] = []
recd['sst_cyt'].append(sst_cell1)
headerd.append('sst_cyt')

reca['gl_ecs'] = []
reca['gl_ecs'].append(gl_ecs)
headera.append('gl_ecs')

reca['gl_cyt'] = []
reca['gl_cyt'].append(gl_cell1)
headera.append('gl_cyt')

recb['ins_ecs'] = []
recb['ins_ecs'].append(ins_ecs)
headerb.append('ins_ecs')

recb['ins_cyt'] = []
recb['ins_cyt'].append(ins_cell1)
headerb.append('ins_cyt')
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

# set initial voltage
for i, j, k in zip(a, b, d):
    i.v = -62
    j.v = -62
    k.v = -62

t = h.Vector().record(h._ref_t)
print(str(datetime.datetime.now()) + '\tinitialize')
h.finitialize()
print(str(datetime.datetime.now()) + '\tsimulate')
h.continuerun(2000)

# print(str(datetime.datetime.now()) + '\tplot glucagon')
# fig = pyplot.figure(dpi=200)
# pyplot.plot(t_vec,gl_cell1, label='cell1')
# pyplot.plot(t_vec,gl_ecs, label='ecs')
# # pyplot.plot(t_vec,gl_cell2, label='cell2')
# pyplot.legend(frameon=False)
# pyplot.xlabel('t (ms)')
# pyplot.ylabel('glucagon (mM)')
# pyplot.show()

# print(str(datetime.datetime.now()) + '\tplot insulin')
# fig = pyplot.figure(dpi=200)
# pyplot.plot(t_vec,ins_cell1, label='cell1')
# pyplot.plot(t_vec,ins_ecs, label='ecs')
# # pyplot.plot(t_vec,gl_cell2, label='cell2')
# pyplot.legend(frameon=False)
# pyplot.xlabel('t (ms)')
# pyplot.ylabel('insulin (mM)')
# pyplot.show()

# print(str(datetime.datetime.now()) + '\tplot somatostatin')
# fig = pyplot.figure(dpi=200)
# pyplot.plot(t_vec,sst_cell1, label='cell1')
# pyplot.plot(t_vec,sst_ecs, label='ecs')
# # pyplot.plot(t_vec,gl_cell2, label='cell2')
# pyplot.legend(frameon=False)
# pyplot.xlabel('t (ms)')
# pyplot.ylabel('somatostatin (mM)')
# pyplot.show()


# Write results to 3 csv's. One for each cell type
print(str(datetime.datetime.now()) + '\twrite data')
# Alpha
with open('data/watts_Alpha.csv','w') as file:
    writer = csv.writer(file,quoting = csv.QUOTE_NONE,escapechar=' ')
    writer.writerow(heada)
    for i in range(len(t)):
        out = [t[i]]
        for q in reca:
            out.append(reca[q][0][i])
        # print(len(rec), len(out), len(header))
        writer.writerow(out)
print(str(datetime.datetime.now()) + '\twrote alpha')

# # Beta
# with open('data/watts_Beta.csv','w') as file:
#     writer = csv.writer(file,quoting = csv.QUOTE_NONE,escapechar=' ')
#     writer.writerow(headb)
#     for i in range(len(t)):
#         out = [t[i]]
#         for q in recb:
#             out.append(recb[q][0][i])
#         # print(len(rec), len(out), len(header))
#         writer.writerow(out)
# print(str(datetime.datetime.now()) + '\twrote beta')

# # Delta
# with open('data/watts_Delta.csv','w') as file:
#     writer = csv.writer(file,quoting = csv.QUOTE_NONE,escapechar=' ')
#     writer.writerow(headd)
#     for i in range(len(t)):
#         out = [t[i]]
#         for q in recd:
#             out.append(recd[q][0][i])
#         # print(len(rec), len(out), len(header))
#         writer.writerow(out)
# print(str(datetime.datetime.now()) + '\twrote delta')
print(str(datetime.datetime.now()) + '\tcompleted')
