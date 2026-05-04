#include "QueueNode.h"

QueueNode::QueueNode(int value) : data(value), next(nullptr) 
{
}

int QueueNode::getData() const 
{
    return data;
}

QueueNode* QueueNode::getNext() const 
{
    return next;
}

void QueueNode::setNext(QueueNode* nextNode) 
{
    next = nextNode;
}
