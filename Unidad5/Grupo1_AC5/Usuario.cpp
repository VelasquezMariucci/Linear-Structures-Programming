//
// Created by Ricky Vicente on 21/12/2024.
//


#include "Usuario.h"
#include <iostream>

Usuario::Usuario()
{
    nombre = "";
    password = "";
    telefono = 0;
    tipo = Regular;
}
// Constructor de Usuario
Usuario::Usuario(std::string nombre, std::string password, long int telefono, tiposUsuarios tipo)
{
    this->nombre = nombre;
    this->password = password;
    this->telefono = telefono;
    this->tipo = tipo;
}

void Usuario::agregarActividad(const std::string& desc, const std::string& fecha) {
    Actividad nuevaActividad(this->nombre, desc, fecha); // Crear una nueva actividad
    actividades->insert_Tail(nuevaActividad);           // Insertar la actividad en la lista enlazada
}
// Obtener el nombre del usuario
std::string Usuario::getNombre()
{
    return nombre;
}
// Obtener la contraseña del usuario
std::string Usuario::getPassword()
{
    return password;
}
// Obtener el telefono del usuario
long int Usuario::getTelefono()
{
    return telefono;
}
// Obtener el tipo del usuario
tiposUsuarios Usuario::getTipoUsuario()
{
    return tipo;
}


