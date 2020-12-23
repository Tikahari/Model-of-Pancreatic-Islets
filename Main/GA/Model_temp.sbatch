#!/bin/bash
#SBATCH --job-name=Model_MOPI
#SBATCH --account=vabfmc
#SBATCH --qos=vabfmc-b
#SBATCH --time=12:00:00
#SBATCH --mem=128GB
#SBATCH --ntasks=1
#SBATCH --output=/blue/lamb/tikaharikhanal/Model-of-Pancreatic-Islets/Main/Run/GA_MOPI_0_1_%j.log

pwd; hostname; date
echo "Run islet $SLURM_ARRAY_TASK_ID for generation 1 in run 0"
ml neuron; ml intel/2019; ml openmpi

python Compile.py 1_$SLURM_ARRAY_TASK_ID 0 4
python Model.py 1_$SLURM_ARRAY_TASK_ID 0 0.15 0.75 4 /blue/lamb/tikaharikhanal/Model-of-Pancreatic-Islets/Main/Run/data/fridlyand_VCell_vp.csv 400 20 1

date