//
// Created by esvel on 22/09/2024.
//

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <map>

/*
 * @brief A simple model class for student objects.
 *
 * This class provides basic functions to build, get, set, view, and compare
 * using private values.
 */
class Student
{
public:
    /*
     *@brief student constructor.
     *
     *The constructor calls the setGradeAverage().
     *
     *@param name String.
     *@param age int.
     *@param grades map of Strings with floats.
     */
    Student(std::string name, int age, std::map<std::string, float> grades);
    ~Student() = default;

    std::map<std::string, float> getGrades();
    std::string getName();
    float getGradeAverage();
    int getAge();

    
    //@Overload << operator to enable string conversion
    friend std::ostream& operator<<(std::ostream& os, Student& student);

    //@Overload == operator to create custom bool comparison.
    bool operator==(const Student& other) const;

private:
    std::map<std::string, float> grades;
    std::string name;
    float gradeAverage;
    int age;

    //calculate grade average from grades vector.
    float setGradeAverage();
};

#endif //STUDENT_H
