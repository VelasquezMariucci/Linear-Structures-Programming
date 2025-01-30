#include <iostream>
#include "../Estructuras/include/Dynarray.h"
#include "Perro.h"

/*Crea un programa que utilice la clase plantilla Dynarray para
almacenar objetos de una clase personalizada. Asegúrate de que la clase Dynarray
sea capaz de manejar cualquier tipo de objeto utilizando plantillas.*/

int main()
{
    // Dog dinarray
    DynArray<Perro> doggies(2); // Initial capacity of 2

    // Add dog objects to the array
    doggies.add(Perro("Bobby", 3));
    doggies.add(Perro("Luna", 5));
    doggies.add(Perro("Rocky", 2));
    doggies.add(Perro("Luna", 5));

    // Print
    std::cout << "Dogs: " << doggies << "\n";

    // Get function
    std::cout << "Doggy at index 1: " << doggies.get(1) << std::endl;

    // Extract function
    std::cout << "Extract Doggy at index 0: " << doggies.extract(0) << std::endl;
    std::cout << "Array after extraction: " << doggies << std::endl;

    // getIndex function
    Perro searchDoggy("Luna", 5);
    int index = doggies.getIndex(searchDoggy);
    if (index != -1)
    {
        std::cout << searchDoggy << " found at index " << index << std::endl;
    }
    else
    {
        std::cout << searchDoggy << " not found." << std::endl;
    }

    // Mode function
    std::cout << "Mode: " << doggies.mode() << std::endl;

    // Sort function
    doggies.sort();
    std::cout << "Sorting dogs: " << doggies << std::endl;

    return 0;
}
