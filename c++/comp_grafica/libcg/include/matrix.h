#ifndef MATRIX_H
#define MATRIX_H

#include "cg_global.h"
#include <QList>
#include <string>

/**
 *  Class that defines a Matrix.
 */
class CGSHARED_EXPORT Matrix
{

private:
    QList< QList<double> > matrix;
    void validatePosition(int row, int column);

public:

    /**
     *  \brief Class constructor.
     *  Constructs a matrix.
     */
    Matrix();

    /**
     *  Add a new value to the matrix.
     *  @param row    - the row of the matrix.
     *  @param column - the column of the matrix.
     *  @param value  - the value.
     */
    void add(int row, int column, double value);


    /**
     *  Get a value from the matrix.
     *  @param row    - the row of the matrix.
     *  @param column - the column of the matrix.
     *  @return the value at matrix[row][column]. Raise an exception if there is no value at matrix[row][column].
     */
    double get(int row, int column) const;

    /**
     *  Get how much columns is on the matrix.
     *  @return how much columns is on the matrix.
     */
    int columnCount() const;

    /**
     *  Get how much rows is on the matrix.
     *  @return how much rows is on the matrix.
     */
    int rowCount() const;

    /**
     *  Multiply two matrices.
     *  @param other - the other matrix.
     *  @return a matrix that is the result of the multiply operation.
     */
    Matrix operator*(const Matrix &other) const;

    /**
     *  Compares if two matrices are equal.
     *  @param other - the other matrix.
     *  @return true if the two matrices are equal.
     */
    bool operator==(const Matrix &other) const;

    /**
     *  Compares if two matrices are not equal.
     *  @param other - the other matrix.
     *  @return true if the two matrices are not equal.
     */
    bool operator!=(const Matrix &other) const;

    /**
     *  Gets a string representation of the matrix.
     *  @return the string representing the matrix.
     */
    const QString toString () const;
};

#endif // MATRIX_H
