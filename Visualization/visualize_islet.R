source("/blue/lamb/robert727/temp/Model-of-Pancreatic-Islets/Visualization/import_csvs_to_tibble.R")
source("/blue/lamb/robert727/temp/Model-of-Pancreatic-Islets/Visualization/grab_vars_of_interest.R")
source("/blue/lamb/robert727/temp/Model-of-Pancreatic-Islets/Visualization/visualize_voltage.R")
source("/blue/lamb/robert727/temp/Model-of-Pancreatic-Islets/Visualization/visualize_currents.R")
source("/blue/lamb/robert727/temp/Model-of-Pancreatic-Islets/Visualization/visualize_calcium.R")
source("/blue/lamb/robert727/temp/Model-of-Pancreatic-Islets/Visualization/visualize_hormones.R")

visualize_islet <- function(islet_path, var_yaml, hormones) {
  data <- import_csvs_to_tibble(islet_path)
  visualize_voltage(data, var_yaml, islet_path)
  visualize_currents(data, var_yaml, islet_path)
  visualize_calcium(data, var_yaml, islet_path)
  visualize_hormones(data, var_yaml, islet_path, hormones)
}