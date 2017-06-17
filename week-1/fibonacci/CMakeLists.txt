cmake_minimum_required(VERSION 3.7)
project(fibonacci)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "-pipe -O2 -std=c++14 -lm")

set(SOURCE_FILES main.cpp fibonacci.cp fibonacci_huge.cpp fibonacci_last_digit.cpp)

add_executable(main main.cpp)
add_executable(fibonacci fibonacci.cpp)
add_executable(fibonacci_huge fibonacci_huge.cpp)
add_executable(fibonacci_last_digit fibonacci_last_digit.cpp)
add_executable(fibonacci_partial_sum fibonacci_partial_sum.cpp)
add_executable(fibonacci_sum_last_digit fibonacci_sum_last_digit.cpp)
add_executable(gcd gcd.cpp)
add_executable(lcm lcm.cpp)