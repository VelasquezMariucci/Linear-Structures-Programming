#include <iostream>
#include "../Structures/LinkedList.h"

/*Utilizando la lista de números enteros desarrollada en el apartado
anterior, inserta tres nuevos elementos. Uno en la cabeza, otro en la cola y otro
entre dos nodos.*/

int main()
{
    // Create int linked list
    LinkedList<int>* intLinkedList = new LinkedList<int>();

    // Add values
    intLinkedList->append(10);
    intLinkedList->append(65);
    intLinkedList->append(98);
    intLinkedList->append(29);
    intLinkedList->append(45);
    // Print
    std::cout << "Start: " << *intLinkedList << std::endl;

    // New head
    intLinkedList->prepend(11);

    // Print
    std::cout << "Prepended: " << *intLinkedList << std::endl;

    // New tail
    intLinkedList->append(43);

    // Print
    std::cout << "Appended: " << *intLinkedList << std::endl;

    // Insert
    intLinkedList->insert(33, 98, 29);

    // Print
    std::cout << "Inserted: " << *intLinkedList << std::endl;

    return 0;
}
