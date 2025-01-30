//
// Created by esvel on 24/10/2024.
//

#include "MochilaVirtual.h"


MochilaVirtual::MochilaVirtual()
{
    this->init();
}

void MochilaVirtual::init()
{
    std::string userInput = "";

    while (userInput != "0")
    {
        GestorArchivos* gestorArchivos = new GestorArchivos("../data/Ficheros");

        std::cout << "----- Mochila Digital -----" << std::endl;
        std::cout << "¿Que deseas hacer?:" << std::endl;
        std::cout << "0) Salir." << std::endl;
        std::cout << "1) Ver listado de Archivos." << std::endl;
        std::cout << "2) Cargar Archivo." << std::endl;
        std::cin >> userInput;

        if (userInput == "0")
        {
            std::cout << "Saliendo de aplicacion" << std::endl;
        }
        else if (userInput == "1")
        {
            gestorArchivos->mostrarListadoArchivos();

            std::cout << "¿Que deseas hacer?:" << std::endl;
            std::cout << "0) Salir:" << std::endl;
            std::cout << "1) Abrir un Archivo:" << std::endl;
            std::cout << "2) Eliminar un Archivo:" << std::endl;
            std::cin >> userInput;

            if (userInput == "0")
            {
                std::cout << "Saliendo de aplicacion" << std::endl;
            }
            else if (userInput == "1")
            {
                std::cout << "Ingresa el indice del archivo: ";
                std::cin >> userInput;

                gestorArchivos->mostrarArchivo(stoi(userInput) - 1);
            }
            else if (userInput == "2")
            {
                std::cout << "Ingresa el indice del archivo: ";
                std::cin >> userInput;

                gestorArchivos->eliminarArchivo(stoi(userInput) - 1);
            }
            else if (userInput == "0")
            {
            }
            else
            {
                std::cout << "Error de input, intenta de nuevo." << std::endl;
            }
        }
        else if (userInput == "2")
        {
            std::cout << "Ingresa la ubicacion de tu archivo: ";
            std::cin >> userInput;
            gestorArchivos->cargarArchivo(userInput);
        }
        else
        {
            std::cout << "Error de input, intenta de nuevo." << std::endl;
        }
    }
}
