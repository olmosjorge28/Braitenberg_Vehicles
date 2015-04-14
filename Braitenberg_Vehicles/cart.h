#ifndef CART_H
#define CART_H

#include <QMainWindow>
#include <QApplication>
#include <QtWidgets>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QLabel>
#include <QPainter>
#include <vector>
#include <QVector>

class cart
{
public:
    cart();
    ~cart();
private:

    int x;
    int y;
    int rotation;

    double leftMotor;
    double rightMotor;

    //QGraphicsItem car;
    //QGraphicsItem sensor1;
    //QGraphicsItem sensor2;
};

#endif // CART_H
