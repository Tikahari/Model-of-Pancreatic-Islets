from neuron import h, gui
from matplotlib import pyplot as plt
import csv
import configparser

mech = 'frid'
def test():
    rec = {}
    header = ['Time']
    config = configparser.ConfigParser()
    config.read(mech + '.ini')
    fridsec = h.Section()
    fridsec.insert(mech)
    # record variables
    # get variable names
    for i in fridsec.psection()['density_mechs'][mech]:
        header.append(i)
        rec[i] = []
        # record every segment
        for j in fridsec:
            setattr(j, i+'_'+mech, float(config['Beta'][i]))
            mechRecord = getattr(j, '_ref_'+i+'_'+mech)
            rec[i].append(h.Vector().record(mechRecord))
    t = h.Vector().record(h._ref_t)
    h.finitialize(-65)
    
    # set mechanism's values from '.ini' file
    for i in fridsec.psection()['density_mechs'][mech]:
        for j in fridsec:
            setattr(j, i+'_'+mech, float(config['Beta'][i]))

    h.continuerun(1000)
    # write to csv
    with open('data/fridsim_fig5.csv','w') as file:
        writer = csv.writer(file,quoting = csv.QUOTE_NONE,escapechar=' ')
        writer.writerow(header)
        for i in range(len(t)):
            rec_csv = ''
            for j in rec:
                rec_csv += str(rec[j][0][i]) +','
            rec_csv = rec_csv[:len(rec_csv)-1] + ' '
            writer.writerow([t[i],rec_csv])
if __name__ == '__main__':
    test()