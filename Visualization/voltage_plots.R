# This function takes in a single tibble created from combining all of the output csv's 
# It uses grab_vars_of_interest to create a tidy tibble of the membrane potential of each cell type
# For cell_types, give a vector of cell types e.g., c("A", "D") for alpha and delta
# If average set to TRUE then the function will output the average membrane potential across time for each cell type


voltage_plots <- function(data, var_yaml, cell_types, average) {
  data <- grab_vars_of_interest(data, "voltage", var_yaml)
  if (average == F) {
    for (cell in cell_types) {
      plot <-  data %>% 
        filter(`Cell Type` == cell) %>% 
        ggplot(aes(Time, `Vm (mV)`, color = ID)) +
        geom_path(size=0.3)
      print(plot)
    }
  } else {
    for (cell in cell_types) {
      plot <-  data %>% 
        filter(`Cell Type` == cell) %>% 
        ggplot(aes(Time, `Vm (mV)`, color = ID)) +
        geom_path(size=0.3)
      print(plot)
    }
    plot <- data %>% 
      group_by(Time, `Cell Type`) %>% 
      summarise("Vm Avg (mV)" = mean(`Vm (mV)`)) %>% 
      ggplot(aes(Time, `Vm Avg (mV)`, color = `Cell Type`)) +
      geom_path(size=0.3)
    print(plot)
  }
}