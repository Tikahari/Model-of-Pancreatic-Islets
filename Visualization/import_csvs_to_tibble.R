# This function takes in the path directory where the output csv's are located
# Reads their names into a list
# set_names removes the higher order path directories
# from the file name and the extension at the end
# This leaves the files with names like a_21, d_3, etc.
# map_dfc applies the function read_csv to all of the files in the list
# and then combines them columnwise (i.e., dfr vs. dfr for row)

import_csvs_to_tibble <- function(file_path) {
  list.files(path = file_path,
             pattern = "*.csv",
             full.names = T) %>%
  set_names(nm = (basename(.) %>% tools::file_path_sans_ext())) %>%
  map_dfc(read_csv)
}