#include <iostream>

#include "PointerList.h"

/*Crea ahora una clase llamada “ListaDePunteros” que contenga un array de
punteros a objetos de cualquier clase. La clase debe tener un método para
agregar un nuevo elemento al array y un método para extraerlo.*/

int main()
{
    PointerList<std::string> myList(10);

    std::string s1 = "Hello";
    std::string s2 = "Hi";
    std::string s3 = "Greatings";
    std::string s4 = "Howdy";

    myList.add(&s1);
    myList.add(&s2);
    myList.add(&s3);
    myList.add(&s4);

    std::cout << "List Content: " << myList << std::endl;

    std::cout << "Get Last Object: " << myList.get() << std::endl;

    return 0;
}
