#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    group = new QGraphicsItemGroup(0);
    light_x_coor = 400;
    light_y_coor = 300;
    cart_x_coor = 400;
    cart_y_coor = 300;
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    scene->addItem(group);
    ui->graphicsView->setScene(scene);\
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->centerOn(400,300);
    ui->graphicsView->setMaximumHeight(600);
    ui->graphicsView->setMaximumWidth(800);
    ui->graphicsView->AnchorViewCenter;
    lights.clear();
}

void MainWindow::on_pushButton_clicked(){

    if(light_x_coor == 0){
        light_x_coor = 800;
    }
    else{
        light_x_coor-=10;
    }
    ui->label->setText(QString::number(light_x_coor));
}
void MainWindow::on_pushButton_2_clicked(){
    if(light_x_coor == 800){
        light_x_coor = 0;
    }
    else{
        light_x_coor+=10;
    }
    ui->label->setText(QString::number(light_x_coor));
}
void MainWindow::on_pushButton_3_clicked(){
    if(light_y_coor == 0){
        light_y_coor = 600;
    }
    else{
        light_y_coor-=10;
    }
    ui->label_2->setText(QString::number(light_y_coor));

}
void MainWindow::on_pushButton_4_clicked(){
    if(light_y_coor == 600){
        light_y_coor = 0;
    }
    else{
        light_y_coor+=10;
    }
    ui->label_2->setText(QString::number(light_y_coor));
}
void MainWindow::on_pushButton_5_clicked(){

    const QBrush &brush = QBrush(Qt::SolidPattern);
    //QGraphicsItemGroup *group = new QGraphicsItemGroup(0);
    QGraphicsEllipseItem* test = new QGraphicsEllipseItem((qreal)light_x_coor,(qreal)light_y_coor,10,10);
    test->setBrush(brush);
    //scene->addItem(test);
    group->addToGroup(test);
    //scene->addItem(group);//
    ui->graphicsView->setScene(scene);
    QPoint* p = new QPoint(light_x_coor, light_y_coor);
    lights.push_back(p);

    for(int i = 0; i < lights.size(); i++)
        cout<<lights[i]->x()<< " " << lights[i]->y() << endl << endl;
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_6_clicked()
{
    if(cart_x_coor == 0){
        cart_x_coor = 800;
    }
    else{
        cart_x_coor-=10;
    }
    ui->label_3->setText(QString::number(cart_x_coor));
}

void MainWindow::on_pushButton_7_clicked()
{
    if(cart_x_coor == 800){
        cart_x_coor = 0;
    }
    else{
        cart_x_coor+=10;
    }
    ui->label_3->setText(QString::number(cart_x_coor));
}

void MainWindow::on_pushButton_8_clicked()
{
    if(cart_y_coor == 0){
        cart_y_coor = 600;
    }
    else{
        cart_y_coor-=10;
    }
    ui->label_4->setText(QString::number(cart_y_coor));
}

void MainWindow::on_pushButton_9_clicked()
{
    if(cart_y_coor == 600){
        cart_y_coor = 0;
    }
    else{
        cart_y_coor+=10;
    }
    ui->label_4->setText(QString::number(cart_y_coor));
}

void MainWindow::on_pushButton_10_clicked()
{
    const QBrush &brush = QBrush(Qt::SolidPattern);
    //QGraphicsItemGroup *group = new QGraphicsItemGroup(0);
    QGraphicsEllipseItem* test = new QGraphicsEllipseItem((qreal)cart_x_coor,(qreal)cart_y_coor,20,5);
    test->setBrush(brush);
    //scene->addItem(test);
    group->addToGroup(test);
    //scene->addItem(group);//
    ui->graphicsView->setScene(scene);
    QPoint* p = new QPoint(cart_x_coor, cart_y_coor);
    carts.push_back(p);

    for(int i = 0; i < carts.size(); i++)
        cout<<carts[i]->x()<< " " << carts[i]->y() << endl << endl;
}

void MainWindow::paintEvent(QPaintEvent *event)
{

}
