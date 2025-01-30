cmake_minimum_required(VERSION 3.29)
project(TrueDirectionCalculator)

set(CMAKE_CXX_STANDARD 23)

add_executable(TrueDirectionCalculator main.cpp
        Calculator.h
        Calculator.cpp)
