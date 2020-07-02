#!/bin/bash
#SBATCH --job-name=Model_MOPI
#SBATCH --account=vabfmc
#SBATCH --qos=vabfmc-b
#SBATCH --time=2:00:00
#SBATCH --mem=16GB
#SBATCH --ntasks=1
#SBATCH --output=/ufrc/lamb/tikaharikhanal/Model-of-Pancreatic-Islets/Main/Run/Model_MOPI_0_1_1.log

pwd; hostname; date
echo "Run islet 1 for generation 1 in run 0"
ml neuron; ml intel/2019; ml openmpi
python Compile.py 1_1 0 5
python Model.py 1_1 0 0.15 0.75 5

date