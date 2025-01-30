#include <iostream>
#include "../Structures/LinkedList.h"

/*Realiza un programa para crear una lista de números aleatorios. Los
nuevos números deben insertarse en el centro de la lista (o el punto medio de los
elementos de esta). Una vez creada se ha de recorrer mostrando únicamente los
números impares.
• Deben meterse los números aleatorios por el teclado del usuario.
• Para terminar de crear la lista, se introducirá el valor reservado -1.*/

int main()
{
    // Create user linked list
    LinkedList<int>* userLinkedList = new LinkedList<int>();

    std::string userInput = "";


    // Loop to insert values
    while (userInput != "-1")
    {
        try
        {
            std::cout << "Enter an random int to insert in the middle of the linkedList (-1 reserved to exit): ";

            std::cin >> userInput;

            int number = stoi(userInput);
            int size = userLinkedList->getSize();

            if (size == 0 || size == 1)
            {
                userLinkedList->append(number);
            }
            else
            {
                int middle = size / 2;

                int left = userLinkedList->at(middle - 1);
                int right = userLinkedList->at(middle);

                userLinkedList->insert(number, left, right);
            }

            std::cout << "Linked list: " << *userLinkedList << std::endl;
        }
        catch (const std::invalid_argument& e)
        {
            std::cout << "Input error" << std::endl;
        } catch (const std::exception& e)
        {
            std::cout << "Unexpected error: " << e.what() << std::endl;
        }
    }

    std::cout << "Goodbye" << std::endl;

    return 0;
}
