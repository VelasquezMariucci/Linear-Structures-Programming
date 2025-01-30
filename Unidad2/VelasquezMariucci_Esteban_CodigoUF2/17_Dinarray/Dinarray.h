//
// Created by esvel on 27/10/2024.
//

#ifndef DINARRAY_H
#define DINARRAY_H
#include <iostream>

/**
 * @brief Template class representing a dynamic array of type T.
 *
 * This class provides functionality to create, manipulate, and access
 * a dynamic array with automatic memory management.
 *
 * @tparam T The type of elements stored in the dynamic array.
 */
template <typename T>
class Dinarray
{
private:
    T* pArray;
    size_t size;

public:

    Dinarray(int size) : size(size)
    {
        pArray = new T[size];
    }

    void setElement(int index, T& value)
    {
        if (index > size)
        {
            std::cout << "Index out of range" << std::endl;
        }
        else
        {
            pArray[index] = value;
        }
    }


    T getElement(int index) const
    {
        if (index > size)
        {
            throw std::out_of_range("Index out of range");
        }
        else
        {
            return pArray[index];
        }
    }


    ~Dinarray()
    {
        delete[] pArray;
    }
};

#endif //DINARRAY_H
