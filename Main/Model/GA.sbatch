#!/bin/bash
#SBATCH --job-name=GA_MOPI
#SBATCH --mail-type=END,FAIL
#SBATCH --mail-user=tikaharikhanal@ufl.edu
#SBATCH --time=10:00:00
#SBATCH --ntasks=1
#SBATCH --output=/ufrc/lamb/tikaharikhanal/Model-of-Pancreatic-Islets/Main/Run/GA_MOPI_%j.log

pwd; hostname; date

ml neuron; ml intel/2019; ml openmpi

python GeneticAlgorithm.py

date
