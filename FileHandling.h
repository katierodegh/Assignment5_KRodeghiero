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
  ~FileHandling();
  bool checkForFile(string fileName); //check to see if the files exist
  bool bothExist();
  void populateFacTree();
  void populateStudTree();
  void CloseFile(ifstream& myFile, ifstream& myFile); // close the file

  BST<Student> &studentTree;
  BST<Faculty> &facultyTree;
};

#endif
