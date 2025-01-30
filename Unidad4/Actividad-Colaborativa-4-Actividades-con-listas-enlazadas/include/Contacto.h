//
// Created by Ricky Vicente on 09/12/2024.
//

#ifndef CONTACTO_H
#define CONTACTO_H
#include <string>

class Contacto
{
private:
    std::string nombre;
    std::string apellido;
    long long numero;

public:
    /**
     * @brief Constructor por defecto de la clase Contacto.
     *
     * Inicializa los atributos nombre, apellido y
     * numero como cadenas vacías.
     */
    Contacto();

    /**
     * @brief Constructor parametrizado de la clase Contacto.
     *
     * @param nombre Nombre del contacto.
     * @param apellido Apellido del contacto.
     * @param numero Numero del contacto.
     *
    * Inicializa los atributos nombre, apellido y
     * numero con los valores dados
     */
    Contacto(std::string n, std::string a, long long num);

    /**
     * @brief Obtiene el nombre del contacto.
     *
     * @return Nombre del contacto.
     */
    std::string getNombre();

   /**
    * @brief Obtiene el apellido del contacto.
    *
    * @return Apellido del contacto.
    */
    std::string getApellido();

   /**
    * @brief Obtiene el numero del contacto.
    *
    * @return Numero del contacto.
    */
    long long getNumero();

   /**
    * @brief Cambia el nombre del contacto.
    */
    void setNombre(std::string n);

   /**
    * @brief Cambia el apellido del contacto.
    */
    void setApellido(std::string a);

   /**
    * @brief Cambia el numero del contacto.
    */
    void setNumero(long long num);
};

#endif //CONTACTO_H
