cmake_minimum_required(VERSION 3.16)
project(modify_brown)

set(CMAKE_CXX_STANDARD 14)

link_libraries(pthread atomic)

add_executable(modify_brown main.cpp )