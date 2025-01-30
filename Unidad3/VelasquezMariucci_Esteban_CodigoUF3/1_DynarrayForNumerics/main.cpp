/*Inicialización y operaciones básicas: Crea un programa que utilice la clase plantilla
Dynarray para almacenar un conjunto de números enteros. Luego, realiza
operaciones básicas como inserción, eliminación y búsqueda de elementos en el
Dynarray.*/

#include <iostream>
#include "../Estructuras/include/Dynarray.h"

using std::cout, std::endl;

int main()
{
    // Create object pointer
    DynArray<int>* dinarray = new DynArray<int>;

    // Add values
    dinarray->add(1);
    dinarray->add(2);
    dinarray->add(3);

    // Print
    cout << *dinarray << endl;

    // Get item print
    cout << dinarray->get(2) << endl;

    // Extract
    dinarray->extract(3);

    // Print again
    cout << *dinarray << endl;

    return 0;
}
