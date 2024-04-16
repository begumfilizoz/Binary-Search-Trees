/**
* Title: Binary Search Trees
* Author : Begüm Filiz Öz
* ID: 22203470
* Section : 3
* Homework : 1
* Description : Queue data structure header */

#ifndef Queue_h
#define Queue_h
#include "QueueNode.h"
class Queue
{
public:
    QueueNode* head;
    QueueNode* tail;
    Queue();
    ~Queue();
    void enqueue(QueueNode* node);
    void dequeue();
    QueueNode* peek();
};

#endif /* Queue_h */
