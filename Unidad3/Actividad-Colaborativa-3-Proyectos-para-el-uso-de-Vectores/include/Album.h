//
// Created by esvel on 20/11/2024.
//

#ifndef ALBUM_H
#define ALBUM_H

#include <ostream>
#include "ArtistaOGrupo.h"
#include "Cancion.h"
#include "DinarrayPEL.h"

using std::string;

class Album
{
private:
    string nombre;    // Nombre del Album
    ArtistaOGrupo* autor;    // Puntero al Artista/Grupo del Album
    DinarrayPEL<Cancion>* canciones = new DinarrayPEL<Cancion>();    // Dinarray que almacena las canciones del Album

public:
    // Constructor por defecto
    Album();
    // Constructor del Album
    Album(string nombre, ArtistaOGrupo* autor);
    // Metodo para devolver el titulo
    string getNombre();
     // Metodo para devolver el Artista/Grupo
    ArtistaOGrupo* getAutor();
    // Metodo para devolver las canciones almacenadas en el Album
    DinarrayPEL<Cancion>* getCaciones();
};

#endif //ALBUM_H
