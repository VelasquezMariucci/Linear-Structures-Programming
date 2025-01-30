//
// Created by esvel on 25/10/2024.
//

#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <iostream>
#include <string>
#include <vector>

#include "Profesor.h"

class Profesor; // Forward declaration
class Aula; // Forward declaration (if needed)

class Estudiante
{
private:
    std::string nombre;
    std::string ID;
    std::string username;
    std::string password;
    Profesor* profesor;
    float notas[3];

public:
    /**
     * @brief Constructor de la clase Estudiante.
     *
     * Inicializa una instancia de Estudiante con los datos proporcionados, incluyendo el nombre,
     * ID, nombre de usuario, contraseña, y el profesor asignado. Luego, llama al cargarNotas()
     * para cargar las notas del archivo correspondiente.
     *
     * @param nombre Nombre completo del estudiante.
     * @param ID Identificador único.
     * @param username Nombre de usuario del estudiante.
     * @param password Contraseña.
     * @param profesor Puntero al profesor unico asociado con el estudiante.
     */
    Estudiante(const std::string& nombre, const std::string& ID, const std::string& username,
               const std::string& password, Profesor* profesor);

    // Setters
    void setProfesor(std::shared_ptr<Profesor> profesor);

    /**
     * @brief Muestra las notas del estudiante en distintas materias.
     *
     * Despliega en consola las notas del estudiante en las materias de Matemáticas, Ingles e Historia.
     */
    void mostrarNotas() const;

    /**
     * @brief Carga las notas del estudiante desde un archivo.
     *
     * Busca las notas en el archivo  "notas.txt" y, si encuentra el nombre del estudiante,
     * carga sus calificaciones en tres materias. Las notas están asociadas al primer nombre del estudiante.
     *
     * @return void Si el archivo no se encuentra o no se hallan notas.
     */
    void cargarNotas();

    // Getters
    std::string obtenerNombre() const;

    std::string getUsername() const;

    std::string getPassword() const;

    std::string getID() const;
};

#endif // ESTUDIANTE_H
