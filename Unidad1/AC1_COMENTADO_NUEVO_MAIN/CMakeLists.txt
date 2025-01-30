cmake_minimum_required(VERSION 3.29)
project(AC1)

set(CMAKE_CXX_STANDARD 23)

add_executable(AC1 main.cpp
        Lista.h
        Lista.cpp
        Libro.h
        Libro.cpp
        Usuario.cpp
        UsuarioCliente.h
        UsuarioCliente.cpp
        UsuarioBibliotecario.h
        UsuarioBibliotecario.cpp)
