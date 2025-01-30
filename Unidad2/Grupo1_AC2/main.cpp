#include <iostream>

#include "Aula.h"
#include "CalculadoraAvanzada.h"
#include "GestorArchivos.h"
#include "JuegoAdivinar.h"
#include "MochilaVirtual.h"
#include "UsuarioAdministrador.h"


/**
 * READ ME!!!
 *
 * Para la demostracion de uso de la aplicacion usa los siguientes perfiles al hacer login.
 *
 * Administrador: username = admin1, password = 1234.
 * Profesor: username = juan, password = 1234.
 * Estudiante: username = carlos, password = 1234
 *
 * Estos corresponden con los objetos que creamos al inicializar el main().
 */

/**
 * @Brief Aplicacion con funcionalidades para estudiantes
 *
 * @param estudiante constant Estudiante address estudiante
 */
void Aplicacion(const Estudiante& estudiante)
{
    std::string userInput;

    while (userInput != "0")
    {
        std::cout << "----- Bienvenido " << estudiante.obtenerNombre() << " -----" << std::endl;
        std::cout << "Recursos: " << std::endl;
        std::cout << "0) Salir." << std::endl;
        std::cout << "1) Mochila Digital." << std::endl;
        std::cout << "2) Calculadora Avanzada. " << std::endl;
        std::cout << "3) Juego." << std::endl;
        std::cout << "Escoge un recurso: " << std::endl;
        std::cin >> userInput;

        switch (stoi(userInput))
        {
        case 0:
            {
                std::cout << "Saliendo de aplicacion" << std::endl;
            }
        case 1:
            {
                MochilaVirtual* miMochila = new MochilaVirtual();
                break;
            }
        case 2:
            {
                CalculadoraAvanzada* calculadora = new CalculadoraAvanzada();
                calculadora->menu();
                break;
            }
        case 3:
            {
                auto* juego = new JuegoAdivinar();
                juego->juegoAdivinar();
            }
        default:
            std::cout << "Opcion no válida." << std::endl;
        }
    }
}

/**
 * @Brief Aplicacion con funcionalidades para profesores
 *
 * @param profesor referencia al profesor.
 */
void Aplicacion(Profesor profesor)
{
    std::string userInput;

    while (userInput != "0")
    {
        std::cout << "----- Bienvenido " << profesor.obtenerNombre() << " -----" << std::endl;
        std::cout << "Recursos: " << std::endl;
        std::cout << "0) salir." << std::endl;
        std::cout << "1) Ver Estudiante en mi Aula." << std::endl;
        std::cout << "2) Ver Informacion de mi Aula. " << std::endl;
        std::cout << "Escoge un recurso: " << std::endl;
        std::cin >> userInput;

        switch (stoi(userInput))
        {
        case 0:
            {
                std::cout << "Saliendo de aplicacion" << std::endl;
            }
        case 1:
            {
                profesor.getAula().mostrarEstudiantes();

                break;
            }
        case 2:
            {
                profesor.getAula().mostrarAula();

                break;
            }
        default:
            std::cout << "Opción no válida." << std::endl;
        }
    }
}

/**
 * @Brief Aplicacion con funcionalidades para Administradores.
 *
 * @param admin UsuarioAdministrador.
 * @param listaAdministradores acceso a todos los administradores.
 * @param listaProfesores acceso a todos los profesores.
 * @param listaEstudiantes acceso a todos los estudiantes.
 */
void Aplicacion(UsuarioAdministrador admin,
                std::list<UsuarioAdministrador>& listaAdministradores, std::list<Profesor>& listaProfesores,
                std::list<Estudiante>& listaEstudiantes)
{
    std::string userInput;

    while (userInput != "0")
    {
        std::cout << "----- Bienvenido " << admin.obtenerNombre() << " -----" << std::endl;
        std::cout << "Recursos: " << std::endl;
        std::cout << "0) salir." << std::endl;
        std::cout << "1) Ver todos los Usuarios." << std::endl;
        std::cout << "2) Crear Usuario. " << std::endl;
        std::cout << "3) Eliminar Usuario. " << std::endl;
        std::cout << "Escoge un recurso: " << std::endl;
        std::cin >> userInput;

        switch (stoi(userInput))
        {
        case 0:
            {
                std::cout << "Saliendo de aplicacion" << std::endl;
            }
        case 1:
            {
                admin.mostrarUsuarios(listaAdministradores, listaProfesores, listaEstudiantes);

                break;
            }
        case 2:
            {
                std::cout << "Que tipo de Usuario deseas crear?: " << std::endl;
                std::cout << "1) Administrador. " << std::endl;
                std::cout << "2) Profesor. " << std::endl;
                std::cout << "3) Estudiante. " << std::endl;
                std::cin >> userInput;

                switch (stoi(userInput))
                {
                case 1:
                    {
                        UsuarioAdministrador adminNuevo = admin.crearUsuarioAdministrador();

                        listaAdministradores.push_back(adminNuevo);
                    }
                case 2:
                    {
                        Profesor profeNuevo = admin.crearProfesor();

                        listaProfesores.push_back(profeNuevo);
                    }
                case 3:
                    {
                        Estudiante estudianteNuevo = admin.crearEstudiante();

                        listaEstudiantes.push_back(estudianteNuevo);
                    }
                default:
                    std::cout << "Opción no válida." << std::endl;
                }
            }
        case 3:
            {
                std::cout << "Ingresa el ID exacto del Usuario que deseas eliminar: ";
                std::cin >> userInput;

                admin.eliminarUsuarioPorID(listaAdministradores, listaProfesores, listaEstudiantes, userInput);
                break;
            }
        default:
            std::cout << "Opción no válida." << std::endl;
        }
    }
}

