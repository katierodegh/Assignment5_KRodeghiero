#include "BST.h"
#include "TreeNode.h"
#include<iostream>
using namespace std;

int main()
{
  //proof it works
  BST<int> b;
  b.insertNode(3);
  b.insertNode(1);
  b.insertNode(2);
  b.insertNode(10);
  b.insertNode(20);
  b.insertNode(21);
  b.insertNode(15);
  b.insertNode(17);
  b.insertNode(18);

  cout << "contains: " << (b.searchNode(99) ? "found it" : "not in tree") << endl;
  b.insertNode(99);
  cout << "contains: " << (b.searchNode(99) ? "found it" : "not in tree") << endl;
  b.deleteNode(3);

  b.printTree();
  /////
  int choose;
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

  switch (choose) {
    case 1:
      cout << "Choice: " << choose << endl;
      //function call
      break;
    case 2:
      cout << "Choice: " << choose << endl;
      //function call
      break;
    case 3:
      cout << "Choice: " << choose << endl;
      //function call
      break;
    case 4:
      cout << "Choice: " << choose << endl;
      //function call
      break;
    case 5:
      cout << "Choice: " << choose << endl;
      //function call
      break;
    case 6:
      cout << "Choice: " << choose << endl;
      //function call
      break;
    case 7:
      cout << "Choice: " << choose << endl;
      //function call
      break;
    case 8:
      cout << "Choice: " << choose << endl;
      //function call
      break;
    case 9:
      cout << "Choice: " << choose << endl;
      //function call
      break;
    case 10:
      cout << "Choice: " << choose << endl;
      //function call
      break;
    case 11:
      cout << "Choice: " << choose << endl;
      //function call
      break;
    case 12:
      cout << "Choice: " << choose << endl;
      //function call
      break;
    case 13:
      cout << "Choice: " << choose << endl;
      //function call
      break;
    case 14:
      cout << "Choice: " << choose << endl;
      //function call
      break;

    default:
      cout << "nope, not actually an option" << endl;
  }

  return 0;

}
