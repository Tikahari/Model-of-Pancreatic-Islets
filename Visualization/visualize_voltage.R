visualize_voltage <- function(data, islet_path) {
  data <- grab_vars_of_interest(data, "voltage")
  for (cell in c("A", "B", "D")) {
    plot <-  data %>% 
        filter(`Cell Type` == cell) %>% 
        ggplot(aes(Time, `Vm (mV)`, color = ID)) +
        geom_path(size=0.3)
      ggsave(filename = str_c(cell, "_Voltage.png"),
             device = "png",
             path = str_c(islet_path, "/Plots/Voltage"))
    }
    plot <- data %>% 
      group_by(Time, `Cell Type`) %>% 
      summarise("Vm Avg (mV)" = mean(`Vm (mV)`)) %>% 
      ggplot(aes(Time, `Vm Avg (mV)`, color = `Cell Type`)) +
      geom_path(size=0.3)
    ggsave(filename = "Voltage_Avg.png",
             device = "png",
             path = str_c(islet_path, "/Plots/Voltage"))  
  }