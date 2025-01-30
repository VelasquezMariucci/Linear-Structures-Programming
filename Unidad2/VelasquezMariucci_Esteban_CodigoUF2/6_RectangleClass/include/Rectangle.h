//
// Created by esvel on 22/10/2024.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>

/*
 * @Brief Class to represent a Rectangle object
 *
 * This class provides functionality of calculating the area and perimeter of a
 * rectangle through the length and width. These values are stored in private
 * fields.
 */
class Rectangle
{
private:
    float longitud;
    float ancho;
    float perimetro;
    float area;

    /*
     * @Brief function to calculate the perimeter.
     *
     * This function calculates the perimeter through the length and with
     * parameters with the formula (length * 2) + (area * 2).
     *
     * @param longitud float to represent the length.
     * @param ancho float to represent the width.
     */
    float calcularPerimetro(float longitud, float ancho);

    /*
     * @Brief function to calculate the area.
     *
     * This function calculates the area through the length and with
     * parameters with the formula (length * width).
     *
     * @param longitud float to represent the length.
     * @param ancho float to represent the width.
     */
    float calcularArea(float longitud, float ancho);

public:
    /*
     * @Brief Rectangle object constructor.
     *
     * Builds the rectangle object with length and width, and calls functions
     * to calculate the area and perimiter
     *
     * @param longitud float to represent the length.
     * @param ancho float to represent the width.
     */
    Rectangle(float longitud, float ancho);

    /*
     * @Brief function to show perimeter and area through the console.
     *
     * Prints perimiter and area in an organized way.
     */
    void mostrar();
};


#endif //RECTANGLE_H
