"""Script defining main islet class."""
import logging
# Setup logging
logger = logging.getLogger(__name__)

import math
import re

import numpy as np
from neuron import h

# Define global variables
# Size of cells
ALPHA_SIZE = DELTA_SIZE = 7
BETA_SIZE = 15.5
# Number of 'segments' to divide islet space into
SEGMENT_SIZE = 10


class Islet:
    def __init__(self, id: str, mechanism: str, islet_radius: int, cells: dict = None):
        """
        Initialize islet instance. Note that cells can be determined by the cells dict or the probabilities dict (which must contain the number of cells).

        Args:
            id (str): id of iselt.
            mechanism (str): mechanism to insert
            islet_radius (int): radius of islet.
            cells (dict, optional): conditional dict (determines how many cells/probabilities/etc. See current example in simulate.ppy). Defaults to None.
        """
        logger.debug("Creating islet")
        
        # Set object variables from constructor parameters
        self._id = id
        self.mechanism = mechanism
        self.islet_radius = islet_radius
        
        # Validate 'cells' parameter
        # TODO: add more validations (probabilities should add up to 100, should be less than 1, etc.)
        if 'type' not in cells or cells['type'] not in ['probabilistic', 'deterministic']:
            raise Exception("'type' needs to be a key in the cells object passed to the islet and should be one of 'probabilistic', 'deterministic'")
            
        # Set the following variables depending the 'type' of the 'cells' variable passed
        self._type = cells['type']
    
        # Probabilities are sent
        if cells['type'] == 'probabilistic':
            self.num_cells = cells['num_cells']
            self.prob_alpha = cells['A']
            self.prob_beta = cells['B']
            self.prob_delta = cells['D']
            self.num_betas = math.floor(self.num_cells * self.prob_beta)
            self.num_alphas = math.ceil(self.num_cells * self.prob_alpha)
            self.num_deltas = self.num_cells - self.num_betas - self.num_alphas
            
        # Number of cells are sent
        else:
            self.num_cells = cells['A'] + cells['B'] + cells['D']
            self.num_betas = cells['B']
            self.num_alphas = cells['A']
            self.num_deltas = cells['D']
        
        # Dict to store values to record
        self.cell_rec = dict()
        
        logger.debug("Islet created")
    
    def __repr__(self):
        """String representation for debugging."""
        return "Islet '{id}' of type '{type}'".format(id=self._id, type=self._type)

    def spatial_setup(self):
        """Setup each cell according to parameters passed to constructor with an appropriate spatial orientation."""
        logger.debug("Setting up potential coordinates for cells")
        
        # Number of segments to use
        nx, ny, nz = (SEGMENT_SIZE, SEGMENT_SIZE, SEGMENT_SIZE)
        
        # The below statements take a line from -radius to radius and chops it up into n segments
        x_coords = np.linspace(-self.islet_radius, self.islet_radius, nx)
        y_coords = np.linspace(-self.islet_radius, self.islet_radius, ny)
        z_coords = np.linspace(-self.islet_radius, self.islet_radius, nz)
        
        # Set locations for all cells
        self.locations = []
        count = 0
        while count < self.num_cells:
            
            # Select a random value for x, y, and z coordinates
            x,y,z = np.random.choice(x_coords, 1), np.random.choice(y_coords, 1), np.random.choice(z_coords, 1)
            
            # Check if the point is within the islet sphere
            if math.sqrt(x**2 + y**2 + z**2) < self.islet_radius:
                
                # Check if random coordinates chosen are unique so not two cells have the same location
                if any(location == [x[0],y[0],z[0]] for location in self.locations): 
                    continue
                else:
                    
                    # If location unique, append it to the locations list
                    self.locations.append({'x': x[0],'y': y[0], 'z': z[0]})
                    count+=1
                    
        logger.debug("Potential coordinates for islet setup")

    def populate_cells(self):
        """Create cell dictionary containing all the sections in the islet.""" 
        logger.debug("Populating cells")
        
        # Dictionary to populate
        self.cells = {}
       
       # Create the sections, which can be accessed by their name in the cells dictionary
        for i in range(self.num_alphas):
            self.cells["A_" + str(i)] = h.Section(name = "A_" + str(i))
        for i in range(self.num_betas):
            self.cells["B_" + str(i)] = h.Section(name = "B_" + str(i))
        for i in range(self.num_deltas):
            self.cells["D_" + str(i)] = h.Section(name = "D_" + str(i))

        # Insert one mechanism into each cell. In future make this like original setup
        # with config file and mechanism names for each cell type.
        for cell in self.cells:
            self.cells[cell].insert(self.mechanism)
            
        logger.debug("Cells populated")

    def set_cell_locations(self):
        """
        Separate the cells dictionary into lists for each cell type.
        This is accomplished by using the search criteria of if "A", "B", or "D" is in cell name.
        """
        logger.debug("Assigning coordinates to cells")
        
        # Get sections for all cell types
        alpha_sections = [val for key, val in self.cells.items() if "A" in key]
        beta_sections = [val for key, val in self.cells.items() if "B" in key]
        delta_sections = [val for key, val in self.cells.items() if "D" in key]
        
        
        count = 0
        logger.debug(f"Setting up:")
        logger.debug(f"{self.num_alphas} alpha cells")
        logger.debug(f"{self.num_betas} beta cells")
        logger.debug(f"{self.num_deltas} delta cells")
        
        for cell_idx in range(self.num_cells):
            
            while count < self.num_alphas:
                alpha_sections[cell_idx].pt3dclear()
                alpha_sections[cell_idx].pt3dadd(self.locations[cell_idx]['x'], self.locations[cell_idx]['y'], self.locations[cell_idx]['z'], ALPHA_SIZE)
                alpha_sections[cell_idx].pt3dadd(self.locations[cell_idx]['x'] + ALPHA_SIZE, self.locations[cell_idx]['y'], self.locations[cell_idx]['z'], ALPHA_SIZE)
                count+=1
            
            while self.num_alphas <= count < self.num_alphas + self.num_betas:
                beta_sections[cell_idx].pt3dclear()
                beta_sections[cell_idx].pt3dadd(self.locations[cell_idx]['x'], self.locations[cell_idx]['y'], self.locations[cell_idx]['z'], BETA_SIZE)
                beta_sections[cell_idx].pt3dadd(self.locations[cell_idx]['x'] + BETA_SIZE, self.locations[cell_idx]['y'], self.locations[cell_idx]['z'], BETA_SIZE)
                count+=1
            
            while self.num_alphas + self.num_betas <= count < self.num_cells:
                delta_sections[cell_idx].pt3dclear()
                delta_sections[cell_idx].pt3dadd(self.locations[cell_idx]['x'], self.locations[cell_idx]['y'], self.locations[cell_idx]['z'], DELTA_SIZE)
                delta_sections[cell_idx].pt3dadd(self.locations[cell_idx]['x'] + DELTA_SIZE, self.locations[cell_idx]['y'], self.locations[cell_idx]['z'], DELTA_SIZE)   
                count+=1    

        logger.debug("Coordinates assigned to cells")
    
    
    def record_values(self):
        """Create dictionary that will store values of all variables of interest present in all mechanisms."""
        logger.debug("Setting up recording dictionary")
        
        # Get all density mechanisms and variables using NEURON defined 'psection()'
        for cell in self.cells:
            self.cell_rec[cell] = dict()
            for mechanism in self.cells[cell].psection()['density_mechs']:
                for variable in self.cells[cell].psection()['density_mechs'][mechanism]:
                    
                    # Get density mechanism name
                    head = re.split("[0-9]", mechanism)[0]
                    
                    # Set name of variable to record
                    self.cell_rec[cell][str(head + '_' + variable)] = []

                    # Record variables of every mechanism in every segment
                    for k in self.cells[cell]:
                        mechRecord = getattr(k, '_ref_'+variable+'_'+mechanism)
                        self.cell_rec[cell][str(head + '_' + variable)].append(h.Vector().record(mechRecord))        

        logger.debug("Recording dictionary setup")