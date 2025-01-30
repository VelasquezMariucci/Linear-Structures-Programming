cmake_minimum_required(VERSION 3.29)
project(15_FileList)

set(CMAKE_CXX_STANDARD 23)

include_directories(include)

add_executable(15_FileList main.cpp
        Include/File.h
        Include/ObjectList.h)
