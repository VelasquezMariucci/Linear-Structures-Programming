//
// Created by esvel on 21/01/2025.
//

#ifndef LIST_H
#define LIST_H
#include <iostream>

template <typename T>
class List {
private:
    int size;    // Maximum size of the list
    int count;   // Current number of elements in the list
    T* data;     // Array to store the list elements

public:
    // Constructor to initialize the list with a given size
    List(int size) : size(size), count(0) {
        data = new T[size];
    }

    // Adds a value to the end of the list
    void add(T value) {
        if (count < size) {
            data[count] = value;
            count++;
        }
    }

    // Adds a value to the beginning of the list
    void add_front(T value) {
        if (count < size) {
            for (int i = count; i > 0; i--) {
                data[i] = data[i - 1];
            }
            data[0] = value;
            count++;
        }
    }

    // Inserts a value at a specified position in the list
    void insert(T value, int position) {
        if (position < 0 || position > count) {
            return;
        }

        if (count < size) {
            for (int i = count; i > position; i--) {
                data[i] = data[i - 1];
            }
            data[position] = value;
            count++;
        }
    }

    // Removes an element at a specified position
    void remove(int position) {
        if (count < size || position > 0) {
            for (int i = position; i < count; i++) {
                data[i] = data[i + 1];
            }
            count--;
        } else {
            std::cout << "Position not available" << std::endl;
        }
    }

    // Removes the last element from the list
    void remove_last() {
        if (count > 0) {
            count--;
        }
    }

    // Removes the first element from the list
    void remove_first() {
        if (count > 0) {
            for (int i = 0; i < count; i++) {
                data[i] = data[i + 1];
            }
            count--;
        }
    }

    // Prints all elements in the list
    void print_list() {
        for (int i = 0; i < count; i++) {
            std::cout << data[i] << ", ";
        }
        std::cout << std::endl;
    }

    // Searches for a value in the list and counts its occurrences
    void search_value(T value) {
        int valueCount = 0;
        if (count <= size) {
            for (int i = 0; i < count; i++) {
                if (value == data[i]) {
                    valueCount++;
                }
            }
            std::cout << "The value " << value << " was found " << valueCount << " times." << std::endl;
        } else {
            std::cout << "Values not found" << std::endl;
        }
    }

    // Retrieves the element at a given index
    T get(int index) {
        if (index >= 0 && index < count) {
            return data[index];
        } else {
            std::cerr << "Error: Index out of range" << std::endl;
            return T(); // Return a default-constructed value of T
        }
    }
};

#endif //LIST_H
