#include <iostream>

/*Haz una pseudo lista enlazada, creando 3 nodos con datos y
conectándolos entre sí. Al terminar, recorrer la pseudolista mostrando los datos de
los nodos.*/

/**
 * @brief struct to represent a node of a linked list.
 *
 * The node holds data and points to the next node making it easy to add new
 * items to the structure.
 */
struct Node
{
    int data;
    int next;

    /**
     * @brief Constructor with parameters for Node.
     *
     * @param data The data to store in the node.
     *  @param next Pointer to the next node.
     */
    Node(int value, int nextNode) : data(value), next(nextNode)
    {
    }
};

int main()
{
    // Create an array to represent pseudo linked list
    Node* pseudoLinkedList[3];

    // add values
    pseudoLinkedList[0] = new Node(10, 1);
    pseudoLinkedList[1] = new Node(20, 2);
    pseudoLinkedList[2] = new Node(30, -1);


    // Print data
    int index = 0;
    while (index != -1)
    {
        std::cout << "Data: " << pseudoLinkedList[index]->data << std::endl;
        index = pseudoLinkedList[index]->next;
    }

    return 0;
}
