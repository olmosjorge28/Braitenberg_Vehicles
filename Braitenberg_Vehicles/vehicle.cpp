#include "vehicle.h"

vehicle::vehicle(QGenericMatrix<2,2,double> K, QPointF position, QVector<Lights*> l, double time, QGraphicsItem *parent) :  QGraphicsItem(parent){

    K_Matrix = K;
    body = QRectF(position.x(), position.y(), 30, 40);
    wheel1 = QRectF((position.x()-5), (position.y()+30), 5, 10);
    wheel2 = QRectF((position.x()+30), (position.y()+30), 5, 10);
    sensor1 = QRectF((position.x() + 5),(position.y() - 5),5,5);
    sensor2= QRectF((position.x()+ 20),(position.y() - 5),5,5);
    lights = l;
    angle = 0;
    xPos = position.x();
    yPos = position.y();
    timeIncrement = time;

}

void vehicle::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget){
    painter->drawRect(body);
    painter->drawRect(wheel1);
    painter->drawRect(wheel2);
    painter->drawEllipse(sensor1);
    painter->drawEllipse(sensor2);
}

vehicle::~vehicle()
{
    ;
}

void vehicle:: UpdateVehiclePos(){

    double sensor1_intensity = 0;
    double sensor2_intensity = 0;
    //n columns by m rows
    for(int i = 0; i < lights.size(); i++) {
        sensor1_intensity += 100/(sqrt(pow((sensor1.center().x() - lights[i]->getLocation().x()), 2) + pow(sensor1.center().x() - lights[i]->getLocation().y(), 2)));
        sensor2_intensity += 100/(sqrt(pow((sensor2.center().x() - lights[i]->getLocation().x()), 2) + pow(sensor2.center().y() - lights[i]->getLocation().y(), 2)));
    }

    double si[2] = {sensor1_intensity,sensor2_intensity};
    std::cout<<"sensor2:" <<sensor1_intensity<<"sensor2: "<<sensor2_intensity<<std::endl;
    Sensor_Matrix.copyDataTo(si);
    double v_l = Velocity_Matrix(0,0);
    double v_r = Velocity_Matrix(1,0);

    double omega = ((v_r - v_l)/(35));
    double R = (35/2)*((v_r+v_l)/(v_r-v_l));
    double ICC_x = this->x() - R*sin(this->rotation()*(3.14159/180));
    double ICC_y = this->y() + R*cos(this->rotation()*(3.14159/180));
    double input_array1[9] = {cos(omega),sin(omega),0, sin(omega), cos(omega), 0, 0, 0,1};
    double input_array2[3] = {this->x() - (ICC_x),this->y()-(ICC_y), this->rotation()*(3.14159/180)};
    double input_array3[3] = {ICC_x,ICC_y,omega};
    std::cout<<"here";
    QGenericMatrix<3,3,double> m1(input_array1);
    QGenericMatrix<1,3,double> m2(input_array2);
    QGenericMatrix<1,3,double> m3(input_array3);
    QGenericMatrix<1,3,double> output;
    output = m1*m2 + m3;
    //double angle = atan(20/35);
    double additionalx = cos(output(2,0))*25;
    double additionaly = sin(output(2,0))*25;
    double x = this->x() + output(0,0)+additionalx;
    double y = this->y() + output(1,0)+additionaly;

    std::cout<<"outpu1:" <<output(0,0)<<"output2: "<<output(1,0)<<std::endl;
    if(x > 800)
        setX(0);

    if(x <= 0)
        setX(800);

    if(y > 600)
        setY(0);

    if(y <= 0)
        setY(600);


    this->setX(x);
    this->setY(y);
    this->setRotation(this->rotation()+ceil((output(2,0)*(180/3.14159))));


}

void vehicle::addLight(Lights* l){
    lights.push_back(l);
}

QRectF vehicle::boundingRect() const{
    return QRectF(0,0,800,600);
}
