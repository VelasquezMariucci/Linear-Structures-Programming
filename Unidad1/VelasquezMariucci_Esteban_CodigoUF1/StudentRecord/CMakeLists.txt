cmake_minimum_required(VERSION 3.29)
project(StudentRecord)

set(CMAKE_CXX_STANDARD 23)

add_executable(StudentRecord main.cpp
        Student.h
        Student.cpp
        StudentRecord.h
        StudentRecord.cpp)
