//
// Created by Ricky Vicente on 29/11/2024.
//

#include "Pelicula.h"
#include <iostream>
// Constructor por defecto
Pelicula::Pelicula() {
    titulo = "";
    genero = "";
    calidad = FHD;
    tarifaEstandar = false;
    precioAlquiler = 0.0;
}
// Constructor para Peliculas/Series en la tarifa estandar
Pelicula::Pelicula(std::string tit, std::string gen, Calidad cal, bool tarifa) {
    titulo = tit;
    genero = gen;
    calidad = cal;
    tarifaEstandar = tarifa;
}
// Constructor para Peliculas/Series no incluidas en la tarifa estandar
Pelicula::Pelicula(std::string tit, std::string gen, Calidad cal, bool tarifa, double precio) {
    titulo = tit;
    genero = gen;
    calidad = cal;
    tarifaEstandar = tarifa;
    // Si no está incluida, se configura el precio
    if (tarifaEstandar) {
        precioAlquiler = precio;
    // Sino, el precio es 0
    } else {
        precioAlquiler = 0.0;
    }
}
// Obtenemos el titulo
std::string Pelicula::getTipoTitulo() {
    return titulo;
}
// Obtenemos el genero
std::string Pelicula::getGenero() {
    return genero;
}
// Obtenemos la calidad
Calidad Pelicula::getCalidad() {
    return calidad;
}
// Obtenemos el tipo de tarifa
bool Pelicula::isTarifaEstandar() {
    return tarifaEstandar;
}
// Obtenemos el precio si necesita alquiler
double Pelicula::getPrecioAlquiler() {
    return tarifaEstandar ? precioAlquiler : 0.0;
}
// Configuramos la tarifa estandar
void Pelicula::setTarifaEstandar(bool tarifa) {
    this->tarifaEstandar = tarifa;
    // Si está incluida, el precio es 0
    if (!tarifaEstandar) {
        precioAlquiler = 0.0;
    }
}
// Metodo para mostrar toda la informacion
void Pelicula::mostrarInfo(){
    std::cout << "Titulo: " << titulo << std::endl;
    std::cout << "Genero: " << genero << std::endl;
    std::cout << "Calidad: " << (calidad == UHD ? "UHD" : "FHD") << std::endl;
    std::cout << "Disponible con tarifa estandar: " << (tarifaEstandar ? "No" : "Si") << std::endl;
    // El precio aparecerá solo si necesita alquiler
    if (tarifaEstandar) {
        std::cout << "Precio de Alquiler: " << precioAlquiler << " euros" << std::endl;
    }
}
