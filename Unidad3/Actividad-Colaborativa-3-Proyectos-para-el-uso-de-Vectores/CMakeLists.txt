cmake_minimum_required(VERSION 3.29)
project(UF3_ACTGRUPAL)

set(CMAKE_CXX_STANDARD 23)

include_directories(include)

add_executable(UF3_ACTGRUPAL src/main.cpp
        include/Album.h
        include/VectorPEL.h
        include/DinarrayPEL.h
        include/Cancion.h
        include/ArtistaOGrupo.h
        src/Album.cpp
        src/ArtistaOGrupo.h.cpp
        src/Cancion.cpp
        src/Pelicula.cpp)
