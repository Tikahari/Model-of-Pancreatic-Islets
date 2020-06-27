#!/bin/bash
#SBATCH --job-name=Model_MOPI
#SBATCH --mail-type=END,FAIL
#SBATCH --mail-user=tikaharikhanal@ufl.edu
#SBATCH --account=vabfmc
#SBATCH --qos=vabfmc-b
#SBATCH --time=72:00:00
#SBATCH --mem=64GB
#SBATCH --ntasks=1
#SBATCH --output=.temp/Model_MOPI_%j.log

pwd; hostname; date
echo "Run Islet $SLURM_ARRAY_TASK_ID for Generation _"
ml neuron; ml intel/2019; ml openmpi

python Model.py 1_$SLURM_ARRAY_TASK_ID

date
