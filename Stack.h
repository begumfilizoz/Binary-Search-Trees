/**
* Title: Binary Search Trees
* Author : Begüm Filiz Öz
* ID: 22203470
* Section : 3
* Homework : 1
* Description : Stack header including its methods */

#ifndef Stack_h
#define Stack_h
#include "StackNode.h"

class Stack
{
public:
    StackNode* head;
    StackNode* tail;
    Stack();
    ~Stack();
    void push(StackNode* node); 
    void pop();
    void popNoDel();
    StackNode* peek();
};

#endif 
