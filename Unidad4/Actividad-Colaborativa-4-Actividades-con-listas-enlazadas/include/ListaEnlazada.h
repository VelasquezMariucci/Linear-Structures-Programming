//
// Created by Ricky Vicente on 09/12/2024.
//

#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H

#include <iostream>

template <typename T>
class ListaEnlazada
{
protected:
    class Nodo
    {
    public:
        T data;
        Nodo* next;

        Nodo(T data) : data(data), next(nullptr)
        {
        }

        Nodo(T data, Nodo* next) : data(data), next(next)
        {
        }
    };

private:
    Nodo* head;
    Nodo* tail;
    int size;

public:
    ListaEnlazada() : head(nullptr), tail(nullptr), size(0)
    {
    }

    ~ListaEnlazada() { printf("ListaEnlazada\n"); }

    bool isEmpty()
    {
        return head == nullptr;
    }

    bool anotherEmpty()
    {
        return size == 0;
    }

    int getSize()
    {
        return size;
    }

    void insert_Head(T data)
    {
        Nodo* novo = new Nodo(data, head);
        if (isEmpty())
        {
            tail = novo;
        }
        head = novo;
        size++;
    }

    void insert_Tail(T data) {
        Nodo* novo = new Nodo(data, nullptr);
        if (isEmpty()) {
            head = novo;
            tail = novo;
        } else {
            tail->next = novo;
            tail = novo;
        }
        size++;
    }

    void insert(T data, int pos)
    {
        Nodo* novo = new Nodo(data, nullptr);
        if (pos <= size && pos >= 0)
        {
            if (pos == 0)
            {
                insert_Head(data);
            }
            else if (pos == size - 1)
            {
                insert_Tail(data);
            }
            else
            {
                Nodo* aux = head;
                for (int i = 0; i < pos; i++)
                {
                    aux = aux->next;
                }
                novo->next = aux->next;
                aux->next = novo;
                size++;
            }
        }
    }

    T remove_Head()
    {
        T dato;
        if (isEmpty())
        {
            printf("No hay nodos\n");
        }
        else
        {
            dato = head->data;
            Nodo* aux = head;
            head = head->next;
            delete aux;
            size--;
        }
        return dato;
    }

    T remove_Tail()
    {
        if (isEmpty())
        {
            printf("La lista está vacía.");
        }
        Nodo* aux = head;
        T data;
        if (head == tail)
        {
            // Solo hay un elemento
            data = head->data;
            delete head;
            head = tail = nullptr;
        }
        else
        {
            while (aux->next != tail)
            {
                aux = aux->next;
            }
            data = tail->data;
            delete tail;
            tail = aux;
            tail->next = nullptr;
        }
        size--;
        return data;
    }

    T remove(int pos)
    {
        T dato;
        if (isEmpty())
        {
            printf("No hay nodos\n");
        }
        else
        {
            if (pos >= size || pos < 0)
            {
                printf("Fuera de rango\n");
            }
            else
            {
                if (pos == 0)
                {
                    remove_Head();
                }
                else if (pos == size - 1)
                {
                    remove_Tail();
                }
                else
                {
                    Nodo* aux = head;
                    for (int i = 0; i < pos - 1; i++)
                    {
                        aux = aux->next;
                    }
                    Nodo* aux2 = aux->next;
                    dato = aux2->data;
                    aux->next = aux2->next;
                    delete aux2;
                    size--;
                }
            }
        }
        return dato;
    }

    void getAllElements()
    {
        Nodo* aux = head;
        while (aux != nullptr)
        {
            std::cout << aux->data << " ";
            aux = aux->next;
        }
        std::cout << "\n";
    }

    T getElement(int pos)
    {
        T dato;
        if (isEmpty())
        {
            printf("No hay nodos\n");
        }
        else
        {
            if (pos >= size || pos < 0)
            {
                printf("Fuera de rango\n");
            }
            else
            {
                Nodo* aux = head;
                for (int i = 0; i < pos; i++)
                {
                    aux = aux->next;
                }
                dato = aux->data;
            }
        }
        return dato;
    }
    T& getElemento(int pos)
    {
        if (isEmpty())
        {
            throw std::out_of_range("No hay nodos");
        }
        if (pos >= size || pos < 0)
        {
            throw std::out_of_range("Fuera de rango");
        }
        Nodo* aux = head;
        for (int i = 0; i < pos; i++)
        {
            aux = aux->next;
        }
        return aux->data;
    }
};

#endif //LISTAENLAZADA_H
