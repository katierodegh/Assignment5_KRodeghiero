// Katie Rodeghiero
// CPSC350 - 02

#include<iostream>
#include<vector>
#include "Student.h"
#include "Faculty.h"
using namespace std;

#ifndef TRANSACTIONTYPE_H
#define TRANSACTIONTYPE_H

class TransactionType {
public:
  TransactionType(); //default constructor
  TransactionType(int ID, int num); //constructor with ID and num of operation
  TransactionType(TreeNode<Faculty>* fac, int num); //faculty tree node with ID and num of operation
  TransactionType(TreeNode<Student>* stud, int num); //student tree node with ID and num of operation

  int ID;
  int num;
  TreeNode<Faculty>* fac;
  TreeNode<Student>* stud;
};

#endif
