/**
* Title: Binary Search Trees
* Author : Begüm Filiz Öz
* ID: 22203470
* Section : 3
* Homework : 1
* Description : Stack data structure implementation */

#include <iostream>
#include "Stack.h"
Stack::Stack() {
    head = nullptr;
    tail = nullptr;
}
Stack::~Stack() {
    while(head)
    {
        pop();
    }
}
void Stack::push(StackNode* node)
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
void Stack::pop()
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
        StackNode* curr = head;
        while(curr && curr->next && curr->next->next)
            curr = curr->next;
        delete tail;
        tail = curr;
        tail->next = nullptr;
    }
}

StackNode* Stack::peek()
{
    return tail;
}
