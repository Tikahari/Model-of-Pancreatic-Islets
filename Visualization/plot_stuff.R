# This is the main visualization function
# it takes in the path of where the output csv's are located
# See the different plot functions for details
# It is likely the different plot functions can be combined into one since they are all so similar.

source("import_csvs_to_tibble.R")
source("voltage_plots.R")
source("current_plots.R")
source("calcium_plots.R")
source("hormone_plots.R")

args <- commandArgs(trailingOnly = TRUE)

print(args[1])
print(args[2])
print(args[3])
print(args[4])
print(args[5])
print(args[6])

plot_stuff <- function(path, variable, var_yaml, cell_types, hormones, average) {
  data <- import_csvs_to_tibble(path)
  if (variable == "voltage") {
    voltage_plots(data, var_yaml, cell_types, average)
  } else if (variable == "current") {
    current_plots(data, var_yaml, cell_types, average)
  } else if (variable == "calcium") {
    calcium_plots(data, var_yaml, cell_types, average)
  } else {
    hormone_plots(data, var_yaml, cell_types, hormones, average)
  }
}

plot_stuff(args[1], args[2], args[3], args[4], args[5], args[6])