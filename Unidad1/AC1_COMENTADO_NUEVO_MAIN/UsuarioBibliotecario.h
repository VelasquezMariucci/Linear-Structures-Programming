//
// Created by esvel on 27/09/2024.
//

#ifndef USUARIOBIBLIOTECARIO_H
#define USUARIOBIBLIOTECARIO_H
#include <iostream>

#include "Libro.h"
#include "Lista.h"
#include "Usuario.h"
#include "UsuarioCliente.h"

//crea la clase del Bibliotecario que hereda de Usuario
class UsuarioBibliotecario : public Usuario
{
public:
    //constructor del Bibliotecario con su nombre y DNI
    UsuarioBibliotecario(std::string nombre, std::string DNI);

    //metodo para comprobar la disponiblidad de un libro pasandole la lista de libros como parametro
    void comprobarDisponibilidad(Lista<Libro>& libros);

    //metodo para ver quien ha reservado un libro
    void verHistorialLibros(Lista<Libro>& libros);

    //metodo para comprobar que reserva ha hecho cada cliente
    void comprobarReservaCliente(UsuarioCliente& cliente);

    //metodo para devolver un libro reservado anteriormente por un cliente
    void devolverLibro(UsuarioCliente& cliente, Libro& libro);
};


#endif //USUARIOBIBLIOTECARIO_H
