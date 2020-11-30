#include<iostream>
using namespace std;

#ifndef FACULTY_H
#define FACULTY_H


class Faculty {
public:
  Faculty(int ID, int name, string facLevel, string department);
  friend ostream& operator<<(ostream& os, const Faculty& obj);
  bool operator<(Faculty const& rhs);
  bool operator>(Faculty const& rhs);
  bool operator==(Faculty const& rhs);
  bool operator==(int id);

private:
  int ID;
  string name;
  string facLevel; // (lecturer, assistant prof, associate prof, etc)
  string department;
  //list of integers list of integers corresponding to all of the faculty member’s advisees’ ids
};

#endif
