#include <iostream>

// Escriba un programa que declare un puntero a un entero y pida al usuario
// que ingrese un valor para ese entero. Luego, imprima el valor del entero y la
// dirección de memoria a la que apunta el puntero.

int main()
{
    int userInput; // simple user input
    int saveUserInput; // where im saving the value through a pointer

    int* pUserInt = &saveUserInput; // pointer

    std::cout << "Enter a Integer: " << std::endl;

    while (!(std::cin >> userInput))
    {
        // Handle input error
        std::cout << "Error not a number, enter a number: " << std::endl;

        // Clear previous input
        std::cin.clear();

        // Discard previous input
        std::cin.ignore(100, '\n');
    }

    *pUserInt = userInput;

    std::cout << "Pointing Location (value): " << pUserInt << ", Excplicit Value:" << *pUserInt <<
        ", Pointer Location: " << &pUserInt;

    return 0;
}
