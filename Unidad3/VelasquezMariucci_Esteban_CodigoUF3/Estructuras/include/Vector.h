#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>
#include <iostream>

/** @brief A simple implementation of a dynamic vector for elements of any type.
 *
 * The Vector class provides dynamic array-like functionality, supporting
 * operations such as adding, removing, accessing elements, and computing
 * properties like sum, average, max, min, and median.
 *
 * @tparam T The type of elements stored in the vector.
 */
template <typename T>
class Vector
{
private:
    T* v;
    T* space;
    T* last;

    void free_memory()
    {
        delete[] v;
        v = nullptr;
        space = nullptr;
        last = nullptr;
    }

public:
    /** @brief Default constructor.
     *
     * Initializes the vector with an initial capacity of 2 elements.
     */
    Vector()
    {
        this->v = new T[2];
        this->space = v;
        this->last = v + 2;
    }

    /** @brief Destructor.
     *
     * Automatically releases allocated memory when the object is destroyed.
     */
    ~Vector()
    {
        free_memory();
    }

    /** @brief Adds an element to the end of the vector.
     *
     * If the vector's capacity is full, it doubles the capacity before adding
     * the new element.
     *
     * @param e The element to be added.
     */
    void push_back(const T& e)
    {
        if (space == last)
        {
            size_t old_size = space - v;
            size_t new_size = old_size == 0 ? 2 : old_size * 2;

            T* new_array = new T[new_size];

            for (size_t i = 0; i < old_size; ++i)
            {
                new_array[i] = v[i];
            }

            free_memory();

            v = new_array;
            space = v + old_size;
            last = v + new_size;
        }

        *space = e;
        ++space;
    }

    /** @brief Removes and returns the last element of the vector.
    *
    * @return The last element of the vector.
    * @throws std::out_of_range if the vector is empty.
    */
    T pop_back()
    {
        if (space == v)
        {
            throw std::out_of_range("Vector is empty");
        }

        --space;
        return *space;
    }

    /** @brief Returns the number of elements in the vector.
     *
     * @return The number of elements currently stored in the vector.
     */
    size_t size() const
    {
        return space - v;
    }

    /** @brief Retrieves the element at the specified index.
     *
     * @param index The index of the element to retrieve.
     * @return A reference to the element at the specified index.
     * @throws std::out_of_range if the index is out of range.
     */
    T& get(size_t index) const
    {
        if (index >= size())
        {
            throw std::out_of_range("Index out of range");
        }

        return v[index];
    }

    /** @brief Calculates the sum of all elements in the vector.
     *
     * @return The sum of all elements in the vector.
     */
    T sum() const
    {
        T tempSum;
        for (size_t i = 0; i < size(); ++i)
        {
            tempSum += v[i];
        }

        return tempSum;
    }

    /** @brief Calculates the average of the elements in the vector.
     *
     * @return The average value of the elements.
     * @throws std::runtime_error if the vector is empty.
     */
    T average() const
    {
        T sumValue = sum();
        return sumValue / size();
    }

    /** @brief Finds the maximum element in the vector.
    *
    * Assumes that the > operator is defined for type T.
    *
    * @return The maximum element in the vector.
    */
    T max() const
    {
        T maxElement = v[0];
        for (size_t i = 1; i < size(); ++i)
        {
            if (v[i] > maxElement)
            {
                maxElement = v[i];
            }
        }
        return maxElement;
    }

    /** @brief Finds the minimum element in the vector.
     *
     * Assumes that the < operator is defined for type T.
     *
     * @return The minimum element in the vector.
     */
    T min() const
    {
        T minElement = v[0];
        for (size_t i = 1; i < size(); ++i)
        {
            if (v[i] < minElement)
            {
                minElement = v[i];
            }
        }
        return minElement;
    }

    /** @brief Finds the median of the elements in the vector.
    *
    * This function creates a temporary sorted copy of the vector and
    * calculates the median based on the number of elements. Assumes that
    * the < operator is defined for type T.
    *
    * @return The median value of the elements.
    * @throws std::out_of_range if the vector is empty.
    */
    T median() const
    {
        if (size() == 0)
        {
            throw std::out_of_range("Vector is empty");
        }

        Vector<T> temp;
        for (size_t i = 0; i < size(); ++i)
        {
            temp.push_back(v[i]);
        }

        for (size_t i = 0; i < temp.size() - 1; ++i)
        {
            for (size_t j = i + 1; j < temp.size(); ++j)
            {
                if (temp.get(i) > temp.get(j))
                {
                    T temp_val = temp.get(i);
                    temp.get(i) = temp.get(j);
                    temp.get(j) = temp_val;
                }
            }
        }

        size_t mid = temp.size() / 2;

        if (temp.size() % 2 == 0)
        {
            return (temp.get(mid - 1) + temp.get(mid)) / static_cast<T>(2);
        }
        else
        {
            return temp.get(mid);
        }
    }
};

#endif // VECTOR_H
