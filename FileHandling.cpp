#include "FileHandling.h"
#include "Student.h"
#include "Faculty.h"
#include "Execute.h"
#include <fstream>
#include<iostream>
using namespace std;

FileHandling::FileHandling(){
  masterStudent = new BST<Student>;
  masterFaculty = new BST<Faculty>;

}

// FileHandling::~FileHandling(){
// }

bool FileHandling::checkForFile(string fileName) { //checks to see if both files exist
  ifstream myfile(fileName);
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
  ifstream facFile("facultyTable.txt");
  string myText;
  int lineID;
  string lineName;
  string lineLevel;
  string lineDepartment;
  int numAdvisees;
  int count = 0;
  vector<int> lineAdvisees;
  while(getline(facFile, myText)) {
    ++count;
    if(count == 1) {
      lineID = stoi(myText);
    }
    else if(count == 2) {
      lineName = myText;
    }
    else if(count == 3) {
      lineLevel = myText;
    }
    else if(count == 4) {
      lineDepartment = myText;
    }
    else if(count == 5) {
      numAdvisees = stoi(myText);
    }
    else if(count <= (5 + numAdvisees)) {
      lineAdvisees.push_back(stoi(myText)); //making the vector
      if (count == (5 + numAdvisees)) {
        //cout << "HERE HERE HERE" << endl;
        masterFaculty->insertNode(Faculty(lineID, lineName, lineLevel, lineDepartment, lineAdvisees));
        lineAdvisees.clear();
        count = 0;
      }
    }

  }
  facFile.close();
}

void FileHandling::populateStudTree() {
  ifstream studFile("studentTable.txt");
  string myText;
  int lineID;
  string lineName;
  string lineLevel;
  string lineMajor;
  double lineGPA;
  int lineAdvisorID;
  int count = 0;
  while(getline(studFile, myText)) {
    ++count;
    if(count == 1) {
      lineID = stoi(myText);
    }
    else if(count == 2) {
      lineName = myText;
    }
    else if(count == 3) {
      lineLevel = myText;
    }
    else if(count == 4) {
      lineMajor = myText;
    }
    else if(count == 5) {
      lineGPA = (stoi(myText) * 1.0);
    }
    else if(count == 6) {
      lineAdvisorID = stoi(myText);
      cout << "ID: " << lineID << endl;
      cout << "ADVISOR ID: " << lineAdvisorID << endl;
      masterStudent->insertNode(Student(lineID, lineName, lineLevel, lineMajor, lineGPA, lineAdvisorID));
      cout << "HERE HERE HERE" <<endl;
      count = 0;
    }
  }
  studFile.close();
}


void FileHandling::PrintToFile(string writeFile) { //passes writeFile by refernces to print to the open writeFile
  ofstream myFile;
  myFile.open(writeFile, ios::trunc);
  //transverse the tree
    //myFile << currentNode;
  //use the print thing from BST??
  //writeFile << arrayGrid[i][j]; //writes each line to the output file
}

// void FileHandling::CloseFile(ifstream& studFile, ifstream& facFile) { //closes the file
//   studFile.close();
//   facFile.close();
// }
