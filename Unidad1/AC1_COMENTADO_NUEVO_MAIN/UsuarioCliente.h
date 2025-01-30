//
// Created by esvel on 27/09/2024.
//

#ifndef USUARIOCLIENTE_H
#define USUARIOCLIENTE_H
#include <iostream>

#include "Libro.h"
#include "Lista.h"
#include "Usuario.h"

//crea la clase UsuarioCliente que hereda de Usuario
class UsuarioCliente : public Usuario
{
private:
    //declara los atributos del UsuarioCliente con su historial, si tiene una reserva y su maximo de libros
    Lista<Libro> historialLibros;
    bool tieneReserva;
    int maxLibros = 20;

public:
    //crea constructor con los parametros del Usuario
    UsuarioCliente(std::string nombre, std::string DNI, bool tieneReserva);

    //getter para reservar un libro
    bool getReserva();

    //getter de la lista de libros reservados por el Usuario
    Lista<Libro> getHistorialLibros();

    //setter del boolean de reservas al reservar un libro como Usuario
    bool setReserva(bool reserva);

    //metodo para reservar un libro como Usuario
    void reservaLibro(Libro& libro);

    //compara dos objectos con boolean de UsuarioCliente incluso si los atributos son privados 
    friend bool operator==(const UsuarioCliente&, const UsuarioCliente&);
};

#endif //USUARIOCLIENTE_H
