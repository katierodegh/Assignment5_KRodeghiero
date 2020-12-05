// Katie Rodeghiero
// CPSC350 - 02

#include<iostream>
#include "TreeNode.h"
using namespace std;

#ifndef STUDENT_H
#define STUDENT_H

class Student {
private:
  int ID;
  string name;
  string studLevel;
  string major;
  double GPA;
  int advisorID;

public:
  Student(); //default student constructor
  Student(int ID, string name, string studLevel, string major, double GPA, int advisorID); //student constructor with everything
  Student(int ID); //student constructor with only the ID
  int getID(); //get the student ID
  int getAdvisorID(); //get the advisor ID
  void setAdvisorID(int ID); //set the advisor ID
  friend ostream& operator<<(ostream& os, const Student& obj); //lets us print the whole student object

};

#endif
