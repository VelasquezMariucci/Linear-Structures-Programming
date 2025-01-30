#include <iostream>
#include "../Structures/Stack_LinkedList.h"

/*Modificar el programa del ejercicio anterior para que la entrada sean
triplas de números enteros (i, j, k) donde i, j tienen el mismo significado que en el
anterior, y k es un numero entero, que puede tomar los valores -1 y 0, con el
siguiente significado:
• -1: hay que borrar todos los elementos de la pila
•  0: el proceso es el indicado en el apartado anterior para i y j.*/

int getInputForI()
{
    int i = 0;
    bool isValid = false;
    while (!isValid)
    {
        std::cout << "Enter an integer for i (-5 to 5, 0 to exit): ";
        std::cin >> i;

        if (std::cin.fail() || i < -5 || i > 5)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. i must be between -5 and 5, excluding 0." << std::endl;
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
        std::cout << "Enter an integer for j: ";
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

int getInputForZ()
{
    int z = 0;
    bool isValid = false;
    while (!isValid)
    {
        std::cout << "Enter an integer for z (-1 or 0): ";
        std::cin >> z;

        if (std::cin.fail() || (z != -1 && z != 0))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. z must be -1 or 0." << std::endl;
        }
        else
        {
            isValid = true;
        }
    }

    return z;
}

int main()
{
    // Create 5 linked list stacks
    Stack_LinkedList<int>* s1 = new Stack_LinkedList<int>();
    Stack_LinkedList<int>* s2 = new Stack_LinkedList<int>();
    Stack_LinkedList<int>* s3 = new Stack_LinkedList<int>();
    Stack_LinkedList<int>* s4 = new Stack_LinkedList<int>();
    Stack_LinkedList<int>* s5 = new Stack_LinkedList<int>();

    int i = 10; // Initial value to enter the loop
    while (i != 0)
    {
        i = getInputForI();
        int j = getInputForJ();
        int z = getInputForZ();

        std::cout << "-----------------------" << std::endl;
        std::cout << "(i:" << i << ", j:" << j << ", z:" << z << ")" << std::endl;

        if (z == 0)
        {
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
        }
        else
        {
            switch (i)
            {
            case 1:
                {
                    s1->clear();
                    break;
                }
            case 2:
                {
                    s2->clear();
                    break;
                }
            case 3:
                {
                    s3->clear();
                    break;
                }
            case 4:
                {
                    s4->clear();
                    break;
                }
            case 5:
                {
                    s5->clear();
                    break;
                }
            case -1:
                {
                    s1->clear();
                    break;
                }
            case -2:
                {
                    s2->clear();
                    break;
                }
            case -3:
                {
                    s3->clear();
                    break;
                }
            case -4:
                {
                    s4->clear();
                    break;
                }
            case -5:
                {
                    s5->clear();
                    break;
                }
            }
        }

        std::cout << "Stack 1: " << *s1 << std::endl;
        std::cout << "Stack 2: " << *s2 << std::endl;
        std::cout << "Stack 3: " << *s3 << std::endl;
        std::cout << "Stack 4: " << *s4 << std::endl;
        std::cout << "Stack 5: " << *s5 << std::endl;
        std::cout << "-----------------------" << std::endl;
    }

    std::cout << "Program ended (i = 0)" << std::endl;

    return 0;
}
