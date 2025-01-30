#include <iostream>

#include "QueueClass.h"

/*Crear una clase “Cola” que implemente una cola de elementos de cualquier
tipo empleando para ello un array. La clase debe agregar y quitar elementos
de la cola. Extra: Con los conocimientos que posees, intenta hacer que su
tamaño sea dinámico.*/

int main()
{
    QueueClass<std::string> q;

    //agregamos elementos a la cola
    q.add("Hi");
    q.add("Howdy");
    q.add("Hello");
    q.add("Greatings");


    std::cout << "First Element in Queue: " << q.getFirst() << std::endl;

    q.remove();

    std::cout << "New First Element in Queue: " << q.getFirst() << std::endl;

    return 0;
}
