#include "BST.h"
#include "TreeNode.h"
#include "Execute.h"
#include "Student.h"
#include "FileHandling.h"
#include<iostream>
using namespace std;

int main()
{
  FileHandling* handleFile = new FileHandling();
  Execute* running = new Execute(handleFile);
  bool keep = true;
  int choose;

  /////
  while (keep) {
    cout << "Please enter the number of the action you wish to perform: " << endl;
    cout << "1. Print all students and their information (sorted by ascending id #)" << endl;
    cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
    cout << "3. Find and display student information given the students id" << endl;
    cout << "4. Find and display faculty information given the faculty id" << endl;
    cout << "5. Given a student’s id, print the name and info of their faculty advisor" << endl;
    cout << "6. Given a faculty id, print ALL the names and info of his/her advisees" << endl;
    cout << "7. Add a new student" << endl;
    cout << "8. Delete a student given the id" << endl;
    cout << "9. Add a new faculty member" << endl;
    cout << "10. Delete a faculty member given the id." << endl;
    cout << "11. Change a student’s advisor given the student id and the new faculty id." << endl;
    cout << "12. Remove an advisee from a faculty member given the ids" << endl;
    cout << "13. Rollback" << endl;
    cout << "14. Exit" << endl;
    cout << "Please enter the number of the action you wish to perform: " << endl;
    cin >> choose;

    bool containsFile = handleFile->bothExist();
    if (!containsFile) {
      cout << "Please start by entering a faculty member" << endl;
      running->newFacMember();
    }

    int inStudID;
    int inFacID;

    switch (choose) {
      case 1:
        running->printStuds();
        break;
      case 2:
        running->printFac();
        break;
      case 3:
        cout << "Enter a student ID number: " << endl;
        cin >> inStudID;
        running->printStudID(inStudID);
        break;
      case 4:
        cout << "Enter a faulty ID number: " << endl;
        cin >> inFacID;
        running->printFacID(inFacID);
        break;
      case 5:
        cout << "Enter a student ID number: " << endl;
        cin >> inStudID;
        running->printAdInfo(inStudID);
        break;
      case 6:
        cout << "Enter a faulty ID number: " << endl;
        cin >> inFacID;
        running->printAllStudsInfo(inFacID);
        break;
      // case 7:
      //   running->addStud(running->newStud());
      //   break;
      // case 8:
      //   cout << "Enter a student ID number: " << endl;
      //   cin >> inStudID;
      //   running->deleteStud(inStudID);
      //   break;
      // case 9:
      //   running->addFac(running->newFacMember());
      //   break;
      // case 10:
      //   cout << "Enter a faulty ID number: " << endl;
      //   cin >> inFacID;
      //   running->deleteFac(inFacID);
      //   break;
      // case 11:
      //   cout << "Enter the student ID number: " << endl;
      //   cin >> inStudID;
      //   cout << "Enter the new faulty ID number: " << endl;
      //   cin >> inFacID;
      //   running->changeAdvisor(inStudID, inFacID);
      //   break;
      // case 12:
      //   cout << "Enter the student ID number to remove: " << endl;
      //   cin >> inStudID;
      //   cout << "Enter the faulty ID number: " << endl;
      //   cin >> inFacID;
      //   running->removeAdvisee(inStudID, inFacID);
      //   running->setEmptyStudAdv(inStudID);
      //   break;
      // case 13:
      //   cout << "Choice: " << choose << endl;
      //   //function call
      //   break;
      // case 14:
      //   cout << "Choice: " << choose << endl;
      //   keep = false;
      //   break;

      default:
        cout << "nope, not actually an option" << endl;
    }
  }

  return 0;

}
