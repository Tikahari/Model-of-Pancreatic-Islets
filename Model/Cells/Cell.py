from neuron import h, gui
import sqlite3

class Cell:
    def __init__(self, id, x, y, z, type, database):
        self.id = id
        self.type = type
        # define type
        self._set_type()
        # set properties
        self._set_properties()
        # define shape and set orientation
        h.define_shape()
        self._set_orientation(x, y, z)
    def _set_type(self):
        # initialize cell name and size based on output from database
        self.cell = h.Section(name = self.type, cell = self)
        self.cell.diam = 1
        self.cell.L = 1
        print('type set', self.type, 'cell')
    def _set_properties(self):
        a =1
        print('properties set')
    def _set_orientation(self, x, y, z):
        self.x, self.y, self.z = x, y, z
        print('3d orientation is', self.cell.n3d(), self.cell.x3d(0))
        for i in range(self.cell.n3d()):
            print(self.cell.x3d(i), self.cell.y3d(i), self.cell.x3d(i))
    def __repr__(self):
        return '{} cell: {}'.format(self.type, self.id)
if __name__ == '__main__':
    cell = Cell(0, 1, 2, 3, "alpha", "db")
    ps = h.PlotShape(True)
    ps.show(0)
    import time
    time.sleep(2000)