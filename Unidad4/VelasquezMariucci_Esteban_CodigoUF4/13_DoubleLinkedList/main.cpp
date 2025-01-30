#include <iostream>
#include "../Structures/DoubleLinkedList.h"

/*Desarrolla un programa que implemente una lista doblemente
enlazada en C++, permitiendo la inserción, eliminación y búsqueda de elementos
en ambas direcciones.*/

int main()
{
    // Create double linked list
    DoubleLinkedList<int>* doubleLinkedList = new DoubleLinkedList<int>();

    // Test append
    doubleLinkedList->append(10);
    doubleLinkedList->append(23);
    doubleLinkedList->append(24);
    std::cout << "Append: " << *doubleLinkedList << std::endl;

    // Test prepend
    doubleLinkedList->prepend(98);
    std::cout << "Prepend: " << *doubleLinkedList << std::endl;

    // Test insert
    doubleLinkedList->insert(5, 10, 23);
    std::cout << "Insertion: " << *doubleLinkedList << std::endl;

    // Test remove (specific value)
    doubleLinkedList->remove(24);
    std::cout << "Removing 24: " << *doubleLinkedList << std::endl;

    // Test leftAt
    std::cout << "leftAt(" << 2 << "): " << doubleLinkedList->leftAt(2) << std::endl;

    // Test rightAt
    std::cout << "rightAt(" << 2 << "): " << doubleLinkedList->rightAt(2) << std::endl;

    return 0;
}
