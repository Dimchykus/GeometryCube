#ifndef LINE_H
#define LINE_H
#include "point.h"

class Line
{
public:
    Line();
    Line(Point start, Point end);
    Line(int start_x, int start_y, int end_X, int end_y);
    int get_start_x(){return start.get_x();}
    int get_start_y(){return start.get_y();}
    int get_end_x(){return end.get_x();}
    int get_end_y(){return end.get_y();}

    void set_start_x(int x){this->start.set_x(x);}
    void set_start_y(int y){this->start.set_y(y);}
    void set_end_x(int x){this->end.set_x(x);}
    void set_end_y(int y){this->end.set_y(y);}


private:
    Point start;
    Point end;
    int lenght;

};

#endif // LINE_H
