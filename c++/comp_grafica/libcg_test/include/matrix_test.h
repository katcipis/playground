#ifndef MATRIX_TEST_H
#define MATRIX_TEST_H

#include <QObject>
#include <QtTest/QtTest>

class MatrixTest : public QObject
{
    Q_OBJECT
private slots:
    void twoMaticesAreEqualIfTheyHaveTheSameRowsAndColumns();
    void twoMaticesAreNotEqualIfTheyDontHaveTheSameRowsAndColumns();
    void aMatrixCanBeMultipliedByAnother();
    void ifTheNumberOfColumnsOfTheLeftMatrixIsNotTheSameAsTheNumberOfRowsOfTheRightMatrixMultiplyGeneratesAException();
    void knowsHowMuchColumnsItHas();
    void knowsHowMuchRowsItHas();

public:
    MatrixTest();
};

#endif // MATRIX_TEST_H
