//
// Created by esvel on 9/12/2024.
//

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

/**
 * @brief A doubly linked list implementation.
 *
 * Allows for efficient insertions and deletions at both ends
 * and traversal in both forward and backward directions.
 *
 * @tparam T The type of the data stored in the list.
 */
template <typename T>
class DoubleLinkedList
{
protected:
    /**
     * @brief Represents a node in the doubly linked list.
     *
     * A node stores data and pointers to the previous and next nodes.
     */
    struct Node
    {
        T data;
        Node* prev;
        Node* next;

        /**
         * @brief Default constructor for Node.
         */
        Node() : data(0), next(nullptr), prev(nullptr)
        {
        };

        /**
         * @brief Constructs a node with specified data and pointers.
         *
         * @param data The data to store in the node.
         * @param next Pointer to the next node (default is nullptr).
         * @param prev Pointer to the previous node (default is nullptr).
         */
        Node(const T& data, Node* next = nullptr, Node* prev = nullptr)
        {
            this->data = data;
            this->next = next;
            this->prev = prev;
        }
    };

    Node* head;
    Node* tail;
    int size;

public:
    /**
     * @brief Constructs an empty DoubleLinkedList.
     */
    DoubleLinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }

    /**
     * @brief Destructor for DoubleLinkedList.
     */
    ~DoubleLinkedList() = default;

    /**
     * @brief Adds an element to the end of the list.
     *
     * @param data The element to append.
     */
    void append(const T& data)
    {
        Node* node = new Node(data);
        if (tail)
        {
            tail->next = node;
            node->prev = tail;
        }
        else
        {
            head = node;
        }
        tail = node;
        size++;
    }

    /**
     * @brief Adds an element to the front of the list.
     *
     * @param data The element to prepend.
     */
    void prepend(const T& data)
    {
        Node* node = new Node(data, head);
        head = node;
        if (head)
        {
            head->prev = node;
        }
        else
        {
            tail = node;
        }
        ++size;
    }

    /**
     * @brief Inserts an element between two specified elements.
     *
     * @param insert The element to insert.
     * @param left The element before the new element.
     * @param right The element after the new element.
     */
    void insert(const T insert, T left, T right)
    {
        Node* temp = head;
        while (temp && temp->next)
        {
            if (temp->data == left && temp->next->data == right)
            {
                Node* newNode = new Node(insert, temp->next, temp);
                temp->next = newNode;
                newNode->prev = temp;
                size++;
                return;
            }

            temp = temp->next;
        }
    }

    /**
     * @brief Removes the first element in the list.
     */
    void removeFront()
    {
        if (!head)
        {
            throw std::runtime_error("List empty.");
        }

        Node* temp = head;
        head = head->next;

        if (head)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr;
        }
        delete temp;
        --size;
    }

    /**
     * @brief Removes the last element in the list.
     */
    void removeBack()
    {
        if (!head)
        {
            throw std::runtime_error("List empty.");
        }

        Node* temp = tail;
        tail = tail->prev;

        if (tail)
        {
            tail->next = nullptr;
        }
        else
        {
            head = nullptr;
        }
        delete temp;
        --size;
    }

    /**
     * @brief Retrieves an element at a specified index from the front.
     *
     * @param index The zero-based index.
     * @return A reference to the element.
     */
    T& leftAt(int index)
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
     * @brief Retrieves an element at a specified index from the back.
     *
     * @param index The zero-based index.
     * @return A reference to the element.
     */
    T& rightAt(int index)
    {
        if (index < 0 || index >= size)
        {
            throw std::out_of_range("Index out of range.");
        }

        Node* current = tail;
        for (int i = size - 1; i > index; i--)
        {
            current = current->prev;
        }
        return current->data;
    }

    /**
     * @brief Gets the number of elements in the list.
     *
     * @return The size of the list.
     */
    int getSize()
    {
        return size;
    }

    /**
     * @brief Removes the first occurrence of a specified element.
     *
     * @param item The element to remove.
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
            head->prev = nullptr;
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
                current->next->prev = current->prev;
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
     * @brief Clears all elements from the list.
     */
    void clear()
    {
        while (head)
        {
            removeFront();
        }
    }

    /**
     * @brief Outputs the elements of the list to a stream.
     *
     * Displays the elements from head to tail in a human-readable format.
     *
     * @param os The output stream.
     * @param list The list to output.
     * @return A reference to the output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const DoubleLinkedList<T>& list)
    {
        Node* current = list.head;
        os << "[nullptr <-> ";
        while (current)
        {
            os << current->data << " <-> ";
            current = current->next;
        }
        os << "nullptr]";
        return os;
    }
};

#endif //DOUBLELINKEDLIST_H
