#include "Student.h"
#include<iostream>
using namespace std;

Student::Student() {
  ID = 0;
  name = "";
  studLevel = "";
  major = "";
  GPA = 0.0;
  advisorID = 0;
}

Student::Student(int ID, string name, string studLevel, string major, double GPA, int advisorID) {
  this->ID = ID;
  this->name = name;
  this->studLevel = studLevel;
  this->major = major;
  this->GPA = GPA;
  this->advisorID = advisorID;
}

Student::Student(int ID) {
  this->ID = ID;
  name = "";
  studLevel = "";
  major = "";
  GPA = 0.0;
  advisorID = 0;
}

int Student::getAdvisorID() {
  return advisorID;
}

int Student::getID() {
  return ID;
}

void Student::setAdvisorID(int ID) {
  this->ID = ID;
}

ostream& operator<<(ostream& os, const Student& obj) {
  os << "ID: " << obj.ID << endl;
  os << "Name: " << obj.name << endl;
  os << "Student Level: " << obj.studLevel << endl;
  os << "Major: " << obj.major << endl;
  os << "GPA: " << obj.GPA << endl;
  os << "Advisor ID: " << obj.advisorID << endl;

  return os;
}

bool Student::operator<(Student* const& rhs) {
//bool Student::operator<(Student* stud) {
  if(this->ID < rhs->ID) {
    return true;
  }
  return false;
}

bool Student::operator>(Student* const& rhs) {
  if(this->ID > rhs->ID) {
    return true;
  }
  return false;
}

bool Student::operator==(Student* const& rhs) {
  if(this->ID == rhs->ID) {
    return true;
  }
  return false;
}

// bool Student::operator<(Student const& rhs) {
//   if(this->ID < rhs.ID) {
//     return true;
//   }
//   return false;
// }

// bool Student::operator>(Student const& rhs) {
//   if(this->ID > rhs.ID) {
//     return true;
//   }
//   return false;
// }
//
// bool Student::operator==(Student const& rhs) {
//   if(this->ID == rhs.ID) {
//     return true;
//   }
//   return false;
// }

bool Student::operator==(int id) {
  if(this->ID == id) {
    return true;
  }
  return false;
}

bool Student::operator!=(int id) {
  if(this->ID != id) {
    return true;
  }
  return false;
}

bool Student::operator!=(Student* stud) {
  if(this->ID != stud->ID) {
    return true;
  }
  return false;
}
