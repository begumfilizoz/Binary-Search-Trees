/**
* Title: Binary Search Trees
* Author : Begüm Filiz Öz
* ID: 22203470
* Section : 3
* Homework : 1
* Description : StackNode header implementations */

#ifndef StackNode_h
#define StackNode_h

#include "TreeNode.h"
class StackNode
{
public:
    TreeNode* treeNode;
    StackNode* next;
    StackNode();
    StackNode(TreeNode*& node);
    ~StackNode();
};
#endif /* StackNode_h */
