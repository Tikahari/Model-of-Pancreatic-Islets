#!/bin/bash
#SBATCH --job-name=Model_MOPI
#SBATCH --account=vabfmc
#SBATCH --qos=vabfmc-b
#SBATCH --time=72:00:00
#SBATCH --mem=64GB
#SBATCH --ntasks=1
#SBATCH --output=/ufrc/lamb/tikaharikhanal/Model-of-Pancreatic-Islets/Main/Run/Model_MOPI_ZY_ZZ.log

pwd; hostname; date
echo 'Run islet $SLURM_ARRAY_TASK_ID for generation ZY'
ml neuron; ml intel/2019; ml openmpi

python Compile.py ZY_$SLURM_ARRAY_TASK_ID ZU
python Model.py ZY_$SLURM_ARRAY_TASK_ID ZX ZW ZV ZU

date