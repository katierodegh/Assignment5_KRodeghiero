#include "FileHandling.h"
#include "Student.h"
#include "Faculty.h"
#include <fstream>
#include<iostream>
using namespace std;

FileHandling::FileHandling(){
  studentTree = new BST<Student>;
  facultyTree = new BST<Faculty>;
}

FileHandling::~FileHandling(){
}

bool FileHandling::checkForFile(string fileName) { //checks to see if both files exist
  ofstream myfile(fileName);
  if(myfile.is_open()) {
    myfile.close();
    return true;
  }
  return false;
}

bool FileHandling::bothExist() {
  if (checkForFile("studentTable.txt") && checkForFile("facultyTable.txt")) {
    populateFacTree();
    populateStudTree();
    return true;
  }
  else {
    return false;
  }
}


void FileHandling::populateFacTree() {
  ofstream facFile("facultyTable.txt");
  string myText;
  int lineID;
  string lineName;
  string lineLevel;
  string lineDepartment;
  int numAdvisees;
  int count = 0;
  while(getline(facFile, myText)) {
    ++count;
    if(count == 1) {
      int lineID = myText
    }

  }
}

void FileHandling::populateStudTree() {
  ofstream studFile("studentTable.txt");
}

// string FileHandling::EachLine(ifstream& myFile) { //takes the open file and returns a line of text
//   string myText;
//   getline(myFile, myText);
//   return myText;
// }
//
void FileHandling::CloseFile(ifstream& studFile, ifstream& facFile) { //closes the file
  studFile.close();
  facFille.close();
}
