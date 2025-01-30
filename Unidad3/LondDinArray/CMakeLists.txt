cmake_minimum_required(VERSION 3.29)
project(LondDinArray)

set(CMAKE_CXX_STANDARD 23)

add_executable(LondDinArray main.cpp
        LongDynArray.h
        "Dinarrays.h")
