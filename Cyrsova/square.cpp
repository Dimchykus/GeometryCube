#include "square.h"
#include <QRegExp>
#define PI 3.14159265

Square::Square()
{

}

Square::Square(Point point)
{
    this->AddPoint(point);
}

Square::Square(double x, double y)
{
    this->AddPoint(x,y);
}

Square::Square(const Square &obj)
{
    this->points = obj.points;
}

Square::~Square()
{
    points.clear();
}

double Square::CalculateSquare()
{
    if(this->PointCount() != 4){
        return 0;
    }
    double square = 0;
    Point cross = CrossingPoint3D(points[0],points[1],points[2],points[3]);
    double cos = AngleBetweenLines(points[0],cross,cross,points[3]);
    double si = sin(acos (cos)); //переведення косинуса у синус
    square = 0.5 * DistanceBetweenPoints(points[0],points[1]) * DistanceBetweenPoints(points[2],points[3]) * si;
    return square;
}

double Square::CalculatePerimetr()
{
    double side1 = DistanceBetweenPoints(points[0],points[2]);
    double side2 = DistanceBetweenPoints(points[2],points[1]);
    double side3 = DistanceBetweenPoints(points[1],points[3]);
    double side4 = DistanceBetweenPoints(points[3],points[0]);
    return side1 + side2 + side3 + side4;
}

void Square::AddPoint(Point point)
{
    points.append(point);
}

void Square::AddPoint(double x, double y, double z)
{
    x = floor( x*10 )/10;//заокруглення
    y = floor( y*10 )/10;
    z = floor( z*10 )/10;
    Point temp;
    temp.set_x(x);
    temp.set_y(y);
    temp.set_z(z);
    points.append(temp);
}

void Square::RemovePoint(int x)
{
    points.remove(x);
}


Point Square::GetPoint(int i)
{
    return points[i];
}

void Square::ClearPoints()
{
    points.clear();
}

QVector<double> Square::GetxVector()
{
    QVector<double> vec;
    for(int i = 0; i<PointCount(); i++)
    {
        vec.append(points[i].get_x());
    }
    return vec;
}

QVector<double> Square::GetyVector()
{
    QVector<double> vec;
    for(int i = 0; i<PointCount(); i++)
    {
        vec.append(points[i].get_y()); //створення вектора
    }
    return vec;
}

void Square::SetxPoint(int iter, double num)
{
    num = floor( num*10 )/10;
    points[iter].set_x(num);
}

void Square::SetyPoint(int iter, double num)
{
    num = floor( num*10 )/10;
    points[iter].set_y(num);
}

void Square::SetzPoint(int iter, double num)
{
    num = floor( num*10 )/10;
    points[iter].set_z(num);
}

void Square::SetxyzPoint(int iter, double x, double y, double z)
{
    x = floor( x*10 )/10;
    points[iter].set_x(x);

    y = floor( y*10 )/10;
    points[iter].set_y(y);

    z = floor( z*10 )/10;
    points[iter].set_z(z);
}

int Square::PointCount()
{
    return points.size();
}

Point Square::CrossingPoint3D(Point a, Point b, Point c, Point d)
{

    double x11 = a.get_x(), y11 = a.get_y(), z11 = a.get_z();
    double x12 = b.get_x(), y12 = b.get_y(), z12 = b.get_z();
    double x21 = c.get_x(), y21 = c.get_y(), z21 = c.get_z();
    double x22 = d.get_x(), y22 = d.get_y(), z22 = d.get_z();

    double a1 ,b1, c1, a2 ,b2, c2;
    a1 = x12 - x11;
    b1 = y12 - y11;
    c1 = z12 - z11;//напрямні вектори

    a2 = x22 - x21;
    b2 = y22 - y21;
    c2 = z22 - z21;//напрямні вектори

    double x, y, z, u;

    double x11t = x11, x21t = x21, y11t =y11, y21t = y21, a1t = a1, a2t=a2, b2t=b2;
    if(a1 == 0 && b2 == 0){
        x = x12;
        y = y21;
        z = z12;
    }
    else if(a1 != 0){
        x11t *= b1/a1;
        a1t *= b1/a1;
        x21t *= b1/a1;
        a2t *= b1/a1;

        u = (y21t-x21t+x11t-y11t)/(a2t-b2t); //знаходження коефіціенту

        x = x21 + u*a2;
        y = y21 + u*b2;//знаходження очки перетину
        z = z21 + u*c2;
    }else{
        x11t = x11, x21t = x21, y11t =y11, y21t = y21, a1t = a1, a2t=a2, b2t=b2;
        x11t *= b2/a2;
        a1t *= b2/a2;
        x21t *= b2/a2;
        a2t *= b2/a2;

        u = (y21t-x21t+x11t-y11t)/(a2t-b2t);

        x = x21 + u*a2;
        y = y21 + u*b2;
        z = z21 + u*c2;
    }
    Point pos;
    pos.set_x(x);
    pos.set_y(y);
    pos.set_z(z);
    return pos;
}

