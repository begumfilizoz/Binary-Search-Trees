/**
* Title: Binary Search Trees
* Author : Begüm Filiz Öz
* ID: 22203470
* Section : 3
* Homework : 1
* Description : StackNode method implementations */

#include <stdio.h>
#include "StackNode.h"
StackNode::StackNode()
{
    next = nullptr;
}
StackNode::StackNode(TreeNode*& node)
{
    next = nullptr;
    treeNode = node;
}
StackNode::~StackNode()
{
    treeNode = nullptr;
    next = nullptr;
}

