#include <iostream>

#include "Dinarray.h"

/*
Crea una clase genérica “Dinarray” que pueda almacenar una serie de
elementos de cualquier tipo. Genera tres contenedores de datos diferentes
para que almacenen datos de 3 TAD diferentes. Estos elementos deben
alojarse en el constructor y cerrarse en su destructor.
*/


int main()
{
    Dinarray<int> intArray(5);
    for (int i = 0; i < 5; ++i)
    {
        int value = i * 10;
        intArray.setElement(i, value);
    }

    std::cout << "Int Array:" << std::endl;
    for (int i = 0; i < 5; ++i)
    {
        std::cout << intArray.getElement(i) << " ";
    }
    std::cout << std::endl;

    Dinarray<double> doubleArray(3);
    for (int i = 0; i < 3; ++i)
    {
        double value = i + 0.5;
        doubleArray.setElement(i, value);
    }

    std::cout << "Double Array:" << std::endl;
    for (int i = 0; i < 3; ++i)
    {
        std::cout << doubleArray.getElement(i) << " ";
    }
    std::cout << std::endl;

    Dinarray<std::string> stringArray(4);
    for (int i = 0; i < 4; ++i)
    {
        std::string value = "Hello#" + std::to_string(i);
        stringArray.setElement(i, value);
    }

    std::cout << "String Array:" << std::endl;
    for (int i = 0; i < 4; ++i)
    {
        std::cout << stringArray.getElement(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}
