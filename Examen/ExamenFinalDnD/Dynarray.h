//
// Created by esvel on 12/11/2024.
//

#ifndef DYNARRAY_H
#define DYNARRAY_H
#include <ostream>

/** @brief A dynamic array template class for storing elements of any type.
 *
 * The DynArray class is a template-based dynamic array implementation,
 * which allows for flexible storage and manipulation of elements. It
 * supports operations like adding elements, extracting  elements,
 * retrieving elements, and printing the array's contents to an output
 * stream.
 *
 * @tparam T The type of elements stored in the dynamic array.
 */
template <typename T>
class DynArray
{
private:
    T* array;
    size_t size;
    size_t maxSize;

public:
    /** @brief Default constructor.
     *
     * Initializes an empty dynamic array with maxSize and size set to zero,
     * and allocates an array with zero elements.
     */
    DynArray()
    {
        maxSize = 0;
        size = maxSize;
        array = new T[size];
    }

    /** @brief Constructor with initial size.
     *
     * Initializes a dynamic array with a specified maximum size, setting
     * the current size to zero. Allocates memory for maxSize elements.
     *
     * @param size Initial maximum size of the dynamic array.
     */
    DynArray(const size_t size)
    {
        maxSize = size;
        this->size = 0;
        array = new T[this->maxSize];
    }

    /** @brief Adds a value to the dynamic array.
     *
     * This function inserts the given value at the next available position in
     * the array. If the array's size has reached its maxSize, it calls alloc
     * to expand the array's capacity.
     *
     * @param val The value to add to the dynamic array.
     */
    void add(T val)
    {
        if (this->size >= this->maxSize)
        {
            this->alloc();
        }

        this->array[size] = val;
        size++;
    }

    /** @brief Extracts and removes an element at a specified position.
     *
     * This function removes the element at the specified index, shifts all
     * subsequent elements one position to the left to fill the gap, and
     * decrements the size. The removed element is returned.
     *
     * @param pos The position of the element to be removed.
     * @return The extracted element from the specified position.
     */
    T extract(size_t pos)
    {
        T aux;
        if (size > 0 && pos < size)
        {
            aux = this->array[pos];
            for (size_t i = pos; i < size - 1; i++)
            {
                this->array[i] = this->array[i + 1];
            }
            size--;
        }
        return aux;
    }

    /** @brief Retrieves an element at a specified position.
     *
     * This function returns the element at the specified position without
     * modifying the array.
     *
     * @param pos The position of the element to retrieve.
     * @return The element at the specified position.
     */
    T get(size_t pos)
    {
        T aux;
        if (size > 0 && pos < size)
        {
            aux = this->array[pos];
        }
        return aux;
    }

    /** @brief Retrieves the index of the first occurrence of a specified element.
     *
     * This function iterates through the array to find the index of the
     * first occurrence of the provided element. If the element is found,
     * it returns its index; otherwise, it returns -1.
     *
     * @param data The element to search for in the dynamic array.
     * @return The index of the element, or -1 if not found.
     */
    int getIndex(T data)
    {
        int tempData = -1;

        for (int i = 0; i < size; ++i)
        {
            if (array[i] == data)
            {
                tempData = i;
                i = size;
            }
        }

        return tempData;
    }

    /** @brief Sorts elements in the dynamic array in ascending order.
     *
     * This function sorts elements stored in the dynamic array. It uses
     * the `<` operator to sort elements in ascending order. For `std::string`,
     * a specialized version is provided to ensure alphabetical ordering.
     */
    void sort()
    {
        std::sort(array, array + size);
    }

    /** @brief Calculates the sum of all elements in the array.
     *
     * This function iterates through the array and computes the total sum
     * of all its elements. The function assumes that the `+` operator is
     * defined for the type `T`.
     *
     * @return The sum of all elements in the array.
     */
    T sum() const
    {
        T tempSum;
        for (int i = 0; i < size; ++i)
        {
            tempSum += array[i];
        }

        return tempSum;
    };

    /** @brief Calculates the average of the array's elements.
     *
     * This function computes the average by dividing the sum of all elements
     * by the total number of elements. It validates that the array is not empty
     * and that its type `T` supports arithmetic operations.
     *
     * @return The average value of the elements in the array.
     * @throws std::runtime_error if the array size is zero or if `T` is non-numeric.
     */
    T average() const
    {
        if (size == 0)
        {
            throw std::runtime_error("Array size is zero.");
        }


        if (!std::is_arithmetic_v<T>)
        {
            throw std::runtime_error("Array contains non-numerical values.");
        }


        return this->sum() / size;
    }

    /** @brief Determines the mode of the array's elements.
     *
     * This function identifies the most frequently occurring element in
     * the array. If there are multiple elements with the same maximum
     * frequency, the function returns the first one encountered.
     *
     * @return The mode of the array's elements.
     */
    T mode() const
    {
        T returnVal = array[0];
        int maxCount = 0;

        for (int i = 0; i < size; i++)
        {
            int repeatCount = 0;

            for (int j = i; j < size; j++)
            {
                if (array[i] == array[j])
                {
                    repeatCount++;
                }
            }

            if (repeatCount > maxCount)
            {
                maxCount = repeatCount;
                returnVal = array[i];
            }
        }

        return returnVal;
    }

    /** @brief Overloads the output stream operator for DynArray.
     *
     * This friend function allows printing of the dynamic array's elements
     * in a list format. The array contents are displayed in square brackets,
     * with elements separated by commas.
     *
     * @param os Output stream.
     * @param dyn The dynamic array to be printed.
     * @return A reference to the output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const DynArray<T>& dyn)
    {
        os << "[";
        for (size_t i = 0; i < dyn.size; ++i)
        {
            os << dyn.array[i];
            if (i < dyn.size - 1)
            {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }

    int getSize()
    {
        return size;
    }

protected:
    /** @brief Expands the dynamic array capacity.
     *
     * This function doubles the maximum size of the dynamic array, allocates
     * a new array with the expanded size, and copies over the existing elements.
     * It then deletes the old array and assigns the new array to the class.
     */
    void alloc()
    {
        if (this->maxSize == 0)
        {
            this->maxSize = 1;
        }

        size_t newMaxSize = this->maxSize * 2;
        T* newArray = new T[newMaxSize];

        for (size_t i = 0; i < this->size; i++)
        {
            newArray[i] = this->array[i];
        }

        delete[] this->array;
        this->array = newArray;
        this->maxSize = newMaxSize;
    }


};

/** @brief Specialized sort function for strings.
 *
 * This specialization of the sort function arranges elements of type
 * std::string in alphabetical order.
 */
template <>
inline void DynArray<std::string>::sort()
{
    std::sort(array, array + size, [](const std::string& a, const std::string& b)
    {
        return a < b;
    });
}


#endif //DYNARRAY_H
