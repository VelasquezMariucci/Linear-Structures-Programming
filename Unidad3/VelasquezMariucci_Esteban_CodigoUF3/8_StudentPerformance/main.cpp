#include <iostream>
#include "../Estructuras/include/Vector.h"
#include "Student.h"
#include <cmath>

/*Desarrolla un programa que utilice la
clase plantilla Vector para almacenar las calificaciones de un grupo de estudiantes
en diferentes asignaturas. Implementa funciones para identificar al estudiante con
el mejor desempeño, el promedio de calificaciones por asignatura y la asignatura
con la mayor dispersión de calificaciones.*/

/**
 * @brief Calculates the variance of student grades.
 *
 * Computes the variance of grades based on their deviation from the average.
 *
 * @param grades A Vector containing Student objects. Each student has a grade accessible via getGrade().
 * @param avg The average of the grades to compare against.
 * @return The calculated variance of the grades.
 */
float calculateVariance(Vector<Student>& grades, float avg)
{
    float variance = 0.0;

    for (size_t i = 0; i < grades.size(); ++i)
    {
        float diff = grades.get(i).getGrade() - avg;
        variance += std::pow(diff, 2);
    }

    return variance / grades.size();
}

using std::cout, std::endl;

int main()
{
    // Create Vector for storing grades of students in Math and Science
    Vector<Student>* mathGrades;
    Vector<Student>* scienceGrades;

    // Add students to Math Class
    mathGrades->push_back(Student("John", 85));
    mathGrades->push_back(Student("Jane", 92));
    mathGrades->push_back(Student("Carlos", 78));
    mathGrades->push_back(Student("Bob", 95));

    // Add students to Science Class
    scienceGrades->push_back(Student("Maria", 82));
    scienceGrades->push_back(Student("Abby", 65));
    scienceGrades->push_back(Student("Mario", 80));
    scienceGrades->push_back(Student("Tomas", 91));


    // Best students
    cout << "Best Student in Math: " << mathGrades->max() << endl;
    cout << "Best Student in Science: " << scienceGrades->max() << endl;


    // Average for Maths
    float mathSum = 0;
    for (size_t i = 0; i < mathGrades->size(); ++i)
    {
        mathSum += mathGrades->get(i).getGrade();
    }
    float mathAverage = mathSum / mathGrades->size();
    cout << "Average grade in Maths: " << mathAverage << endl;


    // Average for Science
    float scienceSum = 0;
    for (size_t i = 0; i < scienceGrades->size(); ++i)
    {
        scienceSum += scienceGrades->get(i).getGrade();
    }
    float scienceAverage = scienceSum / scienceGrades->size();
    cout << "Average grade in Science: " << scienceAverage << endl;


    // Subject has the highest grade variance
    cout << "Math Variance: " << calculateVariance(*mathGrades, mathAverage) << endl;
    cout << "Science Variance: " << calculateVariance(*scienceGrades, scienceAverage) << endl;

    if (calculateVariance(*mathGrades, mathAverage) > calculateVariance(*scienceGrades, scienceAverage))
    {
        cout << "Highest grade variance: Math" << endl;
    }
    else
    {
        cout << "Highest grade variance: Science" << endl;
    }

    return 0;
}
