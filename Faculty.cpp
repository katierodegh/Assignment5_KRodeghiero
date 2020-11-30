#include "Faculty.h"
#include<iostream>
using namespace std;

Faculty::Faculty(int ID, int name, string facLevel, string department) { //advisee
  this->ID = ID;
  this->name = name;
  this->facLevel = facLevel;
  this->department = department;
  //advisee
}

ostream& operator<<(ostream& os, const Faculty& obj) {
  os << obj.ID << endl;
  os << obj.name << endl;
  os << obj.facLevel << endl;
  os << obj.department << endl;
  //advisee shit

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
