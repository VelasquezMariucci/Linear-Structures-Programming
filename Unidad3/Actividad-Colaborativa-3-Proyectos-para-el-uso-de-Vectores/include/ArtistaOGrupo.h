//
// Created by esvel on 20/11/2024.
//

#ifndef ARTISTAOGRUPO_H
#define ARTISTAOGRUPO_H

#include <ostream>

using std::string;

class ArtistaOGrupo
{
private:
    string nombre;    // Nombre del Artista/Grupo

public:
    // Constructor por defecto
    ArtistaOGrupo();
    // Constructor del Artista/Grupo
    ArtistaOGrupo(string nombre);
    // Metodo para devolver el nombre del Artista/Grupo
    string getNombre();
};

#endif //ARTISTAOGRUPO_H
