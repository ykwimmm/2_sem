#include<iostream>
#include<cmath>
#include<limits>
#include"Plane.h"
#include"Point.h"

using namespace std;

Plane::Plane(const Point& p1, const Point& p2, const Point& p3)
{
    double x1 = p1.getX();
    double y1 = p1.getY();
    double z1 = p1.getZ();

    double x2 = p2.getX();
    double y2 = p2.getY();
    double z2 = p2.getZ();

    double x3 = p3.getX();
    double y3 = p3.getY();
    double z3 = p3.getZ();

    if (p1 == p2 || p1 == p3 || p2 == p3) 
    {
        cout << "Ошибка, точки совпадают\n";
        exit(EXIT_FAILURE);
    }

    A = (y2 - y1) * (z3 - z1) - (z2 - z1) * (y3 - y1);
    B = (z2 - z1) * (x3 - x1) - (x2 - x1) * (z3 - z1);
    C = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);

    double norm = sqrt(A * A + B * B + C * C);

    if (norm < numeric_limits<double>::epsilon()) 
    {
        cout << "Ошибка: точки не образуют плоскость!\n";
        exit(EXIT_FAILURE);
    }

    D = -(A * x1 + B * y1 + C * z1);
}

bool Plane::isPointOnPlane(const Point& p) const
{
    double value = A * p.getX() + B * p.getY() + C * p.getZ() + D;
    return fabs(value) < numeric_limits<double>::epsilon();
}

double Plane::distanceToPoint(const Point& p) const
{
    double numerator = fabs(A * p.getX() + B * p.getY() + C * p.getZ() + D);
    double denominator = sqrt(A * A + B * B + C * C);

    return numerator / denominator;
}

