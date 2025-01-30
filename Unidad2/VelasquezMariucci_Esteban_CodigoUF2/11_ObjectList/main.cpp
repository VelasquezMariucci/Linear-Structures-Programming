

#include <iostream>

#include "ObjectList.h"

/*Crear una clase “ListaDeObjetos” que contenga un array de objetos de
cualquier clase. La clase debe tener un método para agregar un nuevo
elemento al array y un método para extraerlo.*/

int main()
{
    ObjectList<std::string> myList(10);

    myList.add("Hello");
    myList.add("Hi");
    myList.add("Greatings");
    myList.add("Howdy");

    std::cout << "List Content: " << myList << std::endl;

    std::cout << "Get Last Object: " << myList.get() << std::endl;

    return 0;
}
