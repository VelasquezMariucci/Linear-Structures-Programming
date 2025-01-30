#include <iostream>
#include "../Structures/BinaryTree_DoubleLinkedList.h"

/*Escribe un programa en C++ para representar un árbol binario como
una lista de dobles enlaces, permitiendo recorridos sencillos y operaciones de
inserción y eliminación de nodos.*/


int main()
{
    // Create double Linked List binary tree
    BinaryTree_DoubleLinkedList<int>* tree = new BinaryTree_DoubleLinkedList<int>();

    // Insert values
    tree->insert(10);
    tree->insert(20);
    tree->insert(30);
    tree->insert(40);

    // print in order
    std::cout << "Order: ";
    tree->inOrder();
    std::cout << std::endl;

    // Remove a value
    tree->remove(40);

    // print again
    std::cout << "order after removal: ";
    tree->inOrder();
    std::cout << std::endl;

    return 0;
}
