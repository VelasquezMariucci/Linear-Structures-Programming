#include <iostream>

#include "Student.h"
#include "StudentRecord.h"

/*
 *Crea una clase “Estudiante” con atributos como nombre, edad y
 *calificaciones. Luego, crea una clase “RegistroEstudiantes” que tenga
 *una colección de objetos de tipo Estudiante. Implementa métodos para
 *agregar estudiantes, calcular el promedio de calificaciones y mostrar la
 *información de todos los estudiantes en el registro.
 */

int main()
{
    std::map<std::string, float> bobsGrades = {{"Math", 10}, {"Spanish", 8}, {"Science", 5}};
    std::map<std::string, float> mariasGrades = {{"Math", 5}, {"Spanish", 10}, {"Science", 7}};

    Student* student1 = new Student("Bob", 21, bobsGrades);
    Student* student2 = new Student("Maria", 19, mariasGrades);

    StudentRecord* studentRecord = new StudentRecord();

    studentRecord->addStudent(*student1);
    studentRecord->addStudent(*student2);

    std::cout << *studentRecord << std::endl;

    return 0;
}
