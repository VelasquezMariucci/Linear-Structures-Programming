//
// Created by esvel on 27/09/2024.
//

#ifndef LIBRO_H
#define LIBRO_H
#include <string>


class Libro
{
private:
    //crea los atributos de libro
    std::string nombre;
    std::string categoria;
    bool disponibilidad;

public:
    Libro();
    //crea constructor
    Libro(std::string nombre, std::string categoria, bool disponibilidad);

    //destructor para liberar memoria
    ~Libro() = default;
    //getter del nombre del libro

    std::string getNombre();

    //getter de disponibilidad del libro
    bool getDisponibilidad();
    //setter de disponibilidad del libro
    void setDisponibilidad(bool disponibilidadLibro);

    //imprime la informacion del libro
    friend std::ostream& operator<<(std::ostream& os, Libro& libro);
};


#endif //LIBRO_H
