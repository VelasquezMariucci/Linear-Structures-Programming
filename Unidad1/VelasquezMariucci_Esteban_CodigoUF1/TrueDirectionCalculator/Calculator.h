//
// Created by esvel on 22/09/2024.
//

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <vector>

//Simple class to do math with angles.
class Calculator
{
public:
    /*
     *@brief calculate the average angle in an array of angles.
     *
     *@param angleList[] List of angles.
     *@param size Size of list.
     *@return average angle in list.
     */
    static float calculateTrueDirection(std::vector<float> anglesList);

    //Instance creation prevention to make class static.
    Calculator() = delete;
};

#endif //CALCULATOR_H
