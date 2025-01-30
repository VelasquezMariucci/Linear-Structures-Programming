//
// Created by Grupo1 on 22/10/2024.
//

#ifndef GESTORARCHIVOS_H
#define GESTORARCHIVOS_H
#include <filesystem>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>

/**
 * @Brief Clase que maneja utilidades para ficheros.
 *
 * Esta clase guarda informacion en un vector de paths.
 */
class GestorArchivos
{
public:
    /**
    * @brief Constructor para inicializar el gestor de archivos.
    *
    * Inicializa el vector de paths de archivos en el directorio especificado
    * en direccion. Si ocurre un error durante la inicializacion, muestra el
    * mensaje de error en consola.
    *
    * @param direccion Ruta del directorio a explorar.
    */
    GestorArchivos(const std::string& direccion);


    ~GestorArchivos() = default;

    /**
     * @brief Muestra un listado de archivos en el directorio.
     *
     * Itera sobre el vector de paths y muestra la primera línea de cada archivo en la consola.
     * La lista se muestra con un índice correspondiente a cada archivo.
     */
    void mostrarListadoArchivos();

    /**
    * @Brief mostrar contenido de un archivo por el indice.
    *
    * Esta funcion encuentra por indice el archivo de un vector de paths alimentado por la ruta
    * "../data/Ficheros".
    *
    * @param indice Int indice de busqueda dado por el usuario.
    */
    void mostrarArchivo(int indice);

    /**
    * @brief Muestra el contenido de un archivo seleccionado por índice.
    *
    * Esta función abre y muestra el contenido del archivo en la posición indicada
    * en pathArchivos.
    *
    * @param indice Índice del archivo a mostrar, dado por el usuario.
    * @return void si el índice es inválido.
    */
    void eliminarArchivo(int indice);

    /**
    * @brief Elimina un archivo del directorio y del vector.
    *
    * Elimina el archivo en el índice especificado en el vector pathArchivos.
    * Si la eliminación es exitosa, lo elimina también del vector.
    *
    * @param indice Índice del archivo a eliminar.
    * @return void si el índice es inválido.
    */
    void cargarArchivo(std::string ubicacion);

private:
    const std::string direccion;

    std::vector<std::filesystem::path> pathArchivos;

    /**
     * @brief Inicializa el vector de paths de archivos en el directorio.
     *
     * Esta función recorre el directorio direccion, añadiendo los archivos ".txt"
     * al vector pathArchivos. Muestra un mensaje de error si no puede abrir algún archivo.
     */
    void init();
};


#endif //GESTORARCHIVOS_H
