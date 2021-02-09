# ml R

size="4"
simulation_time=500
alpha_probability=0.35
beta_probability=0.50
delta_probability=0.15
alpha_beta_combined=$(echo "$alpha_probability + $beta_probability" | bc)
id="Islet_model_${size}_${simulation_time}_${alpha_probability}_${beta_probability}_${delta_probability}"
islet_path="/blue/lamb/robert727/temp/Model-of-Pancreatic-Islets/Outputs/${id}"
echo $file_path
hormones="c('G', 'I', 'Sst')"
Rscript visualize_islet.R $islet_path