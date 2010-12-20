#ifndef XML_PARSER_H
#define XML_PARSER_H

#include <QString>
#include <QMap>
#include <QDomDocument>
#include "point.h"
#include "wire.h"
#include "wireframe.h"
#include "curve_bspline.h"
#include "curve_hermite.h"
#include "window.h"

/**
 *  Class that defines a xml parser.
 */
class CGSHARED_EXPORT XmlParser
{

private:
    QDomDocument doc;
    typedef void (*parserFunc) (XmlParser*, QDomElement*);
    QMap<QString, parserFunc> parsers;
    void parseDocument();

public:
    QMap<QString,Point> points;
    QMap<QString,Wire> wires;
    QMap<QString,WireFrame> wireframes;
    QMap<QString,Curve> curves;
    QMap<QString, QList<Curve> > continuousCurves;
    QList<QString> errors;
    Window* window;

    /**
     *  \brief Class constructor.
     *  Parses the xml file filling the data structures with the objects found on the xml file.
     *  To get all the errors found on the parsing iterate over the errors list.
     *  @param fileName - The path to the xml file.
     */
    XmlParser(const QString& fileName);
};

#endif // XML_PARSER_H
