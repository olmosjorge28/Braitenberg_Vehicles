#ifndef VEHICLE_H
#define VEHICLE_H


#include <QGraphicsItem>
#include <QGenericMatrix>
#include "lights.h"
#include <QPainter>
#include <QVector>
#include <qmath.h>
#include <iostream>

/*
class sensor {
private:

public:

}
*/

class vehicle : public QGraphicsItem
{
private:

    QRectF body;
    QRectF wheel1;
    QRectF wheel2;
    QRectF sensor1;
    QRectF sensor2;
    QGenericMatrix<2,2,double> K_Matrix;
    QGenericMatrix<1,2,double> Sensor_Matrix;
    QGenericMatrix<1,2,double> Velocity_Matrix;
    QVector<double> intensitySensor1;
    QVector<double> intensitySensor2;
    QVector<Lights*> lights;
    double xPos;
    double yPos;

    double angle;
    double timeIncrement;
public:

    vehicle(QGenericMatrix<2,2,double> K, QPointF position, QVector<Lights*> l, double time, QGraphicsItem *parent = 0);
    void UpdateVehiclePos();
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
    void addLight(Lights* l);
    QRectF boundingRect() const;
    ~vehicle();
};

#endif // VEHICLE_H
