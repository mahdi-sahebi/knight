add_library(players STATIC
  player.hpp player.cpp
  pawn.hpp pawn.cpp
  bishop.hpp bishop.cpp
  knight.hpp knight.cpp
  player_manager.hpp player_manager.cpp)

target_link_libraries(players common)
