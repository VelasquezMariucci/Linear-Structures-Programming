#include <iostream>
#include "../Structures/BinaryTree_DoubleLinkedList.h"

/*Utilizando el árbol binario previamente desarrollado, implementa una
función “recorrido()”, que recorre todos los nodos de un árbol binario.*/

int main()
{
    // Create double Linked List binary tree
    BinaryTree_DoubleLinkedList<int>* tree = new BinaryTree_DoubleLinkedList<int>();

    // Insert values
    tree->insert(72);
    tree->insert(56);
    tree->insert(43);
    tree->insert(16);
    tree->insert(95);

    // Traverse binary tree
    std::cout << "Traverse binary tree: ";
    tree->traverse();
    std::cout << std::endl;

    return 0;
}
