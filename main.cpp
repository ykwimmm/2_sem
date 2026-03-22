#include<iostream>
#include"Point.h"
#include"Plane.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    //Point a(0, 0, 0);
    //Point b(1, 0, 0);
    //Point c(0, 1, 0);
    //Point d(2, 3, 5);

    Point p1, p2, p3, p4;

    cout << "Введите координаты трех точек плоскости (x, y, z):" << endl;
    cin >> p1 >> p2 >> p3;

    Plane plane(p1, p2, p3);

    cout << "\nВведите координаты проверяемой точки (x, y, z):" << endl;
    cin >> p4;

    if (plane.isPointOnPlane(p4)) 
    {
        cout << "Точка принадлежит плоскости\n";
    }
    else 
    {
        cout << "Точка НЕ принадлежит плоскости\n";
    }

    cout << "Расстояние от точки до плоскости: " << plane.distanceToPoint(p4) << endl;

    return 0;
}
