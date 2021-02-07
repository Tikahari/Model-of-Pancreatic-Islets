#!/bin/bash
# ml ufrc; srundev --time=10:00:00 --mem=24GB
# Values for each glucose level
# G1 gkatpbara=3, gkatpb=150, gkatpbard=0.29, kserca=0.05
# G7 gkatpbara=0.6, gkatpb=85, gkatpbard=0.27, kserca=0.5
# G11 gkatpbara=0.15, gkatpb=25, gkatpbard=0.18, kserca=0.5
size="4"
simulation_time=500
alpha_probability=0.35
beta_probability=0.50
delta_probability=0.15
alpha_beta_combined=$(echo "$alpha_probability + $beta_probability" | bc)
id="model_${size}_${simulation_time}_${alpha_probability}_${beta_probability}_${delta_probability}_3"
total=$(echo "$alpha_probability + $beta_probability + $delta_probability" | bc)
if [[ $total != 1.00 ]]
then
    echo "ERROR: probabilities add to $total"
    exit
fi
echo -e "\nRunning model with:\nid=$id\nsize=$size\nsimulation_time=$simulation_time\nalpha_probability=$alpha_probability\nbeta_proability=$beta_probability\ndelta_probability=$delta_probability\n"
read -n 1 -p "Verify with enter"
touch log.txt
ml neuron
python3 Super.py $id $size 
echo "------------ Super.py complete ----------"
python3 Compile.py $id $size
echo "------------ Compile.py complete ----------"
python3 Model.py $id $size $simulation_time $alpha_probability $alpha_beta_combined
echo "------------ Model.py complete ----------"
