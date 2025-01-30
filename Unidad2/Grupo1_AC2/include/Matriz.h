//
// Created by esvel on 25/10/2024.
//

#ifndef MATRIZ_H
#define MATRIZ_H


class Matriz
{
private:
    int filas;
    int columnas;
    double** matriz;

public:
    /**
     * @brief Constructor de la clase Matriz.
     *
     * Inicializa una matriz de tamaño filas x columnas y asigna memoria para almacenar los elementos.
     *
     * @param f Número de filas.
     * @param c Número de columnas.
     */
    Matriz(int f, int c) : filas(f), columnas(c)
    {
        // Declaramos la cantidad de espacios de las filas
        matriz = new double*[filas];
        for (int i = 0; i < filas; i++)
        {
            // Por cada uno de dichos espacios declaramos la cantidad de espacios para las columnas
            matriz[i] = new double[columnas];
        }
    }

    /**
     * @brief Destructor de la clase Matriz.
     *
     * Libera la memoria asignada a la matriz para prevenir fugas de memoria.
     */
    ~Matriz()
    {
        for (int i = 0; i < filas; i++)
        {
            delete[] matriz[i];
        }
        delete[] matriz;
    }

    /**
     * @brief Añade un valor en la posición especificada de la matriz.
     *
     * @param fila Fila donde se añadirá el valor.
     * @param columna Columna donde se añadirá el valor.
     * @param valor Valor que se añadirá en la posición especificada.
     */
    void añadirDato(int fila, int columna, double valor)
    {
        matriz[fila][columna] = valor;
    }

    /**
     * @brief Solicita y añade valores para cada posición de la matriz desde la entrada estándar.
     */
    void crearMatriz()
    {
        std::cout << "Ingresa cada valor de la matriz:" << std::endl;
        for (int i = 0; i < filas; i++)
        {
            for (int j = 0; j < columnas; j++)
            {
                double valor;
                std::cin >> valor;
                añadirDato(i, j, valor);
                std::cout << "Valor agnadido en [" << i << "][" << j << "]: " << valor << std::endl;
                // Línea de depuración
            }
        }
    }

