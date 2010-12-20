#ifndef TRANSFORMTEST_H
#define TRANSFORMTEST_H

#include <QObject>
#include <QtTest/QtTest>

class TransformTest : public QObject
{
    Q_OBJECT
private slots:
    void givenASXAndASYCanGenerateTheScaleMatrix();
    void givenADXAndADYCanGenerateTheTranslateMatrix();
    void givenAnAngleAndANumberOfDimensionsCanCreateTheRotateMatrix();

public:
    TransformTest();
};

#endif // TRANSFORMTEST_H
