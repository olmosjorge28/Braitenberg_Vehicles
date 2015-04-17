#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGenericMatrix>
#include "vehicle.h"
#include <iostream>
#include <QTimer>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QVector<Lights*> lights;
    double timeIncrement;


private slots:
    void on_light_clicked();
    void on_vehicle_clicked();
    void timer_function();

private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
    QVector<QPointF> lightPoints;
    QVector<vehicle*> vehicles;
    QTimer* timer;

};

#endif // MAINWINDOW_H
