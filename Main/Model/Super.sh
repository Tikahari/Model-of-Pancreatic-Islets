#!/bin/bash

id="model_5x5x5_10000ms_0.15_0.60_0.25"
size="4"
simulation_time=15000
alpha_probability=0.15
beta_probability=0.60
delta_probability=0.25
alpha_beta_combined=$(echo "$alpha_probability + $beta_probability" | bc)
total=$(echo "$alpha_probability + $beta_probability + $delta_probability" | bc)
if [[ $total != 1.00 ]]
then
    echo "ERROR: probabilities add to $total"
    exit
fi
echo -e "\nRunning model with:\nid=$id\nsize=$size\nsimulation_time=$simulation_time\nalpha_probability=$alpha_probability\nbeta_proability=$beta_probability\ndelta_probability=$delta_probability\n"
read -n 1 -p "Verify with enter"
touch log.txt
python3 Super.py $id $size 
echo "------------ Super.py complete ----------"
python3 Compile.py $id $size
echo "------------ Compile.py complete ----------"
python3 Model.py $id $size $simulation_time $alpha_probability $alpha_beta_combined
echo "------------ Model.py complete ----------"
