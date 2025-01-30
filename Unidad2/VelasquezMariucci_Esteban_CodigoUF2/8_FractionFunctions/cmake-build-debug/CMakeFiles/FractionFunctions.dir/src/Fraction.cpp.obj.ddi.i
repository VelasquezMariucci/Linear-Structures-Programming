# 0 "C:/Users/esvel/OneDrive/Desktop/Code/C++/Unidad2/VelasquezMariucci_Esteban_CodigoUF2/8_FractionFunctions/src/Fraction.cpp"
# 1 "C:\\Users\\esvel\\OneDrive\\Desktop\\Code\\C++\\Unidad2\\VelasquezMariucci_Esteban_CodigoUF2\\8_FractionFunctions\\cmake-build-debug//"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "C:/Users/esvel/OneDrive/Desktop/Code/C++/Unidad2/VelasquezMariucci_Esteban_CodigoUF2/8_FractionFunctions/src/Fraction.cpp"




# 1 "C:/Users/esvel/OneDrive/Desktop/Code/C++/Unidad2/VelasquezMariucci_Esteban_CodigoUF2/8_FractionFunctions/include/Fraction.h" 1
# 9 "C:/Users/esvel/OneDrive/Desktop/Code/C++/Unidad2/VelasquezMariucci_Esteban_CodigoUF2/8_FractionFunctions/include/Fraction.h"
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
# 6 "C:/Users/esvel/OneDrive/Desktop/Code/C++/Unidad2/VelasquezMariucci_Esteban_CodigoUF2/8_FractionFunctions/src/Fraction.cpp" 2

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
