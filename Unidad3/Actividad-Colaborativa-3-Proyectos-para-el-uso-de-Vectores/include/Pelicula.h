//
// Created by Ricky Vicente on 29/11/2024.
//

#ifndef PELICULA_H
#define PELICULA_H
#include <string>

// Enumeración para definir los 2 valores de calidad de la Pelicula o Serie
enum Calidad {UHD, FHD};

class Pelicula {
private:
    std::string titulo;    // Titulo de la Pelicula
    std::string genero;    // Genero de la Pelicula
    Calidad calidad;    // Calidad de la Pelicula (UHD o FHD)
    bool tarifaEstandar;    // Indica si está incluida en la tarifa estandar
    double precioAlquiler;    // Si no está incluida, tendrá un Precio de Alquiler
public:
    // Constructor por defecto
    Pelicula();
    // Constructor de la Pelicula si está incluida en la tarifa estandar
    Pelicula(std::string titulo, std::string genero, Calidad calidad, bool tarifaEstandar);
    // Constructor de la Pelicula si no está incluida en la tarifa estandar (con el precio de alquiler)
    Pelicula(std::string titulo, std::string genero, Calidad calidad, bool tarifa, double precio);
    // Metodo para devolver el titulo
    std::string getTipoTitulo();
    // Metodo para devolver el genero
    std::string getGenero();
    // Metodo para devolver la calidad
    Calidad getCalidad();
    // Metodo para devolver el estado de la tarifa
    bool isTarifaEstandar();
    // Metodo para devolver el precio de alquiler
    double getPrecioAlquiler();
    // Metodo de setting del booleano de la tarifa estandar
    void setTarifaEstandar(bool tarifaEstandar);
    // Metodo para mostrar la info de la Pelicula/Serie
    void mostrarInfo();
};

#endif //PELICULA_H
