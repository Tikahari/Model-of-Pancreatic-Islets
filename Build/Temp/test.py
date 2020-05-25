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
    header = ['Time']
    config = configparser.ConfigParser(allow_no_value= True)
    config.optionxform = str
    config.read('mech.ini')
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
    cnt = 1
    for i in fridsec.psection()['density_mechs']:
        for j in fridsec.psection()['density_mechs'][i]:
            header.append(i+'_'+j)
            rec[str(i+'_'+j)] = []
            # record variables of every mechanism in every segment
            for k in fridsec:
                v.append(h.Vector().record(k._ref_v))
                mechRecord = getattr(k, '_ref_'+j+'_'+i)
                rec[str(i+'_'+j)].append(h.Vector().record(mechRecord))
    t = h.Vector().record(h._ref_t)
    h.finitialize()
    h.continuerun(200)
    z = 0
    for i in rec:
        # print('Header:', header[z], 'Length:', len(rec[i][0]))
        z += 1
    # write to csv
    with open('data/'+sys.argv[1],'w') as file:
        writer = csv.writer(file,quoting = csv.QUOTE_NONE,escapechar=' ')
        writer.writerow(header)
        for i in range(len(t)):
            out = [t[i]]
            for q in rec:
                out.append(rec[q][0][i])
            # print(len(rec), len(out), len(header))
            writer.writerow(out)
if __name__ == '__main__':
    test()
