class Cell:
    def __init__(self, gid, x, y, z):
        self._gid = gid
        self._setup_morphology()
        self.all = self.soma.wholetree()
        self._setup_biophysics()
        self.x, self.y, self.z = (0,0,0)
        h.define_shape()
        #self._rotate_z(theta)
        self._set_position(x,y,z)
    
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

class Alpha(Cell, mechs):
    name = 'Alpha'
    def _setup_morphology(self):
        self.soma = h.Section(name='soma', cell=self)
        self.soma.L = self.soma.diam = 14
    def _setup_biophysics(self):
        self.mechs = mechs
        for sec in self.all:
            sec.Ra = 100    # Axial resistance in Ohm * cm
            sec.cm = 3.24806     # Membrane capacitance in micro Farads / cm^2
        for mech in mechs: 
            self.soma.insert(mech)

# Important recording variables 
rec_vars = ['icala', 'icapqa', 'icata', 'iGIRKa', 'gGIRKbara', 'isoca', 'ikaa', 'ikdra', 'ikatpa', 'gkatpa', 'inaa', 'ila', 'iGIRKb', 'gGIRKbarb', 'ikca', 'ikatp', 'ikb', 'iCa', 'IcaL', 'IcaR', 'icald', 'icapqd', 'iGABA', 'gGABAbar', 'ikad', 'ikatpd', 'ikdrd', 'ild', 'inad', 'EffId', 'EffIa', 'EffSb', 'EffSa', 'JIS', 'JSS', 'JGS', 'G', 'I', 'Sst', 'ca', 'c', 'cd']