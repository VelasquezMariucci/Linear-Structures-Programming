//
// Created by esvel on 22/10/2024.
//

#include "Rectangle.h"

Rectangle::Rectangle(float longitud, float ancho): longitud(longitud), ancho(ancho)
{
    perimetro = this->calcularPerimetro(this->longitud, this->ancho);
    area = this->calcularArea(this->longitud, this->ancho);
}

float Rectangle::calcularPerimetro(float longitud, float ancho)
{
    return ((longitud * 2) + (ancho * 2));
}


float Rectangle::calcularArea(float longitud, float ancho)
{
    return (longitud * ancho);
}

void Rectangle::mostrar()
{
    std::cout << "Perimetro: " << perimetro << ", Area: " << area << std::endl;
}
