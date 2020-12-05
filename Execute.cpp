// Katie Rodeghiero
// CPSC350 - 02

#include "BST.h"
#include "Execute.h"
#include "Student.h"
#include "Faculty.h"
#include "TransactionType.h"
#include "GenStack.h"
#include<iostream>
#include<vector>
using namespace std;

Execute::Execute(FileHandling* handle) {
  trees = handle;
  rolling = new GenStack<TransactionType>;
}

Faculty* Execute::newFacMember() { //make a new faculty member and return the pointer to it
  int ID;
  string name;
  string facLevel;
  string department;
  vector<int> advisees;

  cout << "Please enter the ID number: " << endl;
  cin >> ID;
  cout << "Please enter the name: " << endl;
  cin >> name;
  cout << "Please enter the faculty level: " << endl;
  cin >> facLevel;
  cout << "Please enter the department: " << endl;
  cin >> department;

  Faculty* fac = new Faculty(ID, name, facLevel, department, advisees);
  return(fac);
}

Student* Execute::newStud() { //make a new student and return the pointer to it
  int ID;
  string name;
  string studLevel;
  string major;
  double GPA;
  int advisorID;

  cout << "Please enter the ID number: " << endl;
  cin >> ID;
  cout << "Please enter the name: " << endl;
  cin >> name;
  cout << "Please enter the student level: " << endl;
  cin >> studLevel;
  cout << "Please enter the major: " << endl;
  cin >> major;
  cout << "Please enter the GPA: " << endl;
  cin >> GPA;
  cout << "Please enter the advisor ID: " << endl;
  cin >> advisorID;

  Faculty* fac = new Faculty(advisorID);

  while(!(trees->masterFaculty->searchNode(fac))) {
    cout << "That advisor doesn't exist, please enter a new advisor ID: " << endl;
    cin >> advisorID;
    fac = new Faculty(advisorID);
  }
  Student* stud = new Student(ID, name, studLevel, major, GPA, advisorID);
  return(stud);
}

//1
void Execute::printStuds() { //print the entire student tree
  trees->masterStudent->printTree();
}

//2
void Execute::printFac() { //print the entire faculty tree
  trees->masterFaculty->printTree(); //need it to print the whole faculty
}

//3
void Execute::printStudID(int inID) { //print the student from the ID number
  Student* stud = new Student(inID);

  if(trees->masterStudent->searchNode(stud)) { //if we find the student
    trees->masterStudent->printNode(stud); //print the student
  }
  else { //if we don't find the student, stop
    cout << "There is no student associated with ID: " << inID << endl;
  }
}

//4
void Execute::printFacID(int inID) { //print the faculty from the ID number
  Faculty* fac = new Faculty(inID);
  if(trees->masterFaculty->searchNode(fac)) { //if we find the faculty member
    trees->masterFaculty->printNode(fac); // print the faculty member
  }
  else { //if not, stop
    cout << "There is no faculty member associated with ID: " << inID << endl;
  }
}

//5
void Execute::printAdInfo(int inID) { //given a student ID, print their advisor's info
  TreeNode<Student>* hold = trees->masterStudent->giveNode(inID); //find the student with the corresponding ID
  if(hold != NULL) { //if the student exists
    int findAdvisor = hold->key.getAdvisorID();
    Faculty* fac = new Faculty(findAdvisor);
    trees->masterFaculty->printNode(fac); //print the faculty member
  }
  else { //student doesn't exist
    cout << "That student doesn't exist" << endl;
  }
}

//6
void Execute::printAllStudsInfo(int inID) { //given an advisor's ID, print all their students and their info
  TreeNode<Faculty>* hold = trees->masterFaculty->giveNode(inID);
  if(hold != NULL) {
    vector<int> ids = hold->key.getAdvisees(); //get the advisees from the faculty
    if(ids.size() != 0) {
      for (int i = 0; i < ids.size(); ++i) //loops though all the advisees
      {
        Student* stud = new Student(ids[i]);
        trees->masterStudent->printNode(stud); //prints the whole student
      }
    }
    else {
      cout << "This faculty has no advisees" << endl; //if there are no advisees
    }
  }
  else {
    cout << "That advisor doesn't exist" << endl; //if the advisor doesn't exist
  }
}

//7
void Execute::addStud(Student* stud) { //add student to the tree
  if (!trees->masterStudent->searchNode(stud)) { //if this student does not exist
    trees->masterStudent->insertNode(*stud); //add it to the tree
    int advID = stud->getAdvisorID(); //get the advisor's id

    TreeNode<Faculty>* hold = trees->masterFaculty->giveNode(advID); //advisor node
    vector<int> ids = hold->key.getAdvisees(); //getting all the advisees from the advior (THIS DOES WORK)
    ids.push_back(stud->getID());
    hold->key.setAdvisees(ids); //resets the advisors ID vector

    TransactionType* save = new TransactionType(stud->getID(), 1); //add to the transaction type array
    rolling->push(save);
    cout << "The student has been added" << endl;
  }
  else {
    cout << "A student with this ID already exists" << endl;
  }
}

