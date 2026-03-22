#include<iostream>
#include<limits>
#include"Point.h"

using namespace std;

Point::Point(const double x,const double y,const double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

double Point::getX() const
{ 
    return x; 
}

double Point::getY() const 
{ 
    return y; 
}

double Point::getZ() const 
{ 
    return z; 
}

std::ostream& operator<<(std::ostream& os, const Point& p) 
{
    os << "(" << p.x << ";" << p.y << ";" << p.z << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Point& p) 
{
    while (!(is >> p.x >> p.y >> p.z))
    {
        is.clear();
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cerr << "Ошибка, введите числа (x y z): ";
    }
    return is;
}
