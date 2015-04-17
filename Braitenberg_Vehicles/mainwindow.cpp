#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QPainter>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer =new QTimer(this);
    scene.setSceneRect(0,0,800,600);
    ui->graphicsView->setScene(&scene);
    ui->graphicsView->setSceneRect(0,0,800,600);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_function()));
    timeIncrement = 1000;
    timer->start(timeIncrement);
    ui->graphicsView->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_light_clicked()
{
    Lights* newLight = new Lights(ui->lightX->value(),ui->lightY->value());
    cout<< "x = " <<ui->lightX->value()<<" "<< "y=" <<" "<<ui->lightY->value()<<endl;
    scene.addItem(newLight);
    lightPoints.push_back(newLight->getLocation());
    lights.push_back(newLight);
    for(int i = 0; i < vehicles.size(); i++){
            vehicles[i]->addLight(newLight);
    }
    ui->graphicsView->update();
}

void MainWindow::on_vehicle_clicked()
{
    QGenericMatrix<2,2,double> K;
    K(0,0) = ui->K_11->value();
    K(0,1) = ui->K_12->value();
    K(1,0) = ui->K_21->value();
    K(1,1) = ui->K_22->value();
    QPointF Vehicle_Point(ui->vehicleX->value(),ui->vehicleY->value());
    cout<< "x = " <<ui->vehicleX->value()<<" "<< "y=" <<" "<<ui->vehicleY->value()<<endl;
    vehicle* new_vehicle = new vehicle(K,Vehicle_Point,lights, timeIncrement);
    scene.addItem(new_vehicle);
    vehicles.push_back(new_vehicle);
    ui->graphicsView->update();
}


void MainWindow::timer_function(){
    for(int i=0; i<vehicles.size();i++){
        vehicles[i]->UpdateVehiclePos();
    }
    ui->graphicsView->update();
}
