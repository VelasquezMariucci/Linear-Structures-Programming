//
// Created by esvel on 10/12/2024.
//

#ifndef QUEUE_LINKEDLIST_H
#define QUEUE_LINKEDLIST_H
#include "LinkedList.h"

/**
 * @brief A template class representing a queue.
 *
 * Queue provides standard queue operations such as enqueue, dequeue,
 * and utility methods for copying and comparing queues.
 *
 * @tparam T The type of the data stored in the queue.
 */
template <typename T>
class Queue_LinkedList : public LinkedList<T>
{
public:
    using Node = typename LinkedList<T>::Node;

    /**
     * @brief Adds a value to the end of the queue.
     *
     * @param value The value to add.
     */
    void enqueue(const T& value)
    {
        this->append(value);
    }

    /**
     * @brief Removes a value from the front of the queue.
     *
     * @return The removed value.
     * @throws std::runtime_error if the queue is empty.
     */
    T dequeue()
    {
        if (this->getSize() == 0)
        {
            throw std::runtime_error("Queue is empty.");
        }
        T frontValue = this->at(0);
        this->removeFront();
        return frontValue;
    }

    /**
     * @brief Retrieves the value at a specific position in the queue.
     *
     * @param position The position to retrieve.
     * @return A reference to the value at the position.
     * @throws std::out_of_range if the position is out of range.
     */
    T& valueAt(int position)
    {
        return this->at(position);
    }

    /**
     * @brief Creates a copy of the current queue.
     *
     * @return A new Queue instance that is a copy of the current queue.
     */
    Queue_LinkedList<T> copy() const
    {
        Queue_LinkedList<T> newQueue;
        Node* current = this->head;
        while (current)
        {
            newQueue.enqueue(current->data);
            current = current->next;
        }
        return newQueue;
    }

    /**
     * @brief Compares two queues for equality using the == operator.
     *
     * @param other The other queue to compare with.
     * @return true if the queues are equal, false otherwise.
     */
    bool operator==(const Queue_LinkedList<T>& other) const
    {
        if (this->getSize() != other.getSize())
        {
            return false;
        }

        Node* current1 = this->head;
        Node* current2 = other.head;

        while (current1 && current2)
        {
            if (current1->data != current2->data)
            {
                return false;
            }
            current1 = current1->next;
            current2 = current2->next;
        }
        return true;
    }

    /**
     * @brief Overloaded << operator to print the queue.
     *
     * @param os The output stream.
     * @param queue The queue to print.
     * @return A reference to the output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const Queue_LinkedList<T>& queue)
    {
        Node* current = queue.head;
        os << "Queue: [";
        while (current)
        {
            os << current->data;
            if (current->next)
            {
                os << " -> ";
            }
            current = current->next;
        }
        os << "]";
        return os;
    }
};

#endif //QUEUE_LINKEDLIST_H
