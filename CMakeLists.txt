cmake_minimum_required(VERSION 3.21)
project(Vector)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Vector
        main.cpp
        Vector.h)
