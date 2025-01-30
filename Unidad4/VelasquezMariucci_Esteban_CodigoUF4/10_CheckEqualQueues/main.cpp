#include <iostream>
#include "../Structures/Queue_LinkedList.h"

/*Escribir una función que tenga como argumentos dos colas del mismo
tipo. En caso de ser idénticas, lo indique por consola al usuario.*/

/**
 * @brief Compares two queues for equality.
 *
 * This function compares two queues element by element, ensuring the original
 * queues remain unchanged. Returns true if the queues are identical, false otherwise.
 *
 * @tparam T The type of elements in the queues.
 * @param q1 The first queue to compare.
 * @param q2 The second queue to compare.
 * @return True if both queues are identical, false otherwise.
 */
template <typename T>
bool areQueuesEqual(Queue_LinkedList<T>& q1, Queue_LinkedList<T>& q2)
{
    if (q1.getSize() != q2.getSize())
    {
        return false;
    }

    bool isEqual = true;
    Queue_LinkedList<T> temp1;
    Queue_LinkedList<T> temp2;

    while (q1.getSize() != 0)
    {
        T front1 = q1.dequeue();
        T front2 = q2.dequeue();

        if (front1 != front2)
        {
            isEqual = false;
        }

        temp1.enqueue(front1);
        temp2.enqueue(front2);
    }

    // Restore the original queues
    while (temp1.getSize() != 0)
    {
        q1.enqueue(temp1.dequeue());
        q2.enqueue(temp2.dequeue());
    }

    return isEqual;
}

int main()
{
    // Create queues to compare
    Queue_LinkedList<int>* q1 = new Queue_LinkedList<int>();
    Queue_LinkedList<int>* q2 = new Queue_LinkedList<int>();

    // Add values to queues
    q1->enqueue(12);
    q1->enqueue(45);
    q1->enqueue(98);

    q2->enqueue(12);
    q2->enqueue(45);
    q2->enqueue(98);

    bool isSame = areQueuesEqual(*q1, *q2);

    std::cout << *q1 << std::endl;
    std::cout << *q2 << std::endl;
    std::cout << "Equal?: " << (isSame ? "True" : "False") << std::endl;

    q2->enqueue(34);

    isSame = areQueuesEqual(*q1, *q2);

    std::cout << *q1 << std::endl;
    std::cout << *q2 << std::endl;
    std::cout << "Equal?: " << (isSame ? "True" : "False") << std::endl;

    return 0;
}
