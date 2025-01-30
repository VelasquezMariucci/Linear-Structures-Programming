#ifndef JUEGO_H
#define JUEGO_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Jugador.h"
#include "Enemigo.h"
#include "Ataque.h"

class Juego {
private:
    Jugador* jugador;

public:
    Juego() : jugador(nullptr) {
        srand(static_cast<unsigned>(time(0))); // Inicializar aleatoriedad
    }

    ~Juego() {
        delete jugador;
    }

    void iniciar() {
        std::cout << "Bienvenido a Dragones y Mazmorras!\n";
        std::string nombreJugador;
        std::cout << "Ingresa el nombre de tu personaje: ";
        std::cin >> nombreJugador;
        jugador = new Jugador(nombreJugador);

        // Crear ataques para el jugador
        jugador->agregarAtaqueJugador(Ataque("Espadazo", 15));
        jugador->agregarAtaqueJugador(Ataque("Flecha", 10));
        jugador->agregarObjeto(Objeto("Mini potis", 25));
        jugador->agregarObjeto(Objeto("Poti gorda", 50));

        std::cout << "\nHola, " << nombreJugador << "! Preparate para la aventura.\n";
        explorarMazmorra();
    }

    void explorarMazmorra() {
        std::cout << "\nEntras a una mazmorra oscura...\n";
        Enemigo enemigo("Goblin", 50, 15, 5);
        enemigo.agregarObjeto(Objeto("Mini potis", 25));

        // Crear ataques para el enemigo
        enemigo.agregarAtaqueMonstruo(Ataque("Mordisco", 8));
        enemigo.agregarAtaqueMonstruo(Ataque("Golpe", 12));

        while (jugador->estaVivo() && enemigo.estaVivo()) {
            std::cout << "\nTe enfrentas a un " << enemigo.getNombre() << "!\n";
            combate(enemigo);
        }

        if (jugador->estaVivo()) {
            std::cout << "\nHas derrotado al " << enemigo.getNombre() << "!\n";
        } else {
            std::cout << "\nHas sido derrotado...\n";
        }
    }

    void combate(Enemigo& enemigo)
    {
        while (jugador->estaVivo() && enemigo.estaVivo()) {
            // Mostrar estado de los personajes
            jugador->mostrarEstado();
            enemigo.mostrarEstado();

            // Turno del jugador
            std::cout << "\nEs tu turno. Que deseas hacer?\n";
            std::cout << "1. Atacar\n2. Usar objeto\nElige una opcion: ";
            int opcion;
            std::cin >> opcion;

            if (opcion == 1) {
                // Atacar
                int danioJugador = jugador->atacar();
                enemigo.recibirDanio(danioJugador);
                std::cout << "\nLe hiciste " << danioJugador << " puntos de daño al " << enemigo.getNombre() << "!\n";
            } else if (opcion == 2) {
                // Usar objeto
                if (!jugador->usarObjeto()) {
                    std::cout << "No pudiste usar un objeto. Pierdes tu turno.\n";
                }
            } else {
                std::cout << "Opcion invalida. Pierdes tu turno.\n";
            }

            // Verificar si el enemigo sigue vivo
            if (!enemigo.estaVivo()) {
                std::cout << "\nHas derrotado al " << enemigo.getNombre() << "!\n";
                break;
            }

            // Turno del enemigo
            std::cout << "\nEs el turno del " << enemigo.getNombre() << "...\n";

            // Decidir acción del enemigo
            bool necesitaCurarse = (enemigo.getVida() < enemigo.getVidaMaxima() / 2) && !enemigo.mochilaVacia();
            if (necesitaCurarse && (rand() % 2 == 1)) {
                // Usar objeto
                if (!enemigo.usarObjeto()) {
                    std::cout << enemigo.getNombre() << " intento usar un objeto, pero fallo.\n";
                }
            } else {
                // Atacar
                int danioEnemigo = enemigo.atacar();
                jugador->recibirDanio(danioEnemigo);
                std::cout << enemigo.getNombre() << " te hizo " << danioEnemigo << " puntos de daño!\n";
            }

            // Verificar si el jugador sigue vivo
            if (!jugador->estaVivo()) {
                std::cout << "\nHas sido derrotado por el " << enemigo.getNombre() << "...\n";
            }
        }
}




};

#endif // JUEGO_H
