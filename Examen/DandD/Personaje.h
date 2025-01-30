//
// Created by suare on 15/01/2025.
//

#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <string>
#include "List.h"
#include "Ataque.h"

class Personaje {
protected:
    std::string nombre;
    int vida;
    int ataque;
    int defensa;
    int vidaMaxima; // Nueva variable para manejar la vida máxima

public:
    Personaje(std::string nombre, int vida, int ataque, int defensa)
        : nombre(nombre), vida(vida), ataque(ataque), defensa(defensa), vidaMaxima(vida) {}

    virtual ~Personaje() {}

    std::string getNombre() const { return nombre; }
    int getVida() const { return vida; }
    int getVidaMaxima() const { return vidaMaxima; } // Nuevo getter para la vida máxima
    void recibirDanio(int danio) { vida -= danio; if (vida < 0) vida = 0; }

    virtual int atacar() const { // Método virtual
        return rand() % ataque + 1; // Ataque aleatorio entre 1 y ataque
    }

    bool estaVivo() const { return vida > 0; }
    virtual void mostrarEstado() const {
        std::cout << "Nombre: " << nombre << ", Vida: " << vida << "\n";
    }
};


#endif // PERSONAJE_H

