#!/bin/bash
#SBATCH --job-name=Model_MOPI
#SBATCH --account=vabfmc
#SBATCH --qos=vabfmc-b
#SBATCH --time=12:00:00
#SBATCH --mem=128GB
#SBATCH --ntasks=1
#SBATCH --output=$Output

pwd; hostname; date
echo "Run islet $SLURM_ARRAY_TASK_ID for generation $Generation in run $Run"
ml neuron; ml intel/2019; ml openmpi

python Compile.py $Generation_$SLURM_ARRAY_TASK_ID $Run $Dimensions
python Model.py $Generation_$SLURM_ARRAY_TASK_ID $Run $Alpha_probability $Alpha_Beta_probability $Dimensions $Data $Mean $Threshold $Slope

date