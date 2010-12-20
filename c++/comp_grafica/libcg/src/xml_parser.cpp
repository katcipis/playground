#include "xml_parser.h"
#include "window_ortogonal.h"
#include <QFile>
#include <QColor>

static QString pointName        = QString("ponto");
static QString wireName         = QString("reta");
static QString wireFrameName    = QString("poligono");
static QString curveHermiteName = QString("curvaHermite");
static QString curveBSplineName = QString("curvaBSpline");
static QString object3DName     = QString("objeto3d");
static QString windowName       = QString("window");

/******************************/
/* Parsing internal functions */
/******************************/
static QString getName(XmlParser* parser, QDomElement* elem)
{
    QDomAttr name  = elem->attributeNode("nome");
    if (name.isNull()) {
        parser->errors.append(QString("Error parsing a element without a name !!!"));
        return QString::null;
    }

    return name.value();
}

static QColor getColor(XmlParser* parser, QDomElement* elem)
{
    QDomAttr attr = elem->attributeNode("cor");

    if (attr.isNull()) {
        return QColor(Qt::black);
    }
    QColor color(QString("#") + attr.value());
    if (color.isValid()) {
        return color;
    }

    parser->errors.append(QString("Invalid color: ") + attr.value());
    return QColor(Qt::black);
}

static Point getPoint(XmlParser* parser, QDomElement* elem)
{
    QDomAttr x = elem->attributeNode("x");
    QDomAttr y = elem->attributeNode("y");
    QDomAttr z = elem->attributeNode("z");

    if (x.isNull() || y.isNull() || z.isNull()) {
        parser->errors.append(QString("Error parsing a point with a missing parameter (x or y or z missing)!!!"));
        return Point();
    }

    return Point(x.value().toDouble(), y.value().toDouble(), z.value().toDouble());
}

static QList<Point> getPoints(XmlParser* parser, QDomElement* elem, const QString& name)
{
    QDomElement currentPoint = elem->firstChildElement(pointName);
    QList<Point> points;

    while (!currentPoint.isNull()) {
        Point point = getPoint(parser, &currentPoint);
        if (point.isNull()) {
            parser->errors.append(QString("Error parsing one of the points from: ") + elem->tagName() + QString(" ") + name);
            return QList<Point>();
        }
        points.append(point);
        currentPoint = currentPoint.nextSiblingElement(pointName);
    }
    return points;
}

static Curve getCurveHermite(XmlParser* parser, QDomElement* elem, QColor color)
{
    QDomElement p1Elem = elem->firstChildElement("p1");
    QDomElement p4Elem = elem->firstChildElement("p4");
    QDomElement r1Elem = elem->firstChildElement("r1");
    QDomElement r4Elem = elem->firstChildElement("r4");

    if (p1Elem.isNull() || p4Elem.isNull() || r1Elem.isNull() || r4Elem.isNull()) {
        parser->errors.append(QString("Error parsing a curve with a missing parameter on geometria !!!"));
        return Curve();
    }

    Point p1 = getPoint(parser, &p1Elem);
    Point p4 = getPoint(parser, &p4Elem);
    Point r1 = getPoint(parser, &r1Elem);
    Point r4 = getPoint(parser, &r4Elem);

    if (p1.isNull() || p4.isNull() || r1.isNull() || r4.isNull()) {
        return Curve();
    }

    return CurveHermite(p1,p4,r1,r4,100, color.red(), color.green(), color.blue());
}

static void parsePoint(XmlParser* parser, QDomElement* elem)
{
    QString name = getName(parser, elem);
    QColor color = getColor(parser, elem);
    Point point = getPoint(parser, elem);

    if (name.isNull()) {
        return;
    }

    if (point.isNull()) {
        return;
    }

    if (parser->points.contains(name)) {
        parser->errors.append(QString("Already exists a point with name: ") + name + QString(" , this one will be discarded !!!"));
        return;
    }

    parser->points[name] = Point(color.red(), color.green(), color.blue(),
                                 point.getX(), point.getY(), point.getZ());
}

