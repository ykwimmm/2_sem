#include "Queue.h"
#include <stdexcept>
#include <sstream>

using namespace std;

Queue::Queue() : head(nullptr), tail(nullptr), size(0) 
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

Queue::Queue(Queue&& other) noexcept: head(other.head), tail(other.tail), size(other.size) 
{
    other.head = nullptr;
    other.tail = nullptr;
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
        head = other.head;
        tail = other.tail;
        size = other.size;
        other.head = nullptr;
        other.tail = nullptr;
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
        head = newNode;
        tail = newNode;
    }
    else 
    {
        tail->setNext(newNode);
        tail = newNode;
    }

    size++;
}

int Queue::dequeue() 
{
    if (isEmpty()) 
    {
        throw runtime_error("Очередь пуста.");
    }

    QueueNode* temp = head;
    int value = temp->getData();

    head = head->getNext();

    if (head == nullptr) 
    {
        tail = nullptr;
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

    return head->getData();
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

    QueueNode* current = head;
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
    QueueNode* current = other.head;
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
