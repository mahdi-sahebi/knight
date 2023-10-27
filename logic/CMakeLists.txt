add_subdirectory(players)
add_library(logic STATIC
  location.hpp location.cpp
  grid.hpp grid.cpp
  data_manager.hpp data_manager.cpp
  logic.hpp logic.cpp)
target_link_libraries(logic storage)
