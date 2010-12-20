#include "clipper.h"
#include <QMap>

/* ===========================
   DEFINITION OF INTERNAL DATA
   =========================== */

static QString top("top");
static QString right("right");
static QString bottom("bottom");
static QString left("left");

enum RegionCode {
    IN = 0x00,
    TOP = 0x08,
    BOTTOM = 0x04,
    RIGHT = 0x02,
    LEFT = 0x01,
    BOTTOMRIGHT = 0x06,
    BOTTOMLEFT = 0x05,
    TOPRIGHT = 0x0A,
    TOPLEFT = 0x09,
};

typedef Point (*ClipMethod) (const Point& ,const Point& ,const Point&, double);
static QMap<RegionCode, ClipMethod> clippingMethods;
bool inited = false;

static Point topClipping(const Point& point,const Point& ppcMinPoint,const Point& ppcMaxPoint,double angularCoeficient);
static Point bottomClipping(const Point& point,const Point& ppcMinPoint,const Point& ppcMaxPoint,double angularCoeficient);
static Point topBottomClipping(const Point& point,const Point& ppcMinPoint,const Point& ppcMaxPoint,double angularCoeficient, char side);
static Point rightClipping(const Point& point,const Point& ppcMinPoint,const Point& ppcMaxPoint,double angularCoeficient);
static Point leftClipping(const Point& point,const Point& ppcMinPoint,const Point& ppcMaxPoint,double angularCoeficient);
static Point leftOrRightClipping(const Point& point,const Point& ppcMinPoint,const Point& ppcMaxPoint,double angularCoeficient, char side);
static Point topRightClipping(const Point& point,const Point& ppcMinPoint,const Point& ppcMaxPoint,double angularCoeficient);
static Point topLeftClipping(const Point& point,const Point& ppcMinPoint,const Point& ppcMaxPoint,double angularCoeficient);
static Point bottomRightClipping(const Point& point,const Point& ppcMinPoint,const Point& ppcMaxPoint,double angularCoeficient);
static Point bottomLeftClipping(const Point& point,const Point& ppcMinPoint,const Point& ppcMaxPoint,double angularCoeficient);
static Point compositeClipping(const Point& point,const Point& ppcMinPoint,const Point& ppcMaxPoint,double angularCoeficient, char clipping1,char clipping2);
static RegionCode calculateRegionCode(const Point& point,const Point& ppcMinPoint,const Point& ppcMaxPoint);
static const QMap<QString, QList<Point> > splitWindowSides(const Point &ppcMinPoint, const Point &ppcMaxPoint);
static const Wire clipWire(const Wire& wire, const Point& ppcMinPoint, const Point& ppcMaxPoint, bool* clipped);
static double angularCoefficient(const Wire& wire);
static void insertInWindowSide(const Point& point, QMap<QString, QList<Point> >& windowSides);
static const QList<Point> concatenateWindowSides(const QMap<QString, QList<Point> >& windowSides);

void clipper::init()
{
    if(inited) {
        return;
    }
    inited = true;
    clippingMethods[TOP] = &topClipping;
    clippingMethods[BOTTOM] = &bottomClipping;
    clippingMethods[RIGHT] = &rightClipping;
    clippingMethods[LEFT] = &leftClipping;
    clippingMethods[TOPRIGHT] = &topRightClipping;
    clippingMethods[TOPLEFT] = &topLeftClipping;
    clippingMethods[BOTTOMRIGHT] = &bottomRightClipping;
    clippingMethods[BOTTOMLEFT] = &bottomLeftClipping;
}

QList<Point> clipper::clipPoints(const QList<Point> points, const Point& min, const Point& max)
{
    QList<Point> clipped;
    bool top,bottom,left,right;
    double maxX = max.getX();
    double maxY = max.getY();
    double minX = min.getX();
    double minY = min.getY();

    for(int i = 0; i < points.size();i++)
    {
        top = points[i].getY() <= maxY;
        bottom = points[i].getY() >= minY;
        left = points[i].getX() >= minX;
        right = points[i].getX() <= maxX;
        if (top && bottom && left && right)
        {
            clipped.append(points[i]);
        }
    }

    return clipped;
}

