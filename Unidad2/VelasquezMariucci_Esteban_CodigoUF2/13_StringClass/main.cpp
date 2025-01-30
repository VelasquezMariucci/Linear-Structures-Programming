#include <iostream>

#include "StringClass.h"

/*Crear una clase “Cadena” que contenga un puntero a un array de
caracteres. La clase debe tener un constructor que inicialice el array con una
cadena dada y un destructor que libere la memoria del array.*/

int main()
{
    StringClass myString("Hello, World!");

    std::cout << &myString;

    return 0;
}
