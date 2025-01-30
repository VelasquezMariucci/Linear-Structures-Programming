#include <iostream>

#include "Rectangle.h"

/*
 * Crea una clase "Rectángulo" con atributos de longitud y ancho. Incluye
 * métodos para calcular el área y el perímetro del rectángulo. Luego, crea
 * un objeto de la clase "Rectángulo" y muestra el área y el perímetro.
 */

int main()
{
    // pointer to a Rectangle object.
    Rectangle* rectangle = new Rectangle(25, 75);

    rectangle->mostrar();

    return 0;
}
