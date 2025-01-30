//
// Created by esvel on 27/10/2024.
//

#ifndef POINTERLIST_H
#define POINTERLIST_H

/**
 * @class PointerList
 * @brief A templated list container class that manages pointers to dynamically allocated objects.
 *
 * PointerList provides a dynamic array-like structure for managing pointers any objects. It allows adding,
 * retrieving, and printing the pointers stored in the list.
 *
 * @tparam T Type of objects in the list.
 */
template <typename T>
class PointerList
{
private:
    T** pList; // Pointer to an array of pointers.
    int end; // last element in the list.
    size_t size;

public:
    /**
     * @brief Constructs a PointerList with a specified maximum size.
     *
     * Initializes the list with a given size, defaulting to 10. Allocates memory
     * for the list of pointers and sets the end to 0, indicating an empty list.
     *
     * @param size Initial maximum number of pointers.
     */
    PointerList(const int size = 10) : pList(new T*[size]), end(0), size(size)
    {
    }

    /**
     * @brief Destructor to clean up dynamic memory.
     *
     * Deletes the dynamically allocated array of pointers to prevent memory leaks.
     */
    ~PointerList()
    {
        delete[] pList;
    }

    /**
     * @brief Adds a pointer to an object to the list.
     *
     * Adds a new pointer at the end of the list. If the list reaches its current maximum size,
     * it doubles and reallocates memory to fit additional pointers.
     *
     * @param object Pointer to the object to add to the list.
     */
    void add(const T* object)
    {
        if (end == size) // Check if list is full
        {
            size *= 2; // Double the size
            T** newList = new T*[size]; // Allocate a larger array of pointers

            // Copy existing pointers to new list
            for (int i = 0; i < end; i++)
            {
                newList[i] = pList[i];
            }

            delete[] pList; // Delete old array of pointers
            pList = newList; // Update pList to new list
        }
        pList[end] = const_cast<T*>(object); // Add the new pointer
        end++; // Increment end index
    }

    /**
     * @brief Retrieves and removes the last pointer from the list.
     *
     * Returns the last pointer in the list and removes it by subtracting the end.
     * Throws an exception if the list is empty.
     *
     * @return The last pointer.
     * @throws std::out_of_range
     */
    T* get()
    {
        if (end == 0) // Check if list is empty
        {
            throw std::out_of_range("Error: List Empty");
        }

        T* object = pList[end - 1]; // Get the last pointer
        end--; // Decrement end to remove it

        return object;
    }

    /**
     * @brief Overloaded << operator to output the list contents.
     *
     * Provides a way to print all elements in the list by iterating up to the end index.
     *
     * @param os The output stream to print to.
     * @param list PointerList instance to output.
     * @return The output stream with the list elements.
     */
    friend std::ostream& operator<<(std::ostream& os, const PointerList& list)
    {
        for (int i = 0; i < list.end; i++)
        {
            os << *(list.pList[i]) << " "; // Dereference each pointer to print the object
        }
        os << std::endl;

        return os;
    }
};

#endif //POINTERLIST_H
