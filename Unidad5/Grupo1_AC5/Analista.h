//
// Created by german on 14/01/2025.
//
// Analista.h

#ifndef ANALISTA_H
#define ANALISTA_H
#endif

#include "Usuario.h"  // Incluye la clase base Usuario
#include "ListaRegistro.h"  // Incluye la clase ListaRegistro
#include <vector>  // Usado para manejar el vector de usuarios
#include <string>  // Usado para el tipo string

// Clase Analista que hereda de Usuario
class Analista : public Usuario {
public:
    // Constructor de la clase Analista
    Analista(const std::string& nombre, const std::string& password, long telefono);

    // Método para contar los accesos de manera recursiva
    void contarAccesos(Registro* acceso);

    // Método para buscar actividades sospechosas entre los usuarios
    void buscarActividadesSospechosas(std::vector<Usuario*>& usuarios);

private:
    // Método privado que compara dos actividades para ver si son sospechosas
    bool actividadSospechosa(const Actividad& actividad1, const Actividad& actividad2);
};

