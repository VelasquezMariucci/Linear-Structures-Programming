//
// Created by esvel on 27/09/2024.
//

#include "UsuarioCliente.h"
//constructor del Usuario con parametros heredeados de la clase usuario, tambien muestra reserva activa
UsuarioCliente::UsuarioCliente(std::string nombre, std::string DNI, bool tieneReserva)
    : Usuario(nombre, DNI), tieneReserva(tieneReserva), historialLibros(historialLibros)
{
}
//getter para mostrar si tiene una reserva activa
bool UsuarioCliente::getReserva()
{
    return this->tieneReserva; //devuelve el boolean de si ha reservado o no
}

//metodo para realizar una reserva por un Usuario y asi mostrar la reserva activa
bool UsuarioCliente::setReserva(bool reserva)
{
    tieneReserva = reserva;
}

//metodo para reservar un libro como Usuario pasando el Libro como parametro
void UsuarioCliente::reservaLibro(Libro& libro)
{
    //comprueba si el libro esta disponible y si el usuario no tiene reservas activas
    if (libro.getDisponibilidad() == true && getReserva() == false)
    {
        //pone la reserva del Usuario en true y la disponiblidad del libro en false
        setReserva(true);
        libro.setDisponibilidad(false);

        //añade el libro al historial de libros del Usuario
        historialLibros.añadirValor(libro);

        //muestra por consola el libro reservado
        std::cout << "El libro " << libro.getNombre() << " ha sido reservado" << std::endl;
    }
    else
    {
        //si no ha podido ser reservado lo dice por consola
        std::cout << "Reserva no posible" << std::endl;
    }
}
//metodo para mostrar el historial de libros del usuario
Lista<Libro> UsuarioCliente::getHistorialLibros()
{
    //muestra el historial de libros
    return this->historialLibros;
}
