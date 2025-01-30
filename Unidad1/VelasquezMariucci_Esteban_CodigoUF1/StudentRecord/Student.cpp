//
// Created by esvel on 22/09/2024.
//

#include "Student.h"

#include <iostream>
#include <map>


/*
 *@brief student constructor.
 *
 *The constructor calls the setGradeAverage() function to calculate the grade average once
 *instantiated.
 *
 *@param name String.
 *@param age int.
 *@param grades map of Strings with floats.
 */
Student::Student(std::string name, int age, std::map<std::string, float> grades)
{
    this->name = name;
    this->age = age;
    this->grades = grades;
    this->gradeAverage = this->setGradeAverage();
}

//setters

/*
 *@brief calculate grade average from grades vector.
 *
 *The grade floats inside the vector get added up then divided by the size of the vector giving
 *the grade average.
 */
float Student::setGradeAverage()
{
    float gradeAverage;

    for (std::map<std::string, float>::iterator it = grades.begin(); it != grades.end(); it++)
    {
        gradeAverage += it->second;
    }

    gradeAverage = gradeAverage / grades.size();

    return gradeAverage;
}

//getters
std::map<std::string, float> Student::getGrades()
{
    return grades;
}

std::string Student::getName()
{
    return name;
}

float Student::getGradeAverage()
{
    return gradeAverage;
}

int Student::getAge()
{
    return age;
}

//@Overload << operator to enable custom string conversion (functions as a toString() when object's
//name is called after <<).
std::ostream& operator<<(std::ostream& os, Student& student)
{
    os << "Student Name: " << student.getName() << ", Age: " << student.getAge() << "\n";
    os << "Grade Average: " << student.getGradeAverage() << "\n";

    for (std::map<std::string, float>::iterator it = student.getGrades().begin(); it != student.getGrades().end(); ++it)
    {
        os << it->first << ": " << it->second << "\n";
    }

    return os;
}

//@Overload == operator to create custom bool comparison.
bool Student::operator==(const Student& other) const
{
    return (this->name == other.name && this->age == age);
}
