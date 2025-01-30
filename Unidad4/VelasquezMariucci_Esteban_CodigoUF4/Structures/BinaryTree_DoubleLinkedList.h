//
// Created by esvel on 10/12/2024.
//

#ifndef BINARYTREE_DOUBLELINKEDLIST_H
#define BINARYTREE_DOUBLELINKEDLIST_H
#include <iostream>
#include <stdexcept>

#include "DoubleLinkedList.h"

/**
 * @brief A Binary Tree implementation using a Double Linked List.
 *
 * Extends the functionality of the DoubleLinkedList class to mimic a simple binary tree.
 * Nodes in the binary tree are represented as nodes of the double linked list,
 * where the `prev` pointer acts as the left child, and the `next` pointer acts as the right child.
 *
 * @tparam T The type of data stored in the tree.
 */
template <typename T>
class BinaryTree_DoubleLinkedList : public DoubleLinkedList<T>
{
public:
    using Node = typename DoubleLinkedList<T>::Node;

    /**
     * @brief Inserts a value into the binary tree.
     *
     * Inserts the value in level-order, filling each level of the tree from left to right.
     *
     * @param value The value to insert into the tree.
     */
    void insert(const T& value)
    {
        if (!this->head)
        {
            this->head = new Node(value);
            ++this->size;
            return;
        }

        Node* temp = this->head;
        while (temp)
        {
            if (!temp->prev)
            {
                temp->prev = new Node(value);
                ++this->size;
                return;
            }
            else if (!temp->next)
            {
                temp->next = new Node(value);
                ++this->size;
                return;
            }
            else
            {
                temp = temp->prev;
            }
        }
    }

    /**
     * @brief Performs an in-order traversal of the binary tree.
     *
     * Visits the nodes in the order of left child, root, right child.
     *
     * @param node The current node being visited (used for recursion).
     */
    void inOrderTraversal(Node* node)
    {
        if (!node)
        {
            return;
        }

        inOrderTraversal(node->prev);
        std::cout << node->data << " ";
        inOrderTraversal(node->next);
    }

    /**
     * @brief Public interface for in-order traversal.
     *
     * Starts the traversal from the root of the tree.
     */
    void inOrder()
    {
        inOrderTraversal(this->head);
    }

    /**
     * @brief Traverses the tree in in-order fashion.
     *
     * Alias for the `inOrder` function.
     */
    void traverse()
    {
        inOrderTraversal(this->head);
    }

    /**
     * @brief Removes a value from the binary tree.
     *
     * Only leaf nodes (nodes with no children) can be removed. If the node to be removed is found,
     * it is disconnected from its parent and deleted.
     *
     * @param value The value to remove from the tree.
     * @throws std::runtime_error If the node to remove is not a leaf or if the value is not found.
     */
    void remove(const T& value)
    {
        Node* temp = this->head;
        Node* parent = nullptr;

        while (temp)
        {
            if (temp->data == value)
            {
                if (!temp->prev && !temp->next)
                {
                    if (parent)
                    {
                        if (parent->prev == temp)
                        {
                            parent->prev = nullptr;
                        }

                        else
                        {
                            parent->next = nullptr;
                        }
                    }
                    else
                    {
                        this->head = nullptr;
                    }

                    delete temp;
                    --this->size;
                    return;
                }
                else
                {
                    throw std::runtime_error("Cannot remove non-leaf nodes.");
                }
            }
            parent = temp;

            if (temp->prev)
            {
                temp = temp->prev;
            }
            else
            {
                temp = temp->next;
            }
        }

        throw std::runtime_error("Value not found in the tree.");
    }
};

#endif //BINARYTREE_DOUBLELINKEDLIST_H
