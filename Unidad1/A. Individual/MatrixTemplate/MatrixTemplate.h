//
// Created by esvel on 29/09/2024.
//

#ifndef MATRIXTEMPLATE_H
#define MATRIXTEMPLATE_H

#include <iostream>
#include <vector>

template <typename T>
class MatrixTemplate
{
private:
    std::vector<std::vector<T>> innerMatrix;
    int rows;
    int cols;

public:
    /*
     * @brief Constructor to initialize the matrix with specified dimensions.
     *
     * @param rows Rows in the matrix.
     * @param cols Columns in the matrix.
     */
    MatrixTemplate(int rows, int cols) : rows(rows), cols(cols)
    {
        innerMatrix.resize(rows, std::vector<T>(cols));
    }

    /*
     * @brief Adds an element to the matrix at the specified coordinate.
     *
     * @param row Index of the row.
     * @param col Index of the column.
     * @param value Value to be added.
     */
    void addElement(int row, int col, int value)
    {
        innerMatrix[row][col] = value;
    }

    //getters
    int getRows()
    {
        return rows;
    }

    int getCols()
    {
        return cols;
    }

    std::vector<std::vector<T>>& getInnerMatrix()
    {
        return innerMatrix;
    }

    /*
     * @brief Overrides the + operator to add two matrices.
     *
     * Adds each position of two matrices, one by one, by going though each
     * coordinate.
     *
     * @param otherMatrix The matrix to be added to the current matrix.
     * @return A new MatrixTemplate object containing the sum.
     * @throw std::invalid_argument if the dimensions of the matrices do not match.
     * @Override
     */
    MatrixTemplate<T> operator+(MatrixTemplate<T> otherMatrix)
    {
        MatrixTemplate<T> result(rows, cols);

        if (rows != otherMatrix.getRows() || cols != otherMatrix.getCols())
        {
            throw std::invalid_argument("Dimensions dont match");
        }

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                result.innerMatrix[i][j] = this->innerMatrix()[i][j] + otherMatrix.innerMatrix[i][j];
            }
        }
    }

    /*
     * @brief Overloads the * operator to multiply two matrices.
     *
     * Multiplies the current matrix with another matrix by multiplying each row of matrix 1
     * by each column of matrix 2.
     *
     * @param other The matrix to be multiplied with the current matrix.
     * @return The product of the operation.
     * @throw std::invalid_argument if the number of columns of matrix 1 is different
     * from the number of rows of matrix 2.
     * @Override
     */
    MatrixTemplate<T> operator*(MatrixTemplate<T>& other)
    {
        MatrixTemplate<T> result(rows, other.cols);

        if (cols != other.rows)
        {
            throw std::invalid_argument("Matrix 1 Column size is different than Matrix 2 rows");
        }

        for (size_t i = 0; i < rows; ++i)
        {
            for (size_t j = 0; j < other.cols; ++j)
            {
                for (size_t k = 0; k < cols; ++k)
                {
                    result.innerMatrix[i][j] += innerMatrix[i][k] * other.innerMatrix[k][j];
                }
            }
        }

        return result;
    }

    //@brief Overloads the << operator to print the matrix.
    //@Override
    template <typename U> //separate template used for the friend function
    friend std::ostream& operator<<(std::ostream& os, MatrixTemplate<T>& matrixTemplate);
};


/*
 * @brief Overloads the << operator to print the matrix.
 *
 *
 * @param os The output stream to which the matrix will be sent.
 * @param matrixTemplate The matrix to be printed.
 * @return The output stream.
 * @Override
 */
template <typename T>
std::ostream& operator<<(std::ostream& os, MatrixTemplate<T>& matrixTemplate)
{
    for (const std::vector<T>& row : matrixTemplate.getInnerMatrix())
    {
        for (const T& element : row)
        {
            os << element << " ";
        }
        os << "\n";
    }
    return os;
}

#endif //MATRIXTEMPLATE_H
