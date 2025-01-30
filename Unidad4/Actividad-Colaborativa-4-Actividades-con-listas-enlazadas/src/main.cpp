#include <iostream>
#include "ListaEnlazada.h"
#include "Contacto.h"
#include "Usuario.h"

// Declaración previa de las funciones que se usan más adelante
void agregarContacto(Usuario& usuario);
void eliminarContacto(Usuario& usuario);

/**
 * @brief Función para mostrar el menú de contactos de un usuario.
 * Permite al usuario agregar o eliminar contactos.
 */
void menuUsuario(Usuario& usuario, ListaEnlazada<Usuario>* usuarios)
{
    bool continuar = true; // Variable para saber si se debe continuar

    while (continuar) { // Mientras se deba continuar
        int opcion; // Variable para la opción seleccionada
        std::cout << "\nMenu de Contactos" << std::endl;
        std::cout << "1. Agregar Contacto" << std::endl;
        std::cout << "2. Eliminar Contacto" << std::endl;
        std::cout << "3. Editar Contacto" << std::endl;
        std::cout << "4. Mostrar Contactos" << std::endl;
        std::cout << "5. Exportar Contactos" << std::endl;
        std::cout << "6. Salir" << std::endl;
        std::cout << "Elige una opcion: ";
        std::cin >> opcion; // Obtener la opción seleccionada

        switch (opcion) { // Según la opción seleccionada
            case 1: // Agregar contacto
                usuario.agregarContacto();
            break;
            case 2: // Eliminar contacto
                usuario.eliminarContacto();
            break;
            case 3:
            { //Modificar contacto
                std::string nombre, nuevoNombre, nuevoApellido;
                long long nuevoNumero;
                std::cout << "Ingresa el nombre del contacto a modificar: ";
                std::cin >> nombre; //Nombre del contacto a modificar
                std::cout << "Ingresa el nuevo nombre: ";
                std::cin >> nuevoNombre; //Nuevo nombre del contacto
                std::cout << "Ingresa el nuevo apellido: ";
                std::cin >> nuevoApellido; //Nuevo apellido del contacto
                std::cout << "Ingresa el nuevo numero: ";
                std::cin >> nuevoNumero; //Nuevo numero del contacto
                usuario.modificarContacto(nombre, nuevoNombre, nuevoApellido, nuevoNumero); //Modifica contacto
                break;
            }
            case 4: // Mostrar contactos
                usuario.mostrarContactos();
            break;
            case 5:
            {
                std::string nombre;
                std::cout << "Ingrese el nombre del usuario receptor: " << std::endl;
                std::cin >> nombre;
                bool usuarioEncontrado = false; // Variable para saber si se ha encontrado el usuario
                for(int i = 0; i < usuarios->getSize(); i++) { // Recorrer la lista de usuarios
                    Usuario user = usuarios->getElement(i); // Obtener el usuario en la posición i
                    if(usuarios->getElement(i).getNombre() == nombre) { // Comparar nombres
                        usuario.exportarContacto(&user); // Exportar contactos
                        usuarioEncontrado = true; // Usuario encontrado
                        break;
                    }
                }
                if(!usuarioEncontrado) { // Si no se ha encontrado el usuario
                    std::cout << "Usuario no encontrado" << std::endl;
                }
                break;
            }
            case 6:
                continuar = false;  // Salir
            std::cout << "Saliendo..." << std::endl;
            break;
            default: // Opción no válida
                std::cout << "Opción no válida. Intenta de nuevo." << std::endl;
            break;
        }
    }
}

/**
 * @brief Función que añade el paso de seguridad de Log In para los usuarios
 * del sistema. Compara el nombre de usuario y la contraseña con los datos de
 * los usuarios registrados en la lista enlazada.
 *
 * @param usuarios Lista enlazada de usuarios
 */
