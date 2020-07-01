from neuron import h, rxd
from neuron.rxd import v
from neuron.units import mV, s 

h.load_file('stdrun.hoc')

# create a couple of cells
alpha = h.Section('alpha')
alpha.pt3dclear()
alpha.pt3dadd(-20,0,0,10)
alpha.pt3dadd(-10,0,0,10)

delta = h.Section('delta')
delta.pt3dclear()
delta.pt3dadd(10,0,0,10)
delta.pt3dadd(20,0,0,10)

# Where?
# the intracellular spaces
cyt = rxd.Region(h.allsec(), name='cyt', nrn_region='i')

# plasma membrane 
mem = rxd.Region(h.allsec(), name='mem', geometry=rxd.membrane)

# the extracellular space
ecs = rxd.Extracellular(-35, -15, -15, 35, 15, 15, dx=10, volume_fraction=0.2, tortuosity=1.6)