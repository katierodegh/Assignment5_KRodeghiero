#include "BST.h"
#include "Student.h"
#include "Faculty.h"
#include<iostream>
using namespace std;

class Execute {
public:
  Execute(); //file handling happens before
  //job of this is to get the trees
  Faculty newFacMember();
  Student newStud();
  void printStuds(); //1
  void printFac(); //2
  void printStudID(int inID); //3
  void printFacID(int inID); //4
  void printAdInfo(int inID); //5
  void printAllStudsInfo(int inID); //6
  void addStud(Student stud); //7
  void deleteStud(int inID); //8
  void addFac(Faculty Fac); //9
  void deleteFac(int inID); //10
  void changeAdvisor(int inStudId, int newFacID); //11
  bool removeAdvisee(int inStudId, int inFacID); //12
  void setEmptyStudAdv(int inStudID);


};
