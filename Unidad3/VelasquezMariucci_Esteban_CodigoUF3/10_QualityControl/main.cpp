#include <iostream>
#include "../Estructuras/include/Vector.h"
#include <random>

/*Escribe un programa que utilice la clase plantilla
Vector para almacenar las medidas de ciertas dimensiones en productos
fabricados. Implementa funciones para calcular la media de las medidas, el
rango de variación y la proporción de productos que cumplen con ciertas
especificaciones.*/

int main()
{
    // Create vector
    Vector<float>* dimensions = new Vector<float>();

    // Init random
    std::random_device rd;
    std::mt19937 gen(rd());

    // Set distribution range
    std::uniform_real_distribution<float> dis(10.0f, 200.0f);

    // Calculate 20 random dimensions
    for (int i = 0; i < 20; i++)
    {
        dimensions->push_back(dis(gen));
    }

    // Calculate Median
    std::cout << "Median dimension: " << dimensions->median() << std::endl;

    // Calculate range of variation
    std::cout << "Range of variation: " << dimensions->max() - dimensions->min() << std::endl;

    // set specs
    float specMin = 50.0f;
    float specMax = 150.0f;

    // Calculate products meeting specs
    int count = 0;
    for (size_t i = 0; i < dimensions->size(); ++i)
    {
        float dimension = dimensions->get(i);
        if (dimension >= specMin && dimension <= specMax)
        {
            count++;
        }
    }

    // Calculate proportion
    float proportion = static_cast<float>(count) / dimensions->size();

    // Print
    std::cout << "Products within specifications: " << proportion * 100.0f << "%" << std::endl;

    return 0;
}
