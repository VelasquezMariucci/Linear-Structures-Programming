#include <iostream>

#include "MatrixTemplate.h"

int main()
{
    int rows = 0;
    int cols = 0;
    std::string userInput;

    //user input
    std::cout << "Enter the number of rows in your first matrix" << std::endl;
    std::cin >> rows;

    std::cout << "Enter the number of columns" << std::endl;
    std::cin >> cols;

    //create first matrix
    MatrixTemplate<int>* myMatrix = new MatrixTemplate<int>(rows, cols);

    //assign values to matrix coordinates
    for (int i = 0; i < myMatrix->getRows(); ++i)
    {
        for (int j = 0; j < myMatrix->getCols(); ++j)
        {
            std::cout << "In coordinates: " << "[" << i << ", " << j << "], enter a value: " << std::endl;
            std::cin >> userInput;

            myMatrix->addElement(i, j, std::stoi(userInput));
        }
    }

    std::cout << *myMatrix << std::endl;

    //user input
    std::cout << "Enter the number of rows in your second matrix" << std::endl;
    std::cin >> rows;

    std::cout << "Enter the number of columns" << std::endl;
    std::cin >> cols;

    //create second matrix
    MatrixTemplate<int>* secondMatrix = new MatrixTemplate<int>(rows, cols);

    //assign values to matrix coordinates
    for (int i = 0; i < secondMatrix->getRows(); ++i)
    {
        for (int j = 0; j < secondMatrix->getCols(); ++j)
        {
            std::cout << "In coordinates: " << "[" << i << ", " << j << "], enter a value: " << std::endl;
            std::cin >> userInput;

            secondMatrix->addElement(i, j, std::stoi(userInput));
        }
    }

    std::cout << *myMatrix << std::endl;

    //Addition testing
    MatrixTemplate<int> sum = (*myMatrix + *secondMatrix);
    std::cout << sum << std::endl;

    //Multiplication testing
    MatrixTemplate<int> product = (*myMatrix * *secondMatrix);
    std::cout << product << std::endl;

    return 0;
}