Point Square::CrossingPoint2D(Point a, Point b, Point c, Point d)
{
    double x1 = a.get_x(), y1 = a.get_y();
    double x2 = b.get_x(), y2 = b.get_y();
    double x3 = c.get_x(), y3 = c.get_y();
    double x4 = d.get_x(), y4 = d.get_y();
    double x, y;
    x = ((x1*y2-y1*x2)*(x3-x4)-(x1-x2)*(x3*y4-y3*x4))/((x1-x2)*(y3-y4)-(y1-y2)*(x3-x4));
    y = ((x1*y2-y1*x2)*(y3-y4)-(y1-y2)*(x3*y4-y3*x4))/((x1-x2)*(y3-y4)-(y1-y2)*(x3-x4));
    Point pos;
    pos.set_x(x);
    pos.set_y(y);
    pos.set_z(0);
    return pos;
}

bool Square::IsCrossing(Point a, Point b, Point c, Point d)
{
    double x11 = a.get_x(), y11 = a.get_y(), z11 = a.get_z();
    double x12 = b.get_x(), y12 = b.get_y(), z12 = b.get_z();
    double x21 = c.get_x(), y21 = c.get_y(), z21 = c.get_z();
    double x22 = d.get_x(), y22 = d.get_y(), z22 = d.get_z();

    double a1 ,b1, c1, a2 ,b2, c2, a3 ,b3 ,c3;

    a1 = x12 - x11;
    b1 = y12 - y11;
    c1 = z12 - z11;

    a2 = x22 - x21;
    b2 = y22 - y21;
    c2 = z22 - z21;

    a3 = x21 - x11;
    b3 = y21 - y11;
    c3 = z21 - z11;

    double det1 = a3*b1*c2 + a1*b2*c3 + b3*c1*a2 - a2*b1*c3 - b2*c1*a3 - a1*b3*c2;
    //Визначник матриці 3х3
    //Якщо визначник 0 то перетин існує
    //a3 b3 c3
    //a1 b1 c1
    //a2 b2 c2
    int status = 0;
    Point cross = this->CrossingPoint3D(this->GetPoint(0), this->GetPoint(1), this->GetPoint(2), this->GetPoint(3));
    if(a.get_x()>= b.get_x()){
        if(cross.get_x() <= a.get_x() && cross.get_x() >= b.get_x()){//перевірка чи точка знаходиться у межах лінії

            if(c.get_x()>= d.get_x()){
                if(cross.get_x() <= c.get_x() && cross.get_x() >= d.get_x()){
                    status = 1;
                }
            }else{
                if(cross.get_x() >= c.get_x() && cross.get_x() <= d.get_x()){
                    status = 1;
                }
            }

        }
    }else{
        if(cross.get_x() >= a.get_x() && cross.get_x() <= b.get_x()){

            if(c.get_x()>= d.get_x()){
                if(cross.get_x() <= c.get_x() && cross.get_x() >= d.get_x()){
                    status = 1;
                }
            }else{
                if(cross.get_x() >= c.get_x() && cross.get_x() <= d.get_x()){
                    status = 1;
                }
            }
        }
    }
    if(det1 == 0 && status){
        return 1;
    }else{
        return 0;
    }
}

double Square::DistanceBetweenPoints(double x1, double x2, double y1, double y2, double z1, double z2)
{
    double side1 = fabs(x1-x2), side2 = fabs(y1-y2), side3 = fabs(z1-z2);
    return sqrt(pow(side1,2) + pow(side2,2) + pow(side3,2));
}

double Square::DistanceBetweenPoints(Point x, Point y)
{
    double side1 = fabs(x.get_x()-y.get_x()), side2 = fabs(x.get_y()-y.get_y()), side3 = fabs(x.get_z()-y.get_z());
    return sqrt(pow(side1,2) + pow(side2,2) + pow(side3,2));
}

