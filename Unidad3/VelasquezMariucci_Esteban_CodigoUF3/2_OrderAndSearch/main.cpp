#include <iostream>
#include "../Estructuras/include/Dynarray.h"

/*Ordenamiento y búsqueda: Escribe un programa que utilice la clase plantilla
Dynarray para almacenar un conjunto de cadenas de texto. Implementa funciones
para ordenar el Dynarray alfabéticamente y para buscar una cadena específica en
el arreglo.*/

using std::string, std::cout, std::endl;

int main()
{
    // Create dinarray for strings
    DynArray<string>* stringDinarray = new DynArray<string>();

    // Add strings
    stringDinarray->add("Hello");
    stringDinarray->add("Howdy");
    stringDinarray->add("Hi");

    // Print dinarray
    cout << *stringDinarray << endl;

    // Search for specific string in dinarray
    cout << "Searching for Hi in DynArray: found in index " << stringDinarray->getIndex("Hi") << endl;

    // Sort dinarray
    stringDinarray->sort();

    // Print dinarray again
    cout << *stringDinarray << endl;

    return 0;
}
