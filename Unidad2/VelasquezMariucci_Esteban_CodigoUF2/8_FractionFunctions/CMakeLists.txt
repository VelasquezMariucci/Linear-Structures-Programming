cmake_minimum_required(VERSION 3.29)
project(FractionFunctions)

set(CMAKE_CXX_STANDARD 23)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(FractionFunctions main.cpp
        include/Fraction.h
        src/Fraction.cpp
        include/FractionUtils.h
        src/FractionUtils.cpp
        src/FractionUtils.cpp)
