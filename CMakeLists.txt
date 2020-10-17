cmake_minimum_required(VERSION 3.17)
project(hl_mc_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(hl_mc_cpp src/main.cpp src/CLI.cpp src/CLI.h src/Command.cpp src/Command.h)