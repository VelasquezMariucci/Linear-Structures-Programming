//
// Created by Grupo1 on 20/10/2024.
//

#ifndef USUARIOADMINISTRADOR_H
#define USUARIOADMINISTRADOR_H

#include <vector>
#include <iostream>
#include <list>

#include "Estudiante.h"
#include "Profesor.h"

class Estudiante;
class Profesor;

class UsuarioAdministrador
{
private:
    std::string nombre;
    std::string ID;
    std::string username;
    std::string password;

public:
    /**
     * @brief Constructor de la clase UsuarioAdministrador.
     *
     * @param nombre Nombre del administrador.
     * @param ID Identificación del administrador.
     * @param username Nombre de usuario del administrador.
     * @param password Contraseña del administrador.
     */
    UsuarioAdministrador(const std::string& nombre, const std::string& ID, const std::string& username,
                         const std::string& password);

    //destructor para liberar memoria
    ~UsuarioAdministrador();

    std::string getUsername() const;

    std::string getPassword() const;

    /**
     * @brief Metodo para dar de alta un usuario.
     *
     * @param nombre Puntero al nombre del nuevo usuario.
     * @param apellido Puntero al apellido del nuevo usuario.
     */
    void altaUsuario(std::string* nombre, std::string* apellido);

    /**
     * @brief Metodo para dar de baja un usuario.
      *
     * @param ID Identificación del usuario a dar de baja.
     */
    void bajaUsuario(const std::string& ID);

    /**
     * @brief Metodo para mostrar todos los usuarios.
     *
     * @param listaAdministradores Lista de administradores.
     * @param listaProfesores Lista de profesores.
     * @param listaEstudiantes Lista de estudiantes.
     */
    void mostrarUsuarios(const std::list<UsuarioAdministrador>& listaAdministradores,
                         const std::list<Profesor>& listaProfesores,
                         const std::list<Estudiante>& listaEstudiantes);

    /**
     * @brief Metodo para eliminar un usuario por su ID.
     *
     * @param listaAdministradores Lista de administradores.
     * @param listaProfesores Lista de profesores.
     * @param listaEstudiantes Lista de estudiantes.
     * @param id ID del usuario a eliminar.
     */
    void eliminarUsuarioPorID(std::list<UsuarioAdministrador>& listaAdministradores,
                              std::list<Profesor>& listaProfesores,
                              std::list<Estudiante>& listaEstudiantes, const std::string& id);

    //getters
    std::string obtenerNombre() const;
    std::string getID() const;

    /**
     * @brief Metodo para crear un nuevo usuario administrador.
     *
     * @return Un objeto UsuarioAdministrador con los datos ingresados.
     */
    UsuarioAdministrador crearUsuarioAdministrador();

    /**
     * @brief Metodo para crear un nuevo profesor.
     *
     * @return Un objeto Profesor con los datos ingresados.
     */
    Profesor crearProfesor();

    /**
     * @brief Metodo para crear un nuevo estudiante.
     *
     * @return Un objeto Estudiante con los datos ingresados.
     */
    Estudiante crearEstudiante();
};

#endif // USUARIOADMINISTRADOR_H
