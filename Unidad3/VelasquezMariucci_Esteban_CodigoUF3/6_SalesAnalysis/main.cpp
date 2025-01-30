#include <iostream>
#include "../Estructuras/include/Vector.h"

/*Análisis de datos de ventas: Crea un programa que utilice la clase plantilla Vector
para almacenar las ventas diarias de un conjunto de productos durante un mes.
Implementa funciones para calcular la suma total de las ventas, el producto más
vendido y el día con menor cantidad de ventas.*/

using std::cout, std::string, std::endl;

// Struct to represent a product's daily sale
struct DailySales
{
    int salesQuantity;
    int day;
    string productName;
};

int main()
{
    // Create vector
    Vector<DailySales>* salesVector = new Vector<DailySales>();

    // Add daily sales to vector
    salesVector->push_back(DailySales{1200, 1, "Computers"});
    salesVector->push_back(DailySales{800, 5, "Smartphones"});
    salesVector->push_back(DailySales{1500, 15, "Tablets"});
    salesVector->push_back(DailySales{1000, 27, "Smartwatches"});

    // Calculate the most sales and the least sales
    int totalSales = 0;
    DailySales mostSoldProduct = salesVector->get(0);
    DailySales leastSalesDay = salesVector->get(0);

    for (size_t i = 0; i < salesVector->size(); ++i)
    {
        DailySales ds = salesVector->get(i);

        totalSales += ds.salesQuantity;

        if (ds.salesQuantity > mostSoldProduct.salesQuantity)
        {
            mostSoldProduct = ds;
        }

        if (ds.salesQuantity < leastSalesDay.salesQuantity)
        {
            leastSalesDay = ds;
        }
    }

    // Print
    cout << "Total Sales: " << totalSales << endl;
    cout << "Most Sold Product: " << mostSoldProduct.productName << " with " << mostSoldProduct.salesQuantity << endl;
    cout << "Day with Least Sales: " << leastSalesDay.day << " with " << leastSalesDay.salesQuantity << endl;

    return 0;
}
