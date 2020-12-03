#include<iostream>
#include<vector>
using namespace std;

#ifndef FACULTY_H
#define FACULTY_H


class Faculty {
public:
  Faculty(int ID, string name, string facLevel, string department, vector<int> advisees);
  Faculty(int ID);
  friend ostream& operator<<(ostream& os, const Faculty& obj);
  bool operator<(Faculty const& rhs);
  bool operator>(Faculty const& rhs);
  bool operator==(Faculty const& rhs);
  bool operator==(int id);
  bool operator!=(int id);
  vector<int> getAdvisees();
  int getFacID();

private:
  int ID;
  string name;
  string facLevel; // (lecturer, assistant prof, associate prof, etc)
  string department;
  vector<int> advisees;
};

#endif
