//
// Created by esvel on 27/09/2024.
//

#include "Libro.h"
//constructor de Libro
Libro::Libro() : nombre(""), categoria(""), disponibilidad(true)
{
}

Libro::Libro(std::string nombre, std::string categoria, bool disponibilidad) : nombre(nombre), categoria(categoria),
                                                                               disponibilidad(disponibilidad)
{
}
//getter del nombre del libro
std::string Libro::getNombre()
{
    return this->nombre;
}
//getter de la disponibilidad de los libros
bool Libro::getDisponibilidad()
{
    return this->disponibilidad;
}
//setter de la disponibilidad de un libro (Boolean)
void Libro::setDisponibilidad(bool disponibilidadLibro)
{
    disponibilidad = disponibilidadLibro;
}

