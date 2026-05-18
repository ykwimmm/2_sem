#pragma once
#include "VectorBase.h"
#include "Point.h"

class Vector3D : public VectorBase
{
private:

    /*
	* @brief Компонента вектора по оси X
    */
    double m_dx;  

    /*
	* @brief Компонента вектора по оси Y
    */
    double m_dy; 

    /*
	* @brief Компонента вектора по оси Z
    */
    double m_dz;

public:

    /**
    * @brief Конструктор вектора по компонентам
    * @param dx Компонента X
    * @param dy Компонента Y
    * @param dz Компонента Z
    */
    explicit Vector3D(const double dx = 0.0, const double dy = 0.0, const double dz = 0.0);

    /**
    * @brief Конструктор вектора по двум точкам
    * @param start Точка начала вектора
    * @param end Точка конца вектора
    */
    Vector3D(const Point& start, const Point& end);

    /**
    * @brief Конструктор копирования
    */
    Vector3D(const Vector3D& other) = default;

    /**
    * @brief Оператор присваивания
    */
    Vector3D& operator=(const Vector3D& other) = default;

    /**
    * @brief Деструктор
    */
    ~Vector3D() override = default;

    /**
    * @brief Получить X-компоненту вектора
    * @return Значение компоненты X
    */
    double getX() const;

    /**
    * @brief Получить Y-компоненту вектора
    * @return Значение компоненты Y
    */
    double getY() const;

    /**
    * @brief Получить Z-компоненту вектора
    * @return Значение компоненты Z
    */
    double getZ() const;

    /**
    * @brief Скалярное произведение двух векторов
    * @param other Второй вектор
    * @return Значение скалярного произведения
    */
    double dot(const Vector3D& other) const;

    /**
    * @brief Векторное произведение двух векторов
    * @param other Второй вектор
    * @return Новый вектор - результат векторного произведения
    */
    Vector3D cross(const Vector3D& other) const;

    /**
    * @brief Вычисление евклидовой нормы вектора
    * @return Длина вектора
    */
    double norm() const override;

    /**
    * @brief Сериализация вектора в строку
    * @return Строка в формате "Vector3D(x, y, z)"
    */
    std::string toString() const override;

    /**
    *@brief оператор ==
    * @return 1 если равно
    */
    bool operator==(const Vector3D& other) const;

    /**
    * @brief оператор !=
    * @return 1 если не равно
    */
    bool operator!=(const Vector3D& other) const;

    /**
    * @brief Сложение двух векторов
    * @param other Второй вектор
    * @return сумму двух векторов
    */
    Vector3D operator+(const Vector3D& other) const;

    /**
    * @brief Вычитание двух векторов
    * @param other Вычитаемый вектор
    * @return разность двух векторов
    */
    Vector3D operator-(const Vector3D& other) const;

    /**
     * @brief Умножение вектора на скаляр
     * @param scalar Скалярный множитель
     * @return вектор, умноженный на скаляр
     */
    Vector3D operator*(const double scalar) const;

    /**
    * @brief Деление вектора на скаляр
    * @param scalar Скалярный делитель
    * @return вектор, поделенный на скаляр
    */
    Vector3D operator/(const double scalar) const;

    /**
    * @brief Унарный минус
    * @return Новый вектор с противоположным направлением
    */
    Vector3D operator-() const;

    /**
    * @brief получение разрешения у класса на доступ к private для вывода
    * @param os 
    * @param v - выводимый вектор
    */
    friend std::ostream& operator<<(std::ostream& os, const Vector3D& v);
};

/**
* @brief Умножение скаляра на вектор (коммутативность)
* @param scalar Скалярный множитель
* @param v Вектор
* @return умножение скаляра на вектор
*/
Vector3D operator*(const double scalar, const Vector3D& v);
