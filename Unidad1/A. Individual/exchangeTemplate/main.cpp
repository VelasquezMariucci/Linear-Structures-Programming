#include <iostream>
#include "exchangeTemplate.h"

//Crea una plantilla intercambio que intercambia dos valores del mismo tipo.

int main()
{
    int a = 5;
    int b = 10;

    std::cout << "Antes del intercambio: a = " << a << ", b = " << b << std::endl;
    exchange(a, b);
    std::cout << "Despues del intercambio: a = " << a << ", b = " << b << std::endl;

    return 0;
}
