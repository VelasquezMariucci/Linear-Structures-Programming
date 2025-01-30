#include <iostream>
#include <string>
#include "../Estructuras/include/Vector.h"

/*Escribe un programa que utilice la clase
plantilla Vector para almacenar los precios y cantidades de productos en un
supermercado. Implementa funciones para calcular el valor total del inventario, el
producto con el precio más alto y el promedio de unidades vendidas por producto.*/

using std::cout, std::endl, std::string;

// Struct to represent products
struct Product
{
    string name;
    float price;
    int quantity;
};

int main()
{
    // Create product Vector
    Vector<Product>* inventory = new Vector<Product>();

    // Add products to the inventory
    inventory->push_back(Product{"Apples", 1.2, 100});
    inventory->push_back(Product{"Milk", 0.9, 50});
    inventory->push_back(Product{"Cheese", 5.5, 30});
    inventory->push_back(Product{"Bread", 1.1, 80});
    inventory->push_back(Product{"Eggs", 0.2, 200});

    // Calculate the total value
    float totalValue = 0.0;
    for (size_t i = 0; i < inventory->size(); ++i)
    {
        Product& prod = inventory->get(i);
        totalValue += prod.price * prod.quantity;
    }

    cout << "Total inventory value: " << totalValue << endl;

    // Calculate most expensive product
    Product mostExpensive;
    for (size_t i = 1; i < inventory->size(); ++i)
    {
        Product& prod = inventory->get(i);
        if (prod.price > mostExpensive.price)
        {
            mostExpensive = prod;
        }
    }

    cout << "Most expensive product: " << mostExpensive.name << " " << mostExpensive.price << " per unit" << endl;

    // Calculate average quantity
    int totalQuantity = 0;
    for (size_t i = 0; i < inventory->size(); ++i)
    {
        totalQuantity += inventory->get(i).quantity;
    }

    float averageQuantity = totalQuantity / inventory->size();
    cout << "Average quantity: " << averageQuantity << endl;

    return 0;
}
