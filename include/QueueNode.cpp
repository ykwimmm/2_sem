#pragma once

#include <string>
#include <initializer_list>
#include <ostream>
#include "QueueNode.h"

class Queue 
{
private:

    /*
    * @brief Указатель на начало очереди
    */
    QueueNode* front;   

    /*
    * @brief Указатель на конец очереди
    */
    QueueNode* rear;    

    /*
    * @brief Текущий размер очереди
    */
    size_t size;        

    /**
    * @brief Очистка очереди
    */
    void clear();

    /**
    * @brief Копирование элементов из другой очереди
    * @param other Очередь для копирования
    */
    void copyFrom(const Queue& other);

public:

    /**
    * @brief Конструктор по умолчанию
    */
    Queue();

    /**
    * @brief Конструктор со списком инициализации
    * @param initList Список начальных значений
    */
    Queue(std::initializer_list<int> initList);

    /**
    * @brief Конструктор копирования
    * @param other - другая очередь для копирования
    */
    Queue(const Queue& other);

    /**
    * @brief Конструктор перемещения
    * @param other - другая очередь для перемещения
    */
    Queue(Queue&& other) noexcept;

    /**
    * @brief Деструктор
    */
    ~Queue();

    /**
    * @brief Оператор присваивания копированием
    * @param other - другая очередь
    */
    Queue& operator=(const Queue& other);

    /**
    * @brief Оператор присваивания перемещением
    * @param other - другая очередь
    */
    Queue& operator=(Queue&& other) noexcept;

    /**
    * @brief Оператор сдвига вправо (добавление элемента)
    * @param value - значение для добавления в конец очереди
    */
    Queue& operator>>=(int value);

    /**
    * @brief Оператор сдвига влево (извлечение элемента)
    * @param value - переменная для сохранения извлеченного значения
    */
    Queue& operator<<=(int& value);

    /**
    * @brief Добавление элемента в конец очереди
    * @param value - значение для добавления
    */
    void enqueue(int value);

    /**
    * @brief Извлечение элемента из начала очереди
    * @return Значение из начала очереди
    */
    int dequeue();

    /**
    * @brief Просмотр элемента в начале очереди без извлечения
    * @return Значение из начала очереди
    */
    int peek() const;

    /**
    * @brief Проверка, пуста ли очередь
    * @return true если очередь пуста, иначе false
    */
    bool isEmpty() const;

    /**
    * @brief Получить текущий размер очереди
    * @return Количество элементов в очереди
    */
    size_t getSize() const;

    /**
    * @brief Преобразование очереди в строку
    * @return Строковое представление очереди
    */
    std::string toString() const;

    /**
    * @brief оператор вывода 
    * @param os 
    * @param queue - очередь для вывода
    */
    friend std::ostream& operator<<(std::ostream& os, const Queue& queue);
};
