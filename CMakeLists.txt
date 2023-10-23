cmake_minimum_required(VERSION 3.2)

project(knight LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(storage)
add_executable(${PROJECT_NAME} main.cpp)

