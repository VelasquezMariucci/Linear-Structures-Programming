
#ifndef DINARRAYPEL_H
#define DINARRAYPEL_H

#include <ostream>

/** @brief Una clase plantilla de array dinámico para almacenar elementos de cualquier tipo.
 *
 * La clase DinarrayPEL es una implementación de array dinámico basada en plantillas,
 * que permite un almacenamiento y manipulación flexibles de elementos. Soporta operaciones
 * como agregar elementos, extraer elementos, recuperar elementos y mostrar el contenido del
 * array en un flujo de salida.
 *
 * @tparam T El tipo de elementos almacenados en el array dinámico.
 */
template <typename T>
class DinarrayPEL
{
private:
    T* array; // puntero al array dinámico
    size_t size; // tamaño actual del array
    size_t maxSize; // capacidad máxima del array

public:
    /** @brief Constructor por defecto.
     *
     * inicializa un array dinámico vacío con maxSize y size establecidos en cero,
     * y asigna memoria para un array con cero elementos.
     */
    DinarrayPEL()
    {
        maxSize = 0;
        size = maxSize;
        array = new T[size];
    }

    /** @brief Constructor con tamaño inicial.
     *
     * inicializa un array dinámico con una capacidad máxima especificada, 
     * estableciendo el tamaño actual en cero. Asigna memoria para maxSize elementos.
     *
     * @param size Capacidad máxima inicial del array dinámico.
     */
    DinarrayPEL(const size_t size)
    {
        maxSize = size;
        this->size = 0;
        array = new T[this->maxSize];
    }

    /** @brief Agrega un valor al array dinámico.
     *
     * esta función inserta el valor dado en la siguiente posición disponible en el array. 
     * Si el tamaño del array alcanza su capacidad máxima, llama a alloc para expandir la capacidad del array.
     *
     * @param val El valor que se agregará al array dinámico.
     */
    void add(T val)
    {
        if (this->size >= this->maxSize)
        {
            this->alloc();
        }

        this->array[size] = val;
        size++;
    }

    /** @brief Extrae y elimina un elemento en una posición especificada.
     *
     * esta función elimina el elemento en el índice especificado, mueve todos los 
     * elementos subsecuentes una posición a la izquierda para llenar el espacio y 
     * decrementa el tamaño. Devuelve el elemento eliminado.
     *
     * @param pos La posición del elemento a eliminar.
     * @return El elemento extraído de la posición especificada.
     */
    T extract(size_t pos)
    {
        T aux;
        if (size > 0 && pos < size)
        {
            aux = this->array[pos];
            for (size_t i = pos; i < size - 1; i++)
            {
                this->array[i] = this->array[i + 1];
            }
            size--;
        }
        return aux;
    }

    /** @brief Recupera un elemento en una posición especificada.
     *
     * esta función devuelve el elemento en la posición especificada sin modificar el array.
     *
     * @param pos La posición del elemento a recuperar.
     * @return El elemento en la posición especificada.
     */
    T get(size_t pos)
    {
        T aux;
        if (size > 0 && pos < size)
        {
            aux = this->array[pos];
        }
        return aux;
    }

    /** @brief Recupera el índice de la primera aparición de un elemento especificado.
     *
     * esta función recorre el array para encontrar el índice de la primera aparición 
     * del elemento proporcionado. Si el elemento se encuentra, devuelve su índice; 
     * en caso contrario, devuelve -1.
     *
     * @param data El elemento a buscar en el array dinámico.
     * @return El índice del elemento o -1 si no se encuentra.
     */
    int getIndex(T data)
    {
        int tempData = -1;

        for (int i = 0; i < size; ++i)
        {
            if (array[i] == data)
            {
                tempData = i;
                i = size;
            }
        }

        return tempData;
    }

    /** @brief Proporciona un iterador apuntando al inicio del array.
     *
     * @return Un puntero al primer elemento del array dinámico.
     */
    T* begin()
    {
        return array;
    }

    /** @brief Proporciona un iterador apuntando al final del array.
     *
     * @return Un puntero al elemento después del último en el array dinámico.
     */
    T* end()
    {
        return array + size;
    }

    friend std::ostream& operator<<(std::ostream& os, const DinarrayPEL<T>& dyn)
    {
        os << "[";
        for (size_t i = 0; i < dyn.size; ++i)
        {
            os << dyn.array[i];
            if (i < dyn.size - 1)
            {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }

protected:
    /** @brief Expande la capacidad del array dinámico.
     *
     * esta función duplica la capacidad máxima del array dinámico, asigna
     * un nuevo array con el tamaño expandido y copia los elementos existentes. 
     * Luego elimina el array antiguo y asigna el nuevo array a la clase.
     */
    void alloc()
    {
        if (this->maxSize == 0)
        {
            this->maxSize = 1;
        }

        size_t newMaxSize = this->maxSize * 2;
        T* newArray = new T[newMaxSize];

        for (size_t i = 0; i < this->size; i++)
        {
            newArray[i] = this->array[i];
        }

        delete[] this->array;
        this->array = newArray;
        this->maxSize = newMaxSize;
    }
};

#endif //DINARRAYPEL_H
