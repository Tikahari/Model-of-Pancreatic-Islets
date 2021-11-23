"""These functions are used by functions in but are not critical components of the genetic algorithm and model"""
import datetime
import configparser
import ast
import random
import re
import os

def readInit(values_path, mechanisms_path):
    """Read the 'super' initialization files which include all mechanisms and parameters of all cells of an islet"""
    print(str(datetime.datetime.now()) + '\tHelper.readInit Read mechanisms and values initialization file')
    config_values = configparser.ConfigParser()
    config_values .optionxform = str
    config_values .read(values_path)
    values = {'Alpha': {}, 'Beta': {}, 'Delta': {}}
    # get all values
    for cell_type in config_values:
        for value in config_values[cell_type]:
            values[cell_type][value] = ast.literal_eval(config_values[cell_type][value])
    # get all mechanisms
    mechs = ''
    with open(mechanisms_path) as config_mechanisms:
        mechs = config_mechanisms.readlines()
    return values, mechs
def writeValuesCell(file_values, values, cell, config):
    """Write parameters/initial values of this cell"""
    print(str(datetime.datetime.now()) + '\tHelper.writeValuesCell Write values for cell', cell, 'file', file_values)
    types = {'A': 'Alpha', 'B': 'Beta', 'D': 'Delta'}
    with open(file_values, 'w') as ini:
        cell_type = types[cell[0].upper()]
        ini.write('[' + cell_type + ']\n')
        # iterate through all variables for cell type
        for var in values[cell_type]:
            if(type(values[cell_type][var]) is list):
                val = random.random() * (values[cell_type][var][1] - values[cell_type][var][0]) + values[cell_type][var][0]
            else:
                val = values[cell_type][var]
            ini.write(var + ' = ' + str(val) + '\n')
        ini.write('position = ' + config['Data'][cell])
def writeMechanismsCell(file_mechanisms, mechanisms, cell):
    """Write mechanisms of this cell"""
    print(str(datetime.datetime.now()) + '\tHelper.writeMechanismsCell Write mechanisms for cell', cell, 'file', file_mechanisms)
    types = {'A': 'Alpha', 'B': 'Beta', 'D': 'Delta'}
    with open(file_mechanisms, 'r+') as ini:
        cell_type = types[cell[0].upper()]
        cell_num = cell.split('_')[1]
        new_mech = ""
        write = False
        for old_mech in mechanisms:
            # only write correct cell type
            if cell_type in old_mech:
                write = True
                types[cell[0].upper()] = 'NA/past'
                # print('set true')
            for i in types:
                if types[i] in old_mech:
                    write = False
            if write:
                if '=' in old_mech:
                    temp = old_mech.replace('=', cell_num + '=')
                    temp = temp.replace('"]', cell_num + '"]')
                    new_mech += temp
                elif '[' not in old_mech:
                    new_mech += old_mech.rstrip() + cell_num + '\n'
                else:
                    new_mech += old_mech
        ini.write(new_mech)
def writeConfigurationDirect(islets, paths, simulation_variables):
    """Write configuration files for islets that will be passed onto the next generation unchanged"""
    print(str(datetime.datetime.now()) + '\tHelper.writeConfigurationDirect Write configuration of randomly selected islets that will be passed to the next generation')
    [values_config_path, mechanisms_config_path, run_islet_path, mechanisms_path, template_path] = paths
    [generations, values, mechanisms, run, spatial_configurations] = simulation_variables
    count = 0
    for cell in islets:
        old_islet = 'Islet_' + str(run) + '_' + str(len(generations)-1) + '_' + str(count)
        new_islet = 'Islet_' + str(run) + '_' + str(len(generations)) + '_' + str(count)
        print(str(datetime.datetime.now()) + '\tHelper.writeConfigurationDirect Configure', cell)
        # make configuration folders
        os.system('mkdir -p ' + values_config_path + new_islet)
        os.system('mkdir -p ' + mechanisms_config_path + new_islet)
        os.system('mkdir -p ' + run_islet_path + new_islet)
        # copy mechanisms and values
        os.system('cp -r ' + values_config_path + old_islet + '/* ' + values_config_path + new_islet)
        os.system('cp -r ' + mechanisms_config_path + old_islet + '/* ' + mechanisms_config_path + new_islet)
        count += 1
        # prepare run folder
        # get appropriate orientation template
        template_cell_path = template_path
        for cell_ini in os.listdir(values_config_path + old_islet):
            if 'template' in cell_ini:
                template_cell_path += re.split('\.txt|_', cell_ini)[1]
                break
        print(str(datetime.datetime.now()) + '\tHelper.writeConfigurationDirect Template is', template_cell_path, 'in', old_islet)
        config = configparser.ConfigParser()
        config = configparser.ConfigParser(allow_no_value= True)
        config.optionxform = str
        config.read(template_cell_path + '/config.txt')
        # create folder for each cell and copy appropriate mod files there
        for cell_ini in config['Data']:
            mechanisms_cell_path = mechanisms_path + cell_ini[0].upper() + '*mod'
            folder_mods = run_islet_path + new_islet + '/' + cell_ini + '/'
            os.system('mkdir -p ' + folder_mods)
            os.system('rsync ' + mechanisms_cell_path + ' ' + folder_mods)
    return count
