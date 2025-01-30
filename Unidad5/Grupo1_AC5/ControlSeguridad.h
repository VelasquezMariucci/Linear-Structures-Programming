//
// Created by Jorge Saldaña on 9/1/25.
//

#ifndef CONTROLSEGURIDAD_H
#define CONTROLSEGURIDAD_H

#include <iostream>
#include <string>
#include "ListaEnlazada.h"

class ControlSeguridad {
private:
    ListaEnlazada<std::string> niveles; // niveles de seguridad: bajo, medio, alto
public:
    ControlSeguridad();

    std::string obtenerNivelActual() const;

    void cambiarNivel(const std::string& nuevoNivel); // cambia el nivel actual
    void mostrarNivelActual() const;                 // muestra el nivel actual
    void verificarIdentidad(const std::string& usuario,
                             const std::string& contrasena = "",
                             const std::string& telefono = "") const;
};

#endif // CONTROLSEGURIDAD_H
