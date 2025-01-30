//
// Created by esvel on 27/10/2024.
//

#ifndef PERSON_H
#define PERSON_H
#include <string>

/**
 * @Brief Class to represent a Person object
 *
 * It contains values to represent the age and name.
 */
class Person
{
private:
    std::string* name;
    int* age;

public:
    /**
     * @Brief Person object constructor.
     *
     * Constructs the person object with the given name and age.
     *
     * @param name string pointer.
     * @param age int pointer.
     */
    Person(std::string* name, int* age);

    ~Person() = default;

    // Getters
    std::string getName();

    int getAge();

    // Setters
    void setName(std::string* name);

    void setAge(int* age);
};


#endif //PERSON_H
