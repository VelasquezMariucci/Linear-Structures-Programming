//
// Created by Jorge Saldaña on 9/1/25.
//

#include "ControlSeguridad.h"

// inicializamos los niveles de seguridad
ControlSeguridad::ControlSeguridad() {
    niveles.insert_Head("alto");
    niveles.insert_Head("medio");
    niveles.insert_Head("bajo");
}
std::string ControlSeguridad::obtenerNivelActual() const {
    return niveles.getHead()->data;
}
// cambia el nivel más alto en la lista
void ControlSeguridad::cambiarNivel(const std::string& nuevoNivel) {
    if (nuevoNivel != "bajo" && nuevoNivel != "medio" && nuevoNivel != "alto") {
        std::cerr << "nivel invalido.\n";
        return;
    }
    niveles.remove_Head(); // eliminamos el nivel más alto
    niveles.insert_Head(nuevoNivel); // colocamos el nuevo nivel
}

// muestra el nivel más alto de la lista
void ControlSeguridad::mostrarNivelActual() const {
    if (!niveles.isEmpty()) {
        std::cout << "Nivel de seguriad actual: " << niveles.getHead()->data << std::endl;
    }
}

// verifica la identidad según el nivel de seguridad actual
void ControlSeguridad::verificarIdentidad(const std::string& usuario,
                                          const std::string& contrasena,
                                          const std::string& telefono) const {
    std::string nivelActual = niveles.getHead()->data;
    if (nivelActual == "bajo") {
        std::cout << "Verificando solo usuario: " << usuario << std::endl;
        std::cout << "Bienvenido " << usuario << std::endl;
    } else if (nivelActual == "medio") {
        if (contrasena.empty()) {
            std::cerr << "Se necesita contraseña para el nivel medio.\n";
            return;
        }
        std::cout << "Verificando el usuario y la contraseña.\n";
        std::cout << "Bienvenido " << usuario << std::endl;
    } else if (nivelActual == "alto") {
        if (contrasena.empty() || telefono.empty()) {
            std::cerr << "Se necesita contraseña y telefono para el nivel alto.\n";
            return;
        }
        std::cout << "Verificando usuario, contraseña y telefono.\n";
        std::cout << "Bienvenido " << usuario << std::endl;
    }
}

