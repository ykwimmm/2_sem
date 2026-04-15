#include "Vector3D.h"
#include <cmath>
#include <limits>
#include <sstream>
#include <stdexcept>

using namespace std;

Vector3D::Vector3D(double dx, double dy, double dz) : m_dx(dx), m_dy(dy), m_dz(dz) 
{
}

Vector3D::Vector3D(const Point& start, const Point& end): m_dx(end.getX() - start.getX()), m_dy(end.getY() - start.getY()), m_dz(end.getZ() - start.getZ()) 
{
}

double Vector3D::getX() const 
{
    return m_dx;
}

double Vector3D::getY() const
{
    return m_dy;
}

double Vector3D::getZ() const 
{
    return m_dz;
}

double Vector3D::dot(const Vector3D& other) const 
{
    return m_dx * other.m_dx + m_dy * other.m_dy + m_dz * other.m_dz;
}

Vector3D Vector3D::cross(const Vector3D& other) const 
{
    return Vector3D(
        m_dy * other.m_dz - m_dz * other.m_dy,
        m_dz * other.m_dx - m_dx * other.m_dz,
        m_dx * other.m_dy - m_dy * other.m_dx
    );
}

double Vector3D::norm() const 
{
    return sqrt(m_dx * m_dx + m_dy * m_dy + m_dz * m_dz);
}

std::string Vector3D::toString() const 
{
    std::ostringstream oss;
    oss << "Vector3D(" << m_dx << ", " << m_dy << ", " << m_dz << ")";
    return oss.str();
}

bool Vector3D::operator==(const Vector3D& other) const 
{
    return (fabs(m_dx - other.m_dx) < numeric_limits<double>::epsilon()) &&
        (fabs(m_dy - other.m_dy) < numeric_limits<double>::epsilon()) &&
        (fabs(m_dz - other.m_dz) < numeric_limits<double>::epsilon());
}

bool Vector3D::operator!=(const Vector3D& other) const 
{
    return !(*this == other);
}

Vector3D Vector3D::operator+(const Vector3D& other) const 
{
    return Vector3D(m_dx + other.m_dx, m_dy + other.m_dy, m_dz + other.m_dz);
}

Vector3D Vector3D::operator-(const Vector3D& other) const 
{
    return Vector3D(m_dx - other.m_dx, m_dy - other.m_dy, m_dz - other.m_dz);
}

Vector3D Vector3D::operator*(double scalar) const 
{
    return Vector3D(m_dx * scalar, m_dy * scalar, m_dz * scalar);
}

Vector3D Vector3D::operator/(double scalar) const 
{
    if (fabs(scalar) < numeric_limits<double>::epsilon()) 
    {
        throw std::domain_error("Деление на ноль");
    }
    return Vector3D(m_dx / scalar, m_dy / scalar, m_dz / scalar);
}

Vector3D Vector3D::operator-() const 
{
    return Vector3D(-m_dx, -m_dy, -m_dz);
}

std::ostream& operator<<(std::ostream& os, const Vector3D& v) 
{
    os << v.toString();
    return os;
}

Vector3D operator*(double scalar, const Vector3D& v) 
{
    return v * scalar;
}
