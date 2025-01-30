//
// Created by esvel on 23/11/2024.
//

#include "Date.h"

Date::Date() : day(0), month(0), year(0)
{
}

Date::Date(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}
