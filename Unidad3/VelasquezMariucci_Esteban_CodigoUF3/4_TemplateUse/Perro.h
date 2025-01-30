//
// Created by esvel on 23/11/2024.
//

#ifndef PERRO_H
#define PERRO_H

#include <iostream>

class Perro
{
private:
    std::string nombre;
    int edad;

public:
    Perro();

    Perro(const std::string& nombre, int edad);

    bool operator==(const Perro& other) const
    {
        return edad == other.edad;
    }

    bool operator<(const Perro& other) const {
        return edad < other.edad;
    }
    friend std::ostream& operator<<(std::ostream& os, const Perro& perro)
    {
        os << "Perro: " << perro.nombre << ", Edad: " << perro.edad;
        return os;
    }
};



#endif //PERRO_H
