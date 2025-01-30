//
// Created by esvel on 22/09/2024.
//

#ifndef STUDENTRECORD_H
#define STUDENTRECORD_H

#include <vector>

#include "Student.h"

/**
 * @brief A simple model class to handle student objects.
 *
 * This class provides basic functions to add, delete, view, and get the
 * average student grade.
 */
class StudentRecord
{
public:
    StudentRecord() = default;
    ~StudentRecord() = default;

    void addStudent(Student);

    /*
     *@brief calculate the average student grade
     *
     *@return total Student Grade Average / size.
     */
    float getStudentGradeAverage();

    /*
     *@brief delete student from student vector
     *
     *@return deletedStudent Student.
     *@exception runtime_error Student not found.
     */
    Student deleteStudent(Student& student);

    //@Overload << operator to enable custom string conversion.
    friend std::ostream& operator<<(std::ostream& os, StudentRecord studentRecord);

private:
    std::vector<Student> studentList;
};

#endif //STUDENTRECORD_H
