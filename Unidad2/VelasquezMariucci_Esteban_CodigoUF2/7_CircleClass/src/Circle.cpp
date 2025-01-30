//
// Created by esvel on 22/10/2024.
//

#include "Circle.h"
#include <cmath> // for M_PI

Circle::Circle(float radio): radio(radio)
{
    circunferencia = this->calcularCircunferencia(this->radio);
    area = this->calcularArea(this->radio);
}

float Circle::calcularCircunferencia(float radio)
{
    return (2 * M_PI * radio);
}

float Circle::calcularArea(float radio)
{
    return (M_PI * radio * radio);
}

void Circle::mostrar()
{
    std::cout << "Circunferencia: " << circunferencia << ", Area: " << area << std::endl;
}
