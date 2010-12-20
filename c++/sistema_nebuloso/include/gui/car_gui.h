#ifndef CAR_GUI_H
#define CAR_GUI_H

#include <QPointF>
#include <QGraphicsView>
#include <QGraphicsPolygonItem>

/**
 *  Class that defines how the car is draw and moves on the screen.
 */
class CarGui {

private:
    const static int c = 40;
    const static int l = 10;
    const static int nPontos = 8;
    const static double maxAxisAngle = 30;

    QGraphicsView* drawArea;
    double rotation;
    double speed;

    QGraphicsPolygonItem* currentCar;
    QList<QGraphicsPolygonItem*> drawnCars;
    QVector<QPointF> points;
    QPointF position;

    void draw();

public:
    /**
     *  \brief Class constructor.
     *  Constructs a car.
     *  @param drawArea     - Where the car will be draw.
     *  @param rearPosition - Initial rear position of the car.
     *  @param width        - Car width.
     *  @param height       - Car height.
     *  @param initialAngle - Initial angle of the car.
     */
    CarGui(QGraphicsView* drawArea, QPointF position, double rotation);

    /**
     *  \brief Class destructor.
     */
    ~CarGui();

    void setPos(double x,double y);

    QPointF getPos();

    void stepManeuver(double axisRot);

    void stepManeuver(double axisRot, int speed);

    QPointF getPoint(int index);

    double getRotation();

    void setRotation(double rotation);
    
};

#endif // CAR_GUI_H
