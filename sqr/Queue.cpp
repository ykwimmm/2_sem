#include "Queue.h"
#include <stdexcept>
#include <sstream>

using namespace std;

Queue::Queue() : front(nullptr), rear(nullptr), size(0) 
{
}

Queue::Queue(std::initializer_list<int> initList) : Queue() 
{
    for (int value : initList) {
        enqueue(value);
    }
}

Queue::Queue(const Queue& other) : Queue() 
{
    copyFrom(other);
}

Queue::Queue(Queue&& other) noexcept: front(other.front), rear(other.rear), size(other.size) 
{
    other.front = nullptr;
    other.rear = nullptr;
    other.size = 0;
}

Queue::~Queue() 
{
    clear();
}

Queue& Queue::operator=(const Queue& other) 
{
    if (this != &other) 
    {
        clear();
        copyFrom(other);
    }
    return *this;
}

Queue& Queue::operator=(Queue&& other) noexcept 
{
    if (this != &other) 
    {
        clear();
        front = other.front;
        rear = other.rear;
        size = other.size;
        other.front = nullptr;
        other.rear = nullptr;
        other.size = 0;
    }
    return *this;
}

Queue& Queue::operator>>=(int value) 
{
    enqueue(value);
    return *this;
}

Queue& Queue::operator<<=(int& value) 
{
    if (isEmpty()) 
    {
        throw runtime_error("Очередь пуста.");
    }
    value = dequeue();
    return *this;
}

void Queue::enqueue(int value) 
{
    QueueNode* newNode = new QueueNode(value);

    if (isEmpty()) 
    {
        front = newNode;
        rear = newNode;
    }
    else 
    {
        rear->setNext(newNode);
        rear = newNode;
    }

    size++;
}

int Queue::dequeue() 
{
    if (isEmpty()) 
    {
        throw runtime_error("Очередь пуста.");
    }

    QueueNode* temp = front;
    int value = temp->getData();

    front = front->getNext();

    if (front == nullptr) 
    {
        rear = nullptr;
    }

    delete temp;
    size--;

    return value;
}

int Queue::peek() const 
{
    if (isEmpty()) 
    {
        throw runtime_error("Очередь пуста.");
    }

    return front->getData();
}

bool Queue::isEmpty() const 
{
    return size == 0;
}

size_t Queue::getSize() const 
{
    return size;
}

std::string Queue::toString() const 
{
    if (isEmpty()) 
    {
        return "[]";
    }

    std::ostringstream oss;
    oss << "[";

    QueueNode* current = front;
    while (current != nullptr) 
    {
        oss << current->getData();
        if (current->getNext() != nullptr) 
        {
            oss << ", ";
        }
        current = current->getNext();
    }

    oss << "]";
    return oss.str();
}

void Queue::clear() 
{
    while (!isEmpty()) 
    {
        dequeue();
    }
}

void Queue::copyFrom(const Queue& other) 
{
    QueueNode* current = other.front;
    while (current != nullptr) 
    {
        enqueue(current->getData());
        current = current->getNext();
    }
}

std::ostream& operator<<(std::ostream& os, const Queue& queue) 
{
    os << queue.toString();
    return os;
}
