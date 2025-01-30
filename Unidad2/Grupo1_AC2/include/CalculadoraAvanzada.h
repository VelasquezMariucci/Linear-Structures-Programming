//
// Created by esvel on 25/10/2024.
//

#ifndef CALCULADORAAVANZADA_H
#define CALCULADORAAVANZADA_H
#include <iostream>

#include "Matriz.h"

class Operacion
{
public:
    double* suma(double* n1, double* n2)
    {
        double* resultado = new double;
        *resultado = *n1 + *n2;
        return resultado;
    }

    double* resta(double* n1, double* n2)
    {
        double* resultado = new double;
        *resultado = *n1 - *n2;
        return resultado;
    }

    double* multiplicacion(double* n1, double* n2)
    {
        double* resultado = new double;
        *resultado = (*n1) * (*n2);
        return resultado;
    }

    double* division(double* n1, double* n2)
    {
        double* resultado = new double;
        *resultado = (*n1) / (*n2);
        return resultado;
    }

    double* potencia(double* n1)
    {
        double* resultado = new double;
        *resultado = (*n1) * (*n1);
        return resultado;
    }
};

class CalculadoraAvanzada
{
public:
    void menu()
    {
        int operacion, decision;

        while (operacion != 3)
        {
            std::cout << "Ingresa que tipo de operacion que se quiere realizar: " << std::endl;
            std::cout << "1) Operaciones Basicas" << std::endl;
            std::cout << "2) Operaciones con Matrices" << std::endl;
            std::cout << "3) Salir" << std::endl;

            std::cin >> operacion;
            while (std::cin.fail())
            {
                std::cout << "Opcion no disponible" << std::endl;
                std::cin.clear();
                std::cin.ignore();
                std::cin >> operacion;
            }

            if (operacion == 1)
            {
                Operacion operacion1;
                double a;
                double b;
                std::cout << "Ingresa la operacion que se quiere realizar: " << std::endl;
                std::cout << "1) Suma" << std::endl;
                std::cout << "2) Resta" << std::endl;
                std::cout << "3) Multiplicacion" << std::endl;
                std::cout << "4) Division" << std::endl;
                std::cout << "5) Potencia" << std::endl;
                std::cin >> decision;
                while (std::cin.fail())
                {
                    std::cout << "Opcion no disponible" << std::endl;
                    std::cin.clear();
                    std::cin.ignore();
                    std::cin >> decision;
                }

                if (decision >= 1 && decision <= 4)
                {
                    std::cout << "Ingresa el primer y segundo numero: " << std::endl;
                    std::cin >> a;
                    std::cin >> b;
                    while (std::cin.fail())
                    {
                        std::cout << "Opciones no disponible" << std::endl;
                        std::cin.clear();
                        std::cin.ignore();
                        std::cin >> a;
                        std::cin >> b;
                    }

                    double* n1 = &a;
                    double* n2 = &b;

                    std::cout << "Resultado: ";
                    double* resultado = new double;

                    if (decision == 1)
                    {
                        resultado = operacion1.suma(n1, n2);
                    }
                    else if (decision == 2)
                    {
                        resultado = operacion1.resta(n1, n2);
                    }
                    else if (decision == 3)
                    {
                        resultado = operacion1.multiplicacion(n1, n2);
                    }
                    else if (decision == 4)
                    {
                        resultado = operacion1.division(n1, n2);
                    }
                    std::cout << "Resultado: " << *resultado << std::endl;
                }
                else if (decision == 5)
                {
                    std::cout << "Ingresa el primer numero: " << std::endl;
                    std::cin >> a;
                    while (std::cin.fail())
                    {
                        std::cout << "Opcion no disponible" << std::endl;
                        std::cin.clear();
                        std::cin.ignore();
                        std::cin >> a;
                    }
                    double* n1 = &a;
                    double* resultado = operacion1.potencia(n1);
                    std::cout << "Resultado: " << *resultado << std::endl;
                }
                else
                {
                    std::cout << "Operacion no existente" << std::endl;
                }
            }
            else if (operacion == 2)
            {
                this->menuMatrices();
            }
            else if (operacion == 3)
            {
                std::cout << "Saliendo" << std::endl;
            }
            else
            {
                std::cout << "Error de input" << std::endl;
            }
        }
    };


