#ifndef OBJETO_H
#define OBJETO_H

#include <string>
#include <iostream>

class Objeto {
private:
    std::string nombre;
    int efecto; // Valor del efecto (ej., curación)

public:
    Objeto(std::string nombre, int efecto)
        : nombre(nombre), efecto(efecto) {}

    std::string getNombre() const { return nombre; }
    int getEfecto() const { return efecto; }

    friend std::ostream& operator<<(std::ostream& os, const Objeto& objeto) {
        os << objeto.nombre << " (Efecto: " << objeto.efecto << ")";
        return os;
    }

};

#endif // OBJETO_H
