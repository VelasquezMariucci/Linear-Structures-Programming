cmake_minimum_required(VERSION 3.29)
project(EstructurasExamen)

set(CMAKE_CXX_STANDARD 23)

add_executable(EstructurasExamen main.cpp
        Vector.h
        ../ExamenFinalDnD/LinkedList.h
        List.h)
