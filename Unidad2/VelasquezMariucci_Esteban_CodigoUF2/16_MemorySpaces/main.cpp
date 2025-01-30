#include <iostream>

#include "MemorySpace.h"

/*Crea una clase “EspaciosDeMemoria” que encapsule un puntero a una
dirección aleatoria de memoria. Se debe poder elegir un conjunto de
bloques de memoria para un elemento concreto dando su alineación como
constructor. Estos espacios de memoria deben alojarse en su constructor y
cerrarse en su destructor.*/

int main()
{
    try
    {
        // First allocation
        MemorySpace<int> memSpace1(10, 16);

        memSpace1.getElement(0) = 12;
        memSpace1.getElement(1) = 34;
        memSpace1.getElement(3) = 12351325;

        std::cout << "First element: " << memSpace1.getElement(0) << std::endl;
        std::cout << "Second element: " << memSpace1.getElement(1) << std::endl;
        std::cout << "Third element: " << memSpace1.getElement(2) << std::endl;
    }
    catch (const std::bad_alloc& e)
    {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
    } catch (const std::out_of_range& e)
    {
        std::cerr << "Out of range error: " << e.what() << std::endl;
    }

    return 0;
}
