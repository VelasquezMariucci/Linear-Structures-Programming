#include <iostream>


/*
 * Escriba un programa que declare dos punteros a enteros y pida al usuario
 * que ingrese dos valores enteros. Luego, intercambie los valores a los que
 * apuntan los punteros y finalmente imprima los valores intercambiados.
 */

/*
 * @Brief class that loops until the user enters an integer.
 *
 * Runs a while loop tha jumps only when the value is acceptable (an int). If not acceptable,
 * it clears the input and resets the state.
 *
 * @param message.
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
    int value1;
    int value2;
    int* pValue1 = &value1;
    int* pValue2 = &value2;

    *pValue1 = checkInt("Enter your first int: ");
    *pValue2 = checkInt("Enter your second int: ");

    std::cout << "Current First Pointing Value: " << *pValue1 << std::endl;
    std::cout << "Current Second Pointing Value: " << *pValue2 << std::endl;

    int* tempPointer = pValue1; //temp hold first value to then assign it to second value.
    pValue1 = pValue2;
    pValue2 = tempPointer;

    std::cout << "New First Pointing Value: " << *pValue1 << std::endl;
    std::cout << "New Second Pointing Value: " << *pValue2 << std::endl;

    return 0;
}
