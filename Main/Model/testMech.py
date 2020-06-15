from neuron import h
import sys

a = h.Section()
a.insert(sys.argv[1])
print(a.psection())

# b = h.Section()
# b.insert('B_Cac')
# b.insert('B_BK')
# from = getattr(b(0.5))