static void parseWire(XmlParser* parser, QDomElement* elem)
{
    QString name = getName(parser, elem);
    QColor color = getColor(parser, elem);
    
    QDomElement first  = elem->firstChildElement(pointName);
    QDomElement second = first.nextSiblingElement(pointName);

    if (name.isNull()) {
        return;
    }

    if (first.isNull() || second.isNull()) {
        parser->errors.append(QString("Error, unable to parse the two points that forms the wire name[") + name + QString("] !!!"));
        return;
    }

    Point firstPoint  = getPoint(parser, &first);
    Point secondPoint = getPoint(parser, &second);

    if (firstPoint.isNull() || secondPoint.isNull()) {
        return;
    }

    parser->wires[name] = Wire(firstPoint, secondPoint, color.red(), color.green(), color.blue());
}

static void parseWireFrame(XmlParser* parser, QDomElement* elem)
{
    QString name = getName(parser, elem);
    QColor color = getColor(parser, elem);
    QDomAttr filledAttr = elem->attributeNode("cheio");
    bool isFilled = filledAttr.value() == QString("verdadeiro") ? true : false;

    if (name.isNull()) {
        return;
    }

    if (filledAttr.isNull()) {
        parser->errors.append(QString("Error, unable to find the attribute cheio at poligono: ") + name);
        return;
    }
    QList<Point> points = getPoints(parser, elem, name);
    parser->wireframes[name] = WireFrame(points, isFilled, color.red(), color.green(), color.blue());
}

static void parseCurveHermite(XmlParser* parser, QDomElement* elem)
{
    QString name = getName(parser, elem);
    QColor color = getColor(parser, elem);
    QString geometryName("geometria");
    QDomElement currentGeometry = elem->firstChildElement(geometryName);
    QList<Curve> curves;

    if (name.isNull()) {
        return;
    }

    if (currentGeometry.isNull()) {
        parser->errors.append(QString("Error, trying to create the curvaHermite [") + name + QString("] without any geometria defined !!"));
        return;
    }

    while (!currentGeometry.isNull()) {
        Curve curve = getCurveHermite(parser, &currentGeometry, color);
        if (curve.isNull()) {
            parser->errors.append(QString("Error parsing one of the curves of curvaHermite: ") + name);
            return;
        }
        curves.append(curve);
        currentGeometry = currentGeometry.nextSiblingElement(geometryName);
    }

    if (curves.size() == 1) {
        parser->curves[name] = curves[0];
        return;
    }

    parser->continuousCurves[name] = curves;
}

static void parseCurveBSpline(XmlParser* parser, QDomElement* elem)
{
    QString name = getName(parser, elem);
    QColor color = getColor(parser, elem);

    if (name.isNull()) {
        return;
    }

    QList<Point> points = getPoints(parser, elem, name);
    if (points.size() < 4) {
        parser->errors.append(QString("Error, trying to create a bspline with less than 4 points"));
        return;
    }

    parser->curves[name] = CurveBSpline(points, color.red(), color.green(), color.blue());
}

static void parseObject3D(XmlParser* parser, QDomElement* elem)
{
    QString name = getName(parser, elem);
    QColor color = getColor(parser, elem);
    QDomElement pointsElem  = elem->firstChildElement(QString("pontos"));
    QDomElement arestasElem = elem->firstChildElement(QString("arestas"));
    QString arestaName = QString("aresta");

    if (name.isNull()) {
        return;
    }

    if (pointsElem.isNull()) {
        parser->errors.append(QString("Error, cannot found <pontos> while parsing object 3D: ") + name);
        return;
    }

    if (arestasElem.isNull()) {
        parser->errors.append(QString("Error, cannot found <arestas> while parsing object 3D: ") + name);
        return;
    }

    QList<Point> points = getPoints(parser, &pointsElem, name);
    QList<Wire> wires;
    QDomElement currentAresta = arestasElem.firstChildElement(arestaName);

    while (!currentAresta.isNull()) {
        QDomAttr v1 = currentAresta.attributeNode("v1");
        QDomAttr v2 = currentAresta.attributeNode("v2");

        if (v1.isNull() || v2.isNull()) {
            parser->errors.append(QString("Error, getting v1 or v2 from <aresta> !!"));
            return;
        }

        int v1i = v1.value().toInt();
        int v2i = v2.value().toInt();

        if ((v1i < 0) || (v1i >= points.size()) || (v2i < 0) || (v2i >= points.size())) {
            parser->errors.append(QString("Error, invalid v1 or v2 from <aresta> !!"));
            return;
        }

        wires.append(Wire(points[v1i], points[v2i]));
        currentAresta = currentAresta.nextSiblingElement(arestaName);
    }

    parser->wireframes[name] = WireFrame(Object3D(wires, color.red(), color.green(), color.blue()));
}

