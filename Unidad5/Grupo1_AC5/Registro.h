//
// Created by Ricky Vicente on 21/12/2024.
//

#ifndef REGISTRO_H
#define REGISTRO_H

#include <iostream>
/**
 * @brief Clase Registro que gestiona el acceso de los Usuarios.
 */
class Registro {
private:
    std::string nombreUsuario;
    std::string hora;
    Registro* siguienteAcceso;  // Puntero al siguiente acceso

public:
    /**
     * @brief Constructor por defecto.
     */
    Registro();
    /**
     * @brief Constructor parametrizado.
     * @param nombreUsuario Nombre del Usuario del Registro.
     * @param hora Hora del Registro.
     */
    Registro(std::string nombreUsuario, std::string hora);

     /**
     * @brief Obtiene el nombre del usuario.
     * @return Nombre del usuario del acceso.
     */
    std::string getNombreUsuario() const;
    /**
     * @brief Obtiene la hora del Acceso.
     * @return Hora del Registro.
     */
    std::string getHora() const;
    
    Registro* getSiguienteAcceso() const;  // Debería retornar el siguiente acceso
    /**
      * @brief Mostramos la info del Registro
      */
    void mostrar();
};



#endif //REGISTRO_H
