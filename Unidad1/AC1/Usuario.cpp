//
// Created by esvel on 27/09/2024.
//

#include "Usuario.h"

#include <string>
//constructor sin parametros del usuario (vacio)
Usuario::Usuario() : nombre(""), DNI("")
{
}

//constructor con valores del Usuario como parametros
Usuario::Usuario(std::string nombre, std::string DNI): nombre(nombre), DNI(DNI)
{
}

//funcion para devolver el nombre del usuario usando el getter
std::string Usuario::getNombre()
{
    return this->nombre;
}
