#include "point.h"

Point::Point()
{

}

Point::Point(double x, double y)
{
    this->set_x(x);
    this->set_y(y);
}

Point::Point(double x, double y, double z)
{
    this->set_x(x);
    this->set_y(y);
    this->set_z(z);
}
