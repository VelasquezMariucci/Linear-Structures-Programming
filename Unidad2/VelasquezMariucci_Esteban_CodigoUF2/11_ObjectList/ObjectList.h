//
// Created by esvel on 27/10/2024.
//

#ifndef OBJECTLIST_H
#define OBJECTLIST_H
#include <stdexcept>

/**
 * @class ObjectList
 * @brief A templated list container class.
 *
 * ObjectList provides a simple dynamic array-like structure with functionality
 * to add elements, retrieve elements, and print the list contents.
 *
 * @tparam T Type of elements in the list.
 */
template <typename T>
class ObjectList
{
private:
    T* pList; 
    int end; 
    size_t size; 

public:
    /**
     * @brief Constructs an ObjectList with a specified maximum size.
     *
     * Initializes the list with a given size, defaulting to 10. Allocates memory
     * for the list and sets the end to 0, indicating an empty list.
     *
     * @param size Initial maximum size of the list.
     */
    ObjectList(const int size = 10) : pList(new T[size]), end(0), size(size) {}

    /**
     * @brief Destructor to clean up dynamic memory.
     *
     * Deletes the dynamically allocated array to prevent memory leaks.
     */
    ~ObjectList()
    {
        delete[] pList;
    }

    /**
     * @brief Adds an element to the list.
     *
     * Adds a new element at the end of the list. If the list reaches its current maximum size,
     * it doubles the size and reallocates memory to accommodate additional elements.
     *
     * @param object The element to add to the list.
     */
    void add(const T& object)
    {
        if (end == size) 
        {
            size = size * 2; 
            T* newList = new T[size]; 

            for (int i = 0; i < end; i++)
            {
                newList[i] = pList[i];
            }

            delete[] pList; 
            pList = newList; 
        }
        pList[end] = object; 
        end++; 
    }

    /**
     * @brief Retrieves and removes the last element from the list.
     *
     * Returns the last element in the list and removes it by decrementing end.
     * Throws an exception if the list is empty.
     *
     * @return The last element in the list.
     * @throws std::out_of_range if the list is empty.
     */
    T get()
    {
        if (end == 0) 
        {
            throw std::out_of_range("Error: List Empty");
        }

        T object = pList[end - 1]; 
        end--; 

        return object;
    }

    /**
     * @brief Overloaded << operator to output the list contents.
     *
     * Provides a way to print all elements in the list by iterating up to the end index.
     * Each element is output to the provided ostream, followed by a space.
     *
     * @param os The output stream to print to.
     * @param list The ObjectList instance to output.
     * @return The output stream with the list elements.
     */
    friend std::ostream& operator<<(std::ostream& os, const ObjectList& list)
    {
        for (int i = 0; i < list.end; i++)
        {
            os << list.pList[i] << " "; 
        }
        os << std::endl;

        return os;
    }
};

#endif //OBJECTLIST_H
