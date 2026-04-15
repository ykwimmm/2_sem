#pragma once
#include <iostream>


class Point 
{
private:
    
    /*
    * @brief Абсцисса (координата X)
    */
    double m_x;

    /*
    * @brief Ордината (координата Y)
    */
    double m_y;  

    /*
	* @brief Аппликата (координата Z)
    */
    double m_z;  

public:

    /**
    * @brief Конструктор точки с заданными координатами
    * @param x Координата X (абсцисса)
    * @param y Координата Y (ордината)
    * @param z Координата Z (аппликата)
    */
    explicit Point(double x = 0.0, double y = 0.0, double z = 0.0);

    /**
    * @brief Конструктор копирования
    * @param other Копируемая точка
    */
    Point(const Point& other) = default;

    /**
    * @brief Оператор присваивания копированием
    * @param other Присваиваемая точка
    * @return Ссылка на текущий объект
    */
    Point& operator=(const Point& other) = default;

    /**
    * @brief Деструктор
    */
    ~Point() = default;

    /**
    * @brief Получить координату X (абсциссу)
    * @return Значение координаты X
    */
    double getX() const;

    /**
    * @brief Получить координату Y (ординату)
    * @return Значение координаты Y
    */
    double getY() const;

    /**
    * @brief Получить координату Z (аппликату)
    * @return Значение координаты Z
    */
    double getZ() const;

    /**
    * @brief оператор ==
    * @return 1 если равно
    */
    bool operator==(const Point& other) const;

    /**
    * @brief оператор !=
    * @return 1 если не равно
    */
    bool operator!=(const Point& other) const;

    /**
    * @brief Оператор < 
    * @return 1 если меньше other
    */
    bool operator<(const Point& other) const;

    /**
    * @brief Оператор <=
    * @return 1 если <= other
    */
    bool operator<=(const Point& other) const;

    /**
    * @brief Оператор >
    * @return 1 если > other
    */
    bool operator>(const Point& other) const;

    /**
    * @brief Оператор >=
    * @return 1 если >= other
    */
    bool operator>=(const Point& other) const;

    /**
    * @brief Сложение с вещественным числом
    * @param val Значение, прибавляемое ко всем координатам
    * @return Новая точка с координатами (x+val, y+val, z+val)
    */
    Point operator+(double val) const;

    /**
    * @brief Вычитание вещественного числа из точки
    * @param val Значение, вычитаемое из всех координат
    * @return Новая точка с координатами (x-val, y-val, z-val)
    */
    Point operator-(double val) const;

    /**
    * @brief Покоординатное сложение двух точек
    * @param other Вторая точка
    * @return Новая точка с координатами (x1+x2, y1+y2, z1+z2)
    */
    Point operator+(const Point& other) const;

    /**
    * @brief Покоординатное вычитание двух точек
    * @param other Вычитаемая точка
    * @return Новая точка с координатами (x1-x2, y1-y2, z1-z2)
    */
    Point operator-(const Point& other) const;

    /*
    * @brief получение разрешения у класса на доступ к private для вывода
    * @param os
    * @param p - точка для вывода
    */
    friend std::ostream& operator<<(std::ostream& os, const Point& p);

    /*
    * @brief получение разрешения у класса на доступ к private для ввода
    * @param is
    * @param p - точка для ввода
    */
    friend std::istream& operator>>(std::istream& is, Point& p);
};
