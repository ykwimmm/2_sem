#pragma once
#include <string>
#include <iostream>
#include <memory>

class VectorBase 
{
public:

    /*
    * @brief Конструктор по умолчанию
    */
    VectorBase() = default;

    /**
    * @brief Виртуальный деструктор
    */
    virtual ~VectorBase() = default;

    /**
    * @brief Вычисление евклидовой нормы (длины) вектора
    * @return Длина вектора
    */
    virtual double norm() const = 0;

    /**
    * @brief Нахождение угла между двумя векторами
    * @param v1 Первый вектор
    * @param v2 Второй вектор
    * @return Угол между векторами в радианах
    */
    static double angle(const VectorBase& v1, const VectorBase& v2);

    /**
    * @brief Сериализация вектора в строку
    * @return Строковое представление вектора
    */
    virtual std::string toString() const = 0;
};
