// Katie Rodeghiero
// CPSC350 - 02

#include "BST.h"
#include "Student.h"
#include "Faculty.h"
#include "FileHandling.h"
#include "GenStack.h"
#include "TransactionType.h"
#include<iostream>
using namespace std;

class Execute {
public:
  Execute(FileHandling* handle); //file handling happens before
  //job of this is to get the trees
  Faculty* newFacMember();
  Student* newStud();
  void printStuds(); //1 Print all students and their information (sorted by ascending id #)
  void printFac(); //2 Print all faculty and their information (sorted by ascending id #)
  void printStudID(int inID); //3 Find and display student information given the students id
  void printFacID(int inID); //4 Find and display faculty information given the faculty id
  void printAdInfo(int inID); //5 Given a student’s id, print the name and info of their faculty advisor
  void printAllStudsInfo(int inID); //6 Given a faculty id, print ALL the names and info of his/her advisees
  void addStud(Student* stud); //7 Add a new student
  void deleteStud(int inID); //8 Delete a student given the id
  void addFac(Faculty* Fac); //9 Add a new faculty member
  void deleteFac(int inID); //10 Delete a faculty member given the id.
  void changeAdvisor(int inStudId, int newFacID); //11 Change a student’s advisor given the student id and the new faculty id.
  bool removeAdvisee(int inStudId, int inFacID); //12 Remove an advisee from a faculty member given the ids
  void Rollback(); //13 Rollback

  FileHandling* trees;
  GenStack<TransactionType>* rolling;

};
