/**
* Title: Binary Search Trees
* Author : Begüm Filiz Öz
* ID: 22203470
* Section : 3
* Homework : 1
* Description : QueueNode method implementations */

#include "QueueNode.h"
#include <cmath>
#include <iostream>


QueueNode::QueueNode()
{
    next = nullptr;
}
QueueNode::QueueNode(TreeNode*& node, int num)
{
    next = nullptr;
    treeNode = node;
    level = floor(log2(num)) + 1;
}
QueueNode::QueueNode(TreeNode*& node)
{
    next = nullptr;
    treeNode = node;
    level = 0;
}
QueueNode::~QueueNode()
{
    treeNode = nullptr;
    next = nullptr;
}
