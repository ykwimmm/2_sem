#include "CppUnitTest.h"
#include "../Task2/Point.h"
#include "../Task2/VectorBase.h"
#include "../Task2/Vector3D.h"

#include <cmath>
#include <sstream>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VectorTests
{

    TEST_CLASS(PointTests)
    {
    public:

        TEST_METHOD(Constructor_Default_AllCoordinatesZero)
        {
            Point p;
            Assert::AreEqual(0.0, p.getX(), L"X should be 0");
            Assert::AreEqual(0.0, p.getY(), L"Y should be 0");
            Assert::AreEqual(0.0, p.getZ(), L"Z should be 0");
        }

        TEST_METHOD(Constructor_WithParameters_SetsCorrectValues)
        {
            Point p(1.0, 2.0, 3.0);
            Assert::AreEqual(1.0, p.getX(), L"X should be 1.0");
            Assert::AreEqual(2.0, p.getY(), L"Y should be 2.0");
            Assert::AreEqual(3.0, p.getZ(), L"Z should be 3.0");
        }

        TEST_METHOD(Equality_SamePoints_ReturnsTrue)
        {
            Point p1(1.0, 2.0, 3.0);
            Point p2(1.0, 2.0, 3.0);
            Assert::IsTrue(p1 == p2, L"Points should be equal");
        }

        TEST_METHOD(Equality_DifferentPoints_ReturnsFalse)
        {
            Point p1(1.0, 2.0, 3.0);
            Point p2(4.0, 5.0, 6.0);
            Assert::IsFalse(p1 == p2, L"Points should not be equal");
        }

        TEST_METHOD(Inequality_DifferentPoints_ReturnsTrue)
        {
            Point p1(1.0, 2.0, 3.0);
            Point p2(4.0, 5.0, 6.0);
            Assert::IsTrue(p1 != p2, L"Points should not be equal");
        }

        TEST_METHOD(LessThan_FirstSmaller_ReturnsTrue)
        {
            Point p1(1.0, 2.0, 3.0);
            Point p2(4.0, 5.0, 6.0);
            Assert::IsTrue(p1 < p2, L"p1 should be less than p2");
        }

        TEST_METHOD(LessThan_SamePoints_ReturnsFalse)
        {
            Point p1(1.0, 2.0, 3.0);
            Point p2(1.0, 2.0, 3.0);
            Assert::IsFalse(p1 < p2, L"Equal points: p1 should not be less than p2");
        }

        TEST_METHOD(LessThanOrEqual_EqualPoints_ReturnsTrue)
        {
            Point p1(1.0, 2.0, 3.0);
            Point p2(1.0, 2.0, 3.0);
            Assert::IsTrue(p1 <= p2, L"Equal points: p1 should be <= p2");
        }

        TEST_METHOD(GreaterThan_FirstLarger_ReturnsTrue)
        {
            Point p1(4.0, 5.0, 6.0);
            Point p2(1.0, 2.0, 3.0);
            Assert::IsTrue(p1 > p2, L"p1 should be greater than p2");
        }

        TEST_METHOD(GreaterThanOrEqual_EqualPoints_ReturnsTrue)
        {
            Point p1(1.0, 2.0, 3.0);
            Point p2(1.0, 2.0, 3.0);
            Assert::IsTrue(p1 >= p2, L"Equal points: p1 should be >= p2");
        }

        TEST_METHOD(AdditionWithScalar_AddsToAllCoordinates)
        {
            Point p(1.0, 2.0, 3.0);
            Point result = p + 5.0;
            Assert::AreEqual(6.0, result.getX(), L"X should be 6.0");
            Assert::AreEqual(7.0, result.getY(), L"Y should be 7.0");
            Assert::AreEqual(8.0, result.getZ(), L"Z should be 8.0");
        }

        TEST_METHOD(SubtractionWithScalar_SubtractsFromAllCoordinates)
        {
            Point p(10.0, 20.0, 30.0);
            Point result = p - 5.0;
            Assert::AreEqual(5.0, result.getX(), L"X should be 5.0");
            Assert::AreEqual(15.0, result.getY(), L"Y should be 15.0");
            Assert::AreEqual(25.0, result.getZ(), L"Z should be 25.0");
        }

        TEST_METHOD(AdditionWithPoint_AddsCoordinates)
        {
            Point p1(1.0, 2.0, 3.0);
            Point p2(4.0, 5.0, 6.0);
            Point result = p1 + p2;
            Assert::AreEqual(5.0, result.getX(), L"X should be 5.0");
            Assert::AreEqual(7.0, result.getY(), L"Y should be 7.0");
            Assert::AreEqual(9.0, result.getZ(), L"Z should be 9.0");
        }

        TEST_METHOD(SubtractionWithPoint_SubtractsCoordinates)
        {
            Point p1(4.0, 5.0, 6.0);
            Point p2(1.0, 2.0, 3.0);
            Point result = p1 - p2;
            Assert::AreEqual(3.0, result.getX(), L"X should be 3.0");
            Assert::AreEqual(3.0, result.getY(), L"Y should be 3.0");
            Assert::AreEqual(3.0, result.getZ(), L"Z should be 3.0");
        }

        TEST_METHOD(OutputOperator_FormatsCorrectly)
        {
            Point p(1.5, 2.5, 3.5);
            std::ostringstream oss;
            oss << p;
            std::string expected = "(1.5, 2.5, 3.5)";
            Assert::AreEqual(expected.c_str(), oss.str().c_str());
        }
    };

    TEST_CLASS(Vector3DTests)
    {
    public:

        TEST_METHOD(Constructor_Default_AllComponentsZero)
        {
            Vector3D v;
            Assert::AreEqual(0.0, v.getX(), L"X should be 0");
            Assert::AreEqual(0.0, v.getY(), L"Y should be 0");
            Assert::AreEqual(0.0, v.getZ(), L"Z should be 0");
        }

        TEST_METHOD(Constructor_WithParameters_SetsCorrectValues)
        {
            Vector3D v(1.0, 2.0, 3.0);
            Assert::AreEqual(1.0, v.getX(), L"X should be 1.0");
            Assert::AreEqual(2.0, v.getY(), L"Y should be 2.0");
            Assert::AreEqual(3.0, v.getZ(), L"Z should be 3.0");
        }

        TEST_METHOD(Constructor_FromPoints_CalculatesDifference)
        {
            Point p1(1.0, 2.0, 3.0);
            Point p2(4.0, 6.0, 8.0);
            Vector3D v(p1, p2);
            Assert::AreEqual(3.0, v.getX(), L"X should be 3.0");
            Assert::AreEqual(4.0, v.getY(), L"Y should be 4.0");
            Assert::AreEqual(5.0, v.getZ(), L"Z should be 5.0");
        }

        TEST_METHOD(Norm_3_4_0_Returns5)
        {
            Vector3D v(3.0, 4.0, 0.0);
            Assert::AreEqual(5.0, v.norm(), L"Norm should be 5.0");
        }

        TEST_METHOD(Norm_1_2_2_Returns3)
        {
            Vector3D v(1.0, 2.0, 2.0);
            Assert::AreEqual(3.0, v.norm(), L"Norm should be 3.0");
        }

        TEST_METHOD(Norm_ZeroVector_Returns0)
        {
            Vector3D v(0.0, 0.0, 0.0);
            Assert::AreEqual(0.0, v.norm(), L"Norm should be 0.0");
        }

        TEST_METHOD(Addition_AddsComponents)
        {
            Vector3D v1(1.0, 2.0, 3.0);
            Vector3D v2(4.0, 5.0, 6.0);
            Vector3D result = v1 + v2;
            Assert::AreEqual(5.0, result.getX(), L"X should be 5.0");
            Assert::AreEqual(7.0, result.getY(), L"Y should be 7.0");
            Assert::AreEqual(9.0, result.getZ(), L"Z should be 9.0");
        }

        TEST_METHOD(Subtraction_SubtractsComponents)
        {
            Vector3D v1(4.0, 5.0, 6.0);
            Vector3D v2(1.0, 2.0, 3.0);
            Vector3D result = v1 - v2;
            Assert::AreEqual(3.0, result.getX(), L"X should be 3.0");
            Assert::AreEqual(3.0, result.getY(), L"Y should be 3.0");
            Assert::AreEqual(3.0, result.getZ(), L"Z should be 3.0");
        }

        TEST_METHOD(MultiplicationByScalar_RightSide)
        {
            Vector3D v(1.0, 2.0, 3.0);
            Vector3D result = v * 2.0;
            Assert::AreEqual(2.0, result.getX(), L"X should be 2.0");
            Assert::AreEqual(4.0, result.getY(), L"Y should be 4.0");
            Assert::AreEqual(6.0, result.getZ(), L"Z should be 6.0");
        }

        TEST_METHOD(MultiplicationByScalar_LeftSide)
        {
            Vector3D v(1.0, 2.0, 3.0);
            Vector3D result = 3.0 * v;
            Assert::AreEqual(3.0, result.getX(), L"X should be 3.0");
            Assert::AreEqual(6.0, result.getY(), L"Y should be 6.0");
            Assert::AreEqual(9.0, result.getZ(), L"Z should be 9.0");
        }

        TEST_METHOD(DivisionByScalar_DividesComponents)
        {
            Vector3D v(2.0, 4.0, 6.0);
            Vector3D result = v / 2.0;
            Assert::AreEqual(1.0, result.getX(), L"X should be 1.0");
            Assert::AreEqual(2.0, result.getY(), L"Y should be 2.0");
            Assert::AreEqual(3.0, result.getZ(), L"Z should be 3.0");
        }

        TEST_METHOD(UnaryMinus_NegatesComponents)
        {
            Vector3D v(1.0, -2.0, 3.0);
            Vector3D result = -v;
            Assert::AreEqual(-1.0, result.getX(), L"X should be -1.0");
            Assert::AreEqual(2.0, result.getY(), L"Y should be 2.0");
            Assert::AreEqual(-3.0, result.getZ(), L"Z should be -3.0");
        }

        TEST_METHOD(Equality_SameVectors_ReturnsTrue)
        {
            Vector3D v1(1.0, 2.0, 3.0);
            Vector3D v2(1.0, 2.0, 3.0);
            Assert::IsTrue(v1 == v2, L"Vectors should be equal");
        }

        TEST_METHOD(Equality_DifferentVectors_ReturnsFalse)
        {
            Vector3D v1(1.0, 2.0, 3.0);
            Vector3D v2(4.0, 5.0, 6.0);
            Assert::IsFalse(v1 == v2, L"Vectors should not be equal");
        }

        TEST_METHOD(Inequality_DifferentVectors_ReturnsTrue)
        {
            Vector3D v1(1.0, 2.0, 3.0);
            Vector3D v2(4.0, 5.0, 6.0);
            Assert::IsTrue(v1 != v2, L"Vectors should not be equal");
        }

        TEST_METHOD(DotProduct_CalculatesCorrectly)
        {
            Vector3D v1(1.0, 2.0, 3.0);
            Vector3D v2(4.0, 5.0, 6.0);
            double dot = v1.dot(v2);
            Assert::AreEqual(32.0, dot, L"Dot product should be 32.0");
        }

        TEST_METHOD(DotProduct_OrthogonalVectors_Returns0)
        {
            Vector3D v1(1.0, 0.0, 0.0);
            Vector3D v2(0.0, 1.0, 0.0);
            double dot = v1.dot(v2);
            Assert::AreEqual(0.0, dot, L"Dot product of orthogonal vectors should be 0");
        }

        TEST_METHOD(CrossProduct_UnitVectors)
        {
            Vector3D v1(1.0, 0.0, 0.0);
            Vector3D v2(0.0, 1.0, 0.0);
            Vector3D result = v1.cross(v2);
            Assert::AreEqual(0.0, result.getX(), L"X should be 0.0");
            Assert::AreEqual(0.0, result.getY(), L"Y should be 0.0");
            Assert::AreEqual(1.0, result.getZ(), L"Z should be 1.0");
        }

        TEST_METHOD(CrossProduct_AntiCommutative)
        {
            Vector3D v1(1.0, 0.0, 0.0);
            Vector3D v2(0.0, 1.0, 0.0);
            Vector3D cross1 = v1.cross(v2);
            Vector3D cross2 = v2.cross(v1);
            Assert::AreEqual(cross1.getX(), -cross2.getX());
            Assert::AreEqual(cross1.getY(), -cross2.getY());
            Assert::AreEqual(cross1.getZ(), -cross2.getZ());
        }

        TEST_METHOD(Angle_BetweenXandY_Returns90Degrees)
        {
            Vector3D v1(1.0, 0.0, 0.0);
            Vector3D v2(0.0, 1.0, 0.0);
            double angle = VectorBase::angle(v1, v2);
            double expected = 3.14159265358979323846 / 2.0; // PI/2
            Assert::AreEqual(expected, angle, 1e-9, L"Angle should be PI/2");
        }

        TEST_METHOD(Angle_SameVector_Returns0)
        {
            Vector3D v1(1.0, 0.0, 0.0);
            Vector3D v2(1.0, 0.0, 0.0);
            double angle = VectorBase::angle(v1, v2);
            Assert::AreEqual(0.0, angle, 1e-9, L"Angle should be 0");
        }

        TEST_METHOD(Angle_OppositeVectors_ReturnsPI)
        {
            Vector3D v1(1.0, 0.0, 0.0);
            Vector3D v2(-1.0, 0.0, 0.0);
            double angle = VectorBase::angle(v1, v2);
            double expected = 3.14159265358979323846; // PI
            Assert::AreEqual(expected, angle, 1e-9, L"Angle should be PI");
        }

        TEST_METHOD(ToString_FormatsCorrectly)
        {
            Vector3D v(1.0, 2.0, 3.0);
            std::string str = v.toString();
            std::string expected = "Vector3D(1, 2, 3)";
            Assert::AreEqual(expected.c_str(), str.c_str());
        }

        TEST_METHOD(OutputOperator_FormatsCorrectly)
        {
            Vector3D v(1.0, 2.0, 3.0);
            std::ostringstream oss;
            oss << v;
            std::string expected = "Vector3D(1, 2, 3)";
            Assert::AreEqual(expected.c_str(), oss.str().c_str());
        }
    };
}