QList<Wire> clipper::clipWires(const QList<Wire>& wires, const Point& min, const Point& max)
{
    QList<Wire> clippedWires;
    RegionCode rc0;
    RegionCode rcF;

    for(int i = 0; i < wires.size();i++){
        Wire currentWire = wires[i];

        rc0 = calculateRegionCode(currentWire.getFirstPoint(),min,max);
        rcF = calculateRegionCode(currentWire.getSecondPoint(),min,max);

        if((rc0 == IN) && (rcF == IN)) { //completely in

            clippedWires.append(currentWire);

        } else if((rc0 != rcF) && ((rc0&rcF) == IN)) { //partially in

            double m = angularCoefficient(currentWire);
            Point newP0 = currentWire.getFirstPoint();
            Point newPF = currentWire.getSecondPoint();
            if(rc0 != IN) { //P0 off
                newP0 = clippingMethods[rc0](newP0, min, max, m);
            }
            if(rcF != IN) { //pF off
                newPF = clippingMethods[rcF](newPF, min, max, m);
            }
            if((!newP0.isNull()) &&  (!newPF.isNull())) {
                clippedWires.append(Wire(newP0,newPF, currentWire.getRed(), currentWire.getGreen(), currentWire.getBlue()));
            }
        }
    }

    return clippedWires;
}


QList<WireFrame> clipper::clipWireFrames(const QList<WireFrame>& wireFrames,  const Point& min,  const Point& max)
{
    QList<WireFrame> clipped;
    for (int i = 0; i < wireFrames.size(); i++)
    {
        QList<Wire> wires = wireFrames[i].getWires();
        QList<Point> wireFramePoints;

        for(int j = 0; j < wires.size(); j++){
            wireFramePoints.append(wires[j].getFirstPoint());
            wireFramePoints.append(wires[j].getSecondPoint());
        }

        int wireFrameSize = wireFramePoints.size();

        //init lists
        QList<Point> visibleWireFramePoints = wireFramePoints;
        QList<Point> outToInPoints;
        QMap<QString, QList<Point> > windowSides = splitWindowSides(min,max);

        // when there are no cuts (or 1 cut only) through the window edges,
        // this var indicates if the polygon is completely in or completely out
        int linesInWindow = 0;
        int addedPoints = 0;

        for(int j = 0; j < wireFrameSize; j++)
        {
            Point edge0 = wireFramePoints[j];
            Point edgeF = wireFramePoints[(j + 1) % wireFrameSize];

            Wire wire = Wire(edge0,edgeF);
            bool clipped = false;
            Wire wireClipped = clipWire(wire, min, max, &clipped);

            if(clipped){
                Point newEdge0 = wireClipped.getFirstPoint();
                Point newEdgeF = wireClipped.getSecondPoint();
		
                if(newEdge0 != newEdgeF){ //verify if it is special case
                    linesInWindow++;
                    if(newEdge0 != edge0 && newEdgeF == edgeF){
                        // edgeF inside, edge0 outside -> OutToIn
                        visibleWireFramePoints.insert(j + addedPoints + 1, newEdge0);
                        addedPoints += 1;
                        outToInPoints.append(newEdge0);
                        insertInWindowSide(newEdge0,windowSides);
                    }else if(newEdge0 == edge0 && newEdgeF != edgeF){
                            // edge0 inside, edgeF outside -> InToOut
                            visibleWireFramePoints.insert(j + addedPoints + 1, newEdgeF);
                            addedPoints += 1;
                            insertInWindowSide(newEdgeF, windowSides);
                    }else if(newEdge0!=edge0 && newEdgeF != edgeF){
                            // edge0 outside, edgeF outside -> OutToInToOut
                            visibleWireFramePoints.insert(j + addedPoints + 1, newEdge0);
                            addedPoints += 1;
                            insertInWindowSide(newEdge0, windowSides);
                            outToInPoints.append(newEdge0);

                            visibleWireFramePoints.insert(j + addedPoints + 1, newEdgeF);
                            addedPoints += 1;
                            insertInWindowSide(newEdgeF,windowSides);
                     }
                    // else: line totally in the window
                }//(!specialCase)

            } else {
                if (wireClipped == wire) {
                    //line totally in
                    linesInWindow++;
                } //else the line is totally out
            }
        }

        //lists are ready, lets build the polygon
        QList<Point> segmentedWindowPoints = concatenateWindowSides(windowSides);
	
        if(!outToInPoints.empty())
        {
            int visibleLen = visibleWireFramePoints.size();
            int segmentedLen = segmentedWindowPoints.size();
            QList<Point> tempPoints;
            while(outToInPoints.size() > 0)
            {
                Point firstOutToIn = outToInPoints[0];
                outToInPoints.removeAt(0);
		tempPoints.clear();
                tempPoints.append(firstOutToIn);

                while (true) {
                    int indexActual = (visibleWireFramePoints.indexOf(firstOutToIn) + 1) % visibleLen;
                    Point actual = visibleWireFramePoints[indexActual];
                    while(wireFramePoints.contains(actual))
                    {
                        tempPoints.append(actual);
                        indexActual = (indexActual + 1) % visibleLen;
                        actual = visibleWireFramePoints[indexActual];
                    }
                    tempPoints.append(actual);

                    //changing list
                    indexActual = (segmentedWindowPoints.indexOf(actual) + 1) % segmentedLen;
                    actual = segmentedWindowPoints[indexActual];

                    //list of points that forms the window extremes.
                    QList<Point> windowPoints;
                    windowPoints.append(Point(min.getX(),max.getY()));
                    windowPoints.append(max);
                    windowPoints.append(Point(max.getX(),min.getY()));
                    windowPoints.append(min);

                    while (windowPoints.contains(actual)) {
                        tempPoints.append((actual));
                        indexActual = (indexActual + 1) % segmentedLen;
                        actual = segmentedWindowPoints[indexActual];
                        // actual must be an out-to-in point
                        // continue in same polygon, or already finished?
                    }
                    if(actual == firstOutToIn) {
                        break;//finished
                    } else if( outToInPoints.contains(actual)) { //new out-to-in, continue
                        outToInPoints.removeOne(actual);
                        firstOutToIn = actual;
                        tempPoints.append(actual);
                    }else {
                        break; //start new polygon
                    }
               }
               //creating new wireframes
               QList<Wire> wires;
               for (int k = 0; k < tempPoints.size() - 1;k++) {
                   wires.append(Wire(tempPoints[k],tempPoints[k+1]));
                   
               }
	       wires.append(Wire(tempPoints[tempPoints.size() - 1], tempPoints[0]));
               clipped.append(WireFrame(wires,wireFrames[i].isFilled(), wireFrames[i].getRed(),wireFrames[i].getGreen(),wireFrames[i].getBlue()));
               tempPoints.clear();
            }
        } else if (linesInWindow > 1) {
            clipped.append(wireFrames[i]);
        }
    }

    return clipped;
}

