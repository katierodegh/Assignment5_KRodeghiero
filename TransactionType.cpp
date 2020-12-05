// Katie Rodeghiero
// CPSC350 - 02

#include<iostream>
#include<vector>
#include "TransactionType.h"
using namespace std;

TransactionType::TransactionType() { //default constructor
  num = 0;
}

TransactionType::TransactionType(int ID, int num) { //constructor with ID and num of operation
  this->ID = ID;
  this->num = num;
}

TransactionType::TransactionType(TreeNode<Faculty>* fac, int num) { //faculty tree node with ID and num of operation
  this->fac = fac;
  this->num = num;
}
TransactionType::TransactionType(TreeNode<Student>* stud, int num) { //Student tree node with ID and num of operation
  this->stud = stud;
  this->num = num;
}
