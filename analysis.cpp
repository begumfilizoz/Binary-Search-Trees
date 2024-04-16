/**
* Title: Binary Search Trees
* Author : Begüm Filiz Öz
* ID: 22203470
* Section : 3
* Homework : 1
* Description : Analysis class method implementations */

#include "analysis.h"
using namespace std;

analysis::analysis(){};
analysis::~analysis(){};
void analysis::timeAnalysis(){
    int* keys = {};
    BST bst(keys, 0);
    cout << "Tree is created without any nodes, before additions." << endl;
    delete[] keys;
    keys = nullptr;
    srand(static_cast<unsigned int>(time(0)));
    for(int j = 0; j < 10; j++){
        int* arr = new int[1000];
        for (int i = 0; i < 1000; i++)
        {
            int num = rand();
            for (int j = 0; j < i; j++)
            {
                if (arr[j] == num)
                {
                    num = rand();
                    j = -1;
                }
            }
            arr[i] = num;
        }
        clock_t beg = clock();
        for(int i = 0; i < 1000; i++)
        {
            bst.insertNode(arr[i], bst.root);
        }
        clock_t end = clock();
        cout << "Time: " << double(end - beg) / CLOCKS_PER_SEC << endl;
        cout << "Height: " << bst.findMaxHeight() << endl;
        delete[] arr;
        arr = nullptr;
    }
}

