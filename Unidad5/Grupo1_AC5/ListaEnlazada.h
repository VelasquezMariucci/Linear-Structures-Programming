//
// Created by Ricky Vicente on 21/12/2024.
//


#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H

#include <iostream>

#include "Registro.h"

template <typename T>
class ListaEnlazada {
protected:
    class Nodo {
    public:
        T data;
        Nodo* next;
        Nodo(T data) : data(data), next(nullptr) {}
        Nodo(T data, Nodo* next) : data(data), next(next) {}
        ~Nodo() = default;
    };

private:
    Nodo* head;
    Nodo* tail;
    int size;

public:
    ListaEnlazada() : head(nullptr), tail(nullptr), size(0) {}
    ~ListaEnlazada() {}

    [[nodiscard]] bool isEmpty() const { return head == nullptr; }

    int getSize() const {
        return size;
    }

    typename ListaEnlazada<T>::Nodo* getHead() const {
        return head;
    }

    void insert_Head(T data) {
        Nodo* nuevo = new Nodo(data, head);
        if (isEmpty()) {
            tail = nuevo;
        }
        head = nuevo;
        size++;
    }

    void insert_Tail(T data) {
        Nodo* nuevo = new Nodo(data);
        if (isEmpty()) {
            head = tail = nuevo;
        } else {
            tail->next = nuevo;
            tail = nuevo;
        }
        size++;
    }

    void insert(T data, int pos) {
        if (pos < 0 || pos > size) {
            std::cerr << "Posici\xF3n fuera de rango." << std::endl;
            return;
        }
        if (pos == 0) {
            insert_Head(data);
        } else if (pos == size) {
            insert_Tail(data);
        } else {
            Nodo* prev = head;
            for (int i = 0; i < pos - 1; ++i) {
                prev = prev->next;
            }
            Nodo* nuevo = new Nodo(data, prev->next);
            prev->next = nuevo;
            size++;
        }
    }

    T remove_Head() {
        if (isEmpty()) {
            throw std::out_of_range("La lista esta vacia");
        }
        Nodo* aux = head;
        T dato = aux->data;
        head = head->next;
        delete aux;
        size--;
        if (isEmpty()) {
            tail = nullptr;
        }
        return dato;
    }

    T remove_Tail() {
        if (isEmpty()) {
            throw std::out_of_range("La lista esta vacia");
        }
        Nodo* current = head;
        if (head == tail) {
            T dato = head->data;
            delete head;
            head = tail = nullptr;
            size--;
            return dato;
        }
        while (current->next != tail) {
            current = current->next;
        }
        T dato = tail->data;
        delete tail;
        tail = current;
        tail->next = nullptr;
        size--;
        return dato;
    }

    T& getElement(int pos) const {
        if (pos < 0 || pos >= size) {
            throw std::out_of_range("Posicion fuera de rango");
        }
        Nodo* aux = head;
        for (int i = 0; i < pos; ++i) {
            aux = aux->next;
        }
        return aux->data;
    }

    T* getElementAddr(int pos) {
        if (pos < 0 || pos >= size) {
            return nullptr;
        }
        Nodo* aux = head;
        for (int i = 0; i < pos; ++i) {
            aux = aux->next;
        }
        return &(aux->data);
    }

    /**
     * @brief Imprime de forma recursiva los datos de los nodos en la lista.
     *
     * Si es nullptr, la funcion termina la recursión.
     *
     * @param node Puntero al nodo actual que se está procesando.
     */
    void printListRecursive(Nodo* node) const {
        if (node == nullptr) {
            return;
        }
        std::cout << node->data << std::endl;
        printListRecursive(node->next);
    }

    /**
     * @brief Imprime todos los datos de los nodos en la lista.
     *
     * Llama internamente a una funcion recursiva para realizar la tarea.
     */
    void printList() const {
        printListRecursive(head);
    }
};

#endif // LISTAENLAZADA_H

