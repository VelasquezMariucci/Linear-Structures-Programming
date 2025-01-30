//
// Created by jorge on 25/10/2024.
//
#include "../include/JuegoAdivinar.h"
#include <iostream>

void JuegoAdivinar::juegoAdivinar()
{
    srand((time(0))); // utiliza el tiempo actual para establecer la semilla del generador de numeros aleatorios
    //si no pones esto, el rand siempre usa la misma secuencia de numeros "aleatorios" y pierde la gracia
    int numeroAleatorio = rand() % 100 + 1; // numero aleatorio entre 1 y 100
    int intento = 0; //intento actual
    int intentos = 0; //contador numero de intentos totales

    //comienzo del juego
    std::cout << "Adivina el numero entre 1 y 100.\n";

    // bucle do while hasta que el usuario adivine el número
    do
    {
        std::cout << "Introduce un numero: ";
        std::cin >> intento; //asocia el numero en intento
        intentos++; //aumenta contador de intentos

        if (intento > numeroAleatorio)
        {
            //si el numero es mayor que el intento entonces lo dice
            std::cout << "El numero es menor que " << intento << ".\n";
        }
        else if (intento < numeroAleatorio)
        {
            //si el numero es menor que el intento entonces lo dice
            std::cout << "El numero es mayor que " << intento << ".\n";
        }
        else
        {
            std::cout << "Felicidades! Has adivinado el numero en " << intentos << " intentos.\n"; //has ganado el juego
        }
    }
    while (intento != numeroAleatorio); //mientras que el intento no sea el numero a adivinar
}
