#include<iostream>
#include "TreeNode.h"
#include "Faculty.h"
#include "Student.h"
using namespace std;

#ifndef BST_H
#define BST_H

template <class B>
class BST {
private:
    TreeNode<B> *root;

public:
    BST();
    ~BST();

    void insertNode(B value);
    bool searchNode(B value);
    bool deleteNode(B value);

    bool isEmpty();
    //int getMax();
    //int getMin();
    void recPrint(TreeNode<B> *node);
    void printTree();
    void printNode(B value);
    TreeNode<B> giveNode(int value);

    TreeNode<B> *getSuccessor(TreeNode<B> *d); //returns the successor of the node to be deleted, d
};

template <class B>
BST<B>::BST() {
  root = NULL;
}

template <class B>
BST<B>::~BST() {
  //iterate and delete, this is O(n)
}

template <class B>
bool BST<B>::isEmpty() {
  if (root == NULL) {
    return true;
  }

  return false;
}

template <class B>
void BST<B>::recPrint(TreeNode<B> *node) {
  //inorder traversal
  //prints tree starting at a specfic key
  if (node != NULL) {
    recPrint(node->left);
    cout << node->key << endl;
    recPrint(node->right);
  }
}

template <class B>
void BST<B>::printTree() {
  //prints the whole tree
  recPrint(root);
}

template <class B>
void BST<B>::printNode(B value) {

  TreeNode<B> *current = root;

  while (current->key != value) {
    if (value < current->key) {
      current = current -> left;
    }
    else {
      current = current -> right;
    }
    if(current == NULL) {
      //value does not exist
      return;
    }
  }
  cout << current->key << endl;
}

template <class B>
TreeNode<B> BST<B>::giveNode(int value) {

  TreeNode<B> *current = root;

  while (current->key != value) {
    if (value < current->key) {
      current = current -> left;
    }
    else {
      current = current -> right;
    }
    if(current == NULL) {
      //value does not exist
      return NULL;
    }
  }
  return current;
}

// template <class B>
// int BST<B>::getMax() {
//   if(isEmpty()){
//     return NULL;
//   }
//   TreeNode *current = root;
//   while (current->right != NULL) {
//     current = current -> right;
//   }
//
//   return current->key; //could be key
// }
//
// template <class B>
// int BST<B>::getMin() {
//   if(isEmpty()){
//     return NULL;
//   }
//   TreeNode *current = root;
//   while (current->left != NULL) {
//     current = current -> left;
//   }
//   return current->key; //could be key
// }

template <class B>
void BST<B>::insertNode(B value) {
  TreeNode<B> *node = new TreeNode<B>(value);
  if (isEmpty()) {//root == null
    root = node;
  }
  else {
    TreeNode<B> *parent = NULL;
    TreeNode<B> *current = root;

    while(true) {
      parent = current;

      if(value < current-> key) {
        //go left
        current = current->left;
        if(current == NULL) {
          parent->left = node;
          break;
        }
      }
      else {
        current = current->right;
        if (current == NULL) {
          parent->right = node;
          break;
        }
      }
    }
  }
}

template <class B>
bool BST<B>::searchNode(B value) {
  if (isEmpty()) {
    return false;
  }
  else {
    TreeNode<B> *current = root;

    while (current->key != value) {
      if (value < current->key) {
        current = current -> left;
      }
      else {
        current = current -> right;
      }
      if(current == NULL) {
        //value does not exist
        return false;
      }
    }
    return true;
  }
}

template <class B>
bool BST<B>::deleteNode(B k) {

  if(isEmpty()) { //root == NULL, empty tree
    return false;
  }

  TreeNode<B> *parent = NULL;
  TreeNode<B> *current = root;
  bool isLeftNode = true;

  //usual code to find a node
  while(current -> key != k) {
    parent = current;

    if (k < current->key) {
      isLeftNode = true;
      current = current -> left;
    }
    else {
      isLeftNode = false;
      current = current -> right;
    }

    if(current == NULL) {
      //value does not exist
      return false;
    }
  }

  //if we make it here we found it, now lets proceed to delete

  //case: node to be deleted has no children, AKA leaf node
  if(current->left == NULL && current->right == NULL) {
    if(current == root) {
      root = NULL;
    }
    else if (isLeftNode){
      parent ->left = NULL;
    }
    else {
      parent -> right = NULL;
    }
  }

  //case: node to delete has one child. need to determine whether child is left or right

  if(current -> right == NULL) { //if has left child
    if(current == root) {
      root = current -> left;
    }
    else if (isLeftNode) {
      parent -> left = current -> left;
    }
    else {
      parent -> right = current -> left;
    }
  }
  else if(current -> left == NULL) { //if has right child
    if(current == root) {
      root = current -> right;
    }
    else if (isLeftNode) {
      parent -> left = current -> right;
    }
    else {
      parent -> right = current -> right;
    }
  }
  else {
    //node to be deleted has two children. we need ot find the successor in this case
    TreeNode<B> *successor = getSuccessor(current);

    if(current == root) {
      root = successor;
    }
    else if(isLeftNode) {
      parent -> left = successor;
    }
    else {
      parent -> right = successor;
    }

    successor -> left = current -> left; //might need to be in the else statement above??
  }

  //do we delete(garbage collect) the tree node in the delete function or the destructor;
  //we have to figure it out
  return true;
}

template <class B>
TreeNode<B>* BST<B>::getSuccessor(TreeNode<B> *d) {
  TreeNode<B> *sp = d;
  TreeNode<B> *successor = d;
  TreeNode<B> *current = d-> right;

  while(current != NULL) {
    sp = successor;
    successor = current;
    current = current -> left;
  }

  if (successor != d->right) {
    //descendant of right children
    sp -> left = successor -> right;
    successor-> right = d ->right;
  }

  return successor;
}

#endif
