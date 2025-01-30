//
// Created by esvel on 20/11/2024.
//

#ifndef CANCION_H
#define CANCION_H

#include <ostream>
#include <DinarrayPEL.h>

#include "ArtistaOGrupo.h"

using std::string;

class Cancion
{
private:
    string nombre;    // Nombre de la Cancion
    string genero;    // Genero musical de la Cancion
    DinarrayPEL<ArtistaOGrupo>* artistas = new DinarrayPEL<ArtistaOGrupo>();    // Dinarray de los Artistas O Grupos autores de la Cancion

public:
    // Constructor por defecto
    Cancion();
    // Constuctor de la Cancion
    Cancion(string nombre, string genero);
    // Metodo para devolver el nombre
    string getNombre();
    // Metodo para devolver el genero
    string getGenero();
    // Metodo para mostrar la info de la Cancion
    void mostrarInfo(const string &albumNombre, const string &autorNombre) const;
    // Metodo para devolver todos los artistas de la cancion
    DinarrayPEL<ArtistaOGrupo>* getArtistas();
};

#endif //CANCION_H
