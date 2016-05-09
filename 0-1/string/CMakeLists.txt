cmake_minimum_required(VERSION 2.8)

# Make PROJECT_SOURCE_DIR, PROJECT_BINARY_DIR, and PROJECT_NAME available.
set(PROJECT_NAME String)
project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "-g -O1 -std=c++11")

add_executable(StringPermutation StringPermutation.cpp)
