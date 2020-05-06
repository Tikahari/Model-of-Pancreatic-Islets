from neuron import h, gui
import configparser
import csv

t = []
v = []
mechs = []
rec = {}
header = []
# read configuration
config = configparser.ConfigParser(allow_no_value= True)
config.optionxform = str
config.read('mech.ini')
# get all mechanisms
for i in config['Beta']:
    mechs.append(i)
a = h.Section()
# add all mechanisms
for i in mechs:
    a.insert(i)
# a.nseg = 5
# record mechanisms
for i in a.psection()['density_mechs']:
    for j in a.psection()['density_mechs'][i]:
        header.append(j)
        rec[j] = []
        # record variables of every mechanism in every segment
        for k in a:
            rec['v'] = []
            v = h.Vector().record(k._ref_v)
            rec['v'].append(v)
            mechRecord = getattr(k, '_ref_'+j+'_'+i)
            rec[j].append(h.Vector().record(mechRecord))

# fix header / record voltage of every segment
head = ['Time']
count = 0
for i in a:
    temp = 'VC'+str(count)
    # ease writing to csv by keeping same format even though it is not necessary
    # rec[temp] = []
    # rec[temp].append(h.Vector().record(i._ref_v))
    head.append(temp)
    count += 1
head.extend(header)

t = h.Vector().record(h._ref_t)
h.finitialize(-60)
h.continuerun(20)

print('write to file')
with open('data/mechSim.csv','w') as file:
    writer = csv.writer(file,quoting = csv.QUOTE_NONE,escapechar=' ')
    writer.writerow(head)
    for i in range(len(t)):
        rec_csv = ''
        for j in rec:
            rec_csv += str(rec[j][0][i]) +','
        rec_csv = rec_csv[:len(rec_csv)-1] + ' '
        writer.writerow([t[i], v[i], rec_csv])