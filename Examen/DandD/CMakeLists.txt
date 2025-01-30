cmake_minimum_required(VERSION 3.29)
project(DandD)

set(CMAKE_CXX_STANDARD 20)

add_executable(DandD main.cpp
        Jugador.h
        Enemigo.h
        Juego.h
        List.h
        Personaje.h
        Ataque.h
        Objeto.h)
