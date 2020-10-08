# Model-of-Pancreatic-Islets
This project was part of an honors thesis done under Damon Lamb, Alin Dobra, and Tamer Kahveci in the UF Department of CISE for the Summa Cum Laude distinction. 
I developed a model of electrophysiological and hormonal behaviors of endocrine cells of the pancreas using the [NEURON simulation environment](https://www.neuron.yale.edu/neuron/) and experimental constants from previous models.
## Table of contents
* [General info](#general-info)
* [Software](#software)
* [Usage](#usage)
* [Contact](#contact)
## General info
This model is the first whole islet model of endocrine cells parametrized through a supervised learning algorithm. 
The model makes use of Hodgkin-Huxley style differential equations to represent the temporal relationships between the different states of various ion channels and their relationship with electrical potential across a cells membrane.
Experimentally determined constants and reaction kinetics were mainly taken from models developed by [Fridlyand](https://link.springer.com/protocol/10.1007/978-1-62703-068-7_13) and [Watts and Sherman](https://journals.physiology.org/doi/pdf/10.1152/ajpendo.00415.2015).
The main program `GeneticAlgorithm.py` was responsible for dispatching simulations of model instances (simulated in `Model.py`) and selecting from those instances the subset of models which best replicated the time series in a given dataset.
This program was run in a high performance computing environment with a slurm workload manager overseeing access to hardware and software resources.
The Build folder contains the major, separately developed components of the projects with scripts used to test those components at various stages in development.
The Main folder contains the program and all modules used to run it while the Run folder is where the model instances are simulated.
Accordingly, the Outputs folder contains all data generated by the models and the Configuration folder contains the parameters for the models (separated into Value parameters and Mechanism parameters which represent numeric properties and classes of properties representing an ion channel or reaction, respectively).
## Software
* NEURON 7.7.2
* Python 3.8.1
## Usage
The main program can be found in the Model/Main folder and can run on the command line or dispatched as a job.
It can be run through either<br/>
`python GeneticAlgorithm.py`<br/>
or<br/>
`sbatch GA.sbatch`<br/>
If run through a submission script: intended runtime and path to log files need be configured from within `GA.sbatch`. In either case, `GeneticAlgorithm.py` and the env variable in `Islet.py` need to be updated to reflect the desired simulation parameters and the correct environment.
### Paper
https://ufdc.ufl.edu/AA00078930
### Contact
Email: tikaharik@gmail.com, robert727@ufl.edu
