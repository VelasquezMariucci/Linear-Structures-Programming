//
// Created by esvel on 22/09/2024.
//

#include "StudentRecord.h"

void StudentRecord::addStudent(Student student)
{
    this->studentList.push_back(student);
}

/*
 *@brief calculate the average student grade
 *
 *This function gets all the students average grade and divides it by the total number of students
 *returning the total grade average.
 *
 *@return total Student Grade Average / size.
 */
float StudentRecord::getStudentGradeAverage()
{
    float studentGradeAverage = 0;

    for (Student student : studentList)
    {
        studentGradeAverage += student.getGradeAverage();
    }

    return studentGradeAverage / studentList.size();
}

/*
 *@brief delete student from student vector
 *
 *This function finds the iterator value for the student and saves it as it. It uses that iterator
 *to check if the student is found in the student vector. If it's found its saved in it to later
 *be returned and deleted from the vector. If it's not found runtime_error exception is thrown.
 *
 *@return deletedStudent Student.
 *@exception runtime_error Student not found.
 */
Student StudentRecord::deleteStudent(Student& student)
{
    auto it = std::find(studentList.begin(), studentList.end(), student);

    if (it != studentList.end())
    {
        Student deletedStudent = *it;
        studentList.erase(it);
        return deletedStudent;
    }

    throw std::runtime_error("Student not found");
}

//@Overload << operator to enable custom string conversion.
std::ostream& operator<<(std::ostream& os, StudentRecord studentRecord)
{
    for (Student student : studentRecord.studentList)
    {
        os << student << "\n" << "\n";
    }

    return os;
}
