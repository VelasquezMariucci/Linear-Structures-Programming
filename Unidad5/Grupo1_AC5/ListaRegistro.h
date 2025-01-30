//
// Created by Ricky Vicente on 21/12/2024.
//

#ifndef LISTAREGISTRO_H
#define LISTAREGISTRO_H
#include "ListaEnlazada.h"

class ListaRegistro : public ListaEnlazada<Registro> {
public:
// Metodo para insertar un registro en la lista de forma ordenada por hora
    void ingresaRegistro(Nodo* cabeza, Registro* registro, int& index) {
        // Si la lista está vacía o se alcanzó el final, se inserta el registro en el índice actual
        if (cabeza == nullptr) {
            insert(*registro, index);
        } else {
            // Convertimos la hora del registro a ingresar a minutos totales para comparación
            std::string hora1 = registro->getHora();
            int tiempo1 = (std::stoi(hora1.substr(0, 2)) * 60) + std::stoi(hora1.substr(3, 2));

            // Convertimos la hora del registro del nodo actual de la lista
            std::string hora2 = cabeza->data.getHora();
            int tiempo2 = (std::stoi(hora2.substr(0, 2)) * 60) + std::stoi(hora2.substr(3, 2));
            // Si la hora del nuevo registro es menor que la del nodo actual, se inserta en el índice actual
            if (tiempo1 < tiempo2) {
                insert(*registro, index);
            } else {
                // Si no, avanzamos al siguiente nodo y actualizar el índice
                index++;
                // Si se llega al final de la lista, insertamos el registro al final
                if (cabeza->next == nullptr) {
                    insert(*registro, index);
                } else {
                    // Llamada recursiva para procesar el siguiente nodo
                    ingresaRegistro(cabeza->next, registro, index);
                }
            }
        }
    }
    // Metodo para buscar un registro en la lista por nombre y hora
    bool buscarRegistro(Nodo* cabeza, std::string nombre, std::string hora) {
        // Si se alcanza el final de la lista, devolvemos false
        if (cabeza == nullptr) {
            return false;
        }
        // Comparamos los valores del nodo actual con los buscados
        if (cabeza->data.getNombreUsuario() == nombre && cabeza->data.getHora() == hora) {
            return true;
        }
        // Llamada recursiva para buscar en el siguiente nodo
        return buscarRegistro(cabeza->next, nombre, hora);
    }
};

#endif //LISTAREGISTRO_H
