#include <iostream>
#include "../Structures/LinkedList.h"
#include "../Structures/Stack_LinkedList.h"

/*Escribir una función, copiarPila(), que copie el contenido de una pila
(escrita como una lista enlazada) en otra. La función tendrá dos argumentos de
tipo pila, uno la pila fuente y otro la pila destino. Utilizar las operaciones definidas
sobre el TAD Pila para una pila enlazada.*/

/**
 * @brief Copies the contents of one stack into another.
 *
 * This function transfers elements from the source stack to the target stack.
 * The source stack is modified (elements are removed) and the target stack
 * will contain the reversed order of the source stack's elements.
 *
 * @tparam T The type of elements stored in the stacks.
 * @param source A pointer to the source stack whose elements need to be copied.
 * @param target A pointer to the target stack where elements will be copied.
 */
template <typename T>
void copyStack(Stack_LinkedList<T>* source, Stack_LinkedList<T>* target)
{
    const int size = source->getSize();
    for (int i = 0; i < size; i++)
    {
        target->push(source->pop());
    }
}

int main()
{
    // Create linked list stacks
    Stack_LinkedList<char>* source = new Stack_LinkedList<char>();
    Stack_LinkedList<char>* target = new Stack_LinkedList<char>();

    // Add chars
    source->push('H');
    source->push('E');
    source->push('L');
    source->push('L');
    source->push('O');

    // print stacks
    std::cout << "Source: " << *source << std::endl;
    std::cout << "Target: " << *target << std::endl;

    // Copy Stack
    copyStack(source, target);

    // Print again
    std::cout << "Source: " << *source << std::endl;
    std::cout << "Target: " << *target << std::endl;

    return 0;
}
