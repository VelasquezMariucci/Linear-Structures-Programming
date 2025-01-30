//
// Created by esvel on 25/09/2024.
//

#ifndef TEMPLATEUTILS_H
#define TEMPLATEUTILS_H

#include <iostream>
#include <vector>
#include <algorithm>

/*
 * @brief A Generic List handle class using template for different objects.
 *
 * This class provides basic functions to add, remove, search, and order
 * elements withing a template vector.
 */
template <typename T>
class myGenericList
{
private:
    std::vector<T> list;

public:
    myGenericList() = default;
    ~myGenericList() = default;

    /*
     * @brief adds template element to template vector.
     *
     * @param const T& element Element to be added.
    */
    void addElement(T element)
    {
        list.push_back(element);
    }

    /*
    *@brief eliminate template element to template vector.
    *
    *This function finds the iterator value for the element and saves it as it. It uses that iterator
    *to check if the element is found in the student vector. If it's found its saved in it to later
    *be returned and deleted from the vector. If it's not found runtime_error exception is thrown.
    *
    *@param const T& element Element to be deleted.
    */
    void removeElement(T element)
    {
        auto it = std::find(list.begin(), list.end(), element);
        if (it != list.end())
        {
            list.erase(it);
            std::cout << element << " deleted." << std::endl;
        }
        else
        {
            std::cout << element << " not found." << std::endl;
        }
    }

    /*
     *@brief returns if element can be found in vector.
     *
     *This function finds the iterator value for the student and saves it as it. It uses that
     *iterator to check if the student is found in the student vector. If it's found it returns
     *true, else false.
     *
     *@param const T& element Element to be searched.
     *@return bool if can be found.
     */
    bool searchElement(T element)
    {
        auto it = std::find(list.begin(), list.end(), element);
        if (it != list.end())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    /*
     *@brief sorts template vector.
     *
     *uses std::sort to sort vector list.
     *
     */
    void orderList()
    {
        std::sort(list.begin(), list.end());
    }

    /*
     *@brief prints all elements in the template vector.
     *
     *This function iterates over all elements in the vector and prints them.
     */
    void printList()
    {
        for (const auto& element : list)
        {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
};

#endif //TEMPLATEUTILS_H
