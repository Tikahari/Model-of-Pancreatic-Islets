#!/bin/bash
#SBATCH --job-name=GA_MOPI
#SBATCH --mail-type=END,FAIL
#SBATCH --mail-user=tikaharikhanal@ufl.edu
#SBATCH --time=72:00:00
#SBATCH --mem=256GB
#SBATCH --ntasks=1
#SBATCH --output=.temp/GA_MOPI_%j.log

pwd; hostname; date

ml neuron; ml intel/2019; ml openmpi

python GeneticAlgorithm.py

date