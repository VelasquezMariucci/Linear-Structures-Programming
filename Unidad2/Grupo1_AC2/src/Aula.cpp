//
// Created by esvel on 25/10/2024.
//

#include "Aula.h"

#include <complex.h>

Aula::Aula(const std::string ID, Profesor* profesor)
    : ID(ID), profesor(profesor) // Move the list into the class
{
}

void Aula::agregarEstudiante(Estudiante estudiante) // Pass by const reference to avoid unnecessary copies
{
    estudiantes.push_back(&estudiante);
    std::cout << "Estudiante aniadido." << std::endl;

    profesor->agregarEstudiante(estudiante);
}

void Aula::agregarEstudiante(Estudiante estudiante, int indice) // Pass by const reference
{
    if (indice < 0 || indice > estudiantes.size())
    {
        std::cerr << "Posición inválida." << std::endl;
        return;
    }

    auto it = estudiantes.begin();
    std::advance(it, indice); // Move the iterator to the desired position
    estudiantes.insert(it, &estudiante);
    std::cout << "Estudiante añadido en la posición " << indice << "." << std::endl;
}

void Aula::mostrarEstudiantes() // Mark as const, as it does not modify the object
{
    int count = 1;

    std::cout << "----- Estudiantes en " << this->ID << " -----" << std::endl;

    // Iterate over the list of estudiantes using const reference to avoid copying
    for (const auto e : estudiantes)
    {
        std::cout << "#" << count << " " << e->obtenerNombre() << std::endl;

        e->mostrarNotas();
        count++;
    }
}

void Aula::mostrarAula()
{
    int count = 1;

    std::cout << "----- " << this->ID << " -----" << std::endl;

    std::cout << "Numero de estudiantes: " << this->estudiantes.size() << std::endl;

    for (const auto e : estudiantes)
    {
        std::cout << "#" << count << " " << e->obtenerNombre() << std::endl;

        count++;
    }
}