/* =========================================
   DEFINITION OF INTERNAL CLIPPING FUNCTIONS
   ========================================= */

static const QMap<QString, QList<Point> > splitWindowSides(const Point &ppcMinPoint, const Point &ppcMaxPoint)
{
    QMap<QString, QList<Point> > windowSides;
    QList<Point> topList;
    QList<Point> rightList;
    QList<Point> bottomList;
    QList<Point> leftList;

    topList.append(Point(ppcMinPoint.getX(),ppcMaxPoint.getY()));
    topList.append(ppcMaxPoint);

    rightList.append(ppcMaxPoint);
    rightList.append(Point(ppcMaxPoint.getX(),ppcMinPoint.getY()));

    bottomList.append(Point(ppcMaxPoint.getX(),ppcMinPoint.getY()));
    bottomList.append(ppcMinPoint);

    leftList.append(ppcMinPoint);
    leftList.append(Point(ppcMinPoint.getX(),ppcMaxPoint.getY()));

    windowSides[top] = topList;
    windowSides[right] = rightList;
    windowSides[bottom] = bottomList;
    windowSides[left] = leftList;

    return windowSides;
}


static const QList<Point> concatenateWindowSides(const QMap<QString, QList<Point> >& windowSides)
{
    QList<Point> segmentedWindowPoints;

    QList<Point> ptop    = windowSides[top];
    QList<Point> pright  = windowSides[right];
    QList<Point> pbottom = windowSides[bottom];
    QList<Point> pleft   = windowSides[left];

    ptop.removeLast();
    pright.removeLast();
    pbottom.removeLast();
    pleft.removeLast();

    segmentedWindowPoints.append(ptop);
    segmentedWindowPoints.append(pright);
    segmentedWindowPoints.append(pbottom);
    segmentedWindowPoints.append(pleft);

    return segmentedWindowPoints;
}

