"This is the supervisor script which will write the configuration of an islet instance and dispatch its compilation and simulation"
import os
os.system('ml neuron')
import datetime
import sys
import configparser
import ast
import Islet
from Helper import *
import Compile
import Model
#import rpy2.robjects as robjects

setup_ini = Islet.env['config'] + 'Setup/setup.ini'
config = configparser.ConfigParser()
config.optionxform = str
config.read(setup_ini)
num_cells, islet_radius, simulation_time, alpha_probability, beta_probability, delta_probability = (0,0,0,0,0,0)
setup_vars = {}
# Create dictionary of key-value setup pairs
for line in config['Setup']:
    setup_vars[line] = ast.literal_eval(config['Setup'][line])
# locals takes the dictionary and defines the variables (the keys) by their values
locals().update(setup_vars)
total = alpha_probability + beta_probability + delta_probability
if total != 1:
    print('Error: Probabilities need to add to 1, but add to ' + str(total))
    sys.exit()
print('Running model with the following parameters:\nNumber of cells: ' + str(num_cells))
print("Islet radius:", str(islet_radius))
print('Simulation time:', str(simulation_time))
print('Alpha probability:', str(alpha_probability))
print('Beta probability:', str(beta_probability))
print('Delta probability:', str(delta_probability))
input('Verify with enter')
sep = '_'
model_id_components = ["model", str(islet_radius), str(simulation_time), str(alpha_probability), str(beta_probability), str(delta_probability), '3']
islet_id= sep.join(model_id_components)
islet_path = Islet.env['output'] + islet_id

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
# if __name__ == '__main__':
#     # Super.py 1_0 5
#     Super(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4], sys.argv[5])

Super(islet_id, islet_radius, num_cells, alpha_probability, beta_probability)
print('------- Super.py complete -------')
Compile.Compile(islet_id, islet_radius, num_cells)
print('------- Compile.py complete -------')
Model.Model(islet_id, islet_radius, num_cells, simulation_time, alpha_probability, beta_probability)
print('------- Model.py complete -------')
# r = robjects.r
# r.source(islet_path + 'visualize_islet.R')
os.system('Rscript /blue/lamb/robert727/temp/Model-of-Pancreatic-Islets/Visualization/visualize_islet.R' + islet_path)
print('------- visualize_islet.R complete -------')