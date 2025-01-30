#ifndef VECTORPEL_H
#define VECTORPEL_H

#include <cstddef> // para size_t

/**
 * @brief Clase plantilla para manejar un vector dinámico.
 *
 * Esta clase proporciona una implementación simple de un vector dinámico
 * que puede crecer según sea necesario para almacenar elementos de cualquier tipo.
 *
 * @tparam T Tipo de elementos almacenados en el vector.
 */
template <typename T>
class VectorPEL {
private:
    T* v;       // puntero al inicio del array
    T* space;   // puntero al siguiente elemento libre
    T* last;    // puntero al final de la memoria asignada
public:
    /**
     * @brief Constructor por defecto.
     *
     * inicializa un vector vacío asignando memoria para cero elementos.
     */
    VectorPEL() {
        this->v = new T[0];
        this->space = this->v;
        this->last = this->v;
    }

    /**
     * @brief Destructor.
     *
     * libera la memoria asignada para el vector al destruir el objeto.
     */
    ~VectorPEL() {
        delete[] v; // libera la memoria al destruir el objeto
    }

    /**
     * @brief Obtiene el tamaño actual del vector.
     *
     * Calcula el número de elementos almacenados actualmente en el vector.
     *
     * @return Número de elementos en el vector.
     */
    int getSize() const {
        return (this->space - this->v);
    }

    /**
     * @brief Agrega un elemento al final del vector.
     *
     * Si no hay espacio suficiente, expande la capacidad del vector
     * duplicando su tamaño actual antes de agregar el elemento.
     *
     * @param e Elemento a agregar.
     */
    void push_back(T e) {
        // verifica si el vector está lleno
        if (this->space == this->last) {
            size_t old_size = this->space - this->v; // tamaño actual
            size_t new_size = (old_size == 0) ? 2 : old_size * 2; // nuevo tamaño
            T* new_v = new T[new_size];

            // copia los elementos antiguos
            for (size_t i = 0; i < old_size; i++) {
                new_v[i] = this->v[i];
            }

            delete[] this->v;  // libera la memoria antigua
            this->v = new_v;
            this->space = this->v + old_size;
            this->last = this->v + new_size;
        }

        *this->space = e; // agrega el nuevo elemento
        this->space++;
    }

    /**
     * @brief Elimina y devuelve el último elemento del vector.
     *
     * Si el vector no está vacío, reduce el tamaño actual en uno y devuelve el elemento eliminado.
     *
     * @return Último elemento del vector.
     */
    T pop_back() {
        T aux;
        if (this->v != this->space) { // verifica que el vector no esté vacío
            this->space--; // decrementa el puntero del espacio
            aux = *this->space; // guarda el último elemento
        }
        return aux;
    }

    /**
     * @brief Recupera un elemento en una posición específica.
     *
     * Si la posición es válida, devuelve el elemento en esa posición.
     *
     * @param pos Índice del elemento a recuperar.
     * @return Elemento en la posición especificada.
     */
    T get(size_t pos) const {
        T obj;
        if (pos < getSize() && pos >= 0) { // verifica que la posición sea válida
            obj = this->v[pos];
        }
        return obj;
    }

    /**
     * @brief Iterador al inicio del vector.
     *
     * Permite iterar sobre los elementos del vector.
     *
     * @return Puntero al primer elemento del vector.
     */
    T* begin() {
        return this->v;
    }

    /**
     * @brief Iterador al final del vector.
     *
     * Devuelve un puntero que apunta más allá del último elemento del vector.
     *
     * @return Puntero al espacio después del último elemento del vector.
     */
    T* end() {
        return this->space;
    }

    /**
     * @brief Iterador constante al inicio del vector.
     *
     * Versión constante de `begin` para iterar sin modificar el vector.
     *
     * @return Puntero constante al primer elemento del vector.
     */
    const T* begin() const {
        return this->v;
    }

    /**
     * @brief Iterador constante al final del vector.
     *
     * Versión constante de `end` para iterar sin modificar el vector.
     *
     * @return Puntero constante al espacio después del último elemento del vector.
     */
    const T* end() const {
        return this->space;
    }
};

#endif // VECTORPEL_H