double Square::DistanceBetweenPoints2D(Point x, Point y)
{
    double side1 = fabs(x.get_x()-y.get_x()), side2 = fabs(x.get_y()-y.get_y());
    return sqrt(pow(side1,2) + pow(side2,2));
}


void Square::SwapPoints(double x, double y)
{
    Point temp = this->points[x];
    this->points[x] = this->points[y];
    this->points[y] = temp;
}

bool Square::IsInCircle(Point a, Point b, Point c, Point d)
{
    qDebug()<<DistanceBetweenPoints2D(a,c) << DistanceBetweenPoints2D(d,b) << DistanceBetweenPoints2D(a,d) << DistanceBetweenPoints2D(b,c);
    if(DistanceBetweenPoints2D(a,c) + DistanceBetweenPoints2D(b,d) == DistanceBetweenPoints2D(a,d) + DistanceBetweenPoints2D(b,c))
    {
        return true;
    }else{
        return false;
    }
}

bool Square::IsOutCircle(Point a, Point b, Point c, Point d)
{
    qDebug()<<AngleBetweenLines(a,c,c,b)<<AngleBetweenLines(a,d,d,b);
    if(AngleBetweenLines(a,c,c,b) - AngleBetweenLines(a,d,d,b) == 0 && AngleBetweenLines(d,a,a,c) - AngleBetweenLines(d,b,b,c) == 0){
        return true;
    }else{
        return false;
    }
}

Point Square::CircleOutCenter(Point a, Point b, Point c, Point d)
{
    double x11 = a.get_x(), y11 = a.get_y();
    double x12 = b.get_x(), y12 = b.get_y();
    double x21 = c.get_x(), y21 = c.get_y();
    double x22 = d.get_x(), y22 = d.get_y();

    double a11, b11, mx1, my1;
    double a12, b12, mx2, my2;

    a11 = x12 - x11;
    b11 = y12 - y11;//напрямні вектори

    mx1 = (x12+x11)/2;//мередина прямої
    my1 = (y12+y11)/2;

    a12 = x22 - x21;
    b12 = y22 - y21;

    mx2 = (x22+x21)/2;
    my2 = (y22+y21)/2;

    /////////////
    double k1;
    double t21 = 1,t22;
    if(a11==0){
        t22 = my1;
        t21 = 3;
    }else if(b11==0){
        t22 = 3;
        t21 = mx1;
    }else{
        k1 = b11/a11;
        k1 = -1/k1;     //знаходження перпендикулярної прямої
        t22 = k1*t21-k1*mx1+my1;
    }
    /////////////

    double k2;
    double t212 = 1,t222;
    if(a12==0){
        t222 = my2;
        t212 = 3;
    }else if(b12==0){
        t212 = mx2;
        t222 = 3;
    }else{
        k2 = b12/a12;
        k2 = -1/k2;      //знаходдження другої перпендикулярної прямої
        t222 = k2*t212-k2*mx2+my2;
    }
    /////////////

    Point p11(mx1,my1), p12(t21,t22), p21(mx2,my2), p22(t212,t222);


    Point center;
    center = CrossingPoint2D(p11,p12,p21,p22); //точка перетину двох перпендикулярів
    return center;
}

double Square::RadiusOut()
{
    Point center = this->CircleOutCenter(this->GetPoint(0), this->GetPoint(2), this->GetPoint(2), this->GetPoint(1));
    double radius = this->DistanceBetweenPoints(center, this->GetPoint(0));
    return radius;
}

double Square::RadiusIn()
{
    Point center = this->CircleInCenter(this->GetPoint(0), this->GetPoint(1), this->GetPoint(2), this->GetPoint(3));
    double radius = this->DistanceBetweenPointLine(center,this->GetPoint(0), this->GetPoint(3));
    return radius;
}

