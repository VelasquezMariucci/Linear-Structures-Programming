#include <iostream>
#include "../Structures/LinkedList.h"

/*Crea una lista enlazada de elementos que almacene como dato
números enteros. Debe contener al menos 5 números enteros.*/

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
    std::cout << *intLinkedList;

    return 0;
}
