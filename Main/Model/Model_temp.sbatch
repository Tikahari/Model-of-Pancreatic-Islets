#!/bin/bash
#SBATCH --job-name=Model_MOPI
#SBATCH --account=lamb
#SBATCH --qos=lamb-b
#SBATCH --time=2:00:00
#SBATCH --mem=128GB
#SBATCH --ntasks=1
#SBATCH --output=/ufrc/lamb/tikaharikhanal/Model-of-Pancreatic-Islets/Main/Run/Model_MOPI_0_1_%j.log

pwd; hostname; date
echo "Run islet $SLURM_ARRAY_TASK_ID for generation 1 in run 0"
ml neuron; ml intel/2019; ml openmpi

python Compile.py 1_$SLURM_ARRAY_TASK_ID 0 5
python Model.py 1_$SLURM_ARRAY_TASK_ID 0 0.15 0.75 5

date