visualize_currents <- function(data, islet_path) {
  data <- grab_vars_of_interest(data, "current")
  for (cell in c("A", "B", "D")) {
      plot <-  data %>% 
        filter(`Cell Type` == cell) %>% 
        ggplot(aes(Time, `Current (pA)`, color = Current)) +
        geom_path(size=0.3) +
        facet_wrap(facets = vars(ID))
      ggsave(filename = str_c(cell, "_Currents.png"),
             device = "png",
             path = str_c(islet_path, "/Plots/Currents"))
    }
    plot <- data %>% 
      group_by(Time, Current, `Cell Type`) %>% 
      summarise("Current Avg (pA)" = mean(`Current (pA)`)) %>% 
      ggplot(aes(Time, `Current Avg (pA)`, color = Current)) +
      geom_path(size=0.3) +
      facet_wrap(facets = vars(`Cell Type`))
    ggsave(filename = "Currents_Avg.png",
             device = "png",
             path = str_c(islet_path, "/Plots/Currents"))
  }