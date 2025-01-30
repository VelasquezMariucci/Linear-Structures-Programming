//
// Created by esvel on 23/11/2024.
//

#include "Perro.h"

Perro::Perro() : nombre("Desconocido"), edad(0)
{
}

Perro::Perro(const std::string& nombre, int edad)
{
    this->nombre = nombre;
    this->edad = edad;
}