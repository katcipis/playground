#include "point.h"
#include "cg_exception.h"
#include <QTextStream>

Point::Point(): ColoredGeometricShape(), x(0.0),y(0.0),z(0.0)
{
    this->defineMatriz();
}

QString Point::getTagName() const
{
    return QString("ponto");
}

QString Point::toXML() const
{
    QString point_xml;
    QTextStream stream(&point_xml);

    stream << " cor=\"" << this->getColorAsHex() << "\"" << this->toXMLColorless();

    return point_xml;
}

QString Point::toXMLColorless() const
{
    QString point_xml;
    QTextStream stream(&point_xml);

    stream << " x=\"" << this->x << "\"";
    stream << " y=\"" << this->y << "\"";
    stream << " z=\"" << this->z  << "\"" << "/>\n";

    return point_xml;
}

Point::Point(double x_coordinate, double y_coordinate, double z_coordinate):
             ColoredGeometricShape(false, 0,0,0), x(x_coordinate), y(y_coordinate), z(z_coordinate)
{
    this->defineMatriz();
}

Point::Point(const Matrix& given_matrix, int red, int green, int blue):
        ColoredGeometricShape(false, red, green, blue)
{
    if(given_matrix.rowCount() != 1 || given_matrix.columnCount() < 3){
        throw CGException(QString("Trying to create a Point with a matrix that does not have at least 3 collumns !!!"));
    }
    this->x = given_matrix.get(0,0);
    this->y = given_matrix.get(0,1);
    this->z = given_matrix.get(0,2);

    this->defineMatriz();
}

Point::Point(int red, int green, int blue, double x_coordinate, double y_coordinate, double z_coordinate) :
       ColoredGeometricShape(false, red, green, blue),
       x(x_coordinate), y(y_coordinate), z(z_coordinate)
{
    this->defineMatriz();
}

void Point::defineMatriz()
{
    this->matrix.add(0,0,this->x);
    this->matrix.add(0,1,this->y);
    this->matrix.add(0,2,this->z);
}

double Point::getX() const
{
    return this->x;
}

double Point::getY() const
{
    return this->y;
}

double Point::getZ() const
{
    return this->z;
}

bool Point::operator==(const Point &other) const
{
    return this->x == other.x && this->y == other.y && this->z == other.z && ColoredGeometricShape::operator ==(other);
}

const Matrix& Point::toMatrix() const
{
    return matrix;
}

bool Point::operator!=(const Point &other) const
{
    return !(*this == other);
}

const QString Point::toString () const
{
    QString point_repr;
    QTextStream stream(&point_repr);

    stream << "x:" << this->getX() << " y:" << this->getY() << " z:" << this->getZ();
    return point_repr;
}