Point Square::CircleInCenter(Point a2, Point b2, Point c2, Point d2)
{
    double x11 = a2.get_x(), y11 = a2.get_y();
    double x12 = b2.get_x(), y12 = b2.get_y();
    double x21 = c2.get_x(), y21 = c2.get_y();
    double x22 = d2.get_x(), y22 = d2.get_y();

////////////////////////////////////////////////
//    double n,p,g,k;
//    double x = 2, y;
//    double a,b,c,d;
//    n = x11 - x22; n = -n;
//    p = y11 - y22;

//    k = x12 - x22;
//    g = y12 - y22; g = -g;


//        c = sqrt(p*p+n*n);
//        d = sqrt(k*k+g*g);
//        b = -k*y22+g*x22;
//        a = -p*x22+n*y22;

//        double f12,f11 = 5;
//       // qDebug()<<n*p+k*g << n<<p<<k<<g<<c<<d<<b<<a;
////       if(n*p+k*g > 0){
////           y = (d*p*x+d*a-c*g*x-b*c)/(c*k-n*d);
////           f12 = (d*p*f11+d*a-c*g*f11-b*c)/(c*k-n*d);
////           qDebug()<<f11<<f12;
////       }else if(n*p+k*g < 0){
////           y = (d*p*x+d*a+c*g*x+b*c)/(-c*k-n*d);
////           f12 = (d*p*f11+d*a+c*g*f11+b*c)/(-c*k-n*d);
////           qDebug()<<f11<<f12;
////       }else{
////           y = (d*p*x+d*a-c*g*x-b*c)/(c*k-n*d);
////           f12 = (d*p*f11+d*a-c*g*f11-b*c)/(c*k-n*d);
////           qDebug()<<f11<<f12;
////       }
//    if(c*k-n*d == 0){
//        f11 = x21;
//        f12 = 1;
//    }else{
//    //y = (d*p*x+d*a+c*g*x+b*c)/(-c*k-n*d);
//    f12 = (d*p*f11+d*a+c*g*f11+b*c)/(-c*k-n*d);
//    }
//    qDebug()<<f11<<f12;

//    ////////////////////////////////////////////////////

//    double n1,p1,g1,k1;
//    double x1 = 1, y1;
//    double a1,b1,c1,d1;

//    n1 = x21 - x12; n1 = -n1;
//    p1 = y21 - y12;

//    k1 = x22 - x12;
//    g1 = y22 - y12; g1 = -g1;

//        c1 = sqrt(p1*p1+n1*n1);
//        d1 = sqrt(k1*k1+g1*g1);
//        b1 = (-k*y22+g*x22);
//        a1 = -p1*x22+n1*y22;

//       // qDebug()<<n1*p1+k1*g1;
//         double f22,f21 = 5;
////        if(n*p+k*g > 0){
////            y1 = (d1*p1*x1+d1*a1-c1*g1*x1-b1*c1)/(c1*k1-n1*d1);
////            f22 = (d1*p1*f21+d1*a1-c1*g1*f21-b1*c1)/(c1*k1-n1*d1);
////            qDebug()<<f21<<f22;
////        }else if(n*p+k*g < 0){
////            y1 = (d1*p1*x1+d1*a1+c1*g1*x1+b1*c1)/(-c1*k1-n1*d1);
////            f22 = (d1*p1*f21+d1*a1+c1*g1*f21+b1*c1)/(-c1*k1-n1*d1);
////            qDebug()<<f21<<f22;
////        }else{
////            y1 = (d1*p1*x1+d1*a1-c1*g1*x1-b1*c1)/(c1*k1-n1*d1);
////            f22 = (d1*p1*f21+d1*a1-c1*g1*f21-b1*c1)/(c1*k1-n1*d1);
////            qDebug()<<f21<<f22;
////        }

//        y1 = (d1*p1*x1+d1*a1-c1*g1*x1-b1*c1)/(c1*k1-n1*d1);
//        f22 = (d1*p1*f21+d1*a1-c1*g1*f21-b1*c1)/(c1*k1-n1*d1);
//        qDebug()<<"p2. "<<f21<<f22;


//////    ///////////////////////////////////////////////


////     qDebug()<<f11<<f12<<x21<<y21<<f21<<f22<<x1<<y1;
//     Point p11(f11,f12), p12(x21,y21), p21(f21,f22), p22(x1,y1);

//////////////////////////////////////////////////////////
double a11,a12,a21,a22,n,p,x = 1,y;
    a11 = x11 - x21;
    a12 = y11 - y21;
    a21 = x12 - x21;
    a22 = y12 - y21;
    n = sqrt(pow(a11,2) + pow(a12,2));
    p = sqrt(pow(a21,2) + pow(a22,2));
    if(a22*n - a12*p == 0){
        y = 99;
        x = x21;
    }else{
    y = (a11*x*p-a11*x21*p-a12*y21*p-a12*x*n+a21*x21*n+a22*y21*n)/(a22*n-a12*p);
    }
    qDebug()<<"p1. "<<x21<<y21<<x<<y;
    qDebug()<<"1 "<<a11*x*p-a11*x21*p-a12*y21*p-a12*x*n+a21*x21*n+a22*y21*n;
    qDebug()<<"2 "<<a22*n-a12*p;
    //qDebug()<<"3 "<<
    Point p11(x21,y21), p12(x,y);


/////////////////////////////////////////////////////////


    a11 = x12 - x21;
    a12 = y12 - y21;
    a21 = x12 - x22;
    a22 = y12 - y22;
    n = sqrt(pow(a11,2) + pow(a12,2));
    p = sqrt(pow(a21,2) + pow(a22,2));
    if(a22*n - a12*p == 0){
        x = x12;
        y = 99;
    }else{
        y = (a11*x*p-a11*x12*p-a12*y12*p-a12*x*n+a21*x12*n+a22*y12*n)/(a22*n-a12*p);
    }
    qDebug()<<"p2. "<<x12<<y12<<x<<y;
    qDebug()<<"1. "<<a11*x*p-a11*x21*p-a12*y21*p-a12*x*n+a21*x21*n+a22*y21*n;
    qDebug()<<"2. "<<a22*n-a12*p;
    Point p21(x12,y12), p22(x,y);
    Point center;
    center = CrossingPoint2D(p11,p12,p21,p22);
    return center;
}