static void parseWindow(XmlParser* parser, QDomElement* elem)
{
    QDomElement wminE = elem->firstChildElement(QString("wmin"));
    QDomElement wmaxE = elem->firstChildElement(QString("wmax"));
    QDomElement copE  = elem->firstChildElement(QString("cop"));

    if (wminE.isNull() || copE.isNull() || wmaxE.isNull()) {
        parser->errors.append(QString("Error: missing parameters from window element !!"));
        return;
    }

    if (parser->window) {
        parser->errors.append(QString("Error, there is 2 windows on the document, keeping the first window !!"));
        return;
    }

    Point min = getPoint(parser, &wminE);
    Point max = getPoint(parser, &wmaxE);
    Point cop = getPoint(parser, &copE);

    if (min.isNull() || max.isNull() || cop.isNull()) {
        parser->errors.append(QString("Error parsing parameters from window element !!"));
        return;
    }

    parser->window = new WindowOrtogonal(min, max, cop);
}

/****************************/
/* Class methods definition */
/****************************/

XmlParser::XmlParser(const QString& fileName) : window(0)
{
    QFile file(fileName);
    QString error;
    int errorLine = 0;
    int errorCol  = 0;

    this->doc = QDomDocument("CGXmlParser");


    if (!file.open(QIODevice::ReadOnly)) {
        this->errors.append(QString("Error opening file: ") + fileName + QString(" !"));
        return;
    }
    if (!this->doc.setContent(&file, &error, &errorLine, &errorCol)) {
        file.close();
        this->errors.append(QString("Error [") + error + QString("] at line [") +
                            QString(errorLine) + QString("] at collum [") + QString(errorCol) +
                            QString("] parsing file [") + fileName + QString("] !"));
        return;
    }
    file.close();

    this->parsers[pointName]        = parsePoint;
    this->parsers[wireName]         = parseWire;
    this->parsers[wireFrameName]    = parseWireFrame;
    this->parsers[curveHermiteName] = parseCurveHermite;
    this->parsers[curveBSplineName] = parseCurveBSpline;
    this->parsers[object3DName]     = parseObject3D;
    this->parsers[windowName]       = parseWindow;

    this->parseDocument();
}

void XmlParser::parseDocument()
{
    QDomNode rootNode = this->doc.firstChild();
    QDomNode currentNode;

    while(!rootNode.isNull()) {
        QDomElement e = rootNode.toElement(); // try to convert the node to an element.
        if(!e.isNull()) {
            if (e.tagName() == QString("formas")) {
                currentNode = e.firstChild();
                break;
            }
        }
        rootNode = rootNode.nextSibling();
    }

    if (currentNode.isNull()) {
        this->errors.append(QString("Error, invalid xml document !!!"));
    }

    while (!currentNode.isNull()) {
        QDomElement e = currentNode.toElement();
        currentNode = currentNode.nextSibling();

        if (e.isNull()) {
            continue;
        }

        if (this->parsers.contains(e.tagName())) {
            this->parsers[e.tagName()](this, &e);
        } else {
            this->errors.append(QString("Error parsing element: ") + e.tagName());
        }
    }
}

