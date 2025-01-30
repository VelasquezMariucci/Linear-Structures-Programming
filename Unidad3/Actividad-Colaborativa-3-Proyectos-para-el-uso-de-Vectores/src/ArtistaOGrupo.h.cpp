//
// Created by esvel on 29/11/2024.
//

#include "ArtistaOGrupo.h"
// Constructor por defecto
ArtistaOGrupo::ArtistaOGrupo()
{
    nombre = "";
}
// Constructor del Artista/Grupo
ArtistaOGrupo::ArtistaOGrupo(string nombre)
{
    this->nombre = nombre;
}
// Devolvemos el nombre
string ArtistaOGrupo::getNombre()
{
    return nombre;
}
