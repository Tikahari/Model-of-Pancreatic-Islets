import re
from neuron import h
import pickle
import logging, coloredlogs
coloredlogs.install(level='DEBUG')
import matplotlib.pyplot as plt

class Cell:
    def __init__(self, gid, x, y, z, mechs):
        self._gid = gid
        self._setup_morphology()
        self.all = self.cell.wholetree()
        self._setup_biophysics(mechs)
        self.x, self.y, self.z = (0,0,0)
        h.define_shape()
        #self._rotate_z(theta)
        self._set_position(x,y,z)
        self.rec = {"Time": h.Vector().record(h._ref_t)}
    
    def __repr__(self):
        return '{}[{}]'.format(self.name, self._gid)
    
    def _set_position(self, x, y, z):
        for sec in self.all:
            for i in range(sec.n3d()):
                sec.pt3dchange(i,
                               x - self.x + sec.x3d(i),
                               y - self.y + sec.y3d(i),
                               z - self.z + sec.z3d(i),
                               sec.diam3d(i))
        self.x, self.y, self.z = (0,0,0)


class Alpha(Cell):
    name = 'Alpha'
    def _setup_morphology(self):
        self.cell = h.Section(name='soma', cell=self)
        self.cell.L = self.cell.diam = 14
    def _setup_biophysics(self, mechs):
        self.mechs = mechs
        for sec in self.all:
            sec.Ra = 100    # Axial resistance in Ohm * cm
            sec.cm = 3.24806     # Membrane capacitance in micro Farads / cm^2
        for mech in mechs: 
            self.cell.insert(mech)

def record_or_write(cell_name, write, outputPath = None):
    logging.info("writing data" if write else "recording data")
    if write:
        with open(outputPath, 'wb') as f:
            pickle.dump(cell_name.rec, f)
    else:
        for mechanism in cell_name.cell.psection()['density_mechs']:
            for variable in cell_name.cell.psection()['density_mechs'][mechanism]:
                #if variable in rec_vars:
                head = re.split("[0-9]", mechanism)[0]
                cell_name.rec[str(head + '_' + variable)] = []
                # record variables of every mechanism in every segment
                for k in cell_name.cell:
                    mechRecord = getattr(k, '_ref_'+variable+'_'+mechanism)
                    logging.info(f"recording {variable}_{mechanism} in {cell_name}")
                    cell_name.rec[str(head + '_' + variable)].append(h.Vector().record(mechRecord))



if __name__ == '__main__':
    try:
    # output file path
        alpha_output = "BAD_figs_3-5_1mM_new_write.csv"
        # simulation time steps (.025ms each)
        simulation_time = 2000
        alpha_mechs = ['one']
        alpha = Alpha('cell', 0, 0, 0, alpha_mechs)
        record(alpha, write = False)
        # cvode = h.CVode()
        # cvode.active(True)
        # cvode.atol(1.0E-10)
        # cvode.rtol(1.0E-10)
        # cvode.debug_event(1)
        #h.dt = 0.0125
        h.finitialize()
        h.t = -1000
        #h.secondorder = 2
        for i in range(40 * simulation_time):
            h.fadvance()
            if i%(4000) == 0:
                temp = i * 0.025
                logging.info(f"simulation time: {temp} ms")
        record(alpha, write = True, outputPath = alpha_output)
    except Exception as e:
        logging.error(f"Error occured\n{e}")
