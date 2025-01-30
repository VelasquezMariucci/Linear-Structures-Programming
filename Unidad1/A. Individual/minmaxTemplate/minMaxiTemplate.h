//
// Created by esvel on 23/09/2024.
//

#include <stdexcept>

/*
 * @brief A template function that compares two values and returns the larger one. If the values are equal, it throws a
 * std::runtime_error exception.
 *
 * @param const T& a Value T.
 * @param const T& b Value T.
 */
template <typename T>
T maxi(const T& a, const T& b)
{
    if (a > b)
    {
        return a;
    }
    else if (a < b)
    {
        return b;
    }
    else
    {
        throw std::runtime_error("Values are equal.");
    }
}

/*
* @brief A template function that compares two values and returns the smaller one. If the values are equal, it throws a
* std::runtime_error exception.
 *
 * @param const T& a Value T.
 * @param const T& b Value T.
 */
template <typename T>
T mini(const T& a, const T& b)
{
    if (a < b)
    {
        return a;
    }
    else if (a > b)
    {
        return b;
    }
    else
    {
        throw std::runtime_error("Values are equal.");
    }
}
