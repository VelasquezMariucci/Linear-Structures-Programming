//
// Created by esvel on 27/10/2024.
//

#ifndef QUEUECLASS_H
#define QUEUECLASS_H

#include <iostream>

template <typename T>
class QueueClass
{
private:
    T* queue;
    int currentSize;
    int start;
    int end;
    size_t size;

    /**
     * @brief Doubles the queue size when capacity is reached.
     *
     * Copies current elements to a new, larger array, preserving order.
     */
    void resize()
    {
        int newSize = size * 2;

        T* newArray = new T[newSize];

        for (int i = 0; i < currentSize; i++)
        {
            newArray[i] = queue[(start + i) % size];
        }

        delete[] queue;

        start = 0;

        end = currentSize;

        queue = newArray;

        size = newSize;
    }

public:
    /**
     * @brief Constructor to initialize queue with a given size.
     *
     * Allocates memory for the initial queue size.
     *
     * @param size Initial capacity.
     */
    QueueClass(const int size = 10) : size(size), start(0), end(0), currentSize(0)
    {
        queue = new T[this->size];
    }

    ~QueueClass()
    {
        delete[] queue;
    }

    /**
     * @brief Adds an element to the queue.
     *
     * Resizes the queue if it's full, then adds the element.
     *
     * @param element The element to add.
     */
    void add(T element)
    {
        if (currentSize == size)
        {
            resize();
        }

        queue[end] = element;

        end = (end + 1) % size;

        currentSize++;
    }

    /**
     * @brief Removes the first element from the queue.
     *
     * If the queue is empty, prints a message and returns.
     */
    void remove()
    {
        if (currentSize == 0)
        {
            std::cout << "Queue Empty." << std::endl;

            return;
        }

        start = (start + 1) % size;

        currentSize--;
    }

    // Getters
    bool isEmpty()
    {
        return currentSize == 0;
    }

    int getSize()
    {
        return currentSize;
    }

    T getFirst()
    {
        if (currentSize == 0)
        {
            std::cout << "Queue Empty" << std::endl;

            exit(1);
        }

        return queue[start];
    }
};

#endif //QUEUECLASS_H
