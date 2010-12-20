#include "curve_bspline.h"
#include "matrix.h"
#include "wire.h"
#include "cg_exception.h"
#include <QTextStream>

CurveBSpline::CurveBSpline(QList<Point> points, int red,int green, int blue) : Curve(red,green,blue)
{
    //define os valores de delta
    double delta = 0.005;
    double delta2 = delta * delta;
    double delta3 = delta2 * delta;

    if(points.size() < 4) {
        throw CGException("Trying to create a BSpline with less than 4 points !!!");
    }

    this->formingPoints = points;

    this->deltaMat.add(0,0,delta);
    this->deltaMat.add(0,1,delta2);
    this->deltaMat.add(0,2,delta3);
    this->deltaMat.add(0,3,1.0);

    Matrix mbs;

    mbs.add(0,0, -1.0 / 6.0);
    mbs.add(0,1,  1.0 / 2.0);
    mbs.add(0,2, -1.0 / 2.0);
    mbs.add(0,3,  1.0 / 6.0);
    mbs.add(1,0,  1.0 / 2.0);
    mbs.add(1,1, -1.0);
    mbs.add(1,2,  1.0 / 2.0);
    mbs.add(1,3,  0.0);
    mbs.add(2,0, -1.0 / 2.0);
    mbs.add(2,1,  0.0);
    mbs.add(2,2,  1.0 / 2.0);
    mbs.add(2,3,  0.0);
    mbs.add(3,0,  1.0 / 6.0);
    mbs.add(3,1,  2.0 / 3.0);
    mbs.add(3,2,  1.0 / 6.0);
    mbs.add(3,3,  0.0);

    double fx, delta1x, delta2x, delta3x;
    double fy, delta1y, delta2y, delta3y;

    QList<Point> newPoints;
    //para cada segmento da spline
    for(int i = 0; i < points.size() - 3; i++)
    {
        Matrix gbsx;
        Matrix gbsy;
        Matrix cx,cy,cz;

        //cria a matriz para x
        gbsx.add(0,0,points.at(i).getX());
        gbsx.add(1,0,points.at(i+1).getX());
        gbsx.add(2,0,points.at(i+2).getX());
        gbsx.add(3,0,points.at(i+3).getX());

        //calcula os coeficientes
        cx = mbs * gbsx;

        //cria a matriz para y
        gbsy.add(0,0,points.at(i).getY());
        gbsy.add(1,0,points.at(i+1).getY());
        gbsy.add(2,0,points.at(i+2).getY());
        gbsy.add(3,0,points.at(i+3).getY());

        //calcula os coeficientes
        cy = mbs * gbsy;

        //calcular os valores para o primeiro ponto da curva
        fx = cx.get(3,0);
        delta1x = cx.get(0,0) * delta3 + cx.get(1,0) * delta2 + cx.get(2,0) * delta;
        delta2x = 6.0 * cx.get(0,0) * delta3 + 2.0 * cx.get(1,0) * delta2;
        delta3x = 6.0 * cx.get(0,0) * delta3;

        fy = cy.get(3,0);
        delta1y = cy.get(0,0) * delta3 + cy.get(1,0) * delta2 + cy.get(2,0) * delta;
        delta2y = 6.0 * cy.get(0,0) * delta3 + 2.0 * cy.get(1,0) * delta2;
        delta3y = 6.0 * cy.get(0,0) * delta3;


        double x = ((Matrix)(this->deltaMat * cx)).get(0,0);
        double y = ((Matrix)(this->deltaMat * cy)).get(0,0);

        newPoints.append(this->desenhaCurvaFwdDiff((1.0 / delta),x , delta1x, delta2x, delta3x, y, delta1y, delta2y, delta3y));
    }

    for(int i = 0; i < newPoints.size()-1;i++)
    {
        this->wires.append(Wire(newPoints.at(i), newPoints.at(i+1), red, green, blue));
    }

    this->defineString();
    this->buildXmlRepresentation();
}

void CurveBSpline::buildXmlRepresentation()
{
    QTextStream stream(&this->xmlBody);
    QString internalTab = this->getTab() + this->getTab();

    this->tagName = "curvaBSpline";
    this->xmlEnd = "</curvaBSpline>";
    this->xmlStart = QString(" cor=\"") + this->getColorAsHex() + QString("\">\n");

    for (int i = 0; i < this->formingPoints.size(); i++) {
        stream << internalTab << "<" << this->formingPoints[i].getTagName()  << this->formingPoints[i].toXMLColorless();
    }
}

QList<Point> CurveBSpline::desenhaCurvaFwdDiff(double n, double x, double &delta1x, double &delta2x, double &delta3x, double y, double &delta1y, double &delta2y, double &delta3y)
{
    QList<Point> points;
    double x1,y1,d1x,d2x,d3x,d1y,d2y,d3y;

    points.append(Point(x,y));

    x1 = x;
    d1x = delta1x;
    d2x = delta2x;
    d3x = delta3x;
    y1 = y;
    d1y = delta1y;
    d2y = delta2y;
    d3y = delta3y;

    for (double i = 0; i < n; i++){
        x1 = x1 + d1x;
        d1x = d1x + d2x;
        d2x = d2x + d3x;

        y1 = y1 + d1y;
        d1y = d1y + d2y;
        d2y = d2y + d3y;

        points.append(Point(x1,y1));
    }
    return points;
}

void CurveBSpline::defineString()
{
    QTextStream stream(&this->curve_repr);
    stream << "CurveBSpline formed by [" << this->wires.size() << "] wires \n";
}
