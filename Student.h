#include<iostream>
using namespace std;

#ifndef STUDENT_H
#define STUDENT_H

class Student {
private:
  int ID;
  string name;
  string studLevel; // field (Freshman, Sophomore, etc)
  string major;
  double GPA;
  int advisorID;

public:
  Student(int ID, string name, string studLevel, string major, double GPA, int advisorID);
  Student(int ID);
  int getAdvisorID();
  void setAdvisorID(int ID);
  friend ostream& operator<<(ostream& os, const Student& obj);
  bool operator<(Student const& rhs);
  bool operator>(Student const& rhs);
  bool operator==(Student const& rhs);
  bool operator==(int id);
  bool operator!=(int id);
};

#endif
