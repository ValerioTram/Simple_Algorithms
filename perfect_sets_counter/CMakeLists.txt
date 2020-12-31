cmake_minimum_required(VERSION 3.5)

project(perfect_sets_counter LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core)

add_executable(perfect_sets_counter
  main.cpp
  count_sets.cpp
  count_sets.h
  binary_conv.cpp
  binary_conv.h
  common_libs.h
)
target_link_libraries(perfect_sets_counter Qt5::Core)
