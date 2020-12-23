from neuron import h, rxd
from neuron.rxd import v
# from neuron.units import mV, s 
from matplotlib import pyplot
import sys
import csv 
h.load_file('stdrun.hoc')

# create a couple of cells 
cell1 = h.Section('cell1')
cell1.pt3dclear()
cell1.pt3dadd(-20,0,0,10)
cell1.pt3dadd(-10,0,0,10)
cell1.insert('receive')

cell2 = h.Section('cell2')
cell2.pt3dclear()
cell2.pt3dadd(30,0,0,15)
cell2.pt3dadd(45,0,0,15)
cell2.insert('send')

syn = h.pump(cell1(0.5))

var_1 = syn._ref_ix
var_2 = syn._ref_Kd
l = []
l.append(h.Vector().record(var_2))

# variables to store data cell 1
t = []
v = []
rec = {}
header = []

# record mechanisms cell1
for i in cell1.psection()['density_mechs']:
    for j in cell1.psection()['density_mechs'][i]:
        header.append(j+'_'+i)
        rec[str(j+'_'+i)] = []
        # record variables of every mechanism in every segment
        for k in cell1:
            v.append(h.Vector().record(k._ref_v))
            mechRecord = getattr(k, '_ref_'+j+'_'+i)
            rec[str(j+'_'+i)].append(h.Vector().record(mechRecord))

# fix header / record voltage of every segment
head = ['Time']
count = 0
for i in cell1:
    temp = 'VC'+str(count)
    # ease writing to csv by keeping same format even though it is not necessary
    rec[temp] = []
    rec[temp].append(h.Vector().record(i._ref_v))
    count += 1
head.extend(header)
head.append(temp)


# variables to store data cell 2
t2 = []
v2 = []
rec2 = {}
header2 = []

# record mechanisms cell2
for i in cell2.psection()['density_mechs']:
    for j in cell2.psection()['density_mechs'][i]:
        header2.append(j+'_'+i)
        rec2[str(j+'_'+i)] = []
        # record variables of every mechanism in every segment
        for k in cell2:
            v2.append(h.Vector().record(k._ref_v))
            mechRecord2 = getattr(k, '_ref_'+j+'_'+i)
            rec2[str(j+'_'+i)].append(h.Vector().record(mechRecord2))


cyt = rxd.Region(h.allsec(), name='cyt', nrn_region='i')

# plasma membrane 
mem = rxd.Region(h.allsec(), name='mem', geometry=rxd.membrane)

# the extracellular space
ecs = rxd.Extracellular(-20, -5, -5, 45, 5, 5, dx=1, volume_fraction=0.2, tortuosity=1.6)


glucagon = rxd.Species([cyt, ecs], name='glucagon', charge=0, d=1.0, initial=lambda nd: 31 if hasattr(nd, 'sec') and nd.segment in cell1 else 0)
gcyt = glucagon[cyt]
gecs = glucagon[ecs]

h.setpointer(glucagon.nodes[0]._ref_concentration, 'pnt', syn)



# fix header / record voltage of every segment
head2 = ['Time']
count = 0
for i in cell2:
    temp = 'VC'+str(count)
    # ease writing to csv by keeping same format even though it is not necessary
    rec2[temp] = []
    rec2[temp].append(h.Vector().record(i._ref_v))
    count += 1
head2.extend(header2)
head2.append(temp)



t = h.Vector().record(h._ref_t)
h.finitialize(-62)
h.continuerun(1000)

with open('data/Kd.csv', 'w') as file:
    writer = csv.writer(file,quoting = csv.QUOTE_NONE,escapechar=' ')
    writer.writerow(['Kd'])
    for i in range(len(t)):
        out = [t[i]]
        out.append(l[0][i])
        # print(len(rec), len(out), len(header))
        writer.writerow(out)    


# # write data cell 1
# with open('data/'+sys.argv[1],'w') as file:
#     writer = csv.writer(file,quoting = csv.QUOTE_NONE,escapechar=' ')
#     writer.writerow(head)
#     for i in range(len(t)):
#         out = [t[i]]
#         for q in rec:
#             out.append(rec[q][0][i])
#         # print(len(rec), len(out), len(header))
#         writer.writerow(out)

# # write data cell 2
# with open('data/'+sys.argv[2],'w') as file:
#     writer = csv.writer(file,quoting = csv.QUOTE_NONE,escapechar=' ')
#     writer.writerow(head2)
#     for i in range(len(t)):
#         out = [t[i]]
#         for q in rec2:
#             out.append(rec2[q][0][i])
#         # print(len(rec), len(out), len(header))
#         writer.writerow(out)


