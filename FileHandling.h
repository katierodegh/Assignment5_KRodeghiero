// Katie Rodeghiero
// CPSC350 - 02

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
  bool checkForFile(string fileName); //check to see if the files exist
  bool bothExist();
  void populateFacTree(); //if there's a file, fill the fac tree
  void populateStudTree(); //if there's a file, fill the stud tree
  void PrintToFiles();
  void filePrintStud(TreeNode<Student>* node, ofstream& myFile); //print to the files
  void filePrintFac(TreeNode<Faculty>* node, ofstream& myFile); //print to the files

  BST<Student> *masterStudent;
  BST<Faculty> *masterFaculty;
};

#endif
