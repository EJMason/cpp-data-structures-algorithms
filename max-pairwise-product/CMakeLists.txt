cmake_minimum_required(VERSION 3.7)
project(cpp_data_structures_algorithms)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "-pipe -O2 -std=c++14 -lm")

set(SOURCE_FILES main.cpp)
add_executable(cpp_data_structures_algorithms ${SOURCE_FILES})