void logIn(ListaEnlazada<Usuario>* usuarios) {
    bool isLogged = false;

    while (!isLogged) { // Mientras no se haya iniciado sesión
        try {
            std::string username;
            std::cout << "Username: ";
            std::cin >> username; // Obtener el nombre de usuario

            std::string password;
            std::cout << "Password: ";
            std::cin >> password; // Obtener la contraseña

            bool isUsuario = false; // Variable para saber si el usuario existe
            for (int i = 0; i < usuarios->getSize(); i++) { // Recorrer la lista de usuarios
                Usuario user = usuarios->getElement(i); // Obtener el usuario en la posición i
                if (username == user.getNombre() && password == user.getPassword()) { // Comparar datos
                    menuUsuario(user, usuarios);
                    isUsuario = true; // Usuario encontrado
                    isLogged = true; // Iniciado sesión
                }
            }

            if (!isUsuario) { // Si no se encontró el usuario
                std::cout << "Usuario no encontrado. Intenta de nuevo." << std::endl;
            }
        } catch (const std::exception& e) { // Capturar excepciones
            std::cerr << "Excepcion: " << e.what() << std::endl;
        }
    }
}



int main()
{
    ListaEnlazada<Usuario>* usuarios = new ListaEnlazada<Usuario>();

    // Creación de contactos para los usuarios
    Contacto* contacto1_1 = new Contacto("Ana", "Fernandez", 611234567);
    Contacto* contacto1_2 = new Contacto("Carlos", "Gomez", 622345678);
    Contacto* contacto1_3 = new Contacto("Elena", "Sanchez", 633456789);
    Contacto* contacto1_4 = new Contacto("Javier", "Martinez", 644567890);
    Contacto* contacto1_5 = new Contacto("Lucia", "Perez", 655678901);

    Contacto* contacto2_1 = contacto1_1;
    Contacto* contacto2_2 = new Contacto("Pablo", "Rodriguez", 677890123);
    Contacto* contacto2_3 = new Contacto("Sofia", "Garcia", 688901234);
    Contacto* contacto2_4 = new Contacto("Diego", "Hernandez", 699012345);
    Contacto* contacto2_5 = new Contacto("Claudia", "Alonso", 600123456);
    Contacto* contacto2_6 = contacto1_2;

    Contacto* contacto3_1 = new Contacto("Isabel", "Torres", 620345678);
    Contacto* contacto3_2 = contacto2_2;
    Contacto* contacto3_3 = contacto2_4;
    Contacto* contacto3_4 = new Contacto("Sergio", "Navarro", 650678901);
    Contacto* contacto3_5 = contacto2_5;
    Contacto* contacto3_6 = new Contacto("Alberto", "Castro", 670890123);
    Contacto* contacto3_7 = new Contacto("Marta", "Dominguez", 680901234);

    // Creación de los usuarios y asignación de contactos
    Usuario* ricardo = new Usuario("Ricardo", "Rick_Vicente");
    ricardo->getContactos()->insert_Tail(*contacto1_1);
    ricardo->getContactos()->insert_Head(*contacto1_2);
    ricardo->getContactos()->insert_Head(*contacto1_3);
    ricardo->getContactos()->insert_Head(*contacto1_4);
    ricardo->getContactos()->insert_Head(*contacto1_5);

    Usuario* esteban = new Usuario("Esteban", "1234");
    esteban->getContactos()->insert_Tail(*contacto2_1);
    esteban->getContactos()->insert_Tail(*contacto2_2);
    esteban->getContactos()->insert_Tail(*contacto2_3);
    esteban->getContactos()->insert_Tail(*contacto2_4);
    esteban->getContactos()->insert_Tail(*contacto2_5);
    esteban->getContactos()->insert_Tail(*contacto2_6);

    Usuario* german = new Usuario("German", "germans16");
    german->getContactos()->insert_Tail(*contacto3_1);
    german->getContactos()->insert_Tail(*contacto3_2);
    german->getContactos()->insert_Tail(*contacto3_3);
    german->getContactos()->insert_Tail(*contacto3_4);
    german->getContactos()->insert_Tail(*contacto3_5);
    german->getContactos()->insert_Tail(*contacto3_6);
    german->getContactos()->insert_Tail(*contacto3_7);

    // Agregar usuario "Paula" a German (nuevos contactos que hemos creado)
    Contacto* contacto3_8 = new Contacto("Paula", "Gonzalez", 690123456);
    german->getContactos()->insert_Tail(*contacto3_8);

    // Insertar usuarios en la lista
    usuarios->insert_Head(*ricardo);
    usuarios->insert_Tail(*esteban);
    usuarios->insert_Head(*german);

    // Log in
    logIn(usuarios);

    return 0;
}
