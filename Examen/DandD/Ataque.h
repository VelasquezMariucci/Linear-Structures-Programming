//
// Created by suare on 15/01/2025.
//

#ifndef ATAQUE_H
#define ATAQUE_H


#include <string>
#include <iostream>

class Ataque {
private:
    std::string nombreAtaque;
    int danio;

public:
    Ataque(std::string nombreAtaque, int danio)
        : nombreAtaque(nombreAtaque), danio(danio) {}

    std::string getNombreAtaque() const { return nombreAtaque; }
    int getDanio() const { return danio; }

    friend std::ostream& operator<<(std::ostream& os, const Ataque& ataque) {
        os << ataque.nombreAtaque << " (Danio: " << ataque.danio << ")";
        return os;
    }

};

#endif // ATAQUE_H


