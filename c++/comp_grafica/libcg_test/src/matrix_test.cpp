#include "matrix_test.h"
#include "matrix.h"
#include "cg_exception.h"

MatrixTest::MatrixTest()
{
}

void MatrixTest::twoMaticesAreEqualIfTheyHaveTheSameRowsAndColumns()
{

    Matrix matrix;
    Matrix other;

    matrix.add(0, 0, 1);
    matrix.add(0, 1, 0);
    matrix.add(0, 2, 2);

    matrix.add(1, 0, 4);
    matrix.add(1, 1, 3);
    matrix.add(1, 2, 1);

    other.add(0, 0, 1);
    other.add(0, 1, 0);
    other.add(0, 2, 2);

    other.add(1, 0, 4);
    other.add(1, 1, 3);
    other.add(1, 2, 1);

    QCOMPARE(matrix, other);
}

void MatrixTest::twoMaticesAreNotEqualIfTheyDontHaveTheSameRowsAndColumns()
{
    Matrix matrix;
    Matrix other;

    matrix.add(0, 0, 1);
    matrix.add(0, 1, 0);
    matrix.add(0, 2, 2);

    matrix.add(1, 0, 4);
    matrix.add(1, 1, 3);
    matrix.add(1, 2, 1);

    other.add(0, 0, 1);
    other.add(0, 1, 3);
    other.add(0, 2, 2);

    other.add(1, 0, 3);
    other.add(1, 1, 3);
    other.add(1, 2, 1);

    QVERIFY(matrix != other);
}

void MatrixTest::aMatrixCanBeMultipliedByAnother()
{
    Matrix matrix;
    Matrix other;
    Matrix result;

    matrix.add(0, 0, 1);
    matrix.add(0, 1, 0);
    matrix.add(0, 2, 2);

    matrix.add(1, 0, -1);
    matrix.add(1, 1,  3);
    matrix.add(1, 2,  1);

    other.add(0, 0, 3);
    other.add(0, 1, 1);

    other.add(1, 0, 2);
    other.add(1, 1, 1);

    other.add(2, 0, 1);
    other.add(2, 1, 0);


    result.add(0, 0, 5);
    result.add(0, 1, 1);

    result.add(1, 0, 4);
    result.add(1, 1, 2);

    QCOMPARE(matrix * other, result);
}

void MatrixTest::knowsHowMuchColumnsItHas()
{
    Matrix matrix;

    matrix.add(0, 0, 1);
    matrix.add(0, 1, 0);
    matrix.add(0, 2, 2);

    matrix.add(1, 0, 4);
    matrix.add(1, 1, 3);
    matrix.add(1, 2, 1);

    QCOMPARE(3, matrix.columnCount());
}

void MatrixTest::knowsHowMuchRowsItHas()
{
    Matrix matrix;

    matrix.add(0, 0, 1);
    matrix.add(0, 1, 0);
    matrix.add(0, 2, 2);

    matrix.add(1, 0, 4);
    matrix.add(1, 1, 3);
    matrix.add(1, 2, 1);

    QCOMPARE(2, matrix.rowCount());
}

void MatrixTest::ifTheNumberOfColumnsOfTheLeftMatrixIsNotTheSameAsTheNumberOfRowsOfTheRightMatrixMultiplyGeneratesAException()
{
    Matrix matrix;
    Matrix other;
    bool has_been_throw = false;

    matrix.add(0, 0, 1);
    matrix.add(0, 1, 0);
    matrix.add(0, 2, 2);

    matrix.add(1, 0, -1);
    matrix.add(1, 1,  3);
    matrix.add(1, 2,  1);

    other.add(0, 0, 3);
    other.add(0, 1, 1);

    other.add(1, 0, 2);
    other.add(1, 1, 1);

    try{
        matrix * other;
    } catch(CGException& except) {
        has_been_throw = true;
    }

    QVERIFY(has_been_throw);
}

