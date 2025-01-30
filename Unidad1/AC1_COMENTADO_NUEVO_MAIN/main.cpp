#include <iostream>

#include "Libro.h"
#include "Lista.h"
#include "UsuarioBibliotecario.h"
#include "UsuarioCliente.h"


int main()
{
    //crea lista de libros biblioteca
    Lista<Libro> biblioteca(20);

    //crea los 20 libros
    Libro libro1("El Rey Leon", "Accion", true);
    Libro libro2("Cien Años de Soledad", "Aventuras", true);
    Libro libro3("El Padrino", "Drama", true);
    Libro libro4("Orgullo y Prejuicio", "Romanticismo", true);
    Libro libro5("Mujer en el Espejo", "Drama", true);
    Libro libro6("Harry Potter y la Piedra Filosofal", "Aventuras", false);
    Libro libro7("El Hobbit", "Aventuras", true);
    Libro libro8("Don Quijote de la Mancha", "Drama", true);
    Libro libro9("Cumbres borrascosas", "Drama", true);
    Libro libro10("El Alquimista", "Aventuras", true);
    Libro libro11("La Casa de los Espíritus", "Drama", true);
    Libro libro12("La Metamorfosis", "Drama", false);
    Libro libro13("El Gran Gatsby", "Drama", true);
    Libro libro14("Crónica de una muerte anunciada", "Drama", true);
    Libro libro15("Rayuela", "Drama", false);
    Libro libro16("El Principito", "Aventuras", true);
    Libro libro17("1984", "Drama", true);
    Libro libro18("El retrato de Dorian Gray", "Drama", true);
    Libro libro19("La sombra del viento", "Aventuras", true);
    Libro libro20("Fahrenheit 451", "Drama", true);

    //añade los 20 libros a la biblioteca
    biblioteca.añadirValor(libro1);
    biblioteca.añadirValor(libro2);
    biblioteca.añadirValor(libro3);
    biblioteca.añadirValor(libro4);
    biblioteca.añadirValor(libro5);
    biblioteca.añadirValor(libro6);
    biblioteca.añadirValor(libro7);
    biblioteca.añadirValor(libro8);
    biblioteca.añadirValor(libro9);
    biblioteca.añadirValor(libro10);
    biblioteca.añadirValor(libro11);
    biblioteca.añadirValor(libro12);
    biblioteca.añadirValor(libro13);
    biblioteca.añadirValor(libro14);
    biblioteca.añadirValor(libro15);
    biblioteca.añadirValor(libro16);
    biblioteca.añadirValor(libro17);
    biblioteca.añadirValor(libro18);
    biblioteca.añadirValor(libro19);
    biblioteca.añadirValor(libro20);

    //crea los usuarios clientes con nombre, DNi y boolean de si tienen reservas activas
    UsuarioCliente cliente1("Juan Pérez", "12345678A", false);
    UsuarioCliente cliente2("Ana", "87654321B", true);
    UsuarioCliente cliente3("Jorge", "06415590F", false);
    UsuarioCliente cliente4("Miguel", "12345678A", false);
    UsuarioCliente cliente5("Gabriela", "12345678A", true);

    //crea un usuario bibliotecario que puede gestionar las reservas
    UsuarioBibliotecario bibliotecario("Jesús García", "45618905F");
    bibliotecario.comprobarDisponibilidad(biblioteca);

    return 0;
}
