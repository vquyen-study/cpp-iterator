cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)

project(iterator)

# add_library(iter SHARED iterator.cpp)
include_directories(include)
add_executable(iter src/main.cpp)

