#include "matrix.h"
#include "cg_exception.h"
#include <QTextStream>

Matrix::Matrix()
{
}

void Matrix::validatePosition(int row, int column)
{
    if(this->matrix.size() <= row){
        while(this->matrix.size() <= row){
            this->matrix.append(QList<double>());
        }
    }

    if(this->matrix[row].size() <= column){
        while(this->matrix[row].size() <= column){
            this->matrix[row].append(0);
        }
    }
}

void Matrix::add(int row, int column, double value)
{
    this->validatePosition(row, column);
    this->matrix[row][column] = value;
}


double Matrix::get(int row, int column) const
{
    return this->matrix[row][column];
}

int Matrix::columnCount() const
{
    if(this->matrix.size() == 0){
        return 0;
    }

    return this->matrix[0].size();
}

int Matrix::rowCount() const
{
    return this->matrix.size();
}

Matrix Matrix::operator*(const Matrix &other) const
{
    Matrix result;

    if (this->columnCount() != other.rowCount()) {
        QString error;
        QTextStream stream(&error);
        stream << "Number of columns of the left matrix is not the same as the number of rows of the right matrix !\n";
        stream << "Matrix 1: " << this->toString()  << "\n";
        stream << "Matrix 2: " << other.toString() << "\n";
        throw CGException(error);
    }
    for (int i = 0; i < this->rowCount(); i++) {
        for (int j = 0; j < other.columnCount(); j++) {
            double sum = 0.0;
            for (int k = 0; k < this->columnCount(); k++) {
                sum += this->matrix[i][k] * other.matrix[k][j];
            }
            result.add(i, j, sum);
        }
    }
    return result;
}

bool Matrix::operator== (const Matrix &other) const
{
    if(this->matrix.size() != other.matrix.size()) {
        return false;
    }

    for(int i = 0; i < this->matrix.size(); i++){
        if(this->matrix[i] != other.matrix[i]) {
            return false;
        }
    }

    return true;
}

const QString Matrix::toString () const
{
    QString matrix_repr;
    QTextStream stream(&matrix_repr);

    stream << "Matrix [" << this->rowCount() << "] x [" << this->columnCount() << "] \n";

    for (int i = 0; i < this->rowCount(); i++) {
        stream << "[ ";
        for (int j = 0; j < this->columnCount(); j++) {
            stream << this->get(i,j);
            if (j+1 < this->columnCount()) {
                stream << ", ";
            }
        }
        stream << " ] \n";
    }
    return matrix_repr;
}

bool Matrix::operator!= (const Matrix &other) const
{
    return !(*this == other);
}
