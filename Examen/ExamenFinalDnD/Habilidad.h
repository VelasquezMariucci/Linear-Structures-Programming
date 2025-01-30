//
// Created by esvel on 21/01/2025.
//

#ifndef HABILIDAD_H
#define HABILIDAD_H

#include <string>
#include <iostream>

class Habilidad
{
private:
    std::string name;
    std::string description;
    int damage;

public:
    Habilidad() : name(""), description(""), damage(0)
    {
    }

    Habilidad(const std::string& name, const std::string& description, int damage)
        : name(name), description(description), damage(damage)
    {
    }

    std::string getName() const { return name; }
    std::string getDescription() const { return description; }
    int getDamage() const { return damage; }

    friend std::ostream& operator<<(std::ostream& os, const Habilidad& habilidad)
    {
        os << habilidad.name << " - " << habilidad.description
            << " (Damage: " << habilidad.damage << ")";
        return os;
    }
};

#endif // HABILIDAD_H
