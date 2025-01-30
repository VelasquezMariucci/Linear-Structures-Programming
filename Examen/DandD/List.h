//
// Created by suare on 15/01/2025.
//

#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <string>

template <typename T>
class List {
protected:
    class Nodo {
    public:
        T data;
        Nodo* nexo;
        Nodo(T data) : data(data), nexo(nullptr) {}
        Nodo(T data, Nodo* nexo) : data(data), nexo(nexo) {}
        ~Nodo() { std::cout << "Se elimina el nodo: " << data << std::endl; }
    };

private:
    Nodo* head;
    Nodo* tail;
    int size;

public:
    List() : head(nullptr), tail(nullptr), size(0) {}
    ~List() {
        while (!isEmpty()) {
            remove_head();
        }
        std::cout << "Se elimina la lista enlazada" << std::endl;
    }

    bool isEmpty() { return head == nullptr; }

    void insert_Head(T data) {
        Nodo* nodo = new Nodo(data, head);
        head = nodo;
        if (size == 0) {
            tail = nodo;
        }
        size++;
    }

    void insert_Tail(T data) {
        Nodo* nodo = new Nodo(data);
        if (isEmpty()) {
            head = tail = nodo;
        } else {
            tail->nexo = nodo;
            tail = nodo;
        }
        size++;
    }

    void insert(T data, int pos) {
        if (pos < 0 || pos > size) {
            std::cout << "Posicion incorrecta" << std::endl;
            return;
        }
        if (pos == 0) {
            insert_Head(data);
        } else if (pos == size) {
            insert_Tail(data);
        } else {
            Nodo* aux = head;
            for (int i = 0; i < pos - 1; i++) {
                aux = aux->nexo;
            }
            Nodo* nodo = new Nodo(data, aux->nexo);
            aux->nexo = nodo;
            size++;
        }
    }

    T remove_head() {
        if (isEmpty()) {
            throw std::out_of_range("La lista esta vacia");
        }
        T dato = head->data;
        Nodo* aux = head;
        head = head->nexo;
        delete aux;
        size--;
        if (size == 0) {
            tail = nullptr;
        }
        return dato;
    }

    T remove_tail() {
        if (isEmpty()) {
            throw std::out_of_range("La lista esta vacia");
        }
        T dato = tail->data;
        if (head == tail) {
            delete tail;
            head = tail = nullptr;
        } else {
            Nodo* aux = head;
            while (aux->nexo != tail) {
                aux = aux->nexo;
            }
            delete tail;
            tail = aux;
            tail->nexo = nullptr;
        }
        size--;
        return dato;
    }
    T get(int pos) const {
        if (pos < 0 || pos >= size) {
            throw std::out_of_range("Posicion fuera de rango");
        }

        Nodo* actual = head;
        for (int i = 0; i < pos; i++) {
            actual = actual->nexo;
        }

        return actual->data;
    }
    T remove(int pos) {
        if (pos < 0 || pos >= size) {
            throw std::out_of_range("Posicion incorrecta");
        }
        if (pos == 0) {
            return remove_head();
        } else if (pos == size - 1) {
            return remove_tail();
        } else {
            Nodo* aux = head;
            for (int i = 0; i < pos - 1; i++) {
                aux = aux->nexo;
            }
            Nodo* aux2 = aux->nexo;
            T dato = aux2->data;
            aux->nexo = aux2->nexo;
            delete aux2;
            size--;
            return dato;
        }
    }

    int getSize() const { return size; }

    // Método para mostrar los elementos de la lista
    // Método para mostrar los elementos de la lista con sus posiciones
    void display() const {
        Nodo* current = head;
        int position = 0; // Contador de posición
        std::cout << "Mochila: ";
        while (current != nullptr) {
            std::cout << "[" << position << "] " << current->data << " -> ";
            current = current->nexo;
            position++;
        }
        std::cout << "nullptr" << std::endl;
    }
    bool isEmpty() const {
        return head == nullptr; // O la lógica que determines para verificar si está vacía
    }

};


#endif //LIST_H
