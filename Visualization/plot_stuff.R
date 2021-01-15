# This is the main visualization function
# it takes in the path of where the output csv's are located
# See the different plot functions for details
# It is likely the different plot functions can be combined into one since they are all so similar.

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