add_library(logic STATIC
  grid.hpp grid.cpp
  data_manager.hpp data_manager.cpp
  logic.hpp logic.cpp)
target_link_libraries(logic storage)
target_link_libraries(logic players)
