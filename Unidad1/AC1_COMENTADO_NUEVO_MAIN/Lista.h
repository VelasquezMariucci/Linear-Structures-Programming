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
    Lista(int tamaño);
    ~Lista();

    //metodo para añadir valores a la lista
    void añadirValor(T valor);

    T& operator[](int indice);

    //metodo para obtener el tamaño de la lista
    int obtenerTamaño() const;
};


#endif //LISTA_H