double Square::AngleBetweenLines(Point a, Point b, Point c, Point d)
{
    double x11 = a.get_x(), y11 = a.get_y(), z11 = a.get_z();
    double x12 = b.get_x(), y12 = b.get_y(), z12 = b.get_z();
    double x21 = c.get_x(), y21 = c.get_y(), z21 = c.get_z();
    double x22 = d.get_x(), y22 = d.get_y(), z22 = d.get_z();
    double ax ,ay, az, bx, by, bz;
    ax = x11 - x12;
    ay = y11 - y12;
    az = z11 - z12;
    bx = x21 - x22;
    by = y21 - y22;
    bz = z21 - z22;
    double co = (fabs(ax*bx+ay*by+az*bz))/(sqrt(pow(ax,2) + pow(ay,2) +pow(az,2) ) * sqrt(pow(bx,2) + pow(by,2) +pow(bz,2) ));
    //косину кута між прямими
    return co;
}

double Square::DistanceBetweenPointLine(Point a, Point l1, Point l2)
{
    double distance;

    double n = l2.get_x() - l1.get_x();
    double p = l2.get_y() - l1.get_y();

     distance = ((l1.get_y() - l2.get_y())*a.get_x()+n*a.get_y()+l1.get_x()*l2.get_y()-l2.get_x()*l1.get_y())/(sqrt(n*n+p*p));
     //distance = (p*a.get_x()+n*a.get_y()+(-p*l1.get_x()+n*l1.get_y()))/(sqrt(n*n+p*p));

    return distance;
}



int operator>>( std::ifstream  &input ,  Square &square)
{

    QRegExp rx("([+-]?[0-9]+[.0-9]*)"); //регулярний вираз, формула тексту
    QStringList list;

    while(input.good()){
        std::string points;
        getline(input,points);
        int pos = 0;
        QString str =  QString::fromStdString(points);
        while ((pos = rx.indexIn(str, pos)) != -1) {//знаходження координат по формулі за допомогою regural expresions
            list << rx.cap(1);
            pos += rx.matchedLength();
        }
    }
    qDebug()<<list;
    if(list.size() == 0){
        qDebug() << "Empty file";
        return -2;
    }
    if(list.size() % 3 != 0){
        qDebug() << "Not enough elements";
        return -1;
    }

    square.points.clear();
    for(int i = 0; i < list.size() ; i+=3){
       square.AddPoint(list[i].toDouble(),list[i+1].toDouble(),list[i+2].toDouble());
    }
    return 0;
}

std::ofstream &operator<<( std::ofstream  &output, Square &square)
{
    qDebug() << "Saving to file";
    for(int i = 0; i< square.PointCount();i++){
        output << square.GetPoint(i).get_x() << " "<< square.GetPoint(i).get_y() << " "<< square.GetPoint(i).get_z() << "\n";
    }
    return output;
}
