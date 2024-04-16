/**
* Title: Binary Search Trees
* Author : Begüm Filiz Öz
* ID: 22203470
* Section : 3
* Homework : 1
* Description : Header for TreeNode including its methods */

#ifndef HW1_TREENODE_H
#define HW1_TREENODE_H


class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode();
    TreeNode(int val, TreeNode* leftChild, TreeNode* rightChild);
    ~TreeNode();
};


#endif //HW1_TREENODE_H
