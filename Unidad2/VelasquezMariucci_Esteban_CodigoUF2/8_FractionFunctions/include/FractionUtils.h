//
// Created by esvel on 24/10/2024.
//

#ifndef FRACTIONUTILS_H
#define FRACTIONUTILS_H
#include <string>

#include "Fraction.h"
#include <iostream>
#include <sstream>
#include <cmath>
#include <numeric>

/* @brief Utility class for basic calculates of fraction.
 *
 * Class that returns string representing fractions in the format = "#/#" using
 * fuctions to find the sum, subtraction, multiplication and division.
 */
class FractionUtils
{
public:
    /* @brief sum two fraction objects.
    *
    * This function turns both fraction objects into float values dividing their
    * nominators and denominator. It's sum gets sent into the decToFraction where
    * it gets turned back into a fraction as a string.
    *
    * @param fraction1 Fraction object #1.
    * @param fraction2 Fraction object #2.
    * @return
    */
    static std::string sum(Fraction fraction1, Fraction fraction2);

    /* @brief subtract two fraction objects.
    *
    * This function turns both fraction objects into float values dividing their
    * nominators and denominator. It's subtraction gets sent into the
    * decToFraction where it gets turned back into a fraction as a string.
    *
    * @param fraction1 Fraction object #1.
    * @param fraction2 Fraction object #2.
    * @return
    */
    static std::string subtract(Fraction fraction1, Fraction fraction2);

    /* @brief multiply two fraction objects.
    *
    * This function turns both fraction objects into float values dividing their
    * nominators and denominator. It's multiplication gets sent into the
    * decToFraction where it gets turned back into a fraction as a string.
    *
    * @param fraction1 Fraction object #1.
    * @param fraction2 Fraction object #2.
    * @return
    */
    static std::string multiply(Fraction fraction1, Fraction fraction2);

    /* @brief divide two fraction objects.
    *
    * This function turns both fraction objects into float values dividing their
    * nominators and denominator. It's division gets sent into the
    * decToFraction where it gets turned back into a fraction as a string.
    *
    * @param fraction1 Fraction object #1.
    * @param fraction2 Fraction object #2.
    * @return
    */
    static std::string divide(Fraction fraction1, Fraction fraction2);

private:
    /*
     * @Brief
     *
     * This function takes a float and turns it to a fraction string with the
     * structure "#/#". It separates the decimal value to integer and
     * fractional values. It then uses a precision value of 10000 to find the
     * greatest common divisor to simplify the fraction. They all get
     * formatted and returned as a string.
     *
     * @param dec float to represent a float value.
     * @return
     */
    static std::string decToFraction(float dec);
};


#endif //FRACTIONUTILS_H