def writeConfigurationBreed(p1, p2, curr, paths, simulation_variables):
    """Breed islets and write configuratin files""" 
    print(str(datetime.datetime.now()) + '\tHelper.writeConfigurationBreed Breed and write configuration of islets that will be passed to the next generation', p1, p2)
    [values_config_path, mechanisms_config_path, run_islet_path, mechanisms_path, template_path] = paths
    [generations, values, mechanisms, run, spatial_configurations] = simulation_variables
    # get paths to configuration and run folders
    parent_1 = re.split('.pl|\/', p1[1])[len(re.split('.pl|\/', p1[1]))-2]
    parent_2 = re.split('.pl|\/', p2[1])[len(re.split('.pl|\/', p2[1]))-2]
    child = 'Islet_' + str(run) + '_' + str(len(generations)) + '_' + str(curr)
    # make configuration folders
    os.system('mkdir -p ' + values_config_path + child)
    os.system('mkdir -p ' + mechanisms_config_path + child)
    os.system('mkdir -p ' + run_islet_path + child)
    # copy mechanisms and values then modify values (determine which parent will pass on its template at random)
    rand = random.random()
    print(str(datetime.datetime.now()) + '\tHelper.writeConfigurationBreed Random number to determine which parent passes on template', rand)
    if rand > 0.5:
        os.system('cp -r ' + mechanisms_config_path + parent_1 + '/* ' + mechanisms_config_path + child)
        os.system('cp -r ' + values_config_path + parent_1 + '/* ' + values_config_path + child)
    else:
        os.system('cp -r ' + mechanisms_config_path + parent_2 + '/* ' + mechanisms_config_path + child)
        os.system('cp -r ' + values_config_path + parent_2 + '/* ' + values_config_path + child)
    for cell in os.listdir(values_config_path + child):
        if 'ini' in cell:
            print(str(datetime.datetime.now()) + '\tHelper.writeConfigurationBreed Cell', cell, 'islet', child, 'parent 1', parent_1, 'parent 2', parent_2)
            p1_ini = values_config_path + parent_1 + '/' + cell
            p2_ini = values_config_path + parent_2 + '/' + cell
            child_ini = values_config_path + child + '/' + cell
            with open(p1_ini) as parent_1_cell, open(p2_ini) as parent_2_cell, open(child_ini, 'r+') as child_cell:
                # read the 3 corresponding configuration files
                config_p1 = configparser.ConfigParser()
                config_p1.optionxform = str
                config_p1.read(p1_ini)
                config_p2 = configparser.ConfigParser()
                config_p2.optionxform = str
                config_p2.read(p2_ini)
                config_child = configparser.ConfigParser()
                config_child.optionxform = str
                config_child.read(child_ini)
                # iterate through values within the new files, updating them with a value from parent 1 or 2 at random
                for cell_type in config_child:
                    for val in config_child[cell_type]:
                        # randomly select value to write from parents
                        rand = random.random()
                        if rand > 0.5:
                            config_child[cell_type][val] = config_p1[cell_type][val]
                        else:
                            config_child[cell_type][val] = config_p2[cell_type][val]
                config_child.write(child_cell)
    # prepare run folder
    # get appropriate orientation template
    template_cell_path = template_path
    print('template path', template_path)
    for cell_ini in os.listdir(values_config_path + child):
        if 'template' in cell_ini:
            print('cell_ini', cell_ini)
            template_cell_path += re.split('\.txt|_', cell_ini)[1]
            break
    print(str(datetime.datetime.now()) + '\tHelper.writeConfigurationBreed template is', template_cell_path, 'in', child)
    config_template = configparser.ConfigParser()
    config_template = configparser.ConfigParser(allow_no_value= True)
    config_template.optionxform = str
    config_template.read(template_cell_path + '/config.txt')
    # create folder for each cell and copy appropriate mod files there
    for cell_ini in config_template['Data']:
        mechanisms_cell_path = mechanisms_path + cell_ini[0].upper() + '*mod'
        folder_mods = run_islet_path + child + '/' + cell_ini + '/'
        os.system('mkdir -p ' + folder_mods)
        os.system('rsync ' + mechanisms_cell_path + ' ' + folder_mods)
