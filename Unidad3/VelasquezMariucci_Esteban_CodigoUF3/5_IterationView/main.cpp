#include <iostream>
#include "Date.h"
#include "../Estructuras/include/Dynarray.h"

/*Escribe un programa que utilice la clase plantilla Dynarray
para almacenar fechas en formato día/mes/año. Implementa funciones para
recorrer el Dynarray y mostrar las fechas almacenadas en él en un formato legible*/

int main()
{
    // Date dinarray
    DynArray<Date> dateList;

    // Add dates
    dateList.add(Date(25, 12, 2024));
    dateList.add(Date(1, 1, 2025));
    dateList.add(Date(15, 8, 2024));
    dateList.add(Date(14, 2, 2024));

    std::cout << "Dates: " << dateList << std::endl;

    return 0;
}
