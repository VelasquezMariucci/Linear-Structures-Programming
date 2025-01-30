//
// Created by esvel on 29/11/2024.
//

#include "Cancion.h"
#include <iostream>
// // Constructor por defecto
Cancion::Cancion()
{
    nombre = "";
    genero = "";
    artistas = nullptr;
}
// Constructor de la Cancion
Cancion::Cancion(string nombre, string genero)
{
    this->nombre = nombre;
    this->genero = genero;
}
// Obtenemos el nombre
string Cancion::getNombre()
{
    return nombre;
}
// Obtenemos el genero
string Cancion::getGenero()
{
    return genero;
}
// Metodo para mostrar toda la informacion de la Cancion
void Cancion::mostrarInfo(const string& albumNombre, const string& autorNombre) const
{
    std::cout << "Cancion: " << nombre << std::endl;
    std::cout << "Genero: " << genero << std::endl;
    std::cout << "Album: " << albumNombre << std::endl;
    std::cout << "Autor: " << autorNombre << std::endl;
}
// Metodo para devolver los artistas de la Cancion
DinarrayPEL<ArtistaOGrupo>* Cancion::getArtistas()
{
    return artistas;
}
