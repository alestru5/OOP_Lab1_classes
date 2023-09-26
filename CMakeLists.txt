
cmake_minimum_required(VERSION 3.16)

project(oop_lab1_classes)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_library(matrix matrix.h matrix.cpp)
add_library(helps help.h help.cpp)

link_libraries(matrix helps)

add_executable(main main.cpp)