def writeConfigurationRandom(curr, random_gen, paths, simulation_variables):
    """Write configuration files for randomly generated islets"""
    print(str(datetime.datetime.now()) + '\tGeneticAlgorithm.writeConfigurationRandom Write configuration of islets that will be passed to the next generation current islet', curr, 'number of randomly generated islets', random_gen)
    [values_config_path, mechanisms_config_path, run_islet_path, mechanisms_path, template_path] = paths
    [generations, values, mechanisms, run, spatial_configurations] = simulation_variables# same as parent generation but number islets according to current islet number ('curr')
    count = 0
    while count < random_gen:
        instance = 'Islet_' + str(run) + '_' + str(len(generations)) + '_' + str(curr)
        # create initialization and run folders for this islet
        os.system('mkdir -p ' + mechanisms_config_path + instance)
        os.system('mkdir -p ' + values_config_path + instance)
        os.system('mkdir -p ' + run_islet_path + instance)
        # randomly choose one of the orientation templates
        rand = random.randint(1, spatial_configurations)
        os.system('touch ' + values_config_path + instance + '/template_' + str(rand))
        config_cells = configparser.ConfigParser()
        config_cells = configparser.ConfigParser(allow_no_value= True)
        config_cells.optionxform = str
        config_cells.read(template_path + str(rand) + '/config.txt')
        # iterate through cell types for this islet
        for cell_ini in config_cells['Data']:
            mechanisms_cell_path = mechanisms_path + cell_ini[0].upper() + '*mod'
            file_values = values_config_path + instance + '/' + cell_ini + '.ini'
            file_mechanisms = mechanisms_config_path + instance + '/' + cell_ini + '.ini'
            folder_mods = run_islet_path + instance + '/' + cell_ini + '/'
            # create initialization file and run folders for this cell
            os.system('touch  ' + file_values)
            os.system('touch ' + file_mechanisms)
            os.system('mkdir -p ' + folder_mods)
            # copy appropriate mod files into run folder
            os.system('rsync ' + mechanisms_cell_path + ' ' + folder_mods)
            # write parameters and mechanisms
            writeValuesCell(file_values, values, cell_ini, config_cells)
            writeMechanismsCell(file_mechanisms, mechanisms, cell_ini)
        count += 1
        curr += 1
def getRandom(upper):
    """Get two different random numbers between 0 and some specified value"""                                                                                                                                                                                                    
    x = random.randint(0, upper)
    y = random.randint(0, upper)
    if x == y:
        return getRandom(upper)
    return x, y
def getMultiple(reference, simulated):
    """Determine smaller time step and its relationship to the larger one"""
    if reference[1] - reference[0] > simulated[1] - simulated[0]:
        print('getMultiple return 1', (reference[1] - reference[0]), (simulated[1] - simulated[0]), (reference[1] - reference[0]) / (simulated[1] - simulated[0]))
        return (reference[1] - reference[0]) / (simulated[1] - simulated[0])
    print('getMultiple return 2', (reference[1] - reference[0]), (simulated[1] - simulated[0]), (simulated[1] - simulated[0]) / (reference[1] - reference[0]))
    return (simulated[1] - simulated[0]) / (reference[1] - reference[0])
def getSize(reference, simulated):
    """Determine smaller sample size"""
    if len(reference) > len(simulated):
        return len(reference)
    return len(simulated)