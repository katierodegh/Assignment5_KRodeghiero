// Katie Rodeghiero
// CPSC350 - 02

#include "FileHandling.h"
#include "Student.h"
#include "Faculty.h"
#include "Execute.h"
#include "BST.h"
#include "TreeNode.h"
#include <fstream>
#include<iostream>
using namespace std;

FileHandling::FileHandling(){ //make the trees
  masterStudent = new BST<Student>;
  masterFaculty = new BST<Faculty>;

}

bool FileHandling::checkForFile(string fileName) { //checks to see if file exists
  ifstream myfile(fileName);
  if(myfile.is_open()) {
    myfile.close();
    return true;
  }
  return false;
}

bool FileHandling::bothExist() { //checks to see if both files exists
  if (checkForFile("studentTable.txt") && checkForFile("facultyTable.txt")) {
    populateFacTree(); //if they exist, populate
    populateStudTree();
    return true;
  }
  else {
    return false;
  }
}


void FileHandling::populateFacTree() { //read the faculty input in from the file
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
    if (myText.length() == 0) {
      getline(facFile, myText);
    }
    if(count == 1) {
      lineName = myText;
    }
    else if(count == 2) {
      lineID = stoi(myText);
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
        cout << "HERE HERE HERE" << endl;
        masterFaculty->insertNode(Faculty(lineID, lineName, lineLevel, lineDepartment, lineAdvisees));
        lineAdvisees.clear();
        count = 0;
      }
    }

  }
  facFile.close();
}

void FileHandling::populateStudTree() { //read the student information from the file
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
    if (myText.length() == 0) {
      getline(studFile, myText);
    }
    if(count == 1) {
      lineName = myText;
    }
    else if(count == 2) {
      lineID = stoi(myText);
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
      masterStudent->insertNode(Student(lineID, lineName, lineLevel, lineMajor, lineGPA, lineAdvisorID));
      count = 0;
    }
  }
  studFile.close();
}


void FileHandling::PrintToFiles() { //print to the writeFiles
  ofstream myFile;
  myFile.open("studentTable.txt", ios::trunc);
  TreeNode<Student>* rootStud = masterStudent->root;
  filePrintStud(rootStud, myFile); //rewrite the stud file
  myFile.close();
  myFile.open("facultyTable.txt", ios::trunc);
  TreeNode<Faculty>* rootFac = masterFaculty->root;
  filePrintFac(rootFac, myFile); //rewrite the fac file
  myFile.close();
}

void FileHandling::filePrintStud(TreeNode<Student>* node, ofstream& myFile) { //write on the open student file
  if (node != NULL) {
    filePrintStud(node->left, myFile);
    myFile << node->key << endl;
    filePrintStud(node->right, myFile);
  }
}

void FileHandling::filePrintFac(TreeNode<Faculty>* node, ofstream& myFile) { // write on the open faculty file
  if (node != NULL) {
    filePrintFac(node->left, myFile);
    myFile << node->key << endl;
    filePrintFac(node->right, myFile);
  }
}