/**
 * @Brief Login de cualquier Usuario.
 *
 * @param listaAdministradores acceso para buscar todos los administradores.
 * @param listaProfesores acceso para buscar todos los profesores.
 * @param listaEstudiantes acceso para buscar todos los estudiantes.
 */
void login(std::list<Profesor>& listaProfesores, std::list<Estudiante>& listaEstudiantes,
           std::list<UsuarioAdministrador>& listaAdministradores)
{
    bool loginSuccesful = false;
    std::string username;
    std::string password;

    while (!loginSuccesful)
    {
        std::cout << "Username: ";
        std::cin >> username;
        std::cout << "Password: ";
        std::cin >> password;

        // Buscar en lista de estudiantes
        for (auto& estudiante : listaEstudiantes)
        {
            if (estudiante.getUsername() == username && estudiante.getPassword() == password)
            {
                loginSuccesful = true;
                Aplicacion(estudiante); // Llama a Aplicacion con Estudiante
                return;
            }
        }

        // Buscar en lista de profesores
        for (auto& profesor : listaProfesores)
        {
            if (profesor.getUsername() == username && profesor.getPassword() == password)
            {
                loginSuccesful = true;
                Aplicacion(profesor); // Llama a Aplicacion con Profesor
                return;
            }
        }

        // Buscar en lista de admis
        for (auto& admin : listaAdministradores)
        {
            if (admin.getUsername() == username && admin.getPassword() == password)
            {
                loginSuccesful = true;
                Aplicacion(admin, listaAdministradores, listaProfesores, listaEstudiantes);
                return;
            }
        }

        std::cout << "Login errado. Intenta de nuevo." << std::endl;
    }
}

int main()
{
    // Creacion de un admin
    auto* admin1 = new UsuarioAdministrador("Andrea Pinzon", "13576", "admin1", "1234");

    // Crear una lista de administradores y añadir nuestro administrador.
    std::list<UsuarioAdministrador> listaAdministradores;
    listaAdministradores.push_back(*admin1);

    // Crear un aula
    auto* aula1 = new Aula("Aula A", nullptr);

    // Crear un profesor y asignarle al aula este.
    auto* profe1 = new Profesor("Profe Juan", "44897", "juan", "1234", aula1);
    aula1->profesor = profe1;

    // Crear una lista de profesores y añadir nuestro profesor.
    std::list<Profesor> listaProfesores;
    listaProfesores.push_back(*profe1);

    // Crear estudiantes como punteros a un objeto.
    auto* estudiante1 = new Estudiante("Carlos", "89213", "carlos", "1234", profe1);
    auto* estudiante2 = new Estudiante("Mario", "95639", "mario", "1234", profe1);
    auto* estudiante3 = new Estudiante("Juana", "86396", "juana", "1234", profe1);

    // Asignarlos a nuestra aula.
    aula1->agregarEstudiante(*estudiante1);
    aula1->agregarEstudiante(*estudiante2);
    aula1->agregarEstudiante(*estudiante3);

    // crear una lista de estudiantes y añadir nuestros estudiantes.
    std::list<Estudiante> listaEstudiantes;
    listaEstudiantes.push_back(*estudiante1);
    listaEstudiantes.push_back(*estudiante2);
    listaEstudiantes.push_back(*estudiante3);

    // Llamada al login para comenzar funcionalidad de la aplicacion.
    login(listaProfesores, listaEstudiantes, listaAdministradores);

    delete estudiante1;
    delete estudiante2;
    delete estudiante3;
    delete profe1;
    delete aula1;

    return 0; // No need to delete anything manually; smart pointers handle cleanup
}
