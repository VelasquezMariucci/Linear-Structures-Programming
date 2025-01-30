#include <iostream>

/*
 *@brief function that returns the total cost of the diner using the requested parameters.
 *
 *The total cost is calculated by adding the food price with the silverware cost percentage applied to the food price
 *and with the tip percentage applied to the food price.
 *
 *@param foodPrice Food Price float.
 *@param silverwareCostPercentage Silverware Cost Percentage int.
 *@param tipPercentage Tip Percentage int.
 */
float calculateCost(float foodPrice, int silverwareCostPercentage, int tipPercentage)
{
    float totalCost = 0.0f;

    totalCost = foodPrice + (foodPrice * silverwareCostPercentage / 100) + (foodPrice * tipPercentage / 100);

    return totalCost;
};

int main()
{
    float foodPrice = 0.0f;
    int silverwareCostPercentage;
    int tipPercentage;

    //User input for meal price.
    std::cout << "Calculate you dinner price" << std::endl;
    std::cout << "Enter the cost of your meal: " << std::endl;

    std::cin >> foodPrice;

    //User input for silverware cost percentage;
    std::cout << "Enter the percentage cost of the silverware: " << std::endl;

    std::cin >> silverwareCostPercentage;

    //User input for tip percentage;
    std::cout << "Enter the tip percentage cost: " << std::endl;

    std::cin >> tipPercentage;

    std::cout << "Total cost of your diner: " << calculateCost(foodPrice, silverwareCostPercentage, tipPercentage) <<
        std::endl;

    return 0;
}
