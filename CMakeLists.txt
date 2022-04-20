cmake_minimum_required(VERSION 3.21)
project(Project-Euler)

set(CMAKE_CXX_STANDARD 20)

add_executable(Project-Euler src/main.cpp include/prime_lib.h include/print_lib.h problems/problem1.h include/timer.h problems/problem2.h)
