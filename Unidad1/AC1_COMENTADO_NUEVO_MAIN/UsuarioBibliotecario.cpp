//
// Created by esvel on 27/09/2024.
//

#include "UsuarioBibliotecario.h"

//constructor del UsuarioBibliotecario con los parametros correspondientes llamando a la clase Usuario
UsuarioBibliotecario::UsuarioBibliotecario(std::string nombre, std::string DNI) : Usuario(nombre, DNI)
{
}
//comprueba disponibilidad de un libro pasandole la lista de libros como parametro
void UsuarioBibliotecario::comprobarDisponibilidad(Lista<Libro>& libros)
{
    //bucle que recorre la lista
    for (int i = 0; i < libros.obtenerTamaño(); i++)
    {
        Libro& libro = libros[i];
        if (libro.getDisponibilidad() == true)
        {
            // si el libro esta disponible devuelve true
            std::cout << libro.getNombre() << " esta disponible." << std::endl;
        }
        else
        {
            // si el libro no esta disponible devuelve false
            std::cout << libro.getNombre() << " no esta disponible." << std::endl;
        }
    }
}

//metodo para poder ver quien ha reservado el libro pasando como parametro la lista de libros
void UsuarioBibliotecario::verHistorialLibros(Lista<Libro>& libros)
{
    //bucle que recorre la lista de libros
    for (int i = 0; i < libros.obtenerTamaño(); i++)
    {
        //muestra por consola quien ha reservado el libro
        Libro& libroUsuarios = libros[i];
        std::cout << libroUsuarios.getNombre() << std::endl;
    }
}
//metodo que comprueba si el cliente reservo un libro pasandole el Usuario como parametro
void UsuarioBibliotecario::comprobarReservaCliente(UsuarioCliente& cliente)
{
    //condicion de si ha realizado una reserva
    if (cliente.getReserva() == true)
    {
        //si la ha realizado lo dice
        std::cout << "El cliente reservó un libro" << std::endl;
    }
    else
    {
        //si no ha realizado reservas lo dice
        std::cout << "El cliente no tiene reservado ningun libro" << std::endl;
    }
}
//metodo para devovler un libro pasandole el Usuario y el Libro como parametros
void UsuarioBibliotecario::devolverLibro(UsuarioCliente& cliente, Libro& libro)
{
    //condicion que comprueba si el libro sigue reservado y si el usuario lo habia reservado
    if (libro.getDisponibilidad() == false && cliente.getReserva() == true)
    {
        //retira el libro como reservado y activa su disponibilidad para otros usuarios
        cliente.setReserva(false);
        libro.setDisponibilidad(true);
        //dice por consola que el libro ya se ha devuelto
        std::cout << "Libro devuelto" << std::endl;
    }
    else
    {
        //muestra por consola que la devolucion no es posible
        std::cout << "Devolucion no posible" << std::endl;
    }
}
