#include "Point.h"
#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

Point::Point(double x, double y, double z): m_x(x), m_y(y), m_z(z) 
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

bool Point::operator<(const Point& other) const 
{
    if (fabs(m_x - other.m_x) >= numeric_limits<double>::epsilon()) {
        return m_x < other.m_x;
    }
    if (fabs(m_y - other.m_y) >= numeric_limits<double>::epsilon()) {
        return m_y < other.m_y;
    }
    return m_z < other.m_z - numeric_limits<double>::epsilon();
}

bool Point::operator<=(const Point& other) const 
{
    return (*this < other) || (*this == other);
}

bool Point::operator>(const Point& other) const 
{
    return !(*this <= other);
}

bool Point::operator>=(const Point& other) const 
{
    return !(*this < other);
}

Point Point::operator+(double val) const 
{
    return Point(m_x + val, m_y + val, m_z + val);
}

Point Point::operator-(double val) const 
{
    return Point(m_x - val, m_y - val, m_z - val);
}

Point Point::operator+(const Point& other) const 
{
    return Point(m_x + other.m_x, m_y + other.m_y, m_z + other.m_z);
}

Point Point::operator-(const Point& other) const 
{
    return Point(m_x - other.m_x, m_y - other.m_y, m_z - other.m_z);
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
