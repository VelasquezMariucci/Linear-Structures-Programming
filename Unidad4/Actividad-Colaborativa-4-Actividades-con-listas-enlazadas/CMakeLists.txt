cmake_minimum_required(VERSION 3.29)
project(Grupo1_AC4)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(Grupo1_AC4 src/main.cpp
        src/Usuario.cpp
        src/Contacto.cpp
)
