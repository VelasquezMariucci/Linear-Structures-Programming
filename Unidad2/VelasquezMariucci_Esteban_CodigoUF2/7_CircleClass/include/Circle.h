//
// Created by esvel on 22/10/2024.
//

#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>

/*
 * @Brief Class to represent a Circle object
 *
 * This class provides functionality for calculating the area and circumference
 * of a circle using its radius. These values are stored in private fields.
 */
class Circle
{
private:
    float radio;
    float circunferencia;
    float area;

    /*
     * @Brief function to calculate the circumference.
     *
     * This function calculates the circumference using the formula 2 * PI * radius.
     *
     * @param radio float representing the radius.
     */
    float calcularCircunferencia(float radio);

    /*
     * @Brief function to calculate the area.
     *
     * This function calculates the area using the formula PI * radius^2.
     *
     * @param radio float representing the radius.
     */
    float calcularArea(float radio);

public:
    /*
     * @Brief Circle object constructor.
     *
     * Constructs the circle object with the given radius and calls functions
     * to calculate the area and circumference.
     *
     * @param radio float representing the radius.
     */
    Circle(float radio);

    /*
     * @Brief function to display the circumference and area on the console.
     *
     * Prints the circumference and area in an organized way.
     */
    void mostrar();
};

#endif //CIRCLE_H
