//
// Created by esvel on 27/09/2024.
//

#ifndef USUARIO_H
#define USUARIO_H
#include <string>


class Usuario
{
protected:
    //crea los atributos del Usuario
    std::string nombre;
    std::string DNI;

public:
    //crea un constructor vacio
    Usuario();

    //crea un constructor con los parametros de Usuario
    Usuario(std::string nombre, std::string DNI);

    //crea el getter del nombre del Usuario
    std::string getNombre();
};


#endif //USUARIO_H
