#!/bin/bash
#SBATCH --job-name=Model_MOPI
#SBATCH --account=vabfmc
#SBATCH --qos=vabfmc-b
#SBATCH --time=12:00:00
#SBATCH --mem=128GB
#SBATCH --ntasks=1
#SBATCH --output=/blue/lamb/tikaharikhanal/Model-of-Pancreatic-Islets/Main/Model/logfile.txt

pwd; hostname; date;

ml neuron
ml intel/2019
ml openmpi

python Model.py 0_model_0 0 0.15 0.75 3 /blue/lamb/tikaharikhanal/Model-of-Pancreatic-Islets/Main/Run/data/fridlyand_VCell_vp.csv -40 20 1

date;