    /**
     * @brief Muestra el menú de opciones de la calculadora de matrices.
     *
     * Permite al usuario seleccionar una operación para matrices y ejecutarla en un bucle hasta que elige salir.
     */
    void menuMatrices()
    {
        int opcion;
        do
        {
            std::cout << "----- Calculadora Avanzada Matrices -----" << std::endl;
            std::cout << "1. Sumar Matrices" << std::endl;
            std::cout << "2. Restar Matrices" << std::endl;
            std::cout << "3. Multiplicar Matrices" << std::endl;
            std::cout << "4. Dividir Matrices" << std::endl;
            std::cout << "5. Transponer Matriz" << std::endl;
            std::cout << "6. Calcular Determinante" << std::endl;
            std::cout << "7. Calcular Inversa" << std::endl;
            std::cout << "8. Salir" << std::endl;
            std::cout << "Elige una opción: ";
            std::cin >> opcion;

            switch (opcion)
            {
            case 1:
                operarSumar();
                break;
            case 2:
                operarRestar();
                break;
            case 3:
                operarMultiplicar();
                break;
            case 4:
                operarDividir();
                break;
            case 5:
                operarTransponer();
                break;
            case 6:
                operarDeterminante();
                break;
            case 7:
                operarInversa();
                break;
            case 8:
                std::cout << "Saliendo de la calculadora..." << std::endl;
                break;
            default:
                std::cout << "Opción no válida, intenta de nuevo." << std::endl;
            }
        }
        while (opcion != 8);
    }

private
:
    /**
     * @brief Solicita al usuario los datos para crear una nueva matriz.
     *
     * @return Matriz* Puntero a la matriz creada.
     */
    Matriz* ingresarMatriz()
    {
        int filas, columnas;
        std::cout << "Ingresa el número de filas: ";
        std::cin >> filas;
        std::cout << "Ingresa el número de columnas: ";
        std::cin >> columnas;
        Matriz* matriz = new Matriz(filas, columnas);
        matriz->crearMatriz();
        return matriz;
    }

    /**
     * @brief Realiza la operación de suma entre dos matrices.
     */
    void operarSumar()
    {
        std::cout << "Sumar dos matrices:" << std::endl;
        Matriz* matriz1 = ingresarMatriz();
        Matriz* matriz2 = ingresarMatriz();
        try
        {
            Matriz* resultado = matriz1->sumarMatrices(matriz2);
            resultado->imprimir();
            delete resultado;
        }
        catch (const std::invalid_argument& e)
        {
            std::cerr << e.what() << std::endl;
        }
        delete matriz1;
        delete matriz2;
    }

    /**
    * @brief Realiza la operación de resta entre dos matrices.
    */
    void operarRestar()
    {
        std::cout << "Restar dos matrices:" << std::endl;
        Matriz* matriz1 = ingresarMatriz();
        Matriz* matriz2 = ingresarMatriz();
        try
        {
            Matriz* resultado = matriz1->restarMatrices(matriz2);
            resultado->imprimir();
            delete resultado;
        }
        catch (const std::invalid_argument& e)
        {
            std::cerr << e.what() << std::endl;
        }
        delete matriz1;
        delete matriz2;
    }

    /**
    * @brief Realiza la operación de multiplicación entre dos matrices.
    */
    void operarMultiplicar()
    {
        std::cout << "Multiplicar dos matrices:" << std::endl;
        Matriz* matriz1 = ingresarMatriz();
        Matriz* matriz2 = ingresarMatriz();
        try
        {
            Matriz* resultado = matriz1->multiplicarMatrices(matriz2);
            resultado->imprimir();
            delete resultado;
        }
        catch (const std::invalid_argument& e)
        {
            std::cerr << e.what() << std::endl;
        }
        delete matriz1;
        delete matriz2;
    }

    /**
    * @brief Realiza la operación de división entre dos matrices.
    */
    void operarDividir()
    {
        std::cout << "Dividir dos matrices:" << std::endl;
        Matriz* matriz1 = ingresarMatriz();
        Matriz* matriz2 = ingresarMatriz();
        try
        {
            Matriz* resultado = matriz1->dividirMatrices(matriz2);
            resultado->imprimir();
            delete resultado;
        }
        catch (const std::invalid_argument& e)
        {
            std::cerr << e.what() << std::endl;
        }
        delete matriz1;
        delete matriz2;
    }

    /**
     * @brief Realiza la operación de transposición en una matriz.
     */
    void operarTransponer()
    {
        std::cout << "Transponer una matriz:" << std::endl;
        Matriz* matriz = ingresarMatriz();
        Matriz* resultado = matriz->trasponer();
        resultado->imprimir();
        delete resultado;
        delete matriz;
    }

    /**
     * @brief Calcula el determinante de una matriz.
     */
    void operarDeterminante()
    {
        std::cout << "Calcular determinante de una matriz:" << std::endl;
        Matriz* matriz = ingresarMatriz();
        try
        {
            double det = matriz->determinante();
            std::cout << "El determinante es: " << det << std::endl;
        }
        catch (const std::invalid_argument& e)
        {
            std::cerr << e.what() << std::endl;
        }
        delete matriz;
    }

    /**
     * @brief Calcula la inversa de una matriz.
     */
    void operarInversa()
    {
        std::cout << "Calcular inversa de una matriz:" << std::endl;
        Matriz* matriz = ingresarMatriz();
        try
        {
            Matriz* resultado = matriz->inversa();
            resultado->imprimir();
            delete resultado;
        }
        catch (const std::invalid_argument& e)
        {
            std::cerr << e.what() << std::endl;
        }
        delete matriz;
    }
};

#endif //CALCULADORAAVANZADA_H
