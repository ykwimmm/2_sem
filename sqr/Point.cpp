#include "Point.h"
#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

Point::Point(const double x, const double y, const double z): m_x(x), m_y(y), m_z(z) 
{
    
}

double Point::getX() const 
{
    return m_x;
}

double Point::getY() const 
{
    return m_y;
}

double Point::getZ() const 
{
    return m_z;
}

bool Point::operator==(const Point& other) const 
{
    return (fabs(m_x - other.m_x) < numeric_limits<double>::epsilon()) &&
        (fabs(m_y - other.m_y) < numeric_limits<double>::epsilon()) &&
        (fabs(m_z - other.m_z) < numeric_limits<double>::epsilon());
}

bool Point::operator!=(const Point& other) const 
{
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Point& p) 
{
    os << "(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Point& p) 
{
    while (!(is >> p.m_x >> p.m_y >> p.m_z))
    {
        is.clear();
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cerr << "Ошибка ввода! Введите три числа через пробел (x y z): ";
    }

    return is;
}
