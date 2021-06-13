#ifndef POINT_H
#define POINT_H

class Point
{
public:
    Point();
    Point(double x, double y);
    Point(double x, double y,double z);
    Point(Point *);
    //Point(const Point&);
    double get_x(){return pos_x;}
    double get_y(){return pos_y;}
    double get_z(){return pos_z;}
    void set_x(double x){this->pos_x = x;}
    void set_y(double y){this->pos_y = y;}
    void set_z(double z){this->pos_z = z;}
private:
    double pos_x;
    double pos_y;
    double pos_z;
};

#endif // POINT_H
