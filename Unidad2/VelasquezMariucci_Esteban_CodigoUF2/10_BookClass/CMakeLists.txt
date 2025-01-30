cmake_minimum_required(VERSION 3.29)
project(10_BookClass)

set(CMAKE_CXX_STANDARD 23)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(10_BookClass main.cpp
        src/Book.cpp
        include/Book.h)
