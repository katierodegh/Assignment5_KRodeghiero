#include<iostream>
#include <fstream>
#include "Student.h"
#include "Faculty.h"
#include "BST.h"
using namespace std;

#ifndef FILEHANDLING_H
#define FILEHANDLING_H

class FileHandling {

public:
  FileHandling();
  //~FileHandling();
  bool checkForFile(string fileName); //check to see if the files exist
  bool bothExist();
  void populateFacTree();
  void populateStudTree();
  void PrintToFile(string writeFile);
  void CloseFile(ifstream& studFile, ifstream& facFile); // close the file

  BST<Student> *masterStudent;
  BST<Faculty> *masterFaculty;
};

#endif
