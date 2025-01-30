//
// Created by esvel on 27/09/2024.
//

#ifndef USUARIOCLIENTE_H
#define USUARIOCLIENTE_H
#include <iostream>

#include "Libro.h"
#include "Lista.h"
#include "Usuario.h"


class UsuarioCliente : public Usuario
{
private:
    //declara los atributos del UsuarioCliente con su historial, si tiene una reserva y su maximo de libros
    Lista<Libro>* historialLibros = new Lista<Libro>(20);
    bool tieneReserva;
    int maxLibros = 20;

public:
    //crea constructor con los parametros del Usuario
    UsuarioCliente(std::string nombre, std::string DNI);

    //getter para reservar un libro
    bool getReserva();

    //getter de la lista de libros reservados por el Usuario
    void getHistorialLibros();

    //setter del boolean de reservas al reservar un libro como Usuario
    void setReserva(bool reserva);

    //metodo para reservar un libro como Usuario
    void reservaLibro(Libro& libro);

    //imprime la informacion del cliente
    friend std::ostream& operator<<(std::ostream& os, UsuarioCliente& cliente);
};

#endif //USUARIOCLIENTE_H
