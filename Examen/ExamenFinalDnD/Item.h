//
// Created by esvel on 21/01/2025.
//

#ifndef OBJETO_H
#define OBJETO_H
#include <string>
#include <iostream>

class Item {
private:
    std::string nombre;
    int efecto;

public:
    Item() : nombre(""), efecto(0) {}
    Item(std::string nombre, int efecto) : nombre(nombre), efecto(efecto) {};

    std::string getNombre() const { return nombre; }
    int getEfecto() const { return efecto; }

    bool operator==(const Item& other) const {
        return (nombre == other.nombre && efecto == other.efecto);
    }


    friend std::ostream& operator<<(std::ostream& os, const Item& objeto) {
        os << objeto.nombre << " (Efecto: " << objeto.efecto << ")";
        return os;
    }

    ~Item() = default;
};



#endif //OBJETO_H
