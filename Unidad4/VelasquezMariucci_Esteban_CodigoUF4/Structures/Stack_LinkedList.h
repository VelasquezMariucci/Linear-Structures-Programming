//
// Created by esvel on 9/12/2024.
//

#ifndef STACK_LINKEDLIST_H
#define STACK_LINKEDLIST_H
#include "LinkedList.h"

/**
 * @brief A stack implementation using a linked list as the underlying structure.
 *
 * Provides typical stack operations like push, pop, and clear, along with
 * size retrieval and comparison operators.
 *
 * @tparam T The type of the data stored in the stack.
 */
template <typename T>
class Stack_LinkedList
{
private:
    LinkedList<T>* linkedList;

public:
    /**
     * @brief Default constructor for Stack_LinkedList.
     *
     * Initializes an empty stack by creating a new linked list.
     */
    Stack_LinkedList(): linkedList(new LinkedList<T>())
    {
    }

    /**
     * @brief Copy constructor for Stack_LinkedList.
     *
     * Creates a deep copy of another stack.
     *
     * @param other The stack to copy.
     */
    Stack_LinkedList(const Stack_LinkedList<T>& other) : linkedList(new LinkedList<T>(*other.linkedList))
    {
    }

    /**
     * @brief Removes and returns the top element of the stack.
     *
     * @return The top element of the stack.
     */
    T pop()
    {
        T temp = linkedList->at(linkedList->getSize() - 1);
        linkedList->removeBack();
        return temp;
    }

    /**
     * @brief Adds an element to the top of the stack.
     *
     * @param item The item to add to the stack.
     */
    void push(T item)
    {
        linkedList->append(item);
    }

    /**
     * @brief Retrieves the number of elements in the stack.
     *
     * @return The size of the stack.
     */
    size_t getSize() const
    {
        return linkedList->getSize();
    }

    /**
     * @brief Removes the first occurrence of a specified item from the stack.
     *
     * @param item The item to remove.
     */
    void remove(T item)
    {
        linkedList->remove(item);
    }

    /**
     * @brief Clears all elements from the stack.
     */
    void clear()
    {
        linkedList->clear();
    }

    /**
     * @brief Compares two stacks for equality.
     *
     * Two stacks are considered equal if they contain the same number of elements,
     * in the same order.
     *
     * @param other The stack to compare with.
     * @return True if the stacks are equal, false otherwise.
     */
    bool operator==(const Stack_LinkedList& other) const
    {
        if (this->getSize() != other.getSize())
        {
            return false;
        }

        Stack_LinkedList<T> temp1 = *this;
        Stack_LinkedList<T> temp2 = other;

        size_t size = temp1.getSize();
        for (size_t i = 0; i < size; ++i)
        {
            if (temp1.linkedList->at(i) != temp2.linkedList->at(i))
            {
                return false;
            }
        }

        return true;
    }

    /**
     * @brief Outputs the elements of the stack to a stream.
     *
     * The elements are displayed in order from top to bottom.
     *
     * @param os The output stream.
     * @param stack The stack to output.
     * @return A reference to the output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const Stack_LinkedList<T>& stack)
    {
        // Output the elements of the stack from top to bottom
        LinkedList<T>* list = stack.linkedList;

        const size_t size = list->getSize();

        os << "[";
        for (int i = 0; i < size; i++)
        {
            os << list->at(i) << "->";
        }
        os << "]";
        return os;
    }
};


#endif //STACK_LINKEDLIST_H