static void insertInWindowSide(const Point& point, QMap<QString, QList<Point> >& windowSides)
{
    //supose side is left
    QString side = left;
    bool is_x = false;
    int sign = 1; //side is one of crescent coordinates (left or top)

    Point topLeft = windowSides[top][0];
    Point bottomRight = windowSides[bottom][0];
    if (point.getY() == topLeft.getY()) {
        side = top;
        is_x = true;
    } else if(point.getX() == bottomRight.getX()) {
        side = right;
        sign= -1;
    } else if(point.getY() == bottomRight.getY()) {
        side = bottom;
        is_x = true;
        sign = -1;
    }

    QList<Point>& sidePoints = windowSides[side];
    int i = 0;
    Point actualPoint = sidePoints[i];

    double valueToTest;
    if (is_x) {
        valueToTest = sign * point.getX();
        while( ((sign * actualPoint.getX()) < valueToTest) && (i < sidePoints.size()) ) {
            i++;
            actualPoint = sidePoints[i];
        }
    } else {
        valueToTest = sign * point.getY();
        while( ((sign * actualPoint.getY()) < valueToTest) && (i < sidePoints.size()) ) {
            i++;
            actualPoint = sidePoints[i];
        }
    }
    sidePoints.insert(i,point);
}

static const Wire clipWire(const Wire& wire, const Point& ppcMinPoint, const Point& ppcMaxPoint, bool* clipped)
{

    RegionCode rc0 = calculateRegionCode(wire.getFirstPoint(),ppcMinPoint,ppcMaxPoint);
    RegionCode rcF = calculateRegionCode(wire.getSecondPoint(),ppcMinPoint,ppcMaxPoint);

    if((rc0 == IN) && (rcF == IN)) { //completely in
        *clipped = false;
        return wire;
    } else if((rc0 != rcF) && ((rc0&rcF) == IN)) { //partially in
        double m = angularCoefficient(wire);
        Point newP0 = wire.getFirstPoint();
        Point newPF = wire.getSecondPoint();
        *clipped = true;

        if(rc0 != IN) { //P0 off
            newP0 = clippingMethods[rc0](newP0, ppcMinPoint, ppcMaxPoint, m);
        }
        if(rcF != IN) { //pF off
            newPF = clippingMethods[rcF](newPF, ppcMinPoint, ppcMaxPoint, m);
        }
        return Wire(newP0,newPF);
    }

    //completely out
    *clipped = false;
    return Wire();
}

static RegionCode calculateRegionCode(const Point& point,const Point& ppcMinPoint,const Point& ppcMaxPoint)
{
    if(point.getX() < ppcMinPoint.getX()) {
        if(point.getY() < ppcMinPoint.getY()) {
            return BOTTOMLEFT;
        }
        else if(point.getY() > ppcMaxPoint.getY()) {
            return TOPLEFT;
        }
        else {
            return LEFT;
        }
    }

    if(point.getX() > ppcMaxPoint.getX()) {
        if(point.getY() < ppcMinPoint.getY()) {
            return BOTTOMRIGHT;
        }
        else if(point.getY() > ppcMaxPoint.getY()) {
            return TOPRIGHT;
        }
        else {
            return RIGHT;
        }
    }
    if((point.getX() > ppcMinPoint.getX()) && (point.getX() < ppcMaxPoint.getX())) {
        if(point.getY() < ppcMinPoint.getY()) {
            return BOTTOM;
        }
        else if(point.getY() > ppcMaxPoint.getY()) {
            return TOP;
        }
    }
    return IN;
}

static double angularCoefficient(const Wire& wire)
{
    double angularCoefficient;
    if ((wire.getSecondPoint().getX() - wire.getFirstPoint().getX()) == 0.0)
                angularCoefficient = 0.0;
            else
                angularCoefficient = (wire.getSecondPoint().getY() - wire.getFirstPoint().getY()) / (wire.getSecondPoint().getX() - wire.getFirstPoint().getX());
    return angularCoefficient;
}

