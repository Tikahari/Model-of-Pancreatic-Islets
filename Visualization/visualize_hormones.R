visualize_hormones <- function(data, islet_path) {
  hormones = c("G", "I", "Sst") 
  data <- grab_vars_of_interest(data, "hormone")
  count <- 1
    for (cell in c("A", "B", "D")) {
      plot <-  data %>% 
        filter(`Cell Type` == cell,
               Hormone == hormones[count]) %>% 
        ggplot(aes(Time, `Concentration (pM)`, color = ID)) +
        geom_path(size=0.3, aes(linetype = Location))
      count= count + 1
      ggsave(filename = str_c(cell, "_Hormones.png"),
             device = "png",
             path = str_c(islet_path, "/Plots/Hormones"))
    }
    cell_types = c("A", "B", "D")
    plot <- data %>% 
      filter((Hormone == hormones[1] & `Cell Type` == cell_types[1]) |
               (Hormone == hormones[2] & `Cell Type` == cell_types[2]) |
               (Hormone == hormones[3] & `Cell Type` == cell_types[3])) %>% 
      group_by(Time, `Cell Type`, Hormone, Location) %>% 
      summarise("Avg Concentration (pM)" = mean(`Concentration (pM)`)) %>% 
      ggplot(aes(Time, `Avg Concentration (pM)`, color = `Cell Type`, linetype = Location)) +
      geom_path(size=0.3)
    ggsave(filename = "Hormones_Avg.png",
             device = "png",
             path = str_c(islet_path, "/Plots/Hormones"))
  }