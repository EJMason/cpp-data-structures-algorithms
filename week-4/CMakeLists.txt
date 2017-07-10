cmake_minimum_required(VERSION 3.7)
project(week_4)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-pipe -O2 -std=c++14 -lm")

set(SOURCE_FILES main.cpp)
add_executable(main main.cpp)
add_executable(edit_distance edit_distance.cpp)
add_executable(knapsack knapsack.cpp)
add_executable(lcs3 lcs3.cpp)
add_executable(placing_parentheses placing_parentheses.cpp)
add_executable(primitive_calculator primitive_calculator.cpp)
