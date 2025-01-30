//
// Created by esvel on 27/09/2024.
//

#include "Lista.h"
#include <stdexcept>
#include <stdexcept>
#include <ostream>

    //crea plantilla de la lista
template <typename T>
Lista<T>::Lista(int tamaño) : tamaño(tamaño), contador(0) //constructor
{
    // La lista "datos" será una nueva lista de elementos T de un tamaño "tamaño"
    datos = new T[tamaño];
}

template <typename T>
Lista<T>::~Lista() //destructor
{
    delete[] datos; // Liberar memoria
}

template <typename T>
void Lista<T>::añadirValor(T valor)
{
    // Si el contador está por debajo del tamaño máximo
    if (contador < tamaño)
    {
        // Se le añadirá el valor en esa posición
        datos[contador] = valor;
        contador++;
    }
}

template <typename T>
//@Override
// Busca el valor en la posición que se le ingresa
T& Lista<T>::operator[](int indice)
{
    if (indice >= 0 && indice < contador)
    {
        return datos[indice];
    }
    else
    {
        throw std::out_of_range("Índice fuera de rango");
    }
}

template <typename T>
int Lista<T>::obtenerTamaño() const
{
    return contador;
}

//@Override
// Devuelve todos los datos de la lista usando el operando
friend std::ostream& operator<<(std::ostream& os, Lista<T>& lista)
{
    for (int i = 0; i < sizeof(lista.datos); i++)
    {
        os << lista.datos[i] << "\n";
    }

    return os;
}

