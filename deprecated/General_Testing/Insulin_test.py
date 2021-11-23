import math
from matplotlib import pyplot as plt
from itertools import product
from neuron import h, units, rxd, load_mechanisms
from neuron.units import mV, ms, um, mM
h.load_file("stdrun.hoc")


my_cell = h.Section(name = "my_cell")
my_cell.insert("one")

# Give cell length and diameter of 10 micrometers
my_cell.pt3dadd(10,15,15,10)
my_cell.pt3dadd(20,15,15,10)
ecs = rxd.Extracellular(0,0,0,30,30,30, dx = (10, 10, 10))
# Leave d = 0 so no diffusion meaning insulin should stay right outside of membrane
I = rxd.Species(ecs, name = "I", d = 0, initial = 48.04298494148047, atolscale=1e-10)

vc = 1e-13
fb = 2000
my_cell(0.5).one.JIS = 9.608596975100945e-09

# Create cartesian product of all possible index combinations to create recording vectors for each voxel.
coords = list(product([0,1,2], repeat = 3))
coords = [list(coord) for coord in coords]

# Create doctionary of recording vectors for each voxel
vect_dict = {}
for i in range(len(coords)):
    vect_dict["I" + str(coords[i])] = h.Vector()
    vect_dict["I" + str(coords[i])].record(I[ecs].node_by_ijk(coords[i][0], coords[i][1], coords[i][2])._ref_value)

I_secretion = rxd.Rate(I, (my_cell(0.5).one.JIS/vc)-fb*I, regions = ecs)

t_vec = h.Vector()
t_vec.record(h._ref_t)

JIS = h.Vector()
JIS.record(my_cell(0.5).one._ref_JIS)

# run the simulation
h.finitialize()
# for i in range(2000 * 40):
#     h.fadvance()
#     print(my_cell(0.5).one.JIS)
#     input()
h.continuerun(2000 * ms)

for i in range(len(coords)):
    plt.plot(t_vec, vect_dict["I" + str(coords[i])])
    plt.title("I" + str(coords[i]))
    plt.savefig("Plots/Insulin_test_set_region/I" + str(coords[i]) + ".png")
    plt.close()