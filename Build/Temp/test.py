from neuron import h, gui
from matplotlib import pyplot as plt
import csv
import configparser
import mod
import os
import sys
import ast

def setMod():
    # write mod
    # m = mod.Mod(mech+'.mod', mech+'.ini')
    # m.writeMod()
    # compile mod
    os.system('nrnivmodl *mod > compile 2>&1')

def test():
    setMod()
    rec = {}
    rec2 = {}
    v = []
    pointers = {}
    mechs = []
    header = []
    config = configparser.ConfigParser(allow_no_value= True)
    config.optionxform = str
    config.read('mech.ini')
    print('mechanisms from separate ".mod":', len(config['Beta']))
    for i in config['Beta']:
        mechs.append(i)
        if config['Beta'][i] is not None:
            pointers[i] = ast.literal_eval(config['Beta'][i])
    # record
    # rec = dict.fromkeys(mechs, [])
    # rec2 = dict.fromkeys(mechs, [])

    fridsec = h.Section()
    for i in mechs:
        print('mech:',i)
        fridsec.insert('B_'+i)
    fridsec.insert('frid')
    # membrane capacitance
    fridsec.cm = 9990
    # set pointers
    for i in pointers:
        for j in pointers[i]:
            for k in fridsec:
                temp = j.split('_')
                point_to = "B_"+i
                point_from = "_ref_"+temp[0]+"_B_"+temp[2]
                # print('point from', point_from, "point to", point_to)
                from_ = getattr(k, point_from)
                to_ = getattr(k, point_to)
                h.setpointer(from_, temp[2], to_)

    # record variables
    # get variable names
    for i in fridsec.psection()['density_mechs']:
        for j in fridsec.psection()['density_mechs'][i]:
            header.append(i+'_'+j)
            rec[str(i+'_'+j)] = []
            # record variables of every mechanism in every segment
            for k in fridsec:
                v.append(h.Vector().record(k._ref_v))
                mechRecord = getattr(k, '_ref_'+j+'_'+i)
                rec[str(i+'_'+j)].append(h.Vector().record(mechRecord))
    # fix header / record voltage of every segment
    head = ['Time']
    count = 0
    for i in fridsec:
        temp = 'VC'+str(count)
        # ease writing to csv by keeping same format even though it is not necessary
        rec[temp] = []
        rec[temp].append(h.Vector().record(i._ref_v))
        count += 1
    head.extend(header)
    head.append(temp)
    # simulate
    t = h.Vector().record(h._ref_t)
    h.finitialize(-62)
    h.continuerun(5000)

    # write to csv
    with open('data/'+sys.argv[1],'w+') as file:
        writer = csv.writer(file,quoting = csv.QUOTE_NONE,escapechar=' ')
        writer.writerow(head)
        for i in range(len(t)):
            out = [t[i]]
            for q in rec:
                out.append(rec[q][0][i])
            # print(len(rec), len(out), len(header))
            writer.writerow(out)
if __name__ == '__main__':
    test()
