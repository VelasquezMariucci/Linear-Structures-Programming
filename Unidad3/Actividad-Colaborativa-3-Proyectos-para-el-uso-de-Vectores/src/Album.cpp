//
// Created by esvel on 29/11/2024.
//

#include "Album.h"
// Constructor por defecto
Album::Album()
{
    nombre = "";
    autor = nullptr;
    canciones = nullptr;
}
// Constructor para Albumes
Album::Album(string nombre, ArtistaOGrupo* autor)
{
    this->nombre = nombre;
    this->autor = autor;
}
// Obtenemos el nombre del Album
string Album::getNombre()
{
    return nombre;
}
// Obtenemos el autor del Album
ArtistaOGrupo* Album::getAutor()
{
    return autor;
}
// Obtenemos las canciones almacenadas en el Album
DinarrayPEL<Cancion>* Album::getCaciones()
{
    return canciones;
}
