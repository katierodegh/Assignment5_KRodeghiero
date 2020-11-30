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
  string PromptFileInput(); //promt for the file name
  ifstream OpenFile(string fileName); //Takes in the file name and opens it, returns the open file
  string EachLine(ifstream& myFile); //takes the open file and returns a line of text
  void CloseFile(ifstream& myFile); // close the file

  BST<Student> &studentTree;
  BST<Faculty> &facultyTree;
};

#endif
