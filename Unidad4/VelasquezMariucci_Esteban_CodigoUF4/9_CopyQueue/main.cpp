#include <iostream>
#include "../Structures/Queue_LinkedList.h"

/*Suponiendo que se tiene la clase cola que implementa las operaciones
del TAD cola. Escribir una función que crea un clon (una copia idéntica) de una
cola determinada. Las operaciones que se han de utilizar son únicamente las del
TAD Cola.
*/

/**
 * @brief Creates a copy of a given queue.
 *
 * This function takes a source queue as input and returns a new queue with the same elements,
 * preserving the original order of the elements in the source queue. The function uses two
 * queues to achieve this while ensuring that the source queue remains unmodified.
 *
 * @tparam T The type of elements stored in the queue.
 * @param source The queue to be copied. This queue remains unchanged.
 * @return A new queue containing the same elements as the source queue in the same order.
 */
template <typename T>
Queue_LinkedList<T> copyQueue(const Queue_LinkedList<T>& source)
{
    Queue_LinkedList<T> temp;
    Queue_LinkedList<T> target;
    Queue_LinkedList<T> sourceCopy = source;

    while (sourceCopy.getSize() != 0)
    {
        T front = sourceCopy.dequeue();
        temp.enqueue(front);
        target.enqueue(front);
    }

    while (temp.getSize() != 0)
    {
        sourceCopy.enqueue(temp.dequeue());
    }

    return target;
}

int main()
{
    // Create queues
    Queue_LinkedList<char> q1;
    Queue_LinkedList<char> q2;

    // Add values
    q1.enqueue('H');
    q1.enqueue('E');
    q1.enqueue('L');
    q1.enqueue('L');
    q1.enqueue('O');

    // Pritn
    std::cout << "State of q1: " << q1 << std::endl;
    std::cout << "State of q2: " << q2 << std::endl;

    q2 = copyQueue(q1);

    // Print again
    std::cout << "State of q1: " << q1 << std::endl;
    std::cout << "State of q2: " << q2 << std::endl;

    return 0;
}
