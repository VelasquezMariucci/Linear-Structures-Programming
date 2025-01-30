cmake_minimum_required(VERSION 3.29)
project(6_RectangleClass)

set(CMAKE_CXX_STANDARD 23)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(6_RectangleClass main.cpp
        include/Rectangle.h
        src/Rectangle.cpp)
