/**
* Title: Binary Search Trees
* Author : Begüm Filiz Öz
* ID: 22203470
* Section : 3
* Homework : 1
* Description : BST class method implementations */

#include "BST.h"
#include <string>
#include <iostream>
#include <climits>
using namespace std;
BST::BST(int keys[], int size) {
    root = nullptr;
    for(int i = 0; i < size; i++)
    {
        if (!(keyExists(keys[i], root)))
        {
            insertNode(keys[i], root);
        }
    }
    cout << "BST with size " << size << " is created." << endl;
}
BST::~BST() {
    /*
    while(root)
    {
        deleteNode(root);
    }
     */
    destroyTree(root);

}
void BST::destroyTree(TreeNode*& node)
{
    if (node != nullptr){
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
        node = nullptr;
    }
}
void BST::insertKey(int key)
{
    if (!(keyExists(key, root)))
    {
        insertNode(key, root);
        cout << "Key " << key << " is added." << endl;
    }
    else
    {
        cout << "Key " << key << " is not added. It exists!" << endl;
    }
}
void BST::insertNode(int key, TreeNode*& node)
{

    if(node == nullptr)
    {
        node = new TreeNode(key, nullptr, nullptr);
    } else if (key <  node->value) {
        insertNode(key, node->left);
    }
    else {
        insertNode(key, node->right);
    }
}
bool BST::keyExists(int key, TreeNode* node) {
    bool found = false;
    if(node == nullptr)
        return found;
    if (key == node->value)
    {
        found = true;
        return found;
    }
    found = keyExists(key, node->left);
    if (!found)
        found = keyExists(key, node->right);
    return found;
}
void BST::deleteKey(int key) {
    if (keyExists(key, root))
    {
        deleteItem(key, root);
        cout << "Key " << key << " is deleted." << endl;
    }
    else
    {
        cout << "Key " << key << " is not deleted. It does not exist!" << endl;
    }
}
void BST::deleteItem(int key, TreeNode *&node) {
    if (node)
    {
        if (node->value == key)
        {
            deleteNode(node);
        }
        else if (key < node->value)
        {
            deleteItem(key, node->left);
        }
        else
        {
            deleteItem(key, node->right);
        }
    }
}
void BST::deleteNode(TreeNode *&node) {
    TreeNode* delPtr;
    int rep;
    if ((node->left == nullptr) && (node->right == nullptr))
    {
        delete node;
        node = nullptr;
    }
    else if (node->left == nullptr)
    {
        delPtr = node;
        node = node->right;
        delPtr->right = nullptr;
        delete delPtr;
        delPtr = nullptr;
    }
    else if (node->right == nullptr)
    {
        delPtr = node;
        node = node->left;
        delPtr->left = nullptr;
        delete delPtr;
        delPtr = nullptr;
    }
    else
    {
        processLeft(node->right, rep);
        node->value = rep;
    }
}
void BST::processLeft(TreeNode *&node, int &rep) {
    if (node->left == nullptr)
    {
        rep = node->value;
        TreeNode* delPtr = node;
        node = node->right;
        delPtr->right = nullptr;
        delete delPtr;
        delPtr = nullptr;
    }
    else
    {
        processLeft(node->left, rep);
    }
}
void BST::displayInorder() {
    cout << "Inorder display is: ";
    string str = "";
    inorder(root, str);
    if(str.size() > 2)
    {
        str.erase(str.size() - 1);
        str.erase(str.size() - 1);
    }
    cout << str << endl;
}
void BST::inorder(TreeNode *node, string& str) {
    if (node != nullptr) {
        inorder(node->left, str);
        str = str + to_string(node->value) + ", ";
        inorder(node->right, str);
    }
}
void BST::findFullBTLevel()
{
    cout << "Full binary tree level is: ";
    int level = 0;
    if(!root)
    {
        level = 0;
    }
    else
    {
        Queue* queue = new Queue();
        int num = 1;
        QueueNode* curr = new QueueNode(root, num);
        queue->enqueue(curr);
        while(curr)
        {
            if (curr->treeNode->left && curr->treeNode->right)
            {
                queue->enqueue(new QueueNode(curr->treeNode->left, ++num));
                queue->enqueue(new QueueNode(curr->treeNode->right, ++num));
                queue->dequeue();
                curr = queue->peek();
            }
            else
            {
                level = curr->level;
                delete queue;
                queue = nullptr;
                curr = nullptr;
            }
        }
        cout << level;
    }
     cout << endl;
}
Stack* BST::rootToA(int A)
{
    string res = "";
    Stack* stack = new Stack();
    searchKey(stack, A, root);
    /*if (searchKey(stack, A, root))
    {
        StackNode* curr = stack->head;
        while(curr)
        {
            res = res + to_string(stack->peek()->treeNode->value) + ", ";
            stack->pop();
            curr = stack->head;
        }
    }
    else
    {
        res =  "No path found.";
    }*/
    return stack;
}
bool BST::searchKey(Stack* stack, int num, TreeNode* node)
{
    if (!node)
    {
        delete stack;
        stack = nullptr;
        return false;
    }
    if (node->value == num)
    {
        stack->push(new StackNode(node));
        return true;
    }
    else if (node->value < num)
    {
        stack->push(new StackNode(node));
        return searchKey(stack, num, node->right);
    }
    else if (node->value > num)
    {
        stack->push(new StackNode(node));
        return searchKey(stack, num, node->left);
    }
    else
    {
        return false;
    }
}
void BST::pathFromAtoB(int A, int B)
{
    cout << "Path from " << A << " to " << B << " is: " << findPath(A, B) << endl;
}
string BST::findPath(int A, int B)
{
    string res = "";
    if (keyExists(A, root) && keyExists(B, root))
    {
        Stack* stack1 = rootToA(A);
        Stack* stack2 = rootToA(B);
        StackNode* curr1 = stack1->head;
        StackNode* curr2 = stack2->head;
        while(curr1 && curr2 && curr1->next && curr2->next && curr1->next->treeNode->value == curr2->next->treeNode->value )
        {
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        while(stack1->peek()->treeNode->value != curr1->treeNode->value)
        {
            res = res + to_string(stack1->peek()->treeNode->value) + ", ";
            stack1->pop();
        }
        while(curr2)
        {
            res = res + to_string(curr2->treeNode->value) + ", ";
            curr2 = curr2->next;
        }
        res.erase(res.size() - 1);
        res.erase(res.size() - 1);
        delete stack1;
        delete stack2;
        stack1 = nullptr;
        stack2 = nullptr;
        curr1 = nullptr;
        curr2 = nullptr;
    }
    return res;
}
void BST::lowestCommonAncestor(int A, int B)
{
    cout << "Lowest common ancestor of " << A << " and " << B << " is: ";
    if (keyExists(A, root) && keyExists(B, root))
    {
        Stack* stack1 = rootToA(A);
        Stack* stack2 = rootToA(B);
        StackNode* curr1 = stack1->head;
        StackNode* curr2 = stack2->head;
        while(curr1 && curr2 && curr1->next && curr2->next && curr1->next->treeNode->value == curr2->next->treeNode->value )
        {
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        cout << curr1->treeNode->value;
        delete stack1;
        delete stack2;
        stack1 = nullptr;
        stack2 = nullptr;
        curr1 = nullptr;
        curr2 = nullptr;
    }
    cout << endl;
}
void BST::maximumSumPath()
{
    cout << "Maximum sum path is: ";
    if (root)
    {
        int num = 0;
        int max = INT_MIN;
        int maxNum = root->value;
        calculateSum(root, num, max, maxNum);
        cout << findPath(root->value, maxNum);
    }
    cout << endl;
}
void BST::calculateSum(TreeNode* node, int& num, int& max, int& maxNum)
{
    if (node != nullptr) {
        num = num + node->value;
        if(num > max)
        {
            max = num;
            maxNum = node->value;
        }
        calculateSum(node->left, num, max, maxNum);
        calculateSum(node->right, num, max, maxNum);
        num = num - node->value;
    }
}
void BST::maximumWidth()
{
    cout << "Maximum level is: ";
    int maxLevel;
    int* levelCounts = new int[1];
    int levelSize = 0;
    if(!root)
    {
        delete[] levelCounts;
        maxLevel = 0;
        cout << endl;
        return;
    }
    else
    {
        Queue* queue = new Queue();
        QueueNode* curr = new QueueNode(root); curr->level = 1;
        levelCounts[0] = 1;
        levelSize++;
        queue->enqueue(curr);
        while(curr)
        {
            
            if (curr->treeNode->left)
            {
                queue->enqueue(new QueueNode(curr->treeNode->left));
                queue->tail->level = curr->level + 1;
                if (queue->tail->level > levelSize)
                {
                    int* temp = new int[levelSize + 1];
                    for(int i = 0; i < levelSize; i++)
                    {
                        temp[i] = levelCounts[i];
                    }
                    delete[] levelCounts;
                    levelCounts = new int[levelSize + 1];
                    for(int i = 0; i < levelSize; i++)
                    {
                        levelCounts[i] = temp[i];
                    }
                    levelCounts[levelSize] = 1;
                    levelSize++;
                    delete[] temp;
                    temp = nullptr;
                }
                else
                {
                    levelCounts[queue->tail->level - 1]++;
                }
            }
            if(curr->treeNode->right) {
                queue->enqueue(new QueueNode(curr->treeNode->right));
                queue->tail->level = curr->level + 1;
                if (queue->tail->level > levelSize)
                {
                    int* temp = new int[levelSize + 1];
                    for(int i = 0; i < levelSize; i++)
                    {
                        temp[i] = levelCounts[i];
                    }
                    delete[] levelCounts;
                    levelCounts = new int[levelSize + 1];
                    for(int i = 0; i < levelSize; i++)
                    {
                        levelCounts[i] = temp[i];
                    }
                    levelCounts[levelSize] = 1;
                    levelSize++;
                    delete[] temp;
                    temp = nullptr;
                }
                else
                {
                    levelCounts[queue->tail->level - 1]++;
                }
            }
            queue->dequeue();
            curr = queue->peek();
        }
           
        maxLevel = 0;
        for(int i = 1; i < levelSize; i++)
        {
            if (levelCounts[i] > levelCounts[maxLevel])
                maxLevel = i;
        }
        maxLevel++;
        delete queue;
        }
    Queue* queue = new Queue();
    QueueNode* curr = new QueueNode(root);
    queue->enqueue(curr);
     curr->level = 1;
    string res = "";
    while(curr)
    {
        if (curr->treeNode->left) {
            queue->enqueue(new QueueNode(curr->treeNode->left));
            queue->tail->level = curr->level + 1;
     }
        if(curr->treeNode->right) {
            queue->enqueue(new QueueNode(curr->treeNode->right));
            queue->tail->level = curr->level + 1; }
        if(curr->level == maxLevel) {
            res = res + to_string(curr->treeNode->value) + ", "; }
        queue->dequeue();
        curr = queue->peek();
    }
    if (res.size()>2)
    {
        res.erase(res.size() - 1);
        res.erase(res.size() - 1);
    }
    cout << res;
    cout << endl;
    delete[] levelCounts;
    delete queue;
    levelCounts = nullptr;
    queue = nullptr;
}
int BST::findMaxHeight()
{
    int num = 0;
    int max = 0;
    findHeight(root, num, max);
    return max;
}

void BST::findHeight(TreeNode* node, int& num, int& max)
{
    if (node != nullptr)
    {
        num++;
        if(num > max)
            max = num;
        findHeight(node->left, num, max);
        findHeight(node->right, num, max);
        num--;
    }
}
