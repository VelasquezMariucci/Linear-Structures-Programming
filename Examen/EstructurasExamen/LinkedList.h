//
// Created by esvel on 3/12/2024.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <ostream>
#include <stdexcept>

/**
 * @brief A template class representing a linked list.
 *
 * Provides methods to manipulate a linked list like adding, removing,
 * and accessing elements.
 *
 * @tparam T The type of the data stored in each node ofthe linked list.
 */
template <typename T>
class LinkedList
{
protected:
    /**
    * @brief struct to represent a node of a linked list.
    *
    * The node holds data and points to the next node making it easy to add new
    * items to the structure.
    */
    struct Node
    {
        T data;
        Node* next;

        /**
        * @brief Default constructor for Node.
        */
        Node() : data(0), next(nullptr)
        {
        };

        /**
        * @brief Constructor with parameters for Node.
        *
        * @param data The data to store in the node.
        * @param next Pointer to the next node.
        */
        Node(const T& data, Node* next = nullptr)
        {
            this->data = data;
            this->next = next;
        }
    };

protected:
    Node* head;
    Node* tail;
    int size;

public:
    /**
     * @brief Default constructor for LinkedList.
     *
     * Initializes an empty linked list.
     */
    LinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }

    /**
     * @brief Default destructor for LinkedList.
     */
    ~LinkedList() = default;

    /**
     * @brief Appends an element to the end of the linked list.
     *
     * @param data The data to append.
     */
    void append(const T& data)
    {
        Node* node = new Node(data);
        if (tail)
        {
            tail->next = node;
        }
        else
        {
            head = node;
        }
        tail = node;
        size++;
    }

    /**
     * @brief Prepends an element to the beginning of the linked list.
     *
     * @param data The data to prepend.
     */
    void prepend(const T& data)
    {
        Node* node = new Node(data, head);
        head = node;
        if (!tail)
        {
            tail = head;
        }
        ++size;
    }

    /**
     * @brief Inserts an element between two specified elements.
     *
     * @param insert The data to insert.
     * @param left The data of the left element.
     * @param right The data of the right element.
     */
    void insert(const T insert, T left, T right)
    {
        Node* temp = head;
        while (temp && temp->next)
        {
            if (temp->data == left && temp->next->data == right)
            {
                Node* newNode = new Node(insert, temp->next);
                temp->next = newNode;
                size++;
                return;
            }

            temp = temp->next;
        }
    }

    /**
     * @brief Removes the first element from the linked list.
     *
     * @throws std::runtime_error if the list is empty.
     */
    void removeFront()
    {
        if (!head)
        {
            throw std::runtime_error("List empty.");
        }

        Node* temp = head;
        head = head->next;

        if (!head)
        {
            tail = nullptr;
        }
        delete temp;
        --size;
    }

    /**
     * @brief Removes the last element from the linked list.
     *
     * @throws std::runtime_error if the list is empty.
     */
    void removeBack()
    {
        if (!head)
        {
            throw std::runtime_error("List empty.");
        }

        if (tail == head)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node* current = head;
            while (current->next != tail)
            {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = nullptr;
        }
        --size;
    }

    /**
     * @brief Retrieves the data at the specified index.
     *
     * @param index The index of the element to retrieve.
     * @return A reference to the data at the specified index.
     * @throws std::out_of_range if the index is out of range.
     */
    T& at(int index)
    {
        if (index < 0 || index >= size)
        {
            throw std::out_of_range("Index out of range.");
        }

        Node* current = head;
        for (int i = 0; i < index; ++i)
        {
            current = current->next;
        }
        return current->data;
    }

    /**
     * @brief Gets the size of the linked list.
     *
     * @return The number of elements in the linked list.
     */
    int getSize()
    {
        return size;
    }

    /**
     * @brief Removes the first occurrence of a specified item from the list.
     *
     * @param item The item to remove.
     */
    void remove(T item)
    {
        if (size < 1)
        {
            return;
        }

        if (head && head->data == item)
        {
            Node* temp = head;
            head = head->next;
            if (!head)
            {
                tail = nullptr;
            }
            delete temp;
            --size;
            return;
        }

        Node* current = head;
        while (current && current->next)
        {
            if (current->next->data == item)
            {
                Node* temp = current->next;
                current->next = current->next->next;

                if (!current->next)
                {
                    tail = current;
                }

                delete temp;
                --size;
                return;
            }

            current = current->next;
        }
    }

    /**
     * @brief Clears all elements from the linked list.
     */
    void clear()
    {
        while (head)
        {
            removeFront();
        }
    }

    /**
     * @brief Outputs the linked list to a stream.
     *
     * @param os The output stream.
     * @param list The linked list to output.
     * @return A reference to the output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list)
    {
        Node* current = list.head;
        os << "[";
        while (current)
        {
            os << current->data << " -> ";
            current = current->next;
        }
        os << "nullptr]";
        return os;
    }
};

#endif //LINKEDLIST_H
