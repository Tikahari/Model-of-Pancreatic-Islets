#!/bin/bash
#SBATCH --job-name=Model_MOPI
#SBATCH --account=vabfmc
#SBATCH --qos=vabfmc-b
#SBATCH --time=2:00:00
#SBATCH --mem=16GB
#SBATCH --ntasks=1
#SBATCH --output=/ufrc/lamb/tikaharikhanal/Model-of-Pancreatic-Islets/Main/Run/Model_MOPI_1_0_$SLURM_ARRAY_TASK_ID.log

pwd; hostname; date
echo "Run islet $SLURM_ARRAY_TASK_ID for generation $SLURM_ARRAY_TASK_ID"
ml neuron; ml intel/2019; ml openmpi
python Compile.py 1_1 5
python Model.py 1_1 0 0.15 0.75 5

date