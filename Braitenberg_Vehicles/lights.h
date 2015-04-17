

#include <QPoint>
#include <QGraphicsEllipseItem>
#include <string>

class Lights : public QGraphicsEllipseItem
{
public:
    Lights(QGraphicsItem* parent = 0);
    Lights(double x, double y, QGraphicsItem* parent = 0);
    QPointF getLocation();
    void setLocation(QPointF newLocation);

private:
    QPointF location;
};





