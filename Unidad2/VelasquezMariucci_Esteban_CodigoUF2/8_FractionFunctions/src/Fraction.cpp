//
// Created by esvel on 24/10/2024.
//

#include "Fraction.h"

Fraction::Fraction(float nominator, float denominator): nominator(nominator), denominator(denominator)
{
}

float Fraction::getDenominator()
{
    return denominator;
}

float Fraction::getNominator()
{
    return nominator;
}
