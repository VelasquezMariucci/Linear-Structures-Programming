//
// Created by Ricky Vicente on 09/12/2024.
//

#include "Contacto.h"

#include <utility>

Contacto::Contacto()
{ //Constructor por defecto de la clase Contacto
    nombre = "";
    apellido = "";
    numero = 0;
}

Contacto::Contacto(std::string n, std::string a, long long num)
{ //Constructor de la clase Contacto
    nombre = std::move(n); //Se usa std::move para mover el contenido de n a nombre
    apellido = std::move(a); //Se usa std::move para mover el contenido de a a apellido
    numero = num; //Se asigna el valor de num a numero
}

std::string Contacto::getNombre()
{ //Getter de nombre
    return nombre;
}

std::string Contacto::getApellido()
{ //Getter de apellido
    return apellido;
}

long long Contacto::getNumero()
{ //Getter de numero
    return numero;
}

void Contacto::setNombre(std::string n)
{ //Setter de nombre
    nombre = n;
}

void Contacto::setApellido(std::string a)
{ //Setter de apellido
    apellido = a;
}

void Contacto::setNumero(long long num)
{ //Setter de numero
    numero = num;
}
