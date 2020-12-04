#include "Faculty.h"
#include<iostream>
#include<vector>
using namespace std;

Faculty::Faculty() {
  ID = 0;
  name = "";
  facLevel = "";
  department = "";
  advisees;
}

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

int Faculty::getID() {
  return ID;
}

//might want a destructor

ostream& operator<<(ostream& os, const Faculty& obj) {
  os << "ID: " << obj.ID << endl;
  os << "Name: " << obj.name << endl;
  os << "Faculty Level: " << obj.facLevel << endl;
  os << "Department: " << obj.department << endl;
  os << "Advisee IDs: " << endl;
  if (obj.advisees.size() == 0) {
    os << "This person has no advisees " << endl;
  }
  else {
    for (int i = 0; i < obj.advisees.size(); ++i)
      {
        os << obj.advisees[i] << endl;
      }
    }

  return os;
}

// ostream& operator<<(ostream& os, const Faculty& obj) {
//   os << obj.ID << endl;
//   os << obj.name << endl;
//   os << obj.facLevel << endl;
//   os << obj.department << endl;
//   os << obj.advisees.size() << endl;
//   if (advisees.size() == 0) {
//     //os << "This person has no advisees " << endl;
//   }
//   else {
//     for (int i = 0; i <= obj.advisees.size(); ++i)
//       {
//         os << obj.advisees[i] << endl;
//       }
//     }
//
//   return os;
// }


bool Faculty::operator<(Faculty* const& rhs) {
  if(this->ID < rhs->ID) {
    return true;
  }
  return false;
}

bool Faculty::operator>(Faculty* const& rhs) {
  if(this->ID > rhs->ID) {
    return true;
  }
  return false;
}

bool Faculty::operator==(Faculty* const& rhs) {
  if(this->ID == rhs->ID) {
    return true;
  }
  return false;
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
  if(this->ID != id) {
    return true;
  }
  return false;
}

bool Faculty::operator!=(Faculty* fac) {
  if(this->ID != fac->ID) {
    return true;
  }
  return false;
}
