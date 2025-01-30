#include <iostream>
#include "../Estructuras/include/Vector.h"
#include <random>

/*Crea un programa que utilice la clase plantilla
Vector para almacenar las temperaturas diarias de una ciudad durante un año.
Implementa funciones para calcular la temperatura máxima y mínima registrada, así
como el número de días con temperaturas superiores a cierto umbral.*/

int main()
{
    // Create vector for yearly temperatures
    Vector<float>* yearlyTemp = new Vector<float>();

    // Init random
    std::random_device rd;
    std::mt19937 gen(rd());

    // Set distribution range
    std::uniform_real_distribution<float> dis(-4.0f, 30.0f);

    // Generate a random temp for each day of the year
    for (int i = 0; i < 365; i++)
    {
        yearlyTemp->push_back(dis(gen));
    }

    // Get max and Min temp
    std::cout << "Max temp: " << yearlyTemp->max() << std::endl;
    std::cout << "Min temp: " << yearlyTemp->min() << std::endl;

    // Set day count and threshold
    int days = 0;
    float threshold = 20.0f;

    // Get days above threashold
    for (int i = 0; i < yearlyTemp->size(); i++)
    {
        if (yearlyTemp->get(i) > threshold)
        {
            days += 1;
        }
    }

    // Print
    std::cout << "Days above threshold (" << threshold << "): " << days << std::endl;

    return 0;
}
