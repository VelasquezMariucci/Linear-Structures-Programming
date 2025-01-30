#include <iostream>

/*
 * Escriba un programa que declare un puntero a un arreglo de enteros y pida
 * al usuario que ingrese el tamaño del arreglo y los valores para cada
 * elemento. Luego, calcule la suma de todos los elementos del arreglo y
 * almacene el resultado en la dirección de memoria a la que apunta el
 * puntero. Finalmente, imprima el valor de la suma.
 */

/*
 * @Brief class that loops until the user enters an integer.
 *
 * Runs a while loop tha jumps only when the value is acceptable (an int). If not acceptable,
 * it clears the input and resets the state.
 *
 * @param message string.
 */
int checkInt(std::string message)
{
    int i;

    std::cout << message << std::endl;

    while (!(std::cin >> i))
    {
        std::cout << "Invalid input" << std::endl;

        // Clear previous input
        std::cin.clear();

        // Discard previous input
        std::cin.ignore(100, '\n');
    }

    return i;
}

int main()
{
    int* intArray;
    // This declaration for the variable arraySize is already a pointer.
    const int arraySize = checkInt("Enter the size of your int array: ");
    intArray = new int[arraySize];

    for (int i = 0; i < arraySize; i++)
    {
        // string to feed the checkInt function.
        std::string inputString = "Enter a value for position " + std::to_string(i + 1) + ": ";

        intArray[i] = checkInt(inputString);
    }

    int sum = 0;
    for (int i = 0; i < arraySize; i++)
    {
        sum += intArray[i]; // Sum all the values of the array in a temp int.
    }

    std::cout << "Previous value for array pointer: " << intArray << std::endl;

    delete[] intArray; // Free memory.

    intArray = new int; // New declaration for intArray to point to an int.

    intArray = &sum; // Point to the sum. 

    std::cout << "New value for array pointer: " << intArray << ", pointing value: " << *intArray << std::endl;

    return 0;
}
