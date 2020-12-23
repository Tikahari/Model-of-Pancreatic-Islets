from neuron import h, gui
import sys
import csv
# two sections with appropriate mechanisms and connection object
d = h.Section()
d.insert('D_Somatostatin')
# d.insert('D_CaL')
# d.insert('D_CaPQ')
a = h.Section()
a.insert('A_GIRK')

# following lines are most important
syn = h.A_Conn(a(0))
# target variable, weights, point process/synapse
nc = h.NetCon(d(1)._ref_som_D_Somatostatin,h.A_Conn(a(0)), 1, 1, 1)

# variables to store data
t = []
v = []
rec = {}
header = []

# record mechanisms alpha
for i in a.psection()['density_mechs']:
    for j in a.psection()['density_mechs'][i]:
        header.append(i+'_'+j)
        rec[str(i+'_'+j)] = []
        # record variables of every mechanism in every segment
        for k in a:
            v.append(h.Vector().record(k._ref_v))
            mechRecord = getattr(k, '_ref_'+j+'_'+i)
            rec[str(i+'_'+j)].append(h.Vector().record(mechRecord))
            
# record mechanisms delta
for i in d.psection()['density_mechs']:
    for j in d.psection()['density_mechs'][i]:
        header.append(i+'_'+j)
        rec[str(i+'_'+j)] = []
        # record variables of every mechanism in every segment
        for k in d:
            v.append(h.Vector().record(k._ref_v))
            mechRecord = getattr(k, '_ref_'+j+'_'+i)
            rec[str(i+'_'+j)].append(h.Vector().record(mechRecord))

# fix header / record voltage of every segment
head = ['Time']
count = 0
for i in a:
    temp = 'VC'+str(count)
    # ease writing to csv by keeping same format even though it is not necessary
    rec[temp] = []
    rec[temp].append(h.Vector().record(i._ref_v))
    count += 1
head.extend(header)
head.append(temp)

t = h.Vector().record(h._ref_t)
h.finitialize(-62)
h.continuerun(5000)

with open('data/'+sys.argv[1],'w') as file:
    writer = csv.writer(file,quoting = csv.QUOTE_NONE,escapechar=' ')
    writer.writerow(head)
    for i in range(len(t)):
        out = [t[i]]
        for q in rec:
            out.append(rec[q][0][i])
        # print(len(rec), len(out), len(header))
        writer.writerow(out)
