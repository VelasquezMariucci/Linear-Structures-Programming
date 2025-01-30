#include <iostream>

/*Utilizando la pseudolista enlazada codificada en el ejercicio anterior,
crea funciones para insertar elementos al principio, al final y después de dos
elementos concretos del nodo. No creéis una clase lista para realizar este ejercicio.
únicamente el código de los nodos.*/

/**
 * @brief struct to represent a node of a linked list.
 *
 * The node holds data and points to the next node making it easy to add new
 * items to the structure.
 */
struct Node
{
    int data;
    Node* next;

    /**
     * @brief Constructor with parameters for Node.
     *
     * @param value The data to store in the node.
     *  @param nextNode Pointer to the next node.
     */
    Node(int value, Node* nextNode = nullptr) : data(value), next(nextNode)
    {
    }
};

/**
 * @brief Prepends a node to the beginning of the linked list.
 *
 * Updates the head pointer to point to the new node, effectively making it the first node in the list.
 *
 * @param head Pointer to the head pointer of the list.
 * @param other The node to prepend to the list.
 */
void prepend(Node** head, Node* other)
{
    other->next = *head;
    *head = other;
}

/**
 * @brief Appends a node to the end of the linked list.
 *
 * Traverses the list to find the last node and adds the new node after it.
 *
 * @param head Reference to the head pointer of the list.
 * @param other The node to append to the list.
 */
void append(Node*& head, Node* other)
{
    if (!head)
    {
        head = other;
    }
    else
    {
        Node* current = head;
        while (current->next)
        {
            current = current->next;
        }
        current->next = other;
    }
}

/**
 * @brief Inserts a node between two existing nodes in the linked list.
 *
 * Searches for a pair of consecutive nodes (`left` and `right`) and inserts the new node between them.
 *
 * @param head Pointer to the head of the list.
 * @param left Pointer to the node before the insertion point.
 * @param right Pointer to the node after the insertion point.
 * @param other The node to insert between `left` and `right`.
 */
void insert(Node* head, Node* left, Node* right, Node* other)
{
    while (head && head->next)
    {
        if (head->data == left->data && head->next->data == right->data)
        {
            other->next = left->next;
            left->next = other;
            return;
        }
        head = head->next;
    }
}

/**
 * @brief Prints the contents of the linked list.
 *
 * Outputs the data of each node in the list in the format `[data1 -> data2 -> ...]`.
 *
 * @param head Pointer to the head of the list.
 */
void printList(Node* head)
{
    std::cout << "[";
    while (head)
    {
        std::cout << head->data;
        if (head->next)
        {
            std::cout << " -> ";
        }
        head = head->next;
    }
    std::cout << "]" << std::endl;
}

int main()
{
    // Create head node
    Node* head = nullptr;

    // Create other nodes
    Node* n1 = new Node(10);
    Node* n2 = new Node(35);
    Node* n3 = new Node(30);
    Node* n4 = new Node(97);
    Node* n5 = new Node(25);

    // Prepend elements to list
    prepend(&head, n1);
    prepend(&head, n2);
    std::cout << "Prepend: ";
    printList(head);

    // Append elements to list
    append(head, n3);
    append(head, n4);
    std::cout << "Append: ";
    printList(head);

    // Insert element
    insert(head, n3, n4, n5);
    std::cout << "Insert: ";
    printList(head);

    return 0;
}
