//
// Created by esvel on 23/11/2024.
//

#ifndef DATE_H
#define DATE_H

#include <iostream>

/**
 * @brief Represents a date with day, month, and year components.
 */
class Date
{
private:
    int day;
    int month;
    int year;

public:
    /**
     * @brief Default constructor for the Date class.
     *
     * Initializes the date to an undefined state.
     */
    Date();

    /**
     * @brief Parameterized constructor for the Date class.
     *
     * @param day The day of the month.
     * @param month The month of the year.
     * @param year The year.
     */
    Date(int day, int month, int year);

    /**
     * @brief Equality operator for comparing two dates.
     *
     * Compares two dates to check if they are equal.
     *
     * @param other The date to compare with.
     * @return True if both dates are equal, false otherwise.
     */
    bool operator==(const Date& other) const
    {
        return day == other.day && month == other.month && year == other.year;
    }

    /**
     * @brief Stream insertion operator for Date.
     *
     * Allows printing a date in the format "day/month/year".
     *
     * @param os The output stream.
     * @param f The date to be printed.
     * @return The modified output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const Date& f)
    {
        os << f.day << "/" << f.month << "/" << f.year;
        return os;
    }
};

#endif //DATE_H
