#ifndef JUGADOR_H
#define JUGADOR_H

#include "Personaje.h"
#include "List.h"
#include "Ataque.h"



#include "Objeto.h"

class Jugador : public Personaje {
private:
    List<Ataque> listaAtaquesJugador;
    List<Objeto> mochila; // Nueva mochila para el jugador

public:
    Jugador(std::string nombre)
        : Personaje(nombre, 100, 20, 10) {}

    void agregarAtaqueJugador(const Ataque& ataque) {
        listaAtaquesJugador.insert_Tail(ataque);
    }

    void agregarObjeto(const Objeto& objeto) {
        mochila.insert_Tail(objeto);
    }

    void mostrarMochila() const {
        std::cout << "Mochila del jugador: \n";
        mochila.display();
    }

    bool usarObjeto() {
        if (mochila.isEmpty()) {
            std::cout << "La mochila esta vacia.\n";
            return false;
        }

        // Mostrar la mochila con posiciones
        mochila.display();

        std::cout << "Elige un objeto para usar (posición): ";
        int posicion;
        std::cin >> posicion;

        // Validar posición
        if (posicion < 0 || posicion >= mochila.getSize()) {
            std::cout << "Posicion invalida. Pierdes tu turno.\n";
            return false;
        }

        // Usar el objeto seleccionado
        Objeto objetoUsado = mochila.remove(posicion);
        vida += objetoUsado.getEfecto();
        std::cout << "Usaste " << objetoUsado.getNombre()
                  << " y recuperaste " << objetoUsado.getEfecto() << " puntos de vida.\n";

        return true;
    }
    int atacar() {
        if (listaAtaquesJugador.getSize() == 0) {
            std::cout << "No tienes ataques disponibles!\n";
            return 0;
        }

        int indice = rand() % listaAtaquesJugador.getSize();
        Ataque ataqueSeleccionado = listaAtaquesJugador.get(indice);

        std::cout << "Usaste el ataque: " << ataqueSeleccionado.getNombreAtaque()
                  << " causando " << ataqueSeleccionado.getDanio() << " de daño.\n";

        return ataqueSeleccionado.getDanio();
    }
    void mostrarEstado() const {
        std::cout << "\nJugador: " << nombre << "\nVida: " << vida << "\n";

    }
};

#endif // JUGADOR_H
