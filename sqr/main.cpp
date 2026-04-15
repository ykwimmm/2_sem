#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>
#include <locale.h>
#include "Point.h"
#include "VectorBase.h"
#include "Vector3D.h"

using namespace std;

/*
* @brief Точка входа в программу
* @return 0 в случае успеха
*/
int main() 
{
    setlocale(LC_ALL, "Russian");

    Point A, B, C;

    cout << "Введите точку A (x y z): " << endl;
    cin >> A;
    cout << "Введите точку B (x y z): " << endl;
    cin >> B;
    cout << "Введите точку C (x y z): " << endl;
    cin >> C;

    cout << "\nA = " << A << endl;
    cout << "B = " << B << endl;
    cout << "C = " << C << endl;

    cout << "\nA == B: " << (A == B ? "да" : "нет") << endl;
    cout << "A != B: " << (A != B ? "да" : "нет") << endl;
    cout << "A < B: " << (A < B ? "да" : "нет") << endl;

    cout << "\nA + 10 = " << (A + 10.0) << endl;
    cout << "B - 5 = " << (B - 5.0) << endl;
    cout << "A + B = " << (A + B) << endl;
    cout << "B - A = " << (B - A) << endl;

    Vector3D v1(A, B);
    Vector3D v2(A, C);

    cout << "\nv1 (A->B) = " << v1 << endl;
    cout << "v2 (A->C) = " << v2 << endl;

    cout << "\n|v1| = " << v1.norm() << endl;
    cout << "|v2| = " << v2.norm() << endl;

    cout << "\nv1 + v2 = " << (v1 + v2) << endl;
    cout << "v1 - v2 = " << (v1 - v2) << endl;
    cout << "v1 * 2 = " << (v1 * 2.0) << endl;
    cout << "3 * v2 = " << (3.0 * v2) << endl;
    cout << "-v1 = " << (-v1) << endl;

    cout << "\nv1 == v2: " << (v1 == v2 ? "да" : "нет") << endl;
    cout << "v1 != v2: " << (v1 != v2 ? "да" : "нет") << endl;

    cout << "\nv1 * v2 (скалярное) = " << v1.dot(v2) << endl;
    cout << "v1 x v2 (векторное) = " << v1.cross(v2) << endl;

    double angleRad = VectorBase::angle(v1, v2);
    double angleDeg = angleRad * 180.0 / M_PI;
    cout << "\nУгол = " << angleRad << " рад = " << angleDeg << " градусов" << endl;

    cout << "\nv1.ToString() = " << v1.toString() << endl;
    cout << "v2.ToString() = " << v2.toString() << endl;

    return 0;
}
