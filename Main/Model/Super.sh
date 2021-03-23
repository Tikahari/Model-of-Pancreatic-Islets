#!/bin/bash
# ml ufrc; srundev --time=10:00:00 --mem=24GB
# Values for each glucose level
# G1 gkatpbara=3, gkatpb=150, gkatpbard=0.29, kserca=0.05
# G7 gkatpbara=0.6, gkatpb=85, gkatpbard=0.27, kserca=0.5
# G11 gkatpbara=0.15, gkatpb=25, gkatpbard=0.18, kserca=0.5
num_cells=3
islet_radius="1"
simulation_time=10000
alpha_probability=0.33
beta_probability=0.34
delta_probability=0.33
alpha_beta_combined=$(echo "$alpha_probability + $beta_probability" | bc)
id="model_${islet_radius}_${simulation_time}_${alpha_probability}_${beta_probability}_${delta_probability}_3"
total=$(echo "$alpha_probability + $beta_probability + $delta_probability" | bc)
islet_path="/blue/lamb/robert727/temp/Model-of-Pancreatic-Islets/Outputs/Islet_${id}"
hormones="c('G', 'I', 'Sst')"
if [[ $total != 1.00 ]]
then
    echo "ERROR: probabilities add to $total"
    exit
fi
echo -e "\nRunning model with:\nid=$id\nislet_radius=$islet_radius\nsimulation_time=$simulation_time\nalpha_probability=$alpha_probability\nbeta_proability=$beta_probability\ndelta_probability=$delta_probability\n"
read -n 1 -p "Verify with enter"
touch log.txt
ml neuron
python3 Super.py $id $islet_radius $num_cells $alpha_probability $beta_probability
echo "------------ Super.py complete ----------"
python3 Compile.py $id $islet_radius $num_cells
echo "------------ Compile.py complete ----------"
python3 Model.py $id $islet_radius $num_cells $simulation_time $alpha_probability $beta_probability
echo "------------ Model.py complete ----------"
ml R
Rscript /blue/lamb/robert727/temp/Model-of-Pancreatic-Islets/Visualization/visualize_islet.R $islet_path
echo "------------ visualize_islets.R complete ----------"
