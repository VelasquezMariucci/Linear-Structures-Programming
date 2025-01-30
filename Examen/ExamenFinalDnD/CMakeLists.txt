cmake_minimum_required(VERSION 3.29)
project(ExamenFinalDnD)

set(CMAKE_CXX_STANDARD 23)

add_executable(ExamenFinalDnD main.cpp
        Jugador.h
        Item.h
        Dynarray.h
        Habilidad.h)
