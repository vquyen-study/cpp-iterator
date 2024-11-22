cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)

project(iterator)

# add_library(iter SHARED iterator.cpp)
add_executable(iter main.cpp iterator.cpp)

