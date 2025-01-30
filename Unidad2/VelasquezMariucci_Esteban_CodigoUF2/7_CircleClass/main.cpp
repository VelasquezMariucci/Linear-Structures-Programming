#include <iostream>
#include "Circle.h"

/*
 * Crea una clase "Círculo" con un atributo de radio. Incluye métodos para
 * calcular el área y la circunferencia del círculo. Luego, crea un objeto de la
 * clase "Círculo" y muestra el área y la circunferencia.
 */

int main()
{
    // Pointer to a Circle object.
    Circle* circle = new Circle(10);

    circle->mostrar();

    return 0;
}
