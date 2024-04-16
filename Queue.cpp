/**
* Title: Binary Search Trees
* Author : Begüm Filiz Öz
* ID: 22203470
* Section : 3
* Homework : 1
* Description : Queue data structure implementation */

#include <iostream>
#include "Queue.h"
Queue::Queue() {
    head = nullptr;
    tail = nullptr;
}
Queue::~Queue() {
    while(head)
    {
        dequeue();
    }
}
void Queue::enqueue(QueueNode* node)
{
    if(!head)
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->next = node;
        tail = tail->next;
    }
}
void Queue::dequeue()
{
    if(!head)
        return;
    if(head->next == nullptr)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        QueueNode* temp = head->next;
        delete head;
        head = temp;
    }
}
QueueNode* Queue::peek()
{
    return head;
}
