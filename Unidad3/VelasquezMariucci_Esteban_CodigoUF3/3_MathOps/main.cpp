#include <iostream>
#include "../Estructuras/include/Dynarray.h"

/*Operaciones matemáticas: Desarrolla un programa que utilice la clase plantilla
Dynarray para almacenar números de punto flotante. Implementa funciones para
calcular la suma, el promedio y la moda de los elementos en el Dynarray.*/

using std::cout, std::endl;

int main()
{
    // Create Dinarray
    DynArray<float>* floatDinarray = new DynArray<float>;

    // Add values
    floatDinarray->add(1.65f);
    floatDinarray->add(8.98f);
    floatDinarray->add(5.23f);
    floatDinarray->add(1.65f);
    floatDinarray->add(5.23f);
    floatDinarray->add(5.23f);

    // Print dinarray, it's sum, it's average and it's mode.
    cout << floatDinarray << endl;

    cout << "Sum: " << floatDinarray->sum() << endl;

    cout << "Average: " << floatDinarray->average() << endl;

    cout << "Mode: " << floatDinarray->mode();

    return 0;
}
