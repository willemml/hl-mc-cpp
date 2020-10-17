cmake_minimum_required(VERSION 3.17)
project(hl_mc_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(hl_mc_cpp main.cpp CLI.cpp CLI.h Command.cpp Command.h)