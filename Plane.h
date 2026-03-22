#pragma once
#include<iostream>
#include"Point.h"

class Plane
{
private:

    /*
    * @brief коэффициент при x
    */
    double A;

    /*
    * @brief коэффициент при y
    */
    double B;

    /*
    * @brief коэффициент при z
    */
    double C;

    /*
    * @brief свободный член
    */
    double D;

public:

    /*
    * @brief создает плоскость по трем точкам
    * @param p1 - точка 1
    * @param p2 - точка 2
    * @param p3 - точка 3
    */
    Plane(const Point& p1, const Point& p2, const Point& p3);

    /*
    * @brief проверяет принадлежит ли точка плоскости
    * @param p - проверяемая точка
    * @return 1 если точка принадлежит плоскости, иначе 0
    */
    bool isPointOnPlane(const Point& p) const;

    /*
    * @brief вычисляет расстояние от точки до плоскости
    * @param p - точка
    * @return расстояние до плоскости
    */
    double distanceToPoint(const Point& p) const;
};
