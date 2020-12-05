// Katie Rodeghiero
// CPSC350 - 02

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
    B* key;

public:
    BST(); //default constructor
    ~BST(); //destrctor
    void DeleteRecursive(TreeNode<B>* node); //delete each node in the tree
    TreeNode<B> *root; //pointer to the root
    void insertNode(B value);
    bool searchNode(B* value); //search for a node
    bool deleteNode(B* value);
    bool isEmpty();
    void recPrint(TreeNode<B>* node); //print the tree starting at a node
    void printTree(); //print the whole tree
    void printNode(B* value); //print a node based on content
    TreeNode<B>* giveNode(int value); //return a whole node;

    TreeNode<B> *getSuccessor(TreeNode<B> *d); //returns the successor of the node to be deleted, d
};

template <class B>
BST<B>::BST() {
  root = NULL;
}

template <class B>
BST<B>::~BST()
{
    DeleteRecursive(root);
}

template <class B>
void BST<B>::DeleteRecursive(TreeNode<B>* node) { //traverse the tree the delete the nodes
  if (node)
  {
    DeleteRecursive(node->left);
    DeleteRecursive(node->right);
    delete node;
  }
}

template <class B>
bool BST<B>::isEmpty() { //checks to see if the tree is empty
  if (root == NULL) {
    return true;
  }
  return false;
}

template <class B>
void BST<B>::recPrint(TreeNode<B>* node) { //prints the whole tree smallest to largest value
  if (node != NULL) {
    recPrint(node->left);
    cout << node->key << endl;
    recPrint(node->right);
  }
}

template <class B>
void BST<B>::printTree() { //print the whole tree
  recPrint(root);
}

template <class B>
void BST<B>::printNode(B* value) { //print the node based off the value

  TreeNode<B> *current = root;
  while (current->key.getID() != value->getID()) { //while the current ID doesn't match the one we're looking for
    if (value->getID() < current->key.getID()) { //if it's smaller go left
      current = current -> left;
    }
    else { //larger go right
      current = current -> right;
    }
    if(current == NULL) {
      return;
    }
  }
  cout << current->key << endl; //print the value we find
}

template <class B>
TreeNode<B>* BST<B>::giveNode(int value) { //return the whole node based off the value

  TreeNode<B>* current = root; //start at the root
  while (current->key.getID() != value) { //traverse the tree until we find the node
    if (value < current->key.getID()) {
      current = current -> left;
    }
    else {
      current = current -> right;
    }
    if(current == NULL) { //if the value doesn't exist, return NULL
      return NULL;
    }
  }
  return current; //return the value
}

template <class B>
void BST<B>::insertNode(B value) { //insert a node into the tree
  TreeNode<B> *node = new TreeNode<B>(value);
  if (isEmpty()) { //if the tree is empty, it becomes the root
    root = node;
  }
  else { //keep track of current and parent nodes
    TreeNode<B> *parent = NULL;
    TreeNode<B> *current = root;

    while(true) {
      parent = current;

      if(value.getID() < current-> key.getID()) { //if the value is smaller, go left
        current = current->left;
        if(current == NULL) { //if it's the smaller, insert
          parent->left = node;
          break;
        }
      }
      else { //the value is larger, go right
        current = current->right;
        if (current == NULL) { //if we reach a leaf, insert
          parent->right = node;
          break;
        }
      }
    }
  }
}

template <class B>
bool BST<B>::searchNode(B* value) { //search for a node based on value
  if (isEmpty()) { //if the tree is empty the node does not exist
    return false;
  }
  else {
    TreeNode<B>* current = root; //start at the root
    while (current->key.getID() != value->getID()) { //traverse until we find it
      if (value->getID() < current->key.getID()) { //value is smaller, go left
        current = current -> left;
      }
      else { //value is larger, go right
        current = current -> right;
      }
      if(current == NULL) { //value does not exist
        return false;
      }
    }
    return true;
  }
}

template <class B>
bool BST<B>::deleteNode(B* k) { //delete a node based on content

  if(isEmpty()) { // empty tree node doesn't exist
    return false;
  }

  TreeNode<B> *parent = NULL; //keep track of parent and current
  TreeNode<B> *current = root;
  bool isLeftNode = true;

  //search for the node
  while(current->key.getID() != k->getID()) {
    parent = current;

    if (k->getID() < current->key.getID()) {
      isLeftNode = true;
      current = current->left;
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

  //if the node desn't exist, we're done
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
  if(current->right == NULL) { //if has left child
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
  return true;
}

template <class B>
TreeNode<B>* BST<B>::getSuccessor(TreeNode<B> *d) { //get the sucessor, used in deleting
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
