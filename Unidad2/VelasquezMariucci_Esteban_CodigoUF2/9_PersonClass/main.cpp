#include <iostream>

#include "Person.h"

/*Crea una clase "Persona" con atributos de nombre y edad. Incluye métodos
para obtener y establecer los valores de los atributos. Luego, crea un objeto
de la clase "Persona" y muestra su nombre y edad.*/

int main()
{
    // Variables to feed pointers.
    std::string name = "Carlos";
    int age = 24;

    // Pointers to feed person.
    std::string* pName = &name;
    int* pAge = &age;

    Person* person = new Person(pName, pAge);

    std::cout << "First) Name: " << person->getName() << ", Age:" << person->getAge() << std::endl;

    name = "Maria";
    age = 42;

    person->setName(pName);
    person->setAge(pAge);

    std::cout << "Second) Name: " << person->getName() << ", Age:" << person->getAge() << std::endl;

    return 0;
}
