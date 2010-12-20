#include "curve_hermite.h"
#include <QTextStream>

CurveHermite::CurveHermite(const Point& p1, const Point& p4, const Point& r1, const Point& r4, double precision,
                           int red, int green, int blue) : Curve(red, green, blue),
                           p1(p1), p4(p4), r1(r1), r4(r4), precision(precision)
{
    QList<Point> curvePoints;
    double increment = 1.0 / precision;

    for (double t = 0.0; t <= 1.0; t += increment) {
        curvePoints.append(Point(this->calculateCoordinate(t, this->p1.getX(), this->p4.getX(), this->r1.getX(), this->r4.getX()),
                                 this->calculateCoordinate(t, this->p1.getY(), this->p4.getY(), this->r1.getY(), this->r4.getY())));
    }

    for (int i = 0; i < (curvePoints.size() - 1); i++) {
        this->wires.append(Wire(curvePoints[i], curvePoints[i + 1],
                                red, green, blue));
    }

    this->wires.append(Wire(curvePoints[curvePoints.size() - 1], p4, red, green, blue));
    this->defineString();
    this->buildXmlRepresentation();
}

void CurveHermite::buildXmlRepresentation()
{
    QTextStream stream(&this->xmlBody);
    QString internalTab = this->getTab() + this->getTab() + this->getTab();

    this->tagName = "curvaHermite";
    this->xmlEnd = "</curvaHermite>";
    this->xmlStart = QString(" cor=\"") + this->getColorAsHex() + QString("\">\n");

    stream << this->getTab() << this->getTab() << "<geometria>\n";
    stream << internalTab << "<p1" << this->p1.toXMLColorless();
    stream << internalTab << "<p4" << this->p4.toXMLColorless();
    stream << internalTab << "<r1" << this->r1.toXMLColorless();
    stream << internalTab << "<r4" << this->r4.toXMLColorless();
    stream << this->getTab() << this->getTab() << "</geometria>\n";
}

double CurveHermite::calculateCoordinate(double t, double p1V, double p4V, double r1V, double r4V)
{
    double tSquare = t * t;
    double tCube = tSquare * t;

    return (p1V * (2.0*tCube -3.0*tSquare +1.0)) +
           (p4V * (-2.0*tCube + 3.0*tSquare)) +
           (r1V * (tCube -2.0*tSquare + t)) +
           (r4V * (tCube - tSquare));
}

Point CurveHermite::getP1() const
{
    return this->p1;
}

Point CurveHermite::getP4() const
{
    return this->p4;
}

Point CurveHermite::getR1() const
{
    return this->r1;
}

Point CurveHermite::getR4() const
{
    return this->r4;
}

double CurveHermite::getPrecision() const
{
    return this->precision;
}

void CurveHermite::defineString ()
{
    QTextStream stream(&this->curve_repr);

    stream << "CurveHermite p1: [" << this->p1.toString() << "] \n";
    stream << "             p4: [" << this->p4.toString() << "] \n";
    stream << "             r1: [" << this->r1.toString() << "] \n";
    stream << "             r4: [" << this->r4.toString() << "] \n";
}
