cmake_minimum_required(VERSION 3.2)

project(knight LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(${PROJECT_NAME} main.cpp)


add_subdirectory(storage)
target_link_libraries(${PROJECT_NAME} storage)

add_subdirectory(common)
target_link_libraries(${PROJECT_NAME} common)

add_subdirectory(players)
target_link_libraries(${PROJECT_NAME} players)

add_subdirectory(logic)
target_link_libraries(${PROJECT_NAME} logic)
