cmake_minimum_required(VERSION 3.7)
project(week_3)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "-pipe -O2 -std=c++14 -lm")

add_executable(main main.cpp)
add_executable(binary_search binary_search.cpp)
add_executable(closest closest.cpp)
add_executable(inversions inversions.cpp)
add_executable(majority_element majority_element.cpp)
add_executable(points_and_segments points_and_segments.cpp)
add_executable(sorting sorting.cpp)