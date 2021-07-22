from neuron import h
import numpy as np
import logging, coloredlogs, re, csv
coloredlogs.install(level='DEBUG')

simulation_time = 20000

def record(cell):
    rec = {}
    header = ["time"]
    for mechanism in cell.psection()['density_mechs']:
        for variable in cell.psection()['density_mechs'][mechanism]:
            #if variable in rec_vars:
            head = re.split("[0-9]", mechanism)[0]
            rec[str(head + '_' + variable)] = []
            header.append(str(head + '_' + variable))
            # record variables of every mechanism in every segment
            for k in cell:
                mechRecord = getattr(k, '_ref_'+variable+'_'+mechanism)
                logging.info(f"recording {variable}_{mechanism} in {cell}")
                rec[str(head + '_' + variable)].append(h.Vector().record(mechRecord))
    return rec, header

def write(t, rec, header, output):
    t = [t.as_numpy()]
    with open(output,'w+') as file:
        writer = csv.writer(file, quoting = csv.QUOTE_NONE,escapechar=' ')
        writer.writerow(header)
        for i in range(len(t[0])):
            row = [t[0][i]]
            for var in rec:
                row.append(rec[var][0][i])
            writer.writerow(row)
            if i %40000 == 0:
                logging.info(f"Wrote data for: {.025*i/1000} seconds (cell {output.split('.')[0]})")

# pointers between density mechanisms
s1 = h.Section()
s1.insert('dm1')

s2 = h.Section()
s2.insert('dm2')

# initialize and set up recording variables
h.setpointer(s2(0.5)._ref_p_dm2, "p", s1(0.5).dm1)
t = h.Vector().record(h._ref_t)
s1_rec, s1_header = record(s1)
s2_rec, s2_header = record(s2)
h.finitialize()

# simulate
for i in range(40 * simulation_time):
    h.fadvance()
    if i%40000 == 0:
        temp = (0.025 * i)/1000 
        logging.info("Simulation time: " + str(temp) + " seconds")

write(t, s1_rec, s1_header, "s1.csv")
write(t, s2_rec, s2_header, "s2.csv")

# TODO: pointers between point processes