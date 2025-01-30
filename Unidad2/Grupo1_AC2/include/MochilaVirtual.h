//
// Created by esvel on 24/10/2024.
//

#ifndef MOCHILAVIRTUAL_H
#define MOCHILAVIRTUAL_H

#include "GestorArchivos.h"

#include <iostream>

  /**
   * @brief Clase para lanzar funciones de GestorArchivos.
   *
   * Crea todo el sistema de entrada para el usuario que luego lanza las funciones.
   */
class MochilaVirtual
{
public:
    /**
    * @brief Constructor de la clase MochilaVirtual.
    *
    * Inicializa la aplicación ejecutando el init() que
    * da el menú de opciones para gestionar archivos.
    */
    MochilaVirtual();

private:
    /**
    * @brief funcion para iniciar el menú interactivo.
    *
    * Este metodo da un menú para que el usuario pueda listar, abrir, eliminar, o cargar archivos en la
    * Mochila Virtual, gestionados a través de GestorArchivos.
    *
    * @return void  cuando el usuario selecciona salida.
    */
    void init();
};


#endif //MOCHILAVIRTUAL_H
