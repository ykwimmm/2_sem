#include "VectorBase.h"
#include "Vector3D.h"
#include <cmath>
#include <stdexcept>

double VectorBase::angle(const VectorBase& v1, const VectorBase& v2) 
{
    const auto* vec1 = dynamic_cast<const Vector3D*>(&v1);
    const auto* vec2 = dynamic_cast<const Vector3D*>(&v2);

    if (!vec1 || !vec2) 
    {
        throw std::invalid_argument("Оба вектора должны быть типа Vector3D");
    }

    double n1 = v1.norm();
    double n2 = v2.norm();

    if (n1 == 0.0 || n2 == 0.0) 
    {
        throw std::domain_error("Невозможно вычислить угол для нулевого вектора");
    }

    double dotProduct = vec1->dot(*vec2);

    double cosTheta = dotProduct / (n1 * n2);

    if (cosTheta > 1.0) cosTheta = 1.0;
    if (cosTheta < -1.0) cosTheta = -1.0;

    return std::acos(cosTheta);
}
