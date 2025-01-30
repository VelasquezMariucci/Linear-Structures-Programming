cmake_minimum_required(VERSION 3.29)
project(Grupo1_AC2)

set(CMAKE_CXX_STANDARD 23)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(Grupo1_AC2 main.cpp
        include/GestorArchivos.h
        src/GestorArchivos.cpp
        include/MochilaVirtual.h
        src/MochilaVirtual.cpp
        include/Matriz.h
        include/CalculadoraAvanzada.h
        include/Estudiante.h
        src/Estudiante.cpp
        src/Profesor.cpp
        include/Profesor.h
        src/Aula.cpp
        include/Aula.h
        src/UsuarioAdministrador.cpp
        include/UsuarioAdministrador.h
        src/JuegoAdivinar.cpp
        include/JuegoAdivinar.h)
