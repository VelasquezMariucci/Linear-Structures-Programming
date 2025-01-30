//
// Created by esvel on 28/11/2024.
//

#ifndef STUDENT_H
#define STUDENT_H
#include <string>

/**
 * @brief Represents a student with a name and a grade.
 */
class Student
{
private:
    int grade;
    std::string name;

public:
    /**
     * @brief Gets the name of the student.
     *
     * @return The name of the student as a string.
     */
    std::string getName()
    {
        return name;
    }

    /**
     * @brief Gets the grade of the student.
     *
     * @return The grade of the student as an integer.
     */
    int getGrade()
    {
        return grade;
    }

    /**
     * @brief Default constructor for the Student class.
     *
     * Initializes a student with an empty name and a grade of 0.
     */
    Student()
    {
        name = "";
        grade = 0;
    }

    /**
     * @brief Parameterized constructor for the Student class.
     *
     * @param name The name of the student.
     * @param grade The grade of the student.
     */
    Student(std::string name, int grade)
    {
        this->name = name;
        this->grade = grade;
    }

    /**
     * @brief Equality operator for comparing two students.
     *
     * Compares two students based on their grades.
     *
     * @param other The student to compare with.
     * @return True if the grades are equal, false otherwise.
     */
    bool operator==(const Student& other) const
    {
        return grade == other.grade;
    }

    /**
     * @brief Less-than operator for comparing two students.
     *
     * Compares two students to determine if this student has a lower grade.
     *
     * @param other The student to compare with.
     * @return True if this student's grade is less, false otherwise.
     */
    bool operator<(const Student& other) const
    {
        return grade < other.grade;
    }

    /**
     * @brief Greater-than operator for comparing two students.
     *
     * Compares two students to determine if this student has a higher grade.
     *
     * @param other The student to compare with.
     * @return True if this student's grade is greater, false otherwise.
     */
    bool operator>(const Student& other) const
    {
        return grade > other.grade;
    }

    /**
     * @brief Stream insertion operator for Student.
     *
     * Allows printing a student in the format "Student: [name], Grade: [grade]".
     *
     * @param os The output stream.
     * @param s The student to be printed.
     * @return The modified output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const Student& s)
    {
        os << "Student: " << s.name << ", Grade: " << s.grade;
        return os;
    }
};


#endif //STUDENT_H
