#ifndef POLYGON_H
#define POLYGON_H
#include "line.h"
#include "qcustomplot.h"
#include <QVector>
#include <fstream>
#include <string>
#include <math.h>
#include <QMessageBox>
class Square
{
public:
    Square();
    Square(Point);
    Square(double x, double y);
    Square(const Square&);
    ~Square();

    //сетери
    void SetxPoint(int, double);
    void SetyPoint(int, double);
    void SetzPoint(int, double);
    void SetxyzPoint(int, double, double, double = 0);
    void AddPoint(Point);
    void AddPoint(double, double, double = 0);
    void RemovePoint(int);

    //гетери
    Point GetPoint(int);
    QVector<double> GetxVector();
    QVector<double> GetyVector();
    int PointCount();

    void ClearPoints();//видалення всіх точок
    double CalculateSquare();
    double CalculatePerimetr();
    int Determinant(Point, Point, Point, Point);
    Point CrossingPoint3D(Point, Point, Point, Point);
    Point CrossingPoint2D(Point, Point, Point, Point);
    bool IsCrossing(Point, Point, Point, Point);
    double DistanceBetweenPoints(double, double, double, double, double = 0, double = 0);
    double DistanceBetweenPoints(Point, Point);
    double DistanceBetweenPoints2D(Point, Point);
    void SwapPoints(double, double);
    bool IsInCircle(Point, Point, Point, Point);
    bool IsOutCircle(Point, Point, Point, Point);
    Point CircleInCenter(Point, Point, Point, Point);
    Point CircleOutCenter(Point, Point, Point, Point);
    double RadiusOut();
    double RadiusIn();
    double AngleBetweenLines(Point, Point, Point, Point);
    double DistanceBetweenPointLine(Point, Point,Point);

    //Оператори вводу виводу з файлу
    friend int operator>>( std::ifstream  &input, Square &);
    friend std::ofstream &operator<<( std::ofstream  &output, Square &);
private:

    QVector<Point> points;//точки з координатами x y z
};

#endif // POLYGON_H
