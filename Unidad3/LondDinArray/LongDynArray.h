//
// Created by esvel on 5/11/2024.
//

#ifndef LONGDINARRAY_H
#define LONGDINARRAY_H

template <typename T>
class DynArray
{
private:
    T* array;
    size_t size, maxSize;

public:
    DynArray()
    {
        maxSize = 0;
        size = maxSize;
        array = new T[size];
    }

    DynArray(const size_t size)
    {
        maxSize = size;
        this->size = 0;
        array = new T[this->maxSize];
    }

    void alloc()
    {
        if (this->maxSize == 0)
        {
            this->maxSize = 1;
        }

        size_t aux = this->maxSize * 2;
        T* newArray = new T[aux];
        for (size_t i = 0; i < this->size / 2; i++)
        {
            newArray[i] = this->array[];
        }
        delete[] this->array;
        this->array = newArray;
    }

    void add(T val)
    {
        if (this->size >= this->maxSize)
        {
            this->alloc();
        }

        this->array[size] = val;
        size++;
    }

    T extract(size_t pos)
    {
        T aux;
        if (size > 0 && pos <= size)
        {
            aux = this->array[pos];
            delete (array + pos);
            size--;
            for (size_t i = pos; i < size; i++)
            {
                this->array[i] = this->array[i + 1];
            }
        }
        return aux;
    }
};


template <typename T>
class Vector
{
private:
    T *v, space, last;

public:
    Vector()
    {
        this->v = new T[0];
        this->space = v;
        this->last = v;
    }

    void push_back(T e)
    {
        if (space == last)
        {
            if (this->v == this->last)
            {
                v = new T[2];
                space = v;
                last = v + 2;
            }
            else
            {
                size_t old_size = space - v;
                v = new T[old_size * 2];
                space = v + old_size;
                last = v + old_size * 2;
            }
            *space = e;
        }
    }



    T pop_back()
    {
        if (space == v)
        {

        }

        --space;
        return space;
    }
};

#endif //LONGDINARRAY_H
