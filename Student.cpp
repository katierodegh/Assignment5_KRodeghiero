#include "Student.h"
#include<iostream>
using namespace std;

Student::Student(int ID, string name, string studLevel, string major, double GPA, int advisorID) {
  this->ID = ID;
  this->name = name;
  this->studLevel = studLevel;
  this->major = major;
  this->GPA = GPA;
  this->advisorID = advisorID;
}

ostream& operator<<(ostream& os, const Student& obj) {
  os << obj.ID << endl;
  os << obj.name << endl;
  os << obj.studLevel << endl;
  os << obj.major << endl;
  os << obj.GPA << endl;
  os << obj.advisorID << endl;

  return os;
}

bool Student::operator<(Student const& rhs) {
  if(this->ID < rhs.ID) {
    return true;
  }
  return false;
}

bool Student::operator>(Student const& rhs) {
  if(this->ID > rhs.ID) {
    return true;
  }
  return false;
}

bool Student::operator==(Student const& rhs) {
  if(this->ID == rhs.ID) {
    return true;
  }
  return false;
}

bool Student::operator==(int id) {
  if(this->ID == id) {
    return true;
  }
  return false;
}
