// Katie Rodeghiero
// CPSC350 - 02

#include <iostream>
using namespace std;
#ifndef TREENODE_H
#define TREENODE_H

template <class T>
class TreeNode {
  public:
    TreeNode(); //default constructor
    TreeNode(T key); //constructor that take in a key

    T key; //key is the entire student object
    TreeNode *left; //pointers to out left and right child
    TreeNode *right;

};

template <class T>
TreeNode<T>::TreeNode() { //set left and right pointers
  left = NULL;
  right = NULL;
}

template <class T>
TreeNode<T>::TreeNode(T k) { //set points and key
  left = NULL;
  right = NULL;
  key = k;
}

#endif
