#include <iostream>
#include "minMaxiTemplate.h"

/*
 *Crea una plantilla minmaxi, que declara dos plantillas de funciones, una para una función maxi,
 *que devuelve el valor más alto de los 2 parámetros entregados, y otra, una función min, que
 *devuelve el valor más bajo.
 */

int main()
{
    // int value to compare
    int a = 1;
    int b = 3;

    std::cout << maxi(a, b) << " is bigger " << std::endl;
    std::cout << mini(a, b) << " is smaller " << std::endl;

    // string value to compare
    std::string c = "hi";
    std::string d = "hello";

    std::cout << maxi(c, d) << " is bigger " << std::endl;
    std::cout << mini(c, d) << " is smaller " << std::endl;

    return 0;
}
