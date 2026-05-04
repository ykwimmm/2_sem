#pragma once

class QueueNode 
{
private:

    /*
    * @brief данные узла
    */
    int data;               

    /*
    * @brief указатель на следующий узел
	*/
    QueueNode* next;    

public:

    /**
    * @brief Конструктор с параметром
    * @param value Значение для сохранения в узле
    */
    explicit QueueNode(int value);

    /**
    * @brief Деструктор
    */
    ~QueueNode() = default;

    /**
    * @brief Получить данные узла
    * @return Значение, хранящееся в узле
    */
    int getData() const;

    /**
    * @brief Получить указатель на следующий узел
    * @return Указатель на следующий узел
    */
    QueueNode* getNext() const;

    /**
    * @brief Установить указатель на следующий узел
    * @param nextNode Указатель на следующий узел
    */
    void setNext(QueueNode* nextNode);
};

