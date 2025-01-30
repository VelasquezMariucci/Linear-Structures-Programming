#include <iostream>

#include "Libro.h"
#include "Lista.h"
#include "UsuarioBibliotecario.h"
#include "UsuarioCliente.h"

int main()
{
    Lista<Libro>* listaBiblioteca = new Lista<Libro>(20); //biblioteca general

    //crear libros
    Libro* libro1 = new Libro("El Rey Leon", "Accion", true);
    Libro* libro2 = new Libro("Cien Anios de Soledad", "Aventuras", true);
    Libro* libro3 = new Libro("El Padrino", "Drama", true);
    Libro* libro4 = new Libro("Orgullo y Prejuicio", "Romanticismo", true);
    Libro* libro5 = new Libro("Mujer en el Espejo", "Drama", true);
    Libro* libro6 = new Libro("Harry Potter y la Piedra Filosofal", "Aventuras", false);
    Libro* libro7 = new Libro("El Hobbit", "Aventuras", true);
    Libro* libro8 = new Libro("Don Quijote de la Mancha", "Drama", true);
    Libro* libro9 = new Libro("Cumbres borrascosas", "Drama", true);
    Libro* libro10 = new Libro("El Alquimista", "Aventuras", true);
    Libro* libro11 = new Libro("La Casa de los Espíritus", "Drama", true);
    Libro* libro12 = new Libro("La Metamorfosis", "Drama", false);
    Libro* libro13 = new Libro("El Gran Gatsby", "Drama", true);
    Libro* libro14 = new Libro("Crónica de una muerte anunciada", "Drama", true);
    Libro* libro15 = new Libro("Rayuela", "Drama", false);
    Libro* libro16 = new Libro("El Principito", "Aventuras", true);
    Libro* libro17 = new Libro("1984", "Drama", true);
    Libro* libro18 = new Libro("El retrato de Dorian Gray", "Drama", true);
    Libro* libro19 = new Libro("La sombra del viento", "Aventuras", true);
    Libro* libro20 = new Libro("Fahrenheit 451", "Drama", true);


    //añadir libros a biblioteca
    listaBiblioteca->añadirValor(*libro1);
    listaBiblioteca->añadirValor(*libro2);
    listaBiblioteca->añadirValor(*libro3);
    listaBiblioteca->añadirValor(*libro4);
    listaBiblioteca->añadirValor(*libro5);
    listaBiblioteca->añadirValor(*libro6);
    listaBiblioteca->añadirValor(*libro7);
    listaBiblioteca->añadirValor(*libro8);
    listaBiblioteca->añadirValor(*libro9);
    listaBiblioteca->añadirValor(*libro10);
    listaBiblioteca->añadirValor(*libro11);
    listaBiblioteca->añadirValor(*libro12);
    listaBiblioteca->añadirValor(*libro13);
    listaBiblioteca->añadirValor(*libro14);
    listaBiblioteca->añadirValor(*libro15);
    listaBiblioteca->añadirValor(*libro16);
    listaBiblioteca->añadirValor(*libro17);
    listaBiblioteca->añadirValor(*libro18);
    listaBiblioteca->añadirValor(*libro19);
    listaBiblioteca->añadirValor(*libro20);

    //crear clientes
    UsuarioCliente* cliente1 = new UsuarioCliente("Juan Perez", "12345678A");
    UsuarioCliente* cliente2 = new UsuarioCliente("Maria Martinez", "10010001B");

    // Se pueden hacer ciertas reservas antes de ejecutar el programa
    cliente1->reservaLibro(*libro2);

    //crear bibliotecario
    UsuarioBibliotecario* bibliotecario = new UsuarioBibliotecario("Jesus Garcia", "45618905F");

    // El userInput afectará a cual acción se quiere realizar
    std::string userInput = "";

    // Si se presiona 6, el programa termina
    while (userInput != "6")
    {
        std::cout << "Hola " << bibliotecario->getNombre() << ", que deseas hacer?: " << std::endl;
        std::cout << "1) Comprobar reserva de cliente." << std::endl;
        std::cout << "2) Devolver libro." << std::endl;
        std::cout << "3) Reservar libro" << std::endl;
        std::cout << "4) Ver historial libros" << std::endl;
        std::cout << "5) Comprobar Disponibilidad" << std::endl;
        std::cout << "6) Salir" << std::endl;

        std::cin >> userInput;

        switch (std::stoi(userInput))
        {
        // Se deberá elegir entre uno de los clientes existentes, o sino regresar a la pantalla principal
        case 1:
            std::cout << "Escoge un cliente para ver su reserva" << std::endl;

            std::cout << "1) " << *cliente1 << std::endl;
            std::cout << "2) " << *cliente2 << std::endl;
            std::cout << "6) Salir" << std::endl;

            std::cin >> userInput;

            // Dependiendo del usuario que seleccione, se ejecutará el código con uno o el otro
            if (userInput == "1")
            {
                bibliotecario->comprobarReservaCliente(*cliente1);
            }
            if (userInput == "2")
            {
                bibliotecario->comprobarReservaCliente(*cliente1);
            }

            break;
        case 2:
            std::cout << "Escoge un cliente para devolver su libro" << std::endl;

            std::cout << "1) " << *cliente1 << std::endl;
            std::cout << "2) " << *cliente2 << std::endl;
            std::cout << "6) Salir" << std::endl;

            std::cin >> userInput;

            if (userInput == "1")
            {
                bibliotecario->devolverLibro(*cliente1, *libro2);
            }
            if (userInput == "2")
            {
                bibliotecario->devolverLibro(*cliente2, *libro2);
            }

            break;
        case 3:
            std::cout << "Escoge un cliente para hacer una reserva" << std::endl;

            std::cout << "1) " << *cliente1 << std::endl;
            std::cout << "2) " << *cliente2 << std::endl;
            std::cout << "6) Salir" << std::endl;

            std::cin >> userInput;
            if (userInput == "1")
            {
                std::cout << "Escoge el indice del libro que quieres reservar: " << std::endl;
                std::cout << *listaBiblioteca << std::endl;
                std::cin >> userInput;


                Libro tempLibro = listaBiblioteca[0][0];

                cliente1->reservaLibro(tempLibro);
            }
            if (userInput == "2")
            {
                std::cout << "Escoge el indice del libro que quieres reservar: " << std::endl;
                std::cout << *listaBiblioteca << std::endl;
                std::cin >> userInput;


                Libro tempLibro = listaBiblioteca[0][0];

                cliente2->reservaLibro(tempLibro);
            }

            break;
        case 4:
            std::cout << "Escoge un cliente para ver su historial libros" << std::endl;

            std::cout << "1) " << *cliente1 << std::endl;
            std::cout << "2) " << *cliente2 << std::endl;
            std::cout << "6) Salir" << std::endl;

            std::cin >> userInput;

            if (userInput == "1")
            {
                bibliotecario->verHistorialLibros(*cliente1);
            }
            if (userInput == "2")
            {
                bibliotecario->verHistorialLibros(*cliente2);
            }

            break;
        case 5:
            std::cout << "Escoge un cliente para ver la disponibilidad" << std::endl;

            bibliotecario->comprobarDisponibilidad(*listaBiblioteca);

            break;
        }
    }

    return 0;
}
