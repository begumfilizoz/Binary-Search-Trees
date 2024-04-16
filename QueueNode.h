/**
* Title: Binary Search Trees
* Author : Begüm Filiz Öz
* ID: 22203470
* Section : 3
* Homework : 1
* Description : QueueNode header */

#ifndef QueueNode_h
#define QueueNode_h
#include "TreeNode.h"
class QueueNode
{
public:
    TreeNode* treeNode;
    QueueNode* next;
    int level;
    QueueNode();
    QueueNode(TreeNode*& node, int num);
    QueueNode(TreeNode*& node);
    ~QueueNode();
};

#endif /* QueueNode_h */
