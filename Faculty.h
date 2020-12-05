// Katie Rodeghiero
// CPSC350 - 02

#include<iostream>
#include<vector>
using namespace std;

#ifndef FACULTY_H
#define FACULTY_H


class Faculty {
public:
  Faculty(); //default constructor
  Faculty(int ID, string name, string facLevel, string department, vector<int> advisees); //constructor with all faculty information
  Faculty(int ID); //faculty with only the ID
  friend ostream& operator<<(ostream& os, const Faculty& obj); //lets use print full faculty with just <<
  vector<int> getAdvisees(); //returns the vector of advisees
  void setAdvisees(vector<int> newStuds); //sets the advisee vector
  int getID(); //get the faculty ID

private:
  int ID;
  string name;
  string facLevel;
  string department;
  vector<int> advisees;
};

#endif
