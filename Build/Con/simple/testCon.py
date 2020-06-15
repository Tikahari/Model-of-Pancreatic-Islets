from neuron import h, gui
import sys
import csv

# variables to store data
t = []
v = []
rec = {}
header = []

# two sections with appropriate mechanisms and connection object
d = h.Section()
d.insert('send')
# d.insert('D_CaL')
# d.insert('D_CaPQ')
a = h.Section()
a.insert('receive')

# following lines are most important
syn = h.A_Conn(a(0))
nc = h.NetCon(d(1)._ref_som_send,h.A_Conn(a(0)), 2, 3, 4)
nc.threshold = 0
# record netcon variables
rec_nc = h.Vector()
nc.record(rec_nc)


# header.append('netcon_Sst')
# rec['netcon_Sst'] = []
# rec['netcon_Sst'].append(h.Vector().record(nc.Sst))
# header.append('netcon_w')
# rec['netcon_w'] = []
# rec['netcon_w'].append(h.Vector().record(nc.w))

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

# add netcon info to output
head.append('netcon')
rec['netcon'] = []
rec['netcon'].append(rec_nc)
print('recorded NetCon', rec_nc[0])

with open('data/'+sys.argv[1],'w') as file:
    writer = csv.writer(file,quoting = csv.QUOTE_NONE,escapechar=' ')
    writer.writerow(head)
    for i in range(len(t)):
        out = [t[i]]
        for q in rec:
            if i < len(rec[q][0]):
                out.append(rec[q][0][i])
        # print(len(rec), len(out), len(header))
        writer.writerow(out)
