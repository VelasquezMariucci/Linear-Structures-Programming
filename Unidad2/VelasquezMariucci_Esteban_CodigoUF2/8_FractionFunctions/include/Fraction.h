//
// Created by esvel on 24/10/2024.
//

#ifndef FRACTION_H
#define FRACTION_H


class Fraction
{
public:
    Fraction(float nominator, float denominator);
    ~Fraction() = default;

    float getNominator();
    float getDenominator();

private:
    float nominator;
    float denominator;
};


#endif //FRACTION_H
