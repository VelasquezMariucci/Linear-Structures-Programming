#include <iostream>

#include "Calculator.h"
#include <vector>

int main()
{
    std::vector<float> anglesList;
    std::string userInput;
    int count = 0;

    std::cout << "Enter 'stop' to finish entering values." << std::endl;

    /*
     *@brief loop for user angle inputs until 'stop' key word is entered.
     *
     * input is read as string, if it's a number, it gets turned into a float and stored
     * in a vector. If it's the keyword 'stop' is entered, the loop breaks.
     */
    while (userInput != "stop")
    {
        std::cout << "Enter measured angle #" << count + 1 << ": " << std::endl;

        std::cin >> userInput;

        // Check if the user wants to stop
        if (userInput == "stop")
        {
            break;
        }

        //store input as a float in a vector.
        float angle = std::stof(userInput);
        anglesList.push_back(angle);

        count++;
    }

    /*
     *set trueDirection of a user-entered angles using the calculateTrueDirection func
     *found in Calculator.
     */
    float trueDirection = Calculator::calculateTrueDirection(anglesList);

    std::cout << "The true angle from your given measurements is: " << trueDirection << std::endl;

    return 0;
}
