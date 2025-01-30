//
// Created by Ricky Vicente on 21/12/2024.
//
#include "Registro.h"
#include <iostream>

Registro::Registro() : siguienteAcceso(nullptr) {
    nombreUsuario = "";
    hora = "";
}
// Constructor de Registro
Registro::Registro(std::string nombre, std::string h)
    : nombreUsuario(nombre), hora(h), siguienteAcceso(nullptr) {}
// Obtener el nombre del usuario
std::string Registro::getNombreUsuario() const {
    return nombreUsuario;
}
// Obtener la hora del usuario
std::string Registro::getHora() const {
    return hora;
}

Registro* Registro::getSiguienteAcceso() const {
    return siguienteAcceso;
}
// Mostramos el nombre del usuario y la hora
void Registro::mostrar() {
    std::cout << "Acceso del Usuario " << nombreUsuario << " a la hora " << hora << std::endl;
}
