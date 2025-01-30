#include <iostream>

/*Escriba un programa que declare un puntero a un entero y asigne un valor
a ese entero. Luego, imprima el valor del entero y la dirección de memoria
a la que apunta el puntero.*/

int main()
{
    //Declare int
    int myInt;

    std::cout << "My Int's Value: " << myInt << "\n";

    //pointer to int
    int *pMyInt = &myInt;

    //assign value to my int using the pointer
    *pMyInt = 128;

    std::cout << "My Int's new Value: " << myInt << "\n";

    //final print
    std::cout << "My Int's Location: " << &myInt << "| My Pointer's Location: " << &pMyInt << "| My Pointer's Value: "
        << pMyInt << "\n";

    return 0;
}
