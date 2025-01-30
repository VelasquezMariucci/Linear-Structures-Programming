//
// Created by Ricky Vicente on 09/12/2024.
//

#include "Usuario.h"
#include <iostream>

Usuario::Usuario()
{
    nombre = "";
    password = "";
    contactos = nullptr;
}

// Constructor de Usuario
Usuario::Usuario(std::string nombre, std::string password)
{
    this->nombre = nombre;
    this->password = password;
    this->contactos = new ListaEnlazada<Contacto>();
}

std::string Usuario::getNombre()
{ // Obtener el nombre del usuario
    return nombre;
}

std::string Usuario::getPassword()
{ // Obtener la contraseña del usuario
    return password;
}

ListaEnlazada<Contacto>* Usuario::getContactos()
{ // Obtener la lista de contactos del usuario
    return contactos;
}

void Usuario::mostrarInformacion()
{ // Mostrar la información del usuario
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Password: " << password << std::endl;
    std::cout << "Contactos: " << std::endl;
    for (int i = 0; i < contactos->getSize(); i++)
    { // Bucle para recorrer la lista de contactos
        std::cout << contactos->getElement(i).getNombre() << std::endl; // Mostrar el nombre del contacto
    }
}

void Usuario::exportarContacto(Usuario* usuarioReceptor)
{ // Exportar los contactos de un usuario a otro
    ListaEnlazada<Contacto>* contactos = getContactos(); // Obtener la lista de contactos del usuario emisor
    ListaEnlazada<Contacto>* contactosReceptor = usuarioReceptor->getContactos(); // Obtener la lista de contactos del usuario receptor
    for (int i = 0; i < contactos->getSize(); i++)
    { // Bucle para recorrer la lista de contactos del usuario emisor
        Contacto contacto = contactos->getElement(i); // Obtener el contacto
        bool existe = false;
        for (int j = 0; j < contactosReceptor->getSize(); j++)
        { // Bucle para recorrer la lista de contactos del usuario receptor
            Contacto contactoReceptor = contactosReceptor->getElement(j); // Obtener el contacto
            if (contacto.getNombre() == contactoReceptor.getNombre() &&
                contacto.getApellido() == contactoReceptor.getApellido() &&
                contacto.getNumero() == contactoReceptor.getNumero())
            { // Si el contacto ya existe en la lista de contactos del usuario receptor
                existe = true;
            }
        }
        if (!existe)
        { // Si el contacto no existe en la lista de contactos del usuario receptor
            contactosReceptor->insert_Tail(contactos->getElement(i)); // Agregar el contacto a la lista de contactos del usuario receptor
            std::cout << contacto.getNombre() << " " << contacto.getApellido() <<
                " ha sido agnadido a la lista de Contactos del Usuario " << usuarioReceptor->getNombre() << std::endl; // Mostrar mensaje
        }
        else
        {
            std::cout << "El contacto " << contacto.getNombre() << " " << contacto.getApellido() <<
                " ya existe en la lista de contactos de " << usuarioReceptor->getNombre() << std::endl; // Mostrar mensaje
        }
    }
}

void Usuario::buscarContacto()
{
    bool exit = false;

    while (!exit)
    { // Bucle para buscar un contacto
        try
        {
            std::cout << "---- Buscar Contacto ----" << std::endl;
            std::cout << "0) Salir." << std::endl;
            std::cout << "1) Buscar por nombre." << std::endl;
            std::cout << "2) Buscar por numero." << std::endl;

            std::string userInput;
            std::cin >> userInput;

            switch (stoi(userInput))
            { // Switch para buscar un contacto
            case 0:
                {
                    exit = true; // Salir del bucle
                    break;
                }
            case 1:
                {
                    std::cout << "Ingresa el nombre a buscar: ";
                    std::string nombre;
                    std::cin >> nombre;

                    bool found = false;
                    for (int i = 0; i < contactos->getSize(); i++)
                    { // Bucle para recorrer la lista de contactos
                        Contacto contacto = contactos->getElement(i); // Obtener el contacto
                        if (contacto.getNombre() == nombre)
                        { // Si el nombre del contacto coincide
                            found = true; // Cambiar el valor de found
                            std::cout << "Contacto encontrado: "
                                << contacto.getNombre() << " "
                                << contacto.getApellido() << ", Numero: "
                                << contacto.getNumero() << std::endl; // Mostrar el contacto
                            i = contactos->getSize(); // Salir del bucle
                        }
                    }

                    if (!found)
                    { // Si no se ha encontrado el contacto
                        std::cout << "No se encontro un contacto con ese nombre." << std::endl;
                    }
                    break;
                }

            case 2:
                {
                    std::cout << "Ingresa el numero a buscar: ";
                    long long numero;
                    std::cin >> numero;

                    bool found = false;
                    for (int i = 0; i < contactos->getSize(); i++)
                    { // Bucle para recorrer la lista de contactos
                        Contacto contacto = contactos->getElement(i);
                        if (contacto.getNumero() == numero)
                        { // Si el número del contacto coincide
                            found = true; // Cambiar el valor de found
                            std::cout << "Contacto encontrado: "
                                << contacto.getNombre() << " "
                                << contacto.getApellido() << ", Numero: "
                                << contacto.getNumero() << std::endl; // Mostrar el contacto
                            i = contactos->getSize(); // Salir del bucle
                        }
                    }

                    if (!found)
                    { // Si no se ha encontrado el contacto
                        std::cout << "No se encontro un contacto con ese numero." << std::endl;
                    }
                    break;
                }
            default: // Opción no válida
                std::cout << "Opcion no valida. Intenta de nuevo." << std::endl;
            }
        }
        catch (const std::exception& e)
        { // Capturar excepción
            std::cerr << "Excepcion: " << e.what() << std::endl;
        }
    }
}

