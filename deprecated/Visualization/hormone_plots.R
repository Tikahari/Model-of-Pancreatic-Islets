# This function takes in a single tibble created from combining all of the output csv's 
# It uses grab_vars_of_interest to create a tidy tibble of the hormone concentration of each cell type
# For cell_types, give a vector of cell types e.g., c("A", "D") for alpha and delta
# For hormones, give a vector of hormones you want to visualize and make sure the order matches up with cell_type
# e.g., if you wanted to look at glucagon in alphas and somatostatin in deltas, hormones = c("G", "S") and cell_type as above
# If average set to TRUE then the function will output the average hormone concentration across time for each cell type
# There are issues with the average plot as of now


hormone_plots <- function(data, var_yaml, cell_types, hormones, average) {
  data <- grab_vars_of_interest(data, "hormone", var_yaml)
  count <- 1
  if (average == F) {
    for (cell in cell_types) {
      plot <-  data %>% 
        filter(`Cell Type` == cell,
               Hormone == hormones[count]) %>% 
        ggplot(aes(Time, `Concentration (pM)`, color = ID)) +
        geom_path(size=0.3, aes(linetype = Location))
      count= count + 1
      print(plot)
    }
  } else {
    for (cell in cell_types) {
      plot <-  data %>% 
        filter(`Cell Type` == cell,
               Hormone == hormones[count]) %>% 
        ggplot(aes(Time, `Concentration (pM)`, color = ID)) +
        geom_path(size=0.3, aes(linetype = Location))
      count= count + 1
      print(plot)
    }
    plot <- data %>% 
      # Find a more elegant way to do this. This just ensures we only graph the each cells corresponding hormone
      filter((Hormone == hormones[1] & `Cell Type` == cell_types[1]) |
               (Hormone == hormones[2] & `Cell Type` == cell_types[2]) |
               (Hormone == hormones[3] & `Cell Type` == cell_types[3])) %>% 
      group_by(Time, `Cell Type`, Hormone, Location) %>% 
      summarise("Avg Concentration (pM)" = mean(`Concentration (pM)`)) %>% 
      ggplot(aes(Time, `Avg Concentration (pM)`, color = `Cell Type`, linetype = Location)) +
      geom_path(size=0.3)
    print(plot)
  }
}