static Point topClipping(const Point& point, const Point& ppcMinPoint, const Point& ppcMaxPoint, double angularCoeficient)
{
    return topBottomClipping(point, ppcMinPoint, ppcMaxPoint, angularCoeficient,'t');
}

static Point topBottomClipping(const Point& point, const Point& ppcMinPoint, const Point& ppcMaxPoint, double angularCoeficient, char side)
{
    double yppcWindow;
    double xIntersec;
    if(side == 'b')
        yppcWindow = ppcMinPoint.getY();
    else if(side == 't')
        yppcWindow = ppcMaxPoint.getY();
    if(angularCoeficient != 0)
        xIntersec = point.getX() + (yppcWindow - point.getY()) / angularCoeficient;
    else
        xIntersec = point.getX();

    if((xIntersec < ppcMinPoint.getX()) || (xIntersec > ppcMaxPoint.getX())) {
        return Point();
    }
    return Point(xIntersec,yppcWindow,1);
}

static Point bottomClipping(const Point& point, const Point& ppcMinPoint, const Point& ppcMaxPoint, double angularCoeficient)
{
    return topBottomClipping(point, ppcMinPoint, ppcMaxPoint, angularCoeficient, 'b');
}

static Point rightClipping(const Point& point, const Point& ppcMinPoint, const Point& ppcMaxPoint, double angularCoeficient)
{
    return leftOrRightClipping(point,ppcMinPoint,ppcMaxPoint,angularCoeficient,'r');
}

static Point leftClipping(const Point& point, const Point& ppcMinPoint, const Point& ppcMaxPoint, double angularCoeficient)
{
    return leftOrRightClipping(point,ppcMinPoint,ppcMaxPoint,angularCoeficient,'l');
}

static Point leftOrRightClipping(const Point& point, const Point& ppcMinPoint, const Point& ppcMaxPoint, double angularCoeficient, char side)
{
    double xppcWindow;
    double yIntersec;
    if(side == 'l')
        xppcWindow = ppcMinPoint.getX();
    else if(side == 'r')
        xppcWindow = ppcMaxPoint.getX();

    yIntersec = angularCoeficient * (xppcWindow - point.getX()) + point.getY();
    if((yIntersec < ppcMinPoint.getY()) || yIntersec > ppcMaxPoint.getY()) {
        return Point();
    }

    return Point(xppcWindow,yIntersec,1);
}

static Point topRightClipping(const Point& point, const Point& ppcMinPoint, const Point& ppcMaxPoint, double angularCoeficient){
    return compositeClipping(point,ppcMinPoint,ppcMaxPoint,angularCoeficient,'t','r');
}

static Point topLeftClipping(const Point& point, const Point& ppcMinPoint, const Point& ppcMaxPoint, double angularCoeficient){
    return compositeClipping(point,ppcMinPoint,ppcMaxPoint,angularCoeficient,'t','l');
}

static Point bottomRightClipping(const Point& point, const Point& ppcMinPoint, const Point& ppcMaxPoint, double angularCoeficient){
    return compositeClipping(point,ppcMinPoint,ppcMaxPoint,angularCoeficient,'b','r');
}

static Point bottomLeftClipping(const Point& point, const Point& ppcMinPoint, const Point& ppcMaxPoint, double angularCoeficient){
    return compositeClipping(point,ppcMinPoint,ppcMaxPoint,angularCoeficient,'b','l');
}

static Point compositeClipping(const Point& point, const Point& ppcMinPoint, const Point& ppcMaxPoint, double angularCoeficient, char clipping1, char clipping2){
    Point newP = topClipping(point,ppcMinPoint,ppcMaxPoint,angularCoeficient);
    if (clipping1 == 't') {
        newP = topClipping(point,ppcMinPoint,ppcMaxPoint,angularCoeficient);
    }
    else if(clipping1 == 'b') {
        newP = bottomClipping(point,ppcMinPoint,ppcMaxPoint,angularCoeficient);
    }
    if (newP.isNull()) {
        if(clipping2 == 'r') {
            newP = rightClipping(point,ppcMinPoint,ppcMaxPoint,angularCoeficient);
        } else if(clipping2 == 'l') {
            newP = leftClipping(point,ppcMinPoint,ppcMaxPoint,angularCoeficient);
        }
    }
    return newP;
}





