//
// Created by Ricky Vicente on 09/12/2024.
//

#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include "ListaEnlazada.h"
#include "Contacto.h"

/**
 * @brief Clase Usuario que gestiona información y acciones de los usuarios.
 *
 * La clase permite manejar atributos de los usuarios como nombre, contraseña y contactos,
 * además de realizar acciones como exportar contactos, mostrar información y gestionar
 * un menú interactivo.
 */
class Usuario
{
private:
    std::string nombre;
    std::string password;
    ListaEnlazada<Contacto>* contactos;

public:
    /**
     * @brief Constructor por defecto de la clase Usuario.
     *
     * Inicializa los atributos nombre y password como cadenas vacías,
     * y el puntero contactos como nullptr.
     */
    Usuario();

    /**
     * @brief Constructor parametrizado de la clase Usuario.
     *
     * @param nombre Nombre del usuario.
     * @param password Contraseña del usuario.
     *
     * Inicializa los atributos nombre y password con los valores dados,
     * y crea una lista enlazada vacía de contactos.
     */
    Usuario(std::string nombre, std::string password);

    /**
     * @brief Obtiene el nombre del usuario.
     *
     * @return Nombre del usuario.
     */
    std::string getNombre();

    /**
     * @brief Obtiene la contraseña del usuario.
     *
     * @return Contraseña del usuario.
     */
    std::string getPassword();

    /**
     * @brief Obtiene la lista de contactos del usuario.
     *
     * @return Puntero a la lista de contactos del usuario.
     */
    ListaEnlazada<Contacto>* getContactos();

    /**
     * @brief Muestra la información del usuario por consola.
     *
     * Incluye el nombre, la contraseña y los contactos.
     */
    void mostrarInformacion();

    /**
     * @brief Exporta contactos a otro usuario.
     *
     * @param usuarioReceptor Usuario al que se exportarán los contactos.
     *
     * Agrega contactos únicos del usuario actual a la lista de contactos del usuario receptor.
     */
    void exportarContacto(Usuario* usuarioReceptor);

    /**
     * @brief Permite buscar un contacto por nombre o número.
     *
     * El usuario puede salir o realizar búsquedas según el criterio elegido.
     */
    void buscarContacto();

 /**
 * @brief Modifica un contacto existente.
 *
 * @param nombre Nombre del contacto a modificar.
 * @param nuevoNombre Nuevo nombre del contacto.
 * @param nuevoApellido Nuevo apellido del contacto.
 * @param nuevoNumero Nuevo número del contacto.
 */
 void modificarContacto(const std::string& nombre, const std::string& nuevoNombre, const std::string& nuevoApellido, long long nuevoNumero) const;

 /**
  * @brief Muestra la información de todos los contactos del usuario.
  */
 void mostrarContactos() const;

    /**
    * @brief Elimina un contacto a la lista de contactos del usuario.
    */
 void eliminarContacto() const;

    /**
    * @brief Añade un contacto a la lista de contactos del usuario.
    */
 void agregarContacto() const;

};

#endif //USUARIO_H
