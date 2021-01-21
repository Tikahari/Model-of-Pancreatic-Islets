# This function takes in the output of import_csvs_to_tibble
# It grabs the var you specify for each cell type

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