from neuron import h, rxd
from neuron.rxd import v
from neuron.units import mV
import sys
import csv
import numpy as np
from matplotlib import pyplot as plt

h.load_file('stdrun.hoc')

# create a couple of cells
alpha = h.Section('alpha')
alpha.pt3dclear()
alpha.pt3dadd(-20,0,0,10)
alpha.pt3dadd(-10,0,0,10)
alpha.insert('A_GIRK')
alpha.insert('D_Somatostatin')
alpha.insert('D_CaL')
alpha.insert('D_CaPQ')

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

Sst = rxd.Species([cyt, ecs], name='Sst', d=1.0, initial= 18.71318922819339)
Sst_cyt = Sst[cyt]
Sst_ecs = Sst[ecs]

# Produce Sst in delta cell
# parameter to limit production to cell 1
delta_param = rxd.Parameter(cyt, initial=lambda node: 1.0 if node.segment.sec == delta else 0)

# production with a rate following Michaels Menton kinetics
create_Sst = rxd.Rate(Sst_cyt, delta_param[cyt] * 1.0/(10.0 + Sst_cyt))

# record the concentrations in the cells
t_vec = h.Vector()
t_vec.record(h._ref_t)
alpha_Sst = h.Vector()
alpha_Sst.record(alpha(0.5)._ref_Ssti)
alpha_Sst_ecs = h.Vector()
# alpha_Sst_ecs.record(Sst_ecs.nodes(alpha)(0.5)[0]._ref_concentration)

delta_Sst = h.Vector()
delta_Sst.record(delta(0.5)._ref_Ssti)
delta_Sst_ecs = h.Vector()
# delta_Sst_ecs.record(Sst_ecs.nodes(delta)(0.5)[0]._ref_concentration)

# variables to store data
t = []
v = []
rec = {}
header = ["Time","A_Sst_cyt","A_Sst_ecs","D_Sst_cyt","D_Sst_ecs"]
my_data = [t_vec, alpha_Sst, alpha_Sst_ecs, delta_Sst, delta_Sst_ecs]
# run and plot the results
h.finitialize(-65)
h.continuerun(1000)

# for i in my_data:
#     print(len(i))

np.savetxt("output.csv", my_data, delimiter = ',', fmt='%s')
  
  # write data cell 2
with open('data/'+sys.argv[1],'w') as file:
    writer = csv.writer(file,quoting = csv.QUOTE_NONE,escapechar=' ')
    writer.writerow(header)
    for i in range(len(t_vec)):
        out = []
        for q in my_data:
            if len(q) > 0:
                out.append(q[i])
                # print(q[i], header[i])
        # print(len(rec), len(out), len(header))
        writer.writerow(out)
plt.plot(t_vec, alpha_Sst, label='alpha')
plt.plot(t_vec, delta_Sst, label='delta')
plt.legend(frameon=False)
plt.xlabel('t (ms)')
plt.ylabel('sst (mM)')
plt.show()