/**
 * @brief Función para modificar un contacto del usuario.
 * Permite al usuario modificar un contacto buscando por nombre.
 *
 * @param nombre Nombre del contacto a modificar.
 * @param nuevoNombre Nuevo nombre del contacto.
 * @param nuevoApellido Nuevo apellido del contacto.
 * @param nuevoNumero Nuevo número del contacto.
 */
void Usuario::modificarContacto(const std::string& nombre, const std::string& nuevoNombre, const std::string& nuevoApellido, long long nuevoNumero) const {
    for (int i = 0; i < contactos->getSize(); i++){ // Bucle para recorrer la lista de contactos
        Contacto& contacto = contactos->getElemento(i);
        if (contacto.getNombre() == nombre) { // Si el nombre del contacto coincide
            contacto.setNombre(nuevoNombre); // Cambiar el nombre del contacto
            contacto.setApellido(nuevoApellido); // Cambiar el apellido del contacto
            contacto.setNumero(nuevoNumero); // Cambiar el número del contacto
            std::cout << "Contacto modificado exitosamente." << std::endl;
            return;
        }
    }
    std::cout << "Contacto no encontrado." << std::endl;
}

/**
 * @brief Función para mostrar la información de todos los contactos del usuario.
 * Muestra el nombre, apellido y número de todos los contactos del usuario.
 */

void Usuario::mostrarContactos() const {
    std::cout << "Contactos de " << nombre << ":" << std::endl;
    for (int i = 0; i < contactos->getSize(); i++) // Bucle para recorrer la lista de contactos
    {
        Contacto contacto = contactos->getElement(i); // Obtener el contacto
        std::cout << "Nombre: " << contacto.getNombre() << ", Apellido: " << contacto.getApellido() << ", Numero: " << contacto.getNumero() << std::endl;
    }
}

/**
 * @brief Función para añadir un contacto a un usuario.
 * Permite al usuario añadir un contacto nuevo proporcionando nombre, apellido y número.
 */

void Usuario::agregarContacto() const {
    std::string nombre, apellido;
    long long telefono;

    std::cout << "Ingrese el nombre del contacto: ";
    std::cin >> nombre;
    std::cout << "Ingrese el apellido del contacto: ";
    std::cin >> apellido;
    std::cout << "Ingrese el numero de telefono del contacto: ";
    std::cin >> telefono;

    bool existe = false; // Variable para saber si el contacto ya existe
    for (int i = 0; i < contactos->getSize() && !existe; i++) { // Bucle para buscar el contacto
        Contacto contacto = contactos->getElement(i); // Obtener el contacto
        if (contacto.getNombre() == nombre &&
            contacto.getApellido() == apellido &&
            contacto.getNumero() == telefono) { // Si el contacto ya existe
            existe = true; // Cambiar el valor de la variable existe
            }
    }

    if (existe) { // Si el contacto ya existe
        std::cout << "El contacto ya existe en tu lista de contactos." << std::endl;
    } else {
        Contacto nuevoContacto(nombre, apellido, telefono); // Crear un nuevo contacto
        contactos->insert_Tail(nuevoContacto); // Agregar el contacto a la lista de contactos
        std::cout << "Contacto anadido exitosamente." << std::endl;
    }
}

/**
 * @brief Función para eliminar un contacto de un usuario.
 * Permite al usuario eliminar un contacto buscando por nombre.
 */
void Usuario::eliminarContacto() const {
    std::string nombre;
    std::cout << "Ingrese el nombre del contacto a eliminar: ";
    std::cin >> nombre;

    bool encontrado = false; // Variable para saber si se ha encontrado el contacto
    int index = -1; // Variable para guardar el índice del contacto a eliminar

    for (int i = 0; i < contactos->getSize() && !encontrado; ++i) { // Bucle para buscar el contacto
        if (contactos->getElement(i).getNombre() == nombre) { // Si el nombre del contacto coincide
            index = i; // Guardar el índice del contacto
            encontrado = true; // Cambiar el valor de la variable encontrado
        }
    }

    if (encontrado) { // Si se ha encontrado el contacto
        contactos->remove(index); // Eliminar el contacto
        std::cout << "Contacto eliminado exitosamente." << std::endl;
    } else {
        std::cout << "Contacto no encontrado." << std::endl;
    }
}
