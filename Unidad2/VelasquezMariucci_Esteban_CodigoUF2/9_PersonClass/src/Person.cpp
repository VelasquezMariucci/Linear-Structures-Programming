//
// Created by esvel on 27/10/2024.
//

#include "Person.h"

Person::Person(std::string* name, int* age) : name(name), age(age)
{
}

std::string Person::getName()
{
    return *name;
}

int Person::getAge()
{
    return *age;
}

void Person::setName(std::string* name)
{
    this->name = name;
}

void Person::setAge(int* age)
{
    this->age = age;
}
