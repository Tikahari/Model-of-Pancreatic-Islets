"""This script reads mechanisms to be added from 'mechs.ini' and 
initial values from 'Alpha.ini' and records simulation data in a csv"""
import configparser
import csv
import mod
import os
import ast
import datetime
from matplotlib import pyplot

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
from neuron import h, rxd
h.load_file('stdrun.hoc')

# Alpha cell
a = h.Section()
a.pt3dadd(-20,0,0,10)
a.pt3dadd(-10,0,0,10)
for i in mechsa:
    a.insert('A_'+i)
# simulation parameter
a.cm = 9990

# Beta cell
b = h.Section()
b.pt3dadd(30,0,0,15)
b.pt3dadd(45,0,0,15)
for i in mechsb:
    b.insert('B_'+i)
# simulation parameter
b.cm = 9990

# Delta cell
d = h.Section()
d.pt3dadd(0,0,0,15)
d.pt3dadd(15,0,0,15)
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

print(str(datetime.datetime.now()) + '\tset pointers')
# set pointers
mp = {'Alpha': a, "Beta": b, "Delta": d}
for i in pointers:
    for j in pointers[i]:
        for k in pointers[i][j]:
            for seg in mp[i]:
                temp = k.split('_')
                point_to = i[0].upper() + "_"+j
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

# set up rxd
# the intracellular spaces
cyt = rxd.Region(h.allsec(), name='cyt', nrn_region='i')

# plasma membrane 
mem = rxd.Region(h.allsec(), name='mem', geometry=rxd.membrane)

# the extracellular space
ecs = rxd.Extracellular(-20, -5, -5, 45, 5, 5, dx=1, volume_fraction=0.2, tortuosity=1.6)

# glucagon
glucagon = rxd.Species([cyt, ecs], name='glucagon', charge=1, d=1.0)
gcyt = glucagon[cyt]
gecs = glucagon[ecs]

# somatostatin
sst = rxd.Species([cyt, ecs], name='sst', charge=1, d=1.0)
sstcyt = sst[cyt]
sstecs = sst[ecs]

# insulin
insulin = rxd.Species([cyt, ecs], name='insulin', charge=1, d=1.0)
inscyt = insulin[cyt]
insecs = insulin[ecs]

# uptake and release
# interaction between intracellular and extracellular glucagon
R = 1e5
U = 1e3
rrate = R*gcyt     # release rate [molecules per square micron per ms]
urate = U*gecs     # uptake rate [molecules per square micron per ms]
glucagon_release = rxd.MultiCompartmentReaction(gcyt, gecs, rrate, urate,
                                                membrane=mem, 
                                                custom_dynamics=True)


# record the concentrations in the cells
t_vec = h.Vector()
t_vec.record(h._ref_t)
gl_cell1 = h.Vector().record(a(0.5)._ref_glucagoni)
gl_ecs = h.Vector().record(gecs.node_by_location(0,0,0)._ref_concentration)

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
print(str(datetime.datetime.now()) + '\tinitialize')
h.finitialize()
print(str(datetime.datetime.now()) + '\tsimulate')
h.continuerun(2500)

print(str(datetime.datetime.now()) + '\tplot')
fig = pyplot.figure(dpi=200)
pyplot.plot(t_vec,gl_cell1, label='cell1')
pyplot.plot(t_vec,gl_ecs, label='ecs')
# pyplot.plot(t_vec,gl_cell2, label='cell2')
pyplot.legend(frameon=False)
pyplot.xlabel('t (ms)')
pyplot.ylabel('glucagon (mM)')
pyplot.savefig("/tmp/300620_glucagon_example.png")
pyplot.show()


# Write results to 3 csv's. One for each cell type
print(str(datetime.datetime.now()) + '\twrite data')
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
print(str(datetime.datetime.now()) + '\twrote alpha')
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
print(str(datetime.datetime.now()) + '\twrote beta')
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
print(str(datetime.datetime.now()) + '\twrote delta')
print(str(datetime.datetime.now()) + '\tcompleted')
