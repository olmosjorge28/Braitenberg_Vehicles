#include "lights.h"

Lights::Lights(QGraphicsItem* parent): QGraphicsEllipseItem(parent)
{
    location = QPointF(0,0);
    setRect(0,0,5,5);
}

Lights::Lights(double x, double y, QGraphicsItem* parent): QGraphicsEllipseItem(parent)
{
    location = QPointF(x,y);
    setRect(x,y,5,5);
}

QPointF Lights::getLocation()
{
    return location;
}

void Lights::setLocation(QPointF newLocation)
{
    location = newLocation;
    setRect(location.x(),location.y(),5,5);
}
