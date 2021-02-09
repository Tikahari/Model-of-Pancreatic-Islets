visualize_calcium <- function(data, islet_path) {
  data <- grab_vars_of_interest(data, "calcium")
  for (cell in c("A", "B", "D")) {
      plot <-  data %>% 
        filter(`Cell Type` == cell) %>% 
        ggplot(aes(Time, `[Ca2+] Cytosol`, color = ID)) +
        geom_path(size=0.3)
      ggsave(filename = str_c(cell, "_Calcium.png"),
             device = "png",
             path = str_c(islet_path, "/Plots/Calcium"))
    }
    plot <- data %>% 
      group_by(Time, `Cell Type`) %>% 
      summarise("Avg [Ca2+] Cytosol" = mean(`[Ca2+] Cytosol`)) %>% 
      ggplot(aes(Time, `Avg [Ca2+] Cytosol`, color = `Cell Type`)) +
      geom_path(size=0.3)
    ggsave(filename = "Calcium_Avg.png",
             device = "png",
             path = str_c(islet_path, "/Plots/Calcium"))
  }