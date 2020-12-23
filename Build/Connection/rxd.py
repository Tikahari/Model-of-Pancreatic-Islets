from neuron import h, rxd
import sys
import csv
import numpy as np
from matplotlib import pyplot as plt
import configparser

h.load_file('stdrun.hoc')

# exclude constants from  output
configc = configparser.ConfigParser(allow_no_value= True)
configc.optionxform = str
configc.read('constants.ini')


# create a cell
delta = h.Section('delta')
delta.pt3dclear()
delta.pt3dadd(-9,0,0,10)
delta.pt3dadd(1,0,0,10)
delta.insert('D_Somatostatin')
delta.insert('D_CaL')
delta.insert('D_CaPQ')

# Where?
# the intracellular spaces
cyt = rxd.Region(h.allsec(), name='cyt', nrn_region='i')

# plasma membrane 
mem = rxd.Region(h.allsec(), name='mem', geometry=rxd.membrane)

# the extracellular space
ecs = rxd.Extracellular(-35, -15, -15, 35, 15, 15, dx=10, volume_fraction=0.2, tortuosity=1.6)

Sst = rxd.Species([cyt, ecs], name='sst', charge=0, d=1.0, initial= 18.71318922819339)
Sst_cyt = Sst[cyt]
Sst_ecs = Sst[ecs]

# interaction between intracellular and extracellular glucagon
R = 1e4
U = 1e4
rrate = R*Sst_cyt     # release rate [molecules per square micron per ms]
urate = U*Sst_ecs     # uptake rate [molecules per square micron per ms]

sst_release = rxd.MultiCompartmentReaction(Sst_cyt, Sst_ecs, rrate, urate,
                                                membrane=mem, 
                                                custom_dynamics=True)

# record the concentrations in the cells
t_vec = h.Vector()
t_vec.record(h._ref_t)

delta_Sst = h.Vector()
delta_Sst.record(delta(0.5)._ref_ssti)
delta_Sst_ecs = h.Vector().record(Sst_ecs.node_by_location(0,0,0)._ref_concentration)


# variables to store data for delta cell
t = []
v = []
rec = {}
header = []

# record mechanisms delta
for i in delta.psection()['density_mechs']:
    for j in delta.psection()['density_mechs'][i]:
      if j not in configc['Delta']:
        header.append(j+'_'+i)
        rec[str(j+'_'+i)] = []
        # record variables of every mechanism in every segment
        for k in delta:
            v.append(h.Vector().record(k._ref_v))
            mechRecord = getattr(k, '_ref_'+j+'_'+i)
            rec[str(j+'_'+i)].append(h.Vector().record(mechRecord))

# fix header / record voltage of every segment
head = ['Time']
count = 0
for i in delta:
    temp = 'VC'+str(count)
    # ease writing to csv by keeping same format even though it is not necessary
    rec[temp] = []
    rec[temp].append(h.Vector().record(i._ref_v))
    count += 1
head.extend(header)
head.append(temp)

t = h.Vector().record(h._ref_t)
h.finitialize(-65)
h.continuerun(1000)



# write data cell for delta cell
with open('data/'+sys.argv[2],'w') as file:
    writer = csv.writer(file,quoting = csv.QUOTE_NONE,escapechar=' ')
    writer.writerow(head)
    for i in range(len(t)):
        out = [t[i]]
        for q in rec:
            out.append(rec[q][0][i])
        writer.writerow(out)


plt.plot(t_vec, delta_Sst, label='delta')
plt.plot(t_vec, delta_Sst_ecs, label='ecs')
plt.legend(frameon=False)
plt.xlabel('t (ms)')
plt.ylabel('sst (mM)')
plt.show()