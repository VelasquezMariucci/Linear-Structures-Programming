#include <iostream>
#include "../Structures/Stack_LinkedList.h"

/*Escribe un programa en el que se manejen un total de 5 pilas. La entrada
de datos será de pares de enteros (i, j), tal que 1<= abs(1) <= n. De tal forma que el
criterio de selección de pila sea:
• Si i es positivo, debe introducirse el elemento j en la Pila i.
• Si i es negativo, debe eliminarse el elemento j en la Pila j.
• Si i es 0, fin del proceso de entrada.*/

int getInputForI()
{
    int i = 0;
    bool isValid = false;
    while (!isValid)
    {
        std::cout << "Enter an int for i: ";
        std::cin >> i;

        if (std::cin.fail() || i < -5 || i > 5)
        {
            std::cin.clear(); // Clear error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. iInteger must be between -5 and 5, excluding 0." << std::endl;
        }
        else
        {
            isValid = true;
        }
    }

    return i;
}

int getInputForJ()
{
    int j = 0;
    bool isValid = false;
    while (!isValid)
    {
        std::cout << "Enter an int for j: ";
        std::cin >> j;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid integer." << std::endl;
        }
        else
        {
            isValid = true;
        }
    }

    return j;
}

int main()
{
    // Create 5 linked list stacks
    Stack_LinkedList<int>* s1 = new Stack_LinkedList<int>();
    Stack_LinkedList<int>* s2 = new Stack_LinkedList<int>();
    Stack_LinkedList<int>* s3 = new Stack_LinkedList<int>();
    Stack_LinkedList<int>* s4 = new Stack_LinkedList<int>();
    Stack_LinkedList<int>* s5 = new Stack_LinkedList<int>();

    // while loop
    int i = 10;
    while (i != 0)
    {
        // random i in range of number of stacks
        i = getInputForI();

        // random j in range of 1 <= abs(i) <= n
        int j = getInputForJ();

        switch (i)
        {
        case 1:
            {
                s1->push(j);
                break;
            }
        case 2:
            {
                s2->push(j);
                break;
            }
        case 3:
            {
                s3->push(j);
                break;
            }
        case 4:
            {
                s4->push(j);
                break;
            }
        case 5:
            {
                s5->push(j);
                break;
            }
        case -1:
            {
                s1->remove(j);
                break;
            }
        case -2:
            {
                s2->remove(j);
                break;
            }
        case -3:
            {
                s3->remove(j);
                break;
            }
        case -4:
            {
                s4->remove(j);
                break;
            }
        case -5:
            {
                s5->remove(j);
                break;
            }
        }

        std::cout << "Stack 1: " << *s1 << std::endl;
        std::cout << "Stack 2: " << *s2 << std::endl;
        std::cout << "Stack 3: " << *s3 << std::endl;
        std::cout << "Stack 4: " << *s4 << std::endl;
        std::cout << "Stack 5: " << *s5 << std::endl;
        std::cout << "-----------------------" << std::endl;
    }

    std::cout << "Program ended (i = 0)";

    return 0;
}
