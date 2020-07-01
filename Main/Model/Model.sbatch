#!/bin/bash
#SBATCH --job-name=Model_MOPI
#SBATCH --account=lamb
#SBATCH --qos=lamb-b
#SBATCH --time=2:00:00
#SBATCH --mem=64GB
#SBATCH --ntasks=1
#SBATCH --output=/ufrc/lamb/tikaharikhanal/Model-of-Pancreatic-Islets/Main/Run/Model_MOPI_$Run_$Generation_%j.log

pwd; hostname; date
echo "Run islet $SLURM_ARRAY_TASK_ID for generation $Generation in run $Run"
ml neuron; ml intel/2019; ml openmpi

python Compile.py $Generation_$SLURM_ARRAY_TASK_ID $Run $Dimensions
python Model.py $Generation_$SLURM_ARRAY_TASK_ID $Run $Alpha_probability $Alpha_Beta_probability $Dimensions

date