# This function takes in a single tibble created from combining all of the output csv's 
# It uses grab_vars_of_interest to create a tidy tibble of the different currents of each cell type
# For cell_types, give a vector of cell types e.g., c("A", "D") for alpha and delta
# If average set to TRUE then the function will output the average current across time for each cell and current type

source("grab_vars_of_interest.R")

current_plots <- function(data, var_yaml, cell_types, average) {
  data <- grab_vars_of_interest(data, "current", var_yaml)
  if (average == F) {
    for (cell in cell_types) {
      plot <-  data %>% 
        filter(`Cell Type` == cell) %>% 
        ggplot(aes(Time, `Current (pA)`, color = Current)) +
        geom_path(size=0.1) +
        facet_wrap(facets = vars(ID))
      print(plot)
    }
  } else {
    for (cell in cell_types) {
      plot <-  data %>% 
        filter(`Cell Type` == cell) %>% 
        ggplot(aes(Time, `Current (pA)`, color = Current)) +
        geom_path(size=0.1) +
        facet_wrap(facets = vars(ID))
      print(plot)
    }
    plot <- data %>% 
      group_by(Time, Current, `Cell Type`) %>% 
      summarise("Current Avg (pA)" = mean(`Current (pA)`)) %>% 
      ggplot(aes(Time, `Current Avg (pA)`, color = Current)) +
      geom_path(size=0.1) +
      facet_wrap(facets = vars(`Cell Type`))
    print(plot)
  } 
}