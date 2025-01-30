#include <iostream>

/*
 * Escriba un programa que declare un puntero a un entero y pida al usuario
 * que ingrese dos valores para ese entero. Luego, sume los dos valores y
 * almacene el resultado en la dirección de memoria a la que apunta el
 * puntero. Finalmente, imprima el valor del entero.
 */

/*
 * @Brief class that loops until the user enters an integer.
 *
 * Runs a while loop tha jumps only when the value is acceptable (an int). If not acceptable,
 * it clears the input and resets the state.
 *
 * @param message string error message.
 */
int checkInt(std::string message)
{
    int i;

    while (!(std::cin >> i))
    {
        // Handle input error
        std::cout << message << std::endl;

        // Clear previous input
        std::cin.clear();

        // Discard previous input
        std::cin.ignore(100, '\n');
    }

    return i;
}


int main()
{
    int userInput;

    int userSum;
    int* pUserSum = &userSum;

    // first number
    std::cout << "Enter the first number to be added" << std::endl;

    *pUserSum = checkInt("Error, not an int. Enter the first int: ");

    // second number
    std::cout << "Enter the second number to be added" << std::endl;

    *pUserSum += checkInt("Error, not an int. Enter the second int: ");

    // printer
    std::cout << "Pointer Location: " << &pUserSum << ", Pointing location:" << pUserSum << ", Sum Value: " <<
        *pUserSum << std::endl;

    return 0;
}
