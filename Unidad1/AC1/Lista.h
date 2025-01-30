//
// Created by esvel on 27/09/2024.
//

#ifndef LISTA_H
#define LISTA_H
#include <stdexcept>
#include <ostream>


template <typename T>
class Lista
{
private:
    // Se le establece un tamaño máximo de la lista
    int tamaño;
    // Un contador para mantener el control del orden de la lista
    int contador;
    // Y el tipo de dato genérico
    T* datos;

public:
    Lista(int tamaño) : tamaño(tamaño), contador(0)
    {
        datos = new T[tamaño]; // Reservar memoria
    }

    ~Lista()
    {
        delete[] datos; // Liberar memoria
    }

    //metodo para añadir valores a la lista
    void añadirValor(T& valor)
    {
        if (contador < tamaño)
        {
            // Cambié <= a <
            datos[contador] = valor;
            contador++;
        }
    }

    //getters
    //@Override
    T& operator[](int indice)
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


    int getTamaño() const
    {
        return contador;
    }

    //metodo para obtener el tamaño de la lista
    friend std::ostream& operator<<(std::ostream& os, Lista<T>& lista)
    {
        for (int i = 0; i < sizeof(lista.datos); i++)
        {
            os << lista.datos[i] << "\n";
        }

        return os;
    }
};


#endif //LISTA_H
