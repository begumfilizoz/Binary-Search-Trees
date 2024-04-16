/**
* Title: Binary Search Trees
* Author : Begüm Filiz Öz
* ID: 22203470
* Section : 3
* Homework : 1
* Description : Analysis class header */

#ifndef analysis_h
#define analysis_h
#include <ctime>

#include <iostream>
#include "BST.h"

class analysis
{
public:
    analysis();
    ~analysis();
    void timeAnalysis(); //generates random 10000 integers, adds 1000 of them at each step and calculates the elapsed time & height
};

#endif /* analysis_h */
