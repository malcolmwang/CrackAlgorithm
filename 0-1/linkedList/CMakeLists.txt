cmake_minimum_required(VERSION 2.8)

# Make PROJECT_SOURCE_DIR, PROJECT_BINARY_DIR, and PROJECT_NAME available.
set(PROJECT_NAME LinkedList)
project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "-g -O1 -std=c++11")
set(HEADER_FILES ../utils/ListNode.h)

include_directories(../utils/)
add_executable(PrintListFromEnd PrintListFromEnd.cpp)
add_executable(ReverseList ReverseList.cpp)
