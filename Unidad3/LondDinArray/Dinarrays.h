//
// Created by geosm on 14/11/2023.
//
#include <iostream>
#ifndef DINARRAY_DINARRAY_H
#define DINARRAY_DINARRAY_H

template <typename T>
class Dynarray_base
{
    // Error 1 = Dinarray (que hereda) no puede acceder a estos valores si son privados. Los puse protegidos.
protected:
    T* first; // Dirección de inicio del contenedor
    std::size_t count; // Número de elementos del contenedor
public:
    explicit Dynarray_base(std::size_t n)
    {
        if (n != 0)
        {
            Dynarray_base::first = alloc(n);
            Dynarray_base::count = n;
        }
        else
        {
            Dynarray_base::first = 0;
        }
    }

    static auto alloc(std::size_t n) -> T*
    {
        if (n > SIZE_MAX / sizeof(T))
            throw std::bad_array_new_length{};
        return static_cast<T*>(::operator new(n * sizeof(T)));
    }

    void dealloc() noexcept
    {
        ::operator delete(static_cast<void*>(first));
    }

    ~Dynarray_base() { dealloc(); }
};


template <typename T>
class Dynarray : protected Dynarray_base<T>
{
    using Base = Dynarray_base<T>;
    using Base::first;
    using Base::count;

public:
    // Definición de tipos
    using value_type = T;
    using const_reference = T const&;
    using reference = T&;
    using const_iterator = T const*;
    using iterator = T*;
    using cont_reverse_iterator = std::reverse_iterator<const_iterator>;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using size_type = std::size_t;

    // Constructor vacio
    Dynarray() : Base(0)
    {
        // No additional initialization needed, as Base(0) sets `first = nullptr` and `count = 0`
    }

    //Construcción:
    explicit Dynarray(size_type n) : Base{n}
    // Llama al constructor de la clase base para alojar memoria para n objetos de tipo T sin inicializar
    {
        auto current = first; // Puntero a la posición actual en el bloque de memoria
        try
        {
            for (; n > 0; ++current, --n)
            {
                // Coloca un objeto de tipo T en la posición actual utilizando el operador new
                ::new(static_cast<void*>(current)) value_type; // Inicialización por defecto
            }
        }
        catch (...)
        {
            // Se maneja cualquier tipo de excepción
            // Si se produce una excepción, se destruyen los objetos que se han creado hasta el momento
            for (auto p = first; p != current; ++p)
                p->~value_type();
            throw; // Se relanza la excepción para que sea manejada por el código que llama a este constructor
        }
    }

    Dynarray(size_type n, value_type const& val)
        : Base{n} // Llama al constructor de la clase base para alojar memoria para n objetos de tipo T sin inicializar
    {
        auto current = first; // Puntero a la posición actual en el bloque de memoria
        try
        {
            for (; n > 0; ++current, --n)
            {
                // Coloca un objeto de tipo T en la posición actual utilizando el operador new
                ::new(static_cast<void*>(current)) value_type(val); // Inicialización dada un valor
            }
        }
        catch (...)
        {
            // Se maneja cualquier tipo de excepción
            // Si se produce una excepción, se destruyen los objetos que se han creado hasta el momento
            for (auto p = first; p != current; ++p)
                p->~value_type();
            throw; // Se relanza la excepción para que sea manejada por el código que llama a este constructor
        }
    }

    Dynarray(std::initializer_list<value_type> const& init)
        : Base{init.size()}
    // Llama al constructor de la clase base para alojar memoria para el tamaño de la lista de inicializadores
    {
        auto current = first; // Puntero a la posición actual en el bloque de memoria
        try
        {
            for (auto const& value : init)
            {
                // Coloca un objeto de tipo T en la posición actual utilizando el operador new y el valor del inicializador
                ::new(static_cast<void*>(current++)) value_type(value);
            }
        }
        catch (...)
        {
            // Se maneja cualquier tipo de excepción
            // Si se produce una excepción, se destruyen los objetos que se han creado hasta el momento
            for (auto p = first; p != current; ++p)
            {
                p->~value_type();
            }
            throw; // Se relanza la excepción para que sea manejada por el código que llama a este constructor
        }
    }

    // Error 2: Destructor Arreglado
    ~Dynarray()
    {
        if (first != nullptr)
        {
            auto const last = first + count;
            for (auto p = first; p != last; ++p)
            {
                p->~value_type();
            }
        }
    }
};

#endif //DINARRAY_DINARRAY_H
