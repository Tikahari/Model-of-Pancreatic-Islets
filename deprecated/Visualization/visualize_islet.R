source("/blue/lamb/robert727/temp/Model-of-Pancreatic-Islets/Visualization/import_csvs_to_tibble.R")
source("/blue/lamb/robert727/temp/Model-of-Pancreatic-Islets/Visualization/grab_vars_of_interest.R")
source("/blue/lamb/robert727/temp/Model-of-Pancreatic-Islets/Visualization/visualize_voltage.R")
source("/blue/lamb/robert727/temp/Model-of-Pancreatic-Islets/Visualization/visualize_currents.R")
source("/blue/lamb/robert727/temp/Model-of-Pancreatic-Islets/Visualization/visualize_calcium.R")
source("/blue/lamb/robert727/temp/Model-of-Pancreatic-Islets/Visualization/visualize_hormones.R")

library(tidyverse)
library(yaml)

args = commandArgs(trailingOnly=TRUE)


visualize_islet <- function(islet_path) {
  data <- import_csvs_to_tibble(islet_path)
  visualize_voltage(data, islet_path)
  visualize_currents(data, islet_path)
  visualize_calcium(data, islet_path)
  visualize_hormones(data, islet_path)
}
visualize_islet(args[1])