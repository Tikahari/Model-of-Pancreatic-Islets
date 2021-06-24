import re
from neuron import h
import csv
import logging, coloredlogs
coloredlogs.install(level='DEBUG')

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
        self._record()
    
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

    def _record(self):
        # header of csv file (will store variable names)
        self.header = []
        # dictionary that will store values (key will be the variable name, value will be a list of vectors as defined by neuron)
        self.rec = {}
        # variable names we want to record
        rec_vars = ['icala', 'icapqa', 'icata', 'iGIRKa', 'gGIRKbara', 'isoca', 'ikaa', 'ikdra', 'ikatpa', 'gkatpa', 'inaa', 'ila', 'iGIRKb', 'gGIRKbarb', 'ikca', 'ikatp', 'ikb', 'iCa', 'IcaL', 'IcaR', 'icald', 'icapqd', 'iGABA', 'gGABAbar', 'ikad', 'ikatpd', 'ikdrd', 'ild', 'inad', 'EffId', 'EffIa', 'EffSb', 'EffSa', 'JIS', 'JSS', 'JGS', 'G', 'I', 'Sst', 'ca', 'c', 'cd']
        for mechanism in self.cell.psection()['density_mechs']:
            for variable in self.cell.psection()['density_mechs'][mechanism]:
                if variable in rec_vars:
                    logging.info(f"Recording '{variable}' in mechanism '{mechanism}'")
                    head = re.split("[0-9]", mechanism)[0]
                    self.header.append(head + '_' + variable + '_' + self._gid)
                    self.rec[str(head + '_' + variable + '_' + self._gid)] = []
                    # record variables of every mechanism in every segment
                    for k in self.cell:
                        # self.v.append(h.Vector().record(k._ref_v))
                        mechRecord = getattr(k, '_ref_'+variable+'_'+mechanism)
                        self.rec[str(head + '_' + variable + '_' + self._gid)].append(h.Vector().record(mechRecord))
        # fix header / record voltage of every segment
        count = 0
        for segment in self.cell:
            logging.info(f"Recording voltage for section {count}")
            temp = self._gid+'_Vm_'
            # ease writing to csv by keeping same format even though it is not necessary
            self.rec[temp] = []
            self.rec[temp].append(h.Vector().record(segment._ref_v))
            count += 1
        self.header.append(temp)
        self.t = h.Vector().record(h._ref_t)
    
    def writeData(self, outputPath):
        logging.info(f"Writing data for {self._gid}")
        output_header = ['Time']
        output_header.extend(self.header)
        t = self.t
        with open(outputPath, 'w') as file:
            writer = csv.writer(file, quoting = csv.QUOTE_NONE,escapechar=' ')
            writer.writerow(output_header)
            for step in range(len(t)):
                if step%(5000) == 0:
                    logging.info(f"Writing values for time step {step}")
                data = [t[step]]
                for var in self.rec:
                    data.append(self.rec[var][0][step])
                writer.writerow(data)


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

if __name__ == '__main__':
    try:
        # output file path
        alpha_output = "alpha_output.csv"
        # simulation time steps (.025ms each)
        simulation_time = 1000
        alpha_mechs = ['one']
        alpha = Alpha('alpha_cell', 0, 0, 0, alpha_mechs)
        h.finitialize()
        for i in range(40 * simulation_time):
            h.fadvance()
            if i%(2000) == 0:
                logging.info(f"simulation time: {i} ms")
        alpha.writeData(alpha_output)
    except Exception as e:
        logging.error(f"Error occured\n{e}")
