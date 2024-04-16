/**
* Title: Binary Search Trees
* Author : Begüm Filiz Öz
* ID: 22203470
* Section : 3
* Homework : 1
* Description : TreeNode class implementations */

#include "TreeNode.h"

TreeNode::TreeNode() {
    value = 0;
    left = nullptr;
    right = nullptr;
}
TreeNode::TreeNode(int val, TreeNode *leftChild, TreeNode *rightChild) {
    value = val;
    left = leftChild;
    right = rightChild;
}
TreeNode::~TreeNode() {
    left = nullptr;
    right = nullptr;
}
