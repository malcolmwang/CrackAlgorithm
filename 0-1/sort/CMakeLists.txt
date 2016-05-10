cmake_minimum_required(VERSION 2.8)

# Make PROJECT_SOURCE_DIR, PROJECT_BINARY_DIR, and PROJECT_NAME available.
set(PROJECT_NAME QuickSort)
project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "-g -Wall")

add_executable(QuickSort QuickSort.cpp)
add_executable(HeapSort HeapSort.cpp)
