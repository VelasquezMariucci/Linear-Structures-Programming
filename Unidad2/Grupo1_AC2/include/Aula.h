//
// Created by esvel on 25/10/2024.
//

#ifndef AULA_H
#define AULA_H
#include <list>
#include <string>

#include "Estudiante.h"
#include "Profesor.h"

class Profesor;
class Estudiante;

class Aula
{
public:
    std::string ID;
    Profesor* profesor;
    std::list<Estudiante*> estudiantes;

    /**
    * @brief Constructor de la clase Aula.
    *
    * Inicializa una instancia de Aula con un identificador y un puntero a un objeto Profesor.
    *
    * @param ID Identificador del aula.
    * @param profesor Puntero al profesor asignado a esta aula.
    */
    Aula(const std::string ID, Profesor* profesor);

    /**
     * @brief Agrega un estudiante a la lista de estudiantes del aula.
     *
     * Añade el estudiante dado al final de la lista de estudiantes. Si el estudiante
     * ya está en la lista, no se realiza la adición.
     *
     * @param estudiante Estudiante a añadir.
     * @return void en caso de error.
     */
    void agregarEstudiante(Estudiante estudiante);

    /**
     * @brief Agrega un estudiante en una posición específica de la lista.
     *
     * Inserta el estudiante en el indice dentro de la lista de estudiantes.
     * Si el índice no es válido, muestra un mensaje de error.
     *
     * @param estudiante Objeto `Estudiante` a añadir.
     * @param indice Posición en la lista donde añadir el estudiante.
     * @return void el índice es inválido.
     */
    void agregarEstudiante(Estudiante estudiante, int indice);

    /**
     * @brief Muestra los estudiantes y sus notas en el aula.
     *
     * Recorre la lista de estudiantes y muestra en consola los nombres y notas
     * de cada estudiante.
     *
     * @return void si no modifica el Aula.
     */
    void mostrarEstudiantes();

    /**
     * @brief Muestra un resumen del aula.
     *
     * Despliega el ID del aula, el número total de estudiantes, y el nombre
     * de cada estudiante en la consola.
     *
     * @return void No modifica el aula.
     */
    void mostrarAula();

private:
};

#endif //AULA_H