    /**
     * @brief Imprime los elementos de la matriz en formato de filas y columnas.
     */
    void imprimir()
    {
        std::cout << "Matriz Impresa:  " << std::endl;
        for (int i = 0; i < filas; i++)
        {
            for (int j = 0; j < columnas; j++)
            {
                std::cout << matriz[i][j] << " | ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    /**
     * @brief Devuelve la matriz traspuesta, que es la inversa de filas y columnas.
     *
     * @return Matriz* Puntero a la matriz traspuesta.
     */
    Matriz* trasponer()
    {
        // Se le invierten las filas y columnas
        Matriz* matrizTraspuesta = new Matriz(columnas, filas);
        for (int i = 0; i < filas; i++)
        {
            for (int j = 0; j < columnas; j++)
            {
                // Se le invierten a la nueva matriz los elementos de la otra matriz
                matrizTraspuesta->añadirDato(j, i, matriz[i][j]);
            }
        }
        // Se devuelve la nueva matriz
        return matrizTraspuesta;
    }

    /**
     * @brief Calcula el determinante de la matriz, si es cuadrada.
     *
     * @return double Determinante de la matriz.
     * @throws std::invalid_argument si la matriz no es cuadrada.
     */
    double determinante() const
    {
        // Si la matriz no es cuadrática, el determinante no existe
        if (filas != columnas)
        {
            throw std::invalid_argument("La Matriz no es cuadrática. Determinante imposible");
        }
        double determinante = 0;
        int signo;
        // Si la matriz es de un solo elemento devuelve dicho elemento
        if (filas == 1)
        {
            return matriz[0][0];
        }
        else if (filas == 2)
        {
            // Si la matriz es de 2x2, se hace esta operacion
            return (matriz[0][0] * matriz[1][1]) - (matriz[1][0] * matriz[0][1]);
        }
        else
        {
            // La i indicará cada elemento de la primera fila, cuyo signo deberá ir invirtiendose constantemente
            for (int i = 0; i < filas; i++)
            {
                if (i % 2 == 1)
                {
                    signo = -1;
                }
                else
                {
                    signo = 1;
                }
                // Declaramos una matriz más pequeña, por cada elemento de la primera fila
                Matriz* matrizInterna = new Matriz(filas - 1, columnas - 1);
                int filasInternas = 0;
                for (int j = 0; j < filas; j++)
                {
                    if (j != 0)
                    {
                        int columnasInternas = 0;
                        for (int k = 0; k < columnas; k++)
                        {
                            if (k != i)
                            {
                                // Añadimos en cada espacio de la matriz interna un elemento de la anterior,
                                // siempre que dicho elemento no pertenezca a un espacio cuyas filas
                                // o columnas sean iguales a las del elemento multiplicado por la matriz interna
                                matrizInterna->añadirDato(filasInternas, columnasInternas, matriz[j][k]);
                                columnasInternas++;
                            }
                        }
                        filasInternas++;
                    }
                }

                determinante += signo * matrizInterna->determinante() * matriz[0][i];
            }
            // Se devuelve el determinante final
            return determinante;
        }
    }

    /**
     * @brief Calcula la matriz adjunta, que es la matriz de cofactores.
     *
     * @return Matriz* Puntero a la matriz adjunta.
     * @throws std::invalid_argument si la matriz no es cuadrada.
     */
    Matriz* adjunta()
    {
        // Si la matriz no es cuadrática, la adjunta no existe
        if (filas != columnas)
        {
            throw std::invalid_argument("La matriz no es cuadrada, no se puede calcular la adjunta.");
        }
        int signo = 0;
        Matriz* matrizAdjunta = new Matriz(filas, columnas);
        // La i la j juntas indicarán cada elemento de la primera matriz, cuyo signo deberá ir invirtiendose constantemente
        for (int i = 0; i < filas; i++)
        {
            for (int j = 0; j < columnas; j++)
            {
                if ((i + j) % 2 == 0)
                {
                    signo = 1;
                }
                else
                {
                    signo = -1;
                }
                // Se crea una matriz interna más pequeña por cada elemento de la matriz anterior
                Matriz* matrizInterna = new Matriz(filas - 1, columnas - 1);
                int filasInternas = 0;
                for (int k = 0; k < filas; k++)
                {
                    if (k != i)
                    {
                        int columnasInternas = 0;
                        for (int l = 0; l < columnas; l++)
                        {
                            if (l != i)
                            {
                                // Añadimos en cada espacio de la matriz interna un elemento de la anterior,
                                // siempre que dicho elemento no pertenezca a un espacio cuyas filas
                                // o columnas sean iguales a las del elemento multiplicado por la matriz interna
                                matrizInterna->añadirDato(filasInternas, columnasInternas, matriz[k][l]);
                                columnasInternas++;
                            }
                        }
                        filasInternas++;
                    }
                }
                // Establecemos el cofactor, osea el determinante de la matriz interna por el signo
                double cofactor = signo * matrizInterna->determinante();
                // Y lo añadimos a la matriz adjunta
                matrizAdjunta->añadirDato(i, j, cofactor);
            }
        }
        return matrizAdjunta;
    }

    /**
     * @brief Calcula la matriz inversa, si es cuadrada y su determinante no es 0.
     *
     * @return Matriz* Puntero a la matriz inversa.
     * @throws std::invalid_argument si la matriz no es invertible.
     */
    Matriz* inversa()
    {
        // Aplicamos todos los métodos anteriores (el determinante de la matriz)
        double det = determinante();
        // Se establece si el determinante es distinto a 0 y si las filas son iguales a las columnas
        if (det == 0 || filas != columnas)
        {
            throw std::invalid_argument("Matriz Inversa Imposible");
        }
        // Se crea una matriz a través del metodo trasponer() y luego del adjunta()
        Matriz* matrizAdjuntaTraspuesta = adjunta()->trasponer();
        // Se crea la matriz final
        Matriz* matrizInversa = new Matriz(filas, columnas);
        for (int i = 0; i < filas; i++)
        {
            for (int j = 0; j < columnas; j++)
            {
                // A ella se le asigna cada dato de la adjunta traspuesta dividido por su determinante
                matrizInversa->añadirDato(i, j, matrizAdjuntaTraspuesta->matriz[i][j] / det);
            }
        }
        // Se devuelve la matriz inversa
        return matrizInversa;
    }

    /**
     * @brief Suma dos matrices de las mismas dimensiones.
     *
     * @param matriz2 Puntero a la matriz a sumar.
     * @return Matriz* Puntero a la matriz resultado de la suma.
     * @throws std::invalid_argument si las matrices no tienen las mismas dimensiones.
     */
    Matriz* sumarMatrices(Matriz* matriz2)
    {
        // Si las 2 matrices que le damos son iguales...
        if (filas != matriz2->filas || columnas != matriz2->columnas)
        {
            throw std::invalid_argument("Operación imposible. Las matrices no tienen las mismas dimensiones.");
        }
        // ...instanciamos la matriz resultado a devolver
        Matriz* matrizResultado = new Matriz(filas, columnas);
        for (int i = 0; i < filas; i++)
        {
            for (int j = 0; j < columnas; j++)
            {
                // Cada elemento de la nueva matriz será la suma de las dos anteriores
                matrizResultado->añadirDato(i, j, matriz[i][j] + matriz2->matriz[i][j]);
            }
        }
        // Devolvemos la matriz resultado
        return matrizResultado;
    }

    /**
     * @brief Resta dos matrices de las mismas dimensiones.
     *
     * @param matriz2 Puntero a la matriz a restar.
     * @return Matriz* Puntero a la matriz resultado de la resta.
     * @throws std::invalid_argument si las matrices no tienen las mismas dimensiones.
     */
    Matriz* restarMatrices(Matriz* matriz2)
    {
        // Si las 2 matrices que le damos son iguales...
        if (filas != matriz2->filas || columnas != matriz2->columnas)
        {
            throw std::invalid_argument("Operación imposible. Las matrices no son iguales");
        }
        // ...instanciamos la matriz resultado a devolver
        Matriz* matrizResultado = new Matriz(filas, columnas);
        for (int i = 0; i < filas; i++)
        {
            for (int j = 0; j < columnas; j++)
            {
                // Cada elemento de la nueva matriz será la resta de las dos anteriores
                matrizResultado->añadirDato(i, j, matriz[i][j] - matriz2->matriz[i][j]);
            }
        }
        // Devolvemos la matriz resultado
        return matrizResultado;
    }

    /**
     * @brief Multiplicar dos matrices, si las dimensiones son compatibles.
     *
     * @param matriz2 Puntero a la matriz a multiplicar.
     * @return Matriz* Puntero a la matriz resultado de la multiplioacion.
     * @throws std::invalid_argument si las matrices no tienen las mismas dimensiones.
     */
    Matriz* multiplicarMatrices(Matriz* matriz2)
    {
        // Si las columnas de la primera son iguales a las filas de la segunda...
        if (columnas != matriz2->filas)
        {
            throw std::invalid_argument("Operación imposible. Las matrices no permiten division");
        }
        // Instanciamos la matriz resultado a devolver, que debe tener el n de filas de la primera y el n de columnas de la segunda
        Matriz* matrizResultado = new Matriz(filas, matriz2->columnas);
        // Para asegurarnos de que la suma no de errores, le damos a cada elemento de la matriz un 0
        for (int i = 0; i < filas; i++)
        {
            for (int j = 0; j < matriz2->columnas; j++)
            {
                matrizResultado->añadirDato(i, j, 0);
            }
        }
        // Por cada fila de la primera matriz...
        for (int i = 0; i < filas; i++)
        {
            // y por cada columna de la segunda...
            for (int j = 0; j < matriz2->columnas; j++)
            {
                for (int k = 0; k < columnas; k++)
                {
                    // al elemento de la matriz resultado, se le suman el producto del elemento de la fila
                    // i y columna k de la primera matriz con el de la fila k y columna j de la segunda
                    matrizResultado->matriz[i][j] += (matriz[i][k]) * (matriz2->matriz[k][j]);
                }
            }
        }
        // Devolvemos la matriz resultado
        return matrizResultado;
    }

    /**
     * @brief Dividir dos matrices, si las dimensiones son compatibles.
     *
     * @param matriz2 Puntero a la matriz a dividir.
     * @return Matriz* Puntero a la matriz resultado de la division.
     * @throws std::invalid_argument si las matrices no tienen las mismas dimensiones.
     */
    Matriz* dividirMatrices(Matriz* matriz2)
    {
        if (columnas != matriz2->filas || matriz2->filas != columnas)
        {
            throw std::invalid_argument("Operación imposible. Las matrices no permiten division");
        }
        // Se crea la inversa de la segunda matriz
        Matriz* matrizInversa = new Matriz(filas, columnas);
        matrizInversa = matriz2->inversa();
        Matriz* matrizResultado = new Matriz(filas, matriz2->columnas);
        // Se multiplica la primera matriz por la inversa de la otra
        matrizResultado = multiplicarMatrices(matrizInversa);
        // Devolvemos la matriz resultado
        return matrizResultado;
    }
};

#endif //MATRIZ_H
