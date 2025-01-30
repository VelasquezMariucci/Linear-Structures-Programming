cmake_minimum_required(VERSION 3.29)
project(9_PersonClass)

set(CMAKE_CXX_STANDARD 23)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(9_PersonClass main.cpp
        src/Person.cpp
        include/Person.h)
