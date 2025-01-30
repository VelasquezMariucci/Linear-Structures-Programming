#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "Personaje.h"
#include "List.h"
#include "Ataque.h"
#include "Objeto.h"

class Enemigo : public Personaje {
private:
    List<Ataque> listaAtaquesMonstruo;
    List<Objeto> mochila;

public:
    Enemigo(std::string nombre, int vida, int ataque, int defensa)
        : Personaje(nombre, vida, ataque, defensa) {}

    void agregarAtaqueMonstruo(const Ataque& ataque) {
        listaAtaquesMonstruo.insert_Tail(ataque);
    }
    void agregarObjeto(const Objeto& objeto) {
        mochila.insert_Tail(objeto);
    }
    int atacar() {
        if (listaAtaquesMonstruo.isEmpty()) {
            std::cout << "El enemigo " << nombre << " no tiene ataques disponibles!\n";
            return 0;
        }

        int indice = rand() % listaAtaquesMonstruo.getSize();
        Ataque ataqueSeleccionado = listaAtaquesMonstruo.get(indice);

        std::cout << nombre << " usó el ataque: " << ataqueSeleccionado.getNombreAtaque()
                  << ", causando " << ataqueSeleccionado.getDanio() << " puntos de daño.\n";

        return ataqueSeleccionado.getDanio();
    }

    bool usarObjeto() {
        if (mochila.isEmpty()) {
            std::cout << nombre << " intento usar un objeto, pero la mochila esta vacia.\n";
            return false;
        }

        int posicion = rand() % mochila.getSize();
        Objeto objetoUsado = mochila.remove(posicion);
        vida += objetoUsado.getEfecto();
        if (vida > vidaMaxima) vida = vidaMaxima; // No exceder la vida máxima

        std::cout << nombre << " usó " << objetoUsado.getNombre()
                  << " y recupero " << objetoUsado.getEfecto() << " puntos de vida.\n";

        return true;
    }

    void decidirAccion() {
        bool necesitaCurarse = (vida < (vidaMaxima / 2)) && !mochila.isEmpty();

        if (necesitaCurarse) {
            usarObjeto();
        } else {
            atacar();
        }
    }
    bool mochilaVacia() const {
        return mochila.isEmpty();
    }
};


#endif // ENEMIGO_H
