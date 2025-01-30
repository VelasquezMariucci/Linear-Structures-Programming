cmake_minimum_required(VERSION 3.29)
project(Estructuras)

set(CMAKE_CXX_STANDARD 23)

add_executable(Estructuras main.cpp
        include/Dynarray.h
        include/Vector.h)
