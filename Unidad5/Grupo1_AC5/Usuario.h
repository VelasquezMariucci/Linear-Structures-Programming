//
// Created by Ricky Vicente on 21/12/2024.
//

//
// Created by Ricky Vicente on 21/12/2024.
//

#ifndef USUARIO_H
#define USUARIO_H
#include <string>

#include "ListaEnlazada.h"

/**
 * @brief Enum de tipos de Usuarios
 */
enum tiposUsuarios { Regular, Supervisor, Analista};

struct Actividad {
    std::string dueño;
    std::string descripcion;
    std::string fecha;  // Nuevo campo para la fecha

    Actividad(const std::string& dueño, const std::string& descripcion, const std::string& fecha)
        : dueño(dueño), descripcion(descripcion), fecha(fecha) {}

    // Método para acceder a la descripción
    std::string getDescripcion() const { return descripcion; }  // Asegúrate de tener este getter

    // Método para acceder a la fecha
    std::string getFecha() const { return fecha; }

    friend std::ostream& operator<<(std::ostream& os, const Actividad& actividad) {
        os << "Usuario: " << actividad.dueño << ", Descripción: " << actividad.descripcion << ", Fecha: " << actividad.fecha;
        return os;
    }
};

/**
 * @brief Clase Usuario que gestiona información y acciones de los usuarios.
 */
class Usuario
{
private:
    std::string nombre;
    std::string password;
    long int telefono;
    tiposUsuarios tipo;

    // Usar puntero para la lista de actividades
    ListaEnlazada<Actividad>* actividades = new ListaEnlazada<Actividad>();

public:
    /**
     * @brief Constructor por defecto.
     */
    Usuario();
    /**
     * @brief Constructor parametrizado.
     * @param nombre Nombre del usuario.
     * @param password Contraseña del usuario.
     * @param telefono Teléfono del usuario.
     * @param tipo Tipo de usuario.
     */
    Usuario(std::string nombre, std::string password, long int telefono, tiposUsuarios tipo);
    /**
     * @brief Obtiene el nombre del usuario.
     * @return Nombre del usuario.
     */
    std::string getNombre();
    /**
     * @brief Obtiene la password del usuario.
     * @return Password del usuario.
     */
    std::string getPassword();
    /**
      * @brief Obtiene el teléfono.
      * @return Teléfono del usuario.
      */
    long int getTelefono();
    /**
      * @brief Obtiene el Tipo.
      * @return Tipo de usuario.
      */
    tiposUsuarios getTipoUsuario();


    ListaEnlazada<Actividad>* getActividades() {
        return actividades;
    }

    // Función para agregar actividad
    void agregarActividad(const std::string& desc, const std::string& fecha);





};

#endif //USUARIO_H
