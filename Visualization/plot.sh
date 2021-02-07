
# To install R packages sudo add-apt-repository ppa:marutter/c2d4u3.
Model_run = Islet_model_4_500_0.35_0.50_0.15
install.packages("tidyverse")

islet_path="/blue/lamb/robert727/temp/Model-of-Pancreatic-Islets/${Model_run}"
variable="hormone"
cell_types=c("A","B","D")
var_yaml="C:/Users/Robert/Desktop/Model-of-Pancreatic-Islets/Outputs/Islet_IND_0_model_0/temp/variables.yaml" 
hormones=c("G","I","S")
average=T
plot_stuff(file_path,variable, var_yaml, cell_types, hormones, average)
