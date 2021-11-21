from neuron import h, units, rxd, load_mechanisms
from neuron.units import ms
import math
from matplotlib import pyplot as plt
h.load_file("stdrun.hoc")

beta3 = h.Section(name = "beta3")
beta3.pt3dadd(0,0,0,15.5)
beta3.pt3dadd(15.5,0,0,15.5)
beta3.insert('steady_k')
ecs = rxd.Extracellular(0,0,0,100,100,100, dx = 10)
k_0 = rxd.Species(ecs, d=2.62, name='k_0', charge=-1, initial=3)

# record from an extracellular nodes given by the x,y,z location
kecs_vec0 = h.Vector()
kecs_vec0.record(k_0[ecs].node_by_location(10, 10, 10)._ref_value) 

kecs_vec1 = h.Vector()
kecs_vec1.record(k_0[ecs].node_by_location(10, 10, 20)._ref_value) 

# record the time
t_vec = h.Vector()
t_vec.record(h._ref_t)

# run the simulation
h.finitialize()
h.continuerun(2000 * ms)

# plot the concentations
plt.plot(t_vec, kecs_vec0, label='near the cell')
plt.plot(t_vec, kecs_vec1, label='far from the cell')
plt.ylim([0,10])
plt.legend()
plt.savefig("test_fig_neg.png")