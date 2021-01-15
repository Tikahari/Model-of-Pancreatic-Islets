# This function takes in a single tibble created from combining all of the output csv's 
# It uses grab_vars_of_interest to create a tidy tibble of the intracellular calcium concentration of each cell type
# For cell_types, give a vector of cell types e.g., c("A", "D") for alpha and delta
# If average set to TRUE then the function will output the average calcium concentration across time for each cell type

calcium_plots <- function(data, var_yaml, cell_types, average) {
  data <- grab_vars_of_interest(data, "calcium", var_yaml)
  if (average == F) {
    for (cell in cell_types) {
      plot <-  data %>% 
        filter(`Cell Type` == cell) %>% 
        ggplot(aes(Time, `[Ca2+] Cytosol`, color = ID)) +
        geom_path(size=0.1)
      print(plot)
    }
  } else {
    for (cell in cell_types) {
      plot <-  data %>% 
        filter(`Cell Type` == cell) %>% 
        ggplot(aes(Time, `[Ca2+] Cytosol`, color = ID)) +
        geom_path(size=0.1)
      print(plot)
    }
    plot <- data %>% 
      group_by(Time, `Cell Type`) %>% 
      summarise("Avg [Ca2+] Cytosol" = mean(`[Ca2+] Cytosol`)) %>% 
      ggplot(aes(Time, `Avg [Ca2+] Cytosol`, color = `Cell Type`)) +
      geom_path(size=0.1)
    print(plot)
  }
}