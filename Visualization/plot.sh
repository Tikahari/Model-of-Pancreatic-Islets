file_path="C:/Users/Robert/Desktop/Model-of-Pancreatic-Islets/Outputs/Islet_IND_0_model_0/temp"
variable=hormone
cell_types=("A" "B" "D")
var_yaml="C:/Users/Robert/Desktop/Model-of-Pancreatic-Islets/Outputs/Islet_IND_0_model_0/temp/variables.yaml" 
hormones=("G" "I" "S")
average=T
Rscript plot_stuff.R $file_path \
$variable ${cell_types[*]} \
$var_yaml ${hormones[*]} $average