"This is the supervisor script which will write the configuration of an islet instance and dispatch its compilation and simulation"
import datetime
import sys
import Islet
from Helper import *

def Super(islet_id, islet_radius, num_cells, alpha_probability, beta_probability):
    print(str(datetime.datetime.now()) + '\tSuper.py')
    # id of islets
    Islet.env['id'] = islet_id 
    # islet_radius of islets (dimensions of cube which will contain it)
    islet_radius = int(islet_radius)
    # default probability of each cell type [P(A), P(A) + P(B)]
    probabilities = [float(alpha_probability), float(beta_probability)]
    num_cells = int(num_cells)
    # create template spatial configuration
    template_path = Islet.env['config'] + 'Values/Template_' + Islet.env['id']
    # create folder to write config files to and update Islet env variable
    os.system('mkdir -p ' + template_path)
    # generate islet with random islet_radius
    islet = Islet.Islet(probabilities, None, islet_radius, num_cells)
    islet.spatialConfig()
    print(str(datetime.datetime.now()) + '\tSuper.setTemplates Create islet: id', Islet.env['id'])
    # get parameter values, mechanisms for each cell type
    mechanisms_config_path = Islet.env['config'] + 'Mechanisms/'
    values_config_path = Islet.env['config'] + 'Values/'
    run_islet_path = Islet.env['wd']
    values, mechanisms = readInit(values_config_path + 'super.ini', mechanisms_config_path + 'super.ini')
    # set up run folder appropriately
    instance = 'Islet_' + Islet.env['id']
    # create initialization and run folders for this islet
    os.system('mkdir -p ' + mechanisms_config_path + instance)
    os.system('mkdir -p ' + values_config_path + instance)
    os.system('mkdir -p ' + run_islet_path + instance)
    # read configuration
    config_cells = configparser.ConfigParser()
    config_cells = configparser.ConfigParser(allow_no_value= True)
    config_cells.optionxform = str
    config_cells.read(template_path + '/config.txt')
    # iterate through cell types for this islet
    for cell in config_cells['Data']:
        file_values = values_config_path + instance + '/' + cell + '.ini'
        file_mechanisms = mechanisms_config_path + instance + '/' + cell + '.ini'
        folder_mods = run_islet_path + instance + '/' + cell + '/'
        # create initialization file and run folders for this cell
        os.system('touch  ' + file_values)
        os.system('touch ' + file_mechanisms)
        os.system('mkdir -p ' + folder_mods)
        # copy appropriate mod files into run folder
        os.system('rsync ' + Islet.env['mech'] + cell[0].upper() + '*mod ' + folder_mods)
        # write parameters and mechanisms
        writeValuesCell(file_values, values, cell, config_cells)
        writeMechanismsCell(file_mechanisms, mechanisms, cell)
if __name__ == '__main__':
    # Super.py 1_0 5
    Super(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4], sys.argv[5])