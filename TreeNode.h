#include <iostream>
using namespace std;
#ifndef TREENODE_H
#define TREENODE_H

template <class T>
class TreeNode {
  //I think this needs to store a faculty or student
  public:
    TreeNode();
    TreeNode(T key); //out key is our value, and the value is the key (in this case but they can be separate)
    //TreeNode(int key, string value); //another option
    ~TreeNode();

    T key;
    TreeNode *left; //pointers to out left and right child
    TreeNode *right;

};

template <class T>
TreeNode<T>::TreeNode() {
  left = NULL;
  right = NULL;
}

template <class T>
TreeNode<T>::TreeNode(T k) {
  left = NULL;
  right = NULL;
  key = k;
}

template <class T>
TreeNode<T>::~TreeNode() {
  //need to research this
}

#endif
