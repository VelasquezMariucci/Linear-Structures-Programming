//
// Created by esvel on 24/10/2024.
//

#include "FractionUtils.h"


std::string FractionUtils::sum(Fraction fraction1, Fraction fraction2)
{
    float value1 = (fraction1.getNominator() / fraction1.getDenominator());
    float value2 = (fraction2.getNominator() / fraction2.getDenominator());

    return FractionUtils::decToFraction(value1 + value2);
}

std::string FractionUtils::subtract(Fraction fraction1, Fraction fraction2)
{
    float value1 = (fraction1.getNominator() / fraction1.getDenominator());
    float value2 = (fraction2.getNominator() / fraction2.getDenominator());

    return FractionUtils::decToFraction(value1 - value2);
}

std::string FractionUtils::multiply(Fraction fraction1, Fraction fraction2)
{
    float value1 = (fraction1.getNominator() / fraction1.getDenominator());
    float value2 = (fraction2.getNominator() / fraction2.getDenominator());

    return FractionUtils::decToFraction(value1 * value2);
}

std::string FractionUtils::divide(Fraction fraction1, Fraction fraction2)
{
    float value1 = (fraction1.getNominator() / fraction1.getDenominator());
    float value2 = (fraction2.getNominator() / fraction2.getDenominator());

    return FractionUtils::decToFraction(value1 / value2);
}

std::string FractionUtils::decToFraction(float dec)
{
    // Integral part of the decimal (integer).
    int intDec = static_cast<int>(std::floor(dec));

    // Fractional part of the decimal.
    float fracDec = dec - intDec;

    // Precision value for calculating the fractional part.
    const int PRECISION_VALUE = 10000;

    // Convert fractional part to numerator by multiplying it with the precision.
    int numerator = static_cast<int>(std::round(fracDec * PRECISION_VALUE));

    // Set the denominator to the precision value.
    int denominator = PRECISION_VALUE;

    // Compute the greatest common divisor  to simplify the fraction.
    int gcdValue = std::gcd(numerator, denominator);

    // Simplify the numerator and denominator by dividing by the GCD.
    numerator /= gcdValue;
    denominator /= gcdValue;

    // Create a string to hold the result.
    std::string result;

    // Handle the case where there is an integer part.
    if (intDec != 0)
    {
        result = std::to_string(intDec);

        // If the fractional part exists, add space before the fraction.
        if (numerator != 0)
        {
            result += " " + std::to_string(numerator) + "/" + std::to_string(denominator);
        }
    }
    else
    {
        // If there's no integer part, just return the fraction.
        result = std::to_string(numerator) + "/" + std::to_string(denominator);
    }

    return result;
}
