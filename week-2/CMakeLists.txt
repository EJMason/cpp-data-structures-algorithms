cmake_minimum_required(VERSION 3.7)
project(week_2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-pipe -O2 -std=c++14 -lm")

set(SOURCE_FILES main.cpp)

add_executable(week_2 ${SOURCE_FILES})
add_executable(change change.cpp)
add_executable(covering_segments covering_segments.cpp)
add_executable(different_summands different_summands.cpp)
add_executable(dot_product dot_product.cpp)
add_executable(fractional_knapsack fractional_knapsack.cpp)
add_executable(largest_number largest_number.cpp)