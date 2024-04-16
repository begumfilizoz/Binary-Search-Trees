/**
* Title: Binary Search Trees
* Author : Begüm Filiz Öz
* ID: 22203470
* Section : 3
* Homework : 1
* Description : Header for BST including its methods */

#ifndef HW1_BST_H
#define HW1_BST_H
#include "TreeNode.h"
#include "Queue.h"
#include "QueueNode.h"
#include "Stack.h"
#include "StackNode.h"
#include <iostream>
#include <string>
using namespace std;

class BST {
public:
    TreeNode* root;
    BST(int keys[], int size);
    ~BST();
    void destroyTree(TreeNode*& node); //destroys the tree, deallocates its contents
    void insertKey(int key); //inserts an integer key to the tree
    void insertNode(int key, TreeNode*& node); //inserts the key into the tree as a TreeNode
    bool keyExists(int key, TreeNode* node); //checks if the key exists in the tree
    void deleteKey(int key); //deletes a specific key
    void deleteItem(int key, TreeNode*& node); //chooses where to delete the node corresponding to the key
    void deleteNode(TreeNode*& node); //deletes the node corresponding to the key
    void processLeft(TreeNode*& node, int& rep); //processes left for deletions of nodes with children
    void displayInorder(); //displays the inorder traversal
    void inorder(TreeNode *node, string& str); //produces the string for the inorder traversal
    void findFullBTLevel(); //finds the level up to which the tree is full
    void isFullTree(TreeNode* node, int& num); //returns whether the tree is null
    void lowestCommonAncestor(int A, int B); //gives the common ancestor of two numbers
    void maximumSumPath(); //gives the path that yields the maximum sum
    void calculateSum(TreeNode* node, int& num, int& max, int& maxNum);
    void maximumWidth(); //gives the level at which there are the maximum number of nodes
    void pathFromAtoB(int A, int B); //gives the path from A to B
    string findPath(int A, int B);
    Stack* rootToA(int A);
    bool searchKey(Stack* stack, int num, TreeNode* node);
    int findMaxHeight(); //finds the maximum height in the tree
    void findHeight(TreeNode* node, int& num, int& max);
};


#endif //HW1_BST_H
