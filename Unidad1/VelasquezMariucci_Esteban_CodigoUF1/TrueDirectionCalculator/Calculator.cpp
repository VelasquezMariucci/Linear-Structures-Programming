//
// Created by esvel on 22/09/2024.
//

#include "Calculator.h"
#include <vector>
#include <iostream>

/*
 *@brief calculate the average angle in an array of angles.
 *
 *@param angleList[] List of angles.
 *@param size Size of list.
 *@return average angle in list.
 */
float Calculator::calculateTrueDirection(std::vector<float> anglesList)
{
    float angleSum = 0;

    for (float angle : anglesList)
    {
        angleSum += angle;
    }

    return angleSum / anglesList.size();
};
