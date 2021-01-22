
# To install R packages sudo add-apt-repository ppa:marutter/c2d4u3.

install.packages("tidyverse")

import_csvs_to_tibble <- function(file_path) {
  list.files(path = file_path,
             pattern = "*.csv",
             full.names = T) %>%
  set_names(nm = (basename(.) %>% tools::file_path_sans_ext())) %>%
  map_dfc(read_csv)
}

grab_vars_of_interest <- function(data, var, var_yaml) {
  if (var == "current") {
    data %>%
      # Find cleaner way to name variables.
      # This gets rid of point process version of currents
      select(-contains("B_pp_iCa_", ignore.case = F),
             -contains("B_pp_iCaL_", ignore.case = F),
             -contains("B_pp_iCaR_", ignore.case = F)) %>%
      select(contains(var_yaml$Current, ignore.case = F),
             # ideally find way to merge all time columns together
             # Time...1 is specified because when combining all
             # individual output csv's into one tibble the Time column repeats.
             Time...1) %>%
      rename(Time = Time...1) %>%
      pivot_longer(-Time,
                   names_to = "Temp",
                   values_to = "Current (pA)") %>%
      separate(Temp,
               into = c("Cell Type", "Current.", "Current", "ID"),
               sep = "_") %>%
               # Current name is repeated in variable name
               # so we only need to keep one
      select(-Current.)
  } else if (var == "voltage") {
    data %>%
      select(contains(var_yaml$Voltage, ignore.case = F),
             Time...1) %>%
      rename(Time = Time...1) %>%
      pivot_longer(-Time,
                   names_to = "Temp",
                   values_to = "Vm (mV)") %>%
      separate(Temp,
               into = c("Cell Type", "ID"),
               sep = "_Vm_")
  } else if (var == "calcium") {
    data %>%
      select(contains(var_yaml$Calcium, ignore.case = F),
             Time...1) %>%
      rename(Time = Time...1) %>%
      pivot_longer(-Time,
                   names_to = "Temp",
                   values_to = "[Ca2+] Cytosol") %>%
      separate(Temp,
               into = c("Cell Type", "Temp1", "Temp2", "ID"),
               sep = "_") %>%
      select(-Temp1, -Temp2)
  } else {
    data %>%
      select(contains(var_yaml$Hormones, ignore.case = F),
             Time...1) %>%
      rename(Time = Time...1) %>%
      pivot_longer(-Time,
                   names_prefix = "*pp_",
                   names_to = "Temp",
                   values_to = "Concentration (pM)") %>%
      separate(Temp,
               into = c("Cell Type", "Hormone", "ID"),
               sep = "_") %>%
               # create new column specifying intracellular or extracellular.
               # Whenever an entry in the Hormone column
               # ends in "o" it will have the value Extracellular
               # in this new column. Otherwise Intracellular
      mutate(Location = case_when(str_detect(Hormone, "o$") == T ~ "Extracellular",
                                  str_detect(Hormone, "o$") == F ~ "Intracellular"),
             Hormone = str_replace(Hormone, "o", ""))
  }
}

voltage_plots <- function(data, var_yaml, cell_types, average) {
  data <- grab_vars_of_interest(data, "voltage", var_yaml)
  if (average == F) {
    for (cell in cell_types) {
      plot <-  data %>% 
        filter(`Cell Type` == cell) %>% 
        ggplot(aes(Time, `Vm (mV)`, color = ID)) +
        geom_path(size=0.1)
      print(plot)
    }
  } else {
    for (cell in cell_types) {
      plot <-  data %>% 
        filter(`Cell Type` == cell) %>% 
        ggplot(aes(Time, `Vm (mV)`, color = ID)) +
        geom_path(size=0.1)
      print(plot)
    }
    plot <- data %>% 
      group_by(Time, `Cell Type`) %>% 
      summarise("Vm Avg (mV)" = mean(`Vm (mV)`)) %>% 
      ggplot(aes(Time, `Vm Avg (mV)`, color = `Cell Type`)) +
      geom_path(size=0.1)
    print(plot)
  }
}

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

hormone_plots <- function(data, var_yaml, cell_types, hormones, average) {
  data <- grab_vars_of_interest(data, "hormone", var_yaml)
  count <- 1
  if (average == F) {
    for (cell in cell_types) {
      plot <-  data %>% 
        filter(`Cell Type` == cell,
               Hormone == hormones[count]) %>% 
        ggplot(aes(Time, `Concentration (pM)`, color = ID)) +
        geom_path(size=0.1, aes(linetype = Location))
      count= count + 1
      print(plot)
    }
  } else {
    for (cell in cell_types) {
      plot <-  data %>% 
        filter(`Cell Type` == cell,
               Hormone == hormones[count]) %>% 
        ggplot(aes(Time, `Concentration (pM)`, color = ID)) +
        geom_path(size=0.1, aes(linetype = Location))
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
      geom_path(size=0.1)
    print(plot)
  }
}

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

file_path="C:/Users/Robert/Desktop/Model-of-Pancreatic-Islets/Outputs/Islet_IND_0_model_0/temp"
variable="hormone"
cell_types=c("A","B","D")
var_yaml="C:/Users/Robert/Desktop/Model-of-Pancreatic-Islets/Outputs/Islet_IND_0_model_0/temp/variables.yaml" 
hormones=c("G","I","S")
average=T
plot_stuff(file_path,variable, var_yaml, cell_types, hormones, average)
