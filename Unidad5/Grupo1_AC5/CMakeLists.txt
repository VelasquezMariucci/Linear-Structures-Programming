cmake_minimum_required(VERSION 3.29)
project(ACF_LCDP)

set(CMAKE_CXX_STANDARD 20)

add_executable(ACF_LCDP main.cpp
        ListaEnlazada.h
        Usuario.h
        Registro.h
        Usuario.cpp
        Registro.cpp
        ListaRegistro.h
        ControlSeguridad.cpp
        ControlSeguridad.h
        Analista.cpp
        Analista.cpp
        Analista.h
)
