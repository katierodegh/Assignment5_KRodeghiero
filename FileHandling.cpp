#include "FileHandling.h"
#include "Student.h"
#include "Faculty.h"
#include <fstream>
#include<iostream>
using namespace std;

// FileHandling::FileHandling(){
// }
//
// string FileHandling::PromptFileInput() { //prompts for the input file name
//   string fileName;
//   cout<< "Please enter the file you wish to use: " << endl;
//   cin >> fileName;
//   return fileName;
// }
//
// ifstream FileHandling::OpenFile(string fileName) { //Takes in the file name and opens it, returns the open file
//   ifstream myFile;
//   myFile.open(fileName);
//   while (!(myFile.is_open())) { //if the file is not open, reprompt until good input
//     cout << "That file doesn't exist." << endl;
//     fileName = PromptFileInput();
//     myFile.open(fileName);
//   }
//   return myFile;
// }
//
// string FileHandling::EachLine(ifstream& myFile) { //takes the open file and returns a line of text
//   string myText;
//   getline(myFile, myText);
//   return myText;
// }
//
// void FileHandling::CloseFile(ifstream& myFile) { //closes the file
//   myFile.close();
// }
