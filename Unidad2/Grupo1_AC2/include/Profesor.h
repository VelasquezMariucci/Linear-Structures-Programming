//
// Created by esvel on 25/10/2024.
//

#ifndef PROFESOR_H
#define PROFESOR_H

#include <fstream>
#include <list>
#include <memory>
#include <sstream>
#include <string>

#include "Aula.h"
#include "Estudiante.h"

class Aula;
class Estudiante;

class Profesor
{
private:
    std::string nombre;
    std::string ID;
    std::string username;
    std::string password;
    std::list<Estudiante*> estudiantes;
    Aula* aula;

public:
    /**
     * @brief Constructor de la clase Profesor.
     *
     * @param nombre Nombre del profesor.
     * @param ID Identificación del profesor.
     * @param username Nombre de usuario del profesor.
     * @param password Contraseña del profesor.
     * @param aula Puntero al aula asociada al profesor.
     */
    Profesor(const std::string& nombre, const std::string& ID, const std::string& username, const std::string& password,
             Aula* aulas);

    /**
     * @brief Obtiene el nombre del profesor.
     *
     * @return El nombre del profesor.
     */
    std::string obtenerNombre() const;

    /**
     * @brief Agrega un estudiante a la lista de estudiantes del profesor.
     *
     * @param estudiante Objeto Estudiante a agregar.
     */
    void agregarEstudiante(Estudiante estudiante);

    // Getters
    Aula getAula();
    std::string getUsername() const;
    std::string getPassword() const;
    std::string getID() const;
};

#endif // PROFESOR_H
