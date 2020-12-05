// Katie Rodeghiero
// CPSC350 - 02

#include "Faculty.h"
#include<iostream>
#include<vector>
using namespace std;

Faculty::Faculty() { //default faculty constructor
  ID = 0;
  name = "";
  facLevel = "";
  department = "";
  advisees;
}

Faculty::Faculty(int ID, string name, string facLevel, string department, vector<int> advisees) { //faculty with all information
  this->ID = ID;
  this->name = name;
  this->facLevel = facLevel;
  this->department = department;
  this->advisees = advisees;
}

Faculty::Faculty(int ID) { //faculty set with only the ID
  this->ID = ID;
  name = "";
  facLevel = "";
  department = "";
  advisees;
}

vector<int> Faculty::getAdvisees() { //get the private vector of advisees
  return advisees;
}

void Faculty::setAdvisees(vector<int> newStuds) { //sets the vector of advisees
  advisees.clear();
  for (int i = 0; i < newStuds.size(); ++i) {
    advisees.push_back(newStuds[i]);
  }
}

int Faculty::getID() { //returns the faculty ID
  return ID;
}

ostream& operator<<(ostream& os, const Faculty& obj) { //allows us to just use << print the whole Faculty member
  os << obj.name << endl;
  os << obj.ID << endl;
  os << obj.facLevel << endl;
  os << obj.department << endl;
  os << obj.advisees.size() << endl;
  for (int i = 0; i < obj.advisees.size(); ++i) {
      os << obj.advisees[i] << endl;
  }
  return os;
}
