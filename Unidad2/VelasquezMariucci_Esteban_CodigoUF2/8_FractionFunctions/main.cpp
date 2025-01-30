#include <iostream>

#include "Fraction.h"
#include "FractionUtils.h"

/*
 * Crea una clase "Fracción" con atributos de numerador y denominador.
 * Incluye métodos para sumar, restar, multiplicar y dividir fracciones. Luego,
 * crea dos objetos de la clase "Fracción" y muestra los resultados de las
 * operaciones.
 */

int main()
{
    // My fractions
    Fraction* frac1 = new Fraction(1.0f, 3.0f);
    Fraction* frac2 = new Fraction(3.0f, 7.0f);

    // print my fractions
    std::cout << "Fraction 1: " << frac1->getNominator() << "/" << frac1->getDenominator() << std::endl;
    std::cout << "Fraction 2: " << frac2->getNominator() << "/" << frac2->getDenominator() << std::endl;

    // Fraction operations
    std::cout << "Sum: " << FractionUtils::sum(*frac1, *frac2) << std::endl;
    std::cout << "Subtraction: " << FractionUtils::subtract(*frac1, *frac2) << std::endl;
    std::cout << "Multiplication: " << FractionUtils::multiply(*frac1, *frac2) << std::endl;
    std::cout << "Multiplication: " << FractionUtils::divide(*frac1, *frac2) << std::endl;

    return 0;
}
