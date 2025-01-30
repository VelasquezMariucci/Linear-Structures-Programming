//
// Created by esvel on 25/10/2024.
//

#include "Profesor.h"

Profesor::Profesor(const std::string& nombre, const std::string& ID, const std::string& username,
                   const std::string& password, Aula* aula)
    : nombre(nombre), ID(ID), username(username), password(password), aula(aula)
{
}

std::string Profesor::obtenerNombre() const
{
    return nombre;
}

void Profesor::agregarEstudiante(Estudiante estudiante)
{
    estudiantes.push_back(&estudiante);
}

Aula Profesor::getAula()
{
    return *aula;
}

std::string Profesor::getUsername() const
{
    return username;
}

std::string Profesor::getPassword() const
{
    return password;
}

std::string Profesor::getID() const
{
    return ID;
}
