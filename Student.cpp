// Katie Rodeghiero
// CPSC350 - 02

#include "Student.h"
#include<iostream>
using namespace std;

Student::Student()  { //default student constructor
  ID = 0;
  name = "";
  studLevel = "";
  major = "";
  GPA = 0.0;
  advisorID = 0;
}

Student::Student(int ID, string name, string studLevel, string major, double GPA, int advisorID) { //student constructor that takes in all the info
  this->ID = ID;
  this->name = name;
  this->studLevel = studLevel;
  this->major = major;
  this->GPA = GPA;
  this->advisorID = advisorID;
}

Student::Student(int ID) { //makes a student with only the id
  this->ID = ID;
  name = "";
  studLevel = "";
  major = "";
  GPA = 0.0;
  advisorID = 0;
}

int Student::getAdvisorID() { //gets advior ID number
  return advisorID;
}

int Student::getID() { //gets the student's id number
  return ID;
}

void Student::setAdvisorID(int ID) { //sets the advisor ID number
  advisorID = ID;
}

ostream& operator<<(ostream& os, const Student& obj) { //lets us print the whole student object
  os << obj.name << endl;
  os << obj.ID << endl;
  os << obj.studLevel << endl;
  os << obj.major << endl;
  os << obj.GPA << endl;
  os << obj.advisorID << endl;

  return os;
}
