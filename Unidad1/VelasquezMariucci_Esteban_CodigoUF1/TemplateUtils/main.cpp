#include <iostream>
#include "TemplateUtils.h"

/*
 *Crear una clase de lista genérica utilizando plantillas. La clase debe ser
 *capaz de manejar listas de diferentes tipos de datos, como enteros,
 *flotantes y caracteres. La clase debe tener métodos para agregar
 *elementos a la lista, eliminar elementos de la lista, buscar elementos en la
 *lista y ordenar la lista.
 */

int main()
{
    myGenericList<std::string>* genericList = new myGenericList<std::string>;

    // Adding elements to the string list
    genericList->addElement("hello");
    genericList->addElement("world");
    genericList->addElement("hi");

    genericList->printList();

    // Search for an element
    if (genericList->searchElement("hello"))
        std::cout << "Element 'hello' found in the list." << std::endl;
    else
        std::cout << "Element 'hello' not found in the list." << std::endl;

    // Remove an element
    genericList->removeElement("hello");

    // Order the string list and display it
    genericList->orderList();
    std::cout << "Ordered string list: ";
    genericList->printList();

    return 0;
}
