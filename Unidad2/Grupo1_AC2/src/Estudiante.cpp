//
// Created by esvel on 25/10/2024.
//

#include "Estudiante.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_map>

Estudiante::Estudiante(const std::string& nombre, const std::string& ID, const std::string& username,
                       const std::string& password, Profesor* profesor)
{
    this->nombre = nombre;
    this->ID = ID;
    this->username = username;
    this->password = password;
    this->profesor = profesor;

    cargarNotas();
}

std::string Estudiante::getUsername() const
{
    return username;
}

std::string Estudiante::getPassword() const
{
    return password;
}

void Estudiante::cargarNotas()
{
    std::ifstream archivo("../data/notas.txt");
    if (!archivo)
    {
        std::cout << "No se pudo abrir el archivo." << std::endl;
        return;
    }

    std::string linea;

    while (std::getline(archivo, linea))
    {
        std::stringstream ss(linea);
        std::string nombreCompleto;
        std::getline(ss, nombreCompleto, ';');

        // Extract the first name for comparison
        std::string primerNombre = nombreCompleto.substr(0, nombreCompleto.find(" "));

        // Compare with the first name in this->nombre
        if (primerNombre == this->nombre)
        {
            for (int i = 0; i < 3; ++i)
            {
                std::string calificacionStr;
                std::getline(ss, calificacionStr, ';');
                notas[i] = std::stof(calificacionStr);
            }
            return; // Exit after loading notes
        }
    }

    std::cout << "No se encontraron notas para el estudiante " << this->nombre << "." << std::endl;
}


std::string Estudiante::obtenerNombre() const
{
    return nombre;
}

std::string Estudiante::getID() const
{

    return ID;
}

void Estudiante::mostrarNotas() const
{
    std::cout << "\t Matematicas: " << notas[0] << std::endl;
    std::cout << "\t Ingles: " << notas[1] << std::endl;
    std::cout << "\t Historia: " << notas[2] << std::endl;
}
