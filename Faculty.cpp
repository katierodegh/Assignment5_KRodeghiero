#include "Faculty.h"
#include<iostream>
#include<vector>
using namespace std;

Faculty::Faculty(int ID, string name, string facLevel, string department, vector<int> advisees) { //advisee
  this->ID = ID;
  this->name = name;
  this->facLevel = facLevel;
  this->department = department;
  this->advisees = advisees;
}

Faculty::Faculty(int ID) {
  this->ID = ID;
  name = "";
  facLevel = "";
  department = "";
  advisees;
}

vector<int> Faculty::getAdvisees() {
  return advisees;
}

int Faculty::getFacID() {
  return ID;
}

//might want a destructor

ostream& operator<<(ostream& os, const Faculty& obj) {
  os << "ID: " << obj.ID << endl;
  os << "Name: " << obj.name << endl;
  os << "Faculty Level: " << obj.facLevel << endl;
  os << "Department: " << obj.department << endl;
  os << "Advisee IDs: " << endl;
  //advisee shit
  for (int i = 0; i <= obj.advisees.size(); ++i)
    {
      os << obj.advisees[i] << endl;
    }

  return os;
}

bool Faculty::operator<(Faculty const& rhs) {
  if(this->ID < rhs.ID) {
    return true;
  }
  return false;
}

bool Faculty::operator>(Faculty const& rhs) {
  if(this->ID > rhs.ID) {
    return true;
  }
  return false;
}

bool Faculty::operator==(Faculty const& rhs) {
  if(this->ID == rhs.ID) {
    return true;
  }
  return false;
}

bool Faculty::operator==(int id) {
  if(this->ID == id) {
    return true;
  }
  return false;
}

bool Faculty::operator!=(int id) {
  if(this->ID == id) {
    return true;
  }
  return false;
}