//8
void Execute::deleteStud(int inID) { //delete student from the tree
  Student* stud = new Student(inID);
  TreeNode<Student>* hold = trees->masterStudent->giveNode(inID); //get the faculty node
  if (hold!=NULL) { //if that faculty exists
    int facHoldID = hold->key.getAdvisorID();  //get the student's advisor's id
    if (trees->masterStudent->deleteNode(stud)) { //delete the student from the advisor
      removeAdvisee(inID, facHoldID); //remove the student ID from the advisors list

      TransactionType* save = new TransactionType(hold, 2); //save it or roll back
      rolling->push(save);
      cout << "The student has been deleted" << endl;
    }
  }
  else {
    cout << "There is no student associated with this ID: " << inID << endl;
  }
}

//9
void Execute::addFac(Faculty* fac) { //add faculty to the tree
  if (!trees->masterFaculty->searchNode(fac)) { //if a faculty with the id doesn't exist...add it
    trees->masterFaculty->insertNode(*fac);

    TransactionType* save = new TransactionType(fac->getID(), 3); //save it for rollback
    rolling->push(save);
    cout << "The faculty member has been added" << endl;
  }
  else {
    cout << "A faculty member with this ID already exists" << endl;
  }
}

//10
void Execute::deleteFac(int inID) { //delete a faculty member
  Faculty* fac = new Faculty(inID);
  TreeNode<Faculty> *hold = trees->masterFaculty->giveNode(inID);
  if(hold != NULL) { //if the faculty member exists
    vector<int> adHold = hold->key.getAdvisees(); //vector of their advisors
    int newAdvisor;
    if (hold->right != NULL) {
      newAdvisor = hold->right->key.getID();
    }
    else if (hold->left != NULL) {
      newAdvisor = hold->left->key.getID();
    }
    else {
      newAdvisor = trees->masterFaculty->root->key.getID();
    }
    for (int i = 0; i < adHold.size(); ++i) { //give its students to a different faculty member
      changeAdvisor(adHold[i], newAdvisor);
    }
    if (trees->masterFaculty->deleteNode(fac)) { //once the node is deleted
      TransactionType* save = new TransactionType(hold, 4); //save for rollback
      rolling->push(save);
      cout << "The faculty member has been deleted" << endl;
    }
  }
  else {
    cout << "There is no faculty member associated with this ID: " << inID << endl;
  }
}

//11
void Execute::changeAdvisor(int inStudID, int newFacID) {
  TreeNode<Student>* holdStud = trees->masterStudent->giveNode(inStudID);
  TreeNode<Faculty>* newFac = trees->masterFaculty->giveNode(newFacID);

  if((holdStud != NULL) && (newFac != NULL)) {

    int oldAdID = holdStud->key.getAdvisorID(); //old student advisor
    if (removeAdvisee(inStudID, oldAdID)) { //remove the advisee from the old advisor
      vector<int> holdNewIDs = newFac->key.getAdvisees();//Get new faculty advisees
      holdNewIDs.push_back(inStudID); //add the advisee
      newFac->key.setAdvisees(holdNewIDs); //updates advisor's list
      holdStud->key.setAdvisorID(newFacID); //set student's advisor to new
    }
  }
  else {
    cout << "At least one ID does not connect to a person" << endl;
  }
}

//12
bool Execute::removeAdvisee(int inStudId, int inFacID) { //removes the advisee from the faculty
  TreeNode<Faculty> *hold = trees->masterFaculty->giveNode(inFacID);
  if(hold != NULL) {
    vector<int> adHold = hold->key.getAdvisees(); //get the advisee vector
    vector<int> temp;
    bool check = false;
    for (int i = 0; i < adHold.size(); ++i) { //loop through them
      if (adHold[i] != inStudId) {
        temp.push_back(adHold[i]); //don't add the one we want to remove
      }
      else {
        check = true;
      }
    }
    if (check) {
      hold->key.setAdvisees(temp); //updates the advisee vector
      return true;
    }
    else {
    cout << "That student wasn't in the advisor's list" << endl;
    return false;
    }
  }
  else {
    cout << "That faculty member does not exist" << endl;
  }
}

//13
void Execute::Rollback() { //undo previous commands
  TransactionType now = rolling->pop();
  switch(now.num) {
    case 1:
      deleteStud(now.ID);
      break;
    // case 2:
    //   addStud(now.stud->key);
    //   break;
    case 3:
      deleteFac(now.ID);
      break;
    // case 4:
    //   addFac(now.fac->key);
    //   break;
    default:
      cout << "No more rollback options" << endl;
      break;
  }
}
