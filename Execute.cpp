#include "BST.h"
#include "Execute.h"
#include "Student.h"
#include "Faculty.h"
#include<iostream>
#include<vector>
using namespace std;

Execute::Execute() {
    //job of this is to get the trees
  studTree;
  facTree;
}

Faculty Execute::newFacMember() {
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

  return(Faculty(ID, name, facLevel, department, advisees));

}

Student Execute::newStud() {
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

  while(facTree->giveNode(advisorID) == NULL) {
    cout << "That advisor doesn't exist, please enter a new advisor ID: " << endl;
    cin >> advisorID;
  }
  return(Student(ID, name, studLevel, major, GPA, advisorID));
}

//1
void Execute::printStuds() {
  studTree->recPrint(); //need it to print the whole student
}

//2
void Execute::printFac() {
  facTree->recPrint(); //need it to print the whole faculty
}

//3
void Execute::printStudID(int inID) {
  Student* stud = new Student(inID);

  if(studTree->searchNode(stud)) {
    studTree->printNode(stud);
  }
  else {
    cout << "There is no student associated with ID: " << inID << endl;
  }
}

//4
void Execute::printFacID(int inID) {
  Faculty* fac = new Faculty(inID);
  if(facTree->searchNode(fac)) {
    facTree->printNode(fac);
  }
  else {
    cout << "There is no faculty member associated with ID: " << inID << endl;
  }
  //delete fac; //maybe because of the vector
}

//5
void Execute::printAdInfo(int inID) { //given a student ID, print their advisor's info
  Student* stud = new Student(inID);
  if(studTree->searchNode(stud)) {
    TreeNode<Student>* hold = studTree->giveNode(inID);
    int findAdvisor = hold->key.getAdvisorID();
    Faculty* fac = new Faculty(findAdvisor);
    facTree->printNode(fac);
  }
  else {
    cout << "That student doesn't exist" << endl;
  }
}

//6
void Execute::printAllStudsInfo(int inID) { //given an advisor's ID, print all their students and their info
  Faculty* fac = new Faculty(inID);
  if(facTree->searchNode(fac)) {
    TreeNode<Faculty>* hold = facTree->giveNode(inID);
    vector<int> ids = hold->key.getAdvisees(); //hold->Faculty()->getAdvisees();
    int count = 0;
    for (int i = 0; i <= ids.size(); ++i)
    {
      //could do an check to make sure it prints
      cout << "Student " << count << ": " << endl;
      studTree->printNode(hold[i]);
    }
  }
  else {
    cout << "That advisor doesn't exist" << endl;
  }
}

//7
void Execute::addStud(Student stud) { //need to give the advissee infor to an advisor
  if (!studTree->searchNode(stud)) {
    studTree->insertNode(stud);
    cout << "The student has been added" << endl;
  }
  else {
    cout << "A student with this ID already exists" << endl;
  }
}

//8
void Execute::deleteStud(int inID) { //need to remove it from the advisor
  TreeNode<Student>* hold = studTree->giveNode(inID);
  int facHoldID = hold->key.getAdvisorID();
  if (studTree->deleteNode(hold)) {
    removeAdvisee(inID, facHoldID);
    cout << "The student has been deleted" << endl;
  }
  else {
    cout << "There is no student associated with this ID: " << inID << endl;
  }

  delete hold;
}

//9
void Execute::addFac(Faculty fac) {
  if (!facTree->searchNode(fac)) {
    facTree->insertNode(fac);
    cout << "The faculty member has been added" << endl;
  }
  else {
    cout << "A faculty member with this ID already exists" << endl;
  }
}

// //10
void Execute::deleteFac(int inID) { //need to reassign all the advisee info
  Faculty* fac = new Faculty(inID);
  if(facTree->searchNode(fac)) {
    TreeNode<Faculty>* hold = facTree->giveNode(inID);

    vector<int> adHold = hold->key.getAdvisees();
    for (int i = 0; i <= adHold.size(); ++i) {
      Student* currStud = studTree->giveNode(adHold[i]);

      if (hold->right != NULL) {
        currStud->setAdvisorID(hold->right->key.getFacID());
      }
      else if (hold->left != NULL) {
        currStud->setAdvisorID(hold->left->key.getFacID());
      }
      else {
        currStud->setAdvisorID(studTree->root->key.getFacID());
      }
    }
    if (facTree->deleteNode(hold)) {
      cout << "The faculty member has been deleted" << endl;
    }
  }
  else {
    cout << "There is no faculty member associated with this ID: " << inID << endl;
  }
}

//11
void Execute::changeAdvisor(int inStudID, int newFacID) {
  // Student* stud = new Student(inStudID);
  // Faculty* fac = new Faculty(inFacID);
  TreeNode<Student>* holdStud = studTree->giveNode(inStudID);
  TreeNode<Faculty>* newFac = facTree->giveNode(newFacID);
  //if(studTree->searchNode(stud) && facTree->searchNode(fac))
  if((holdStud == NULL) && (newFac == NULL)) {
    int oldAdID = holdStud->key.getAdvisorID(); //old student advisor
    if (removeAdvisee(inStudID, oldAdID)) { //remove the advisee from the old advisor
      vector<int> holdNewAD = facTree->key.getAdvisees()//Get new faculty advisees
      holdAD.push_back(newFacID); //add the advisee
      holdStud->key.setAdvisorID(newFacID); //set student's advisor to new
    }
  }
  else {
    cout << "At least one ID does not connect to a person" << endl;
  }
}

//12
bool Execute::removeAdvisee(int inStudId, int inFacID) { //what do I do with that student?????
  Faculty* fac = new Faculty(inFacID); //this will only hold the ID
  if(facTree->searchNode(fac))
  {
    int place;
    TreeNode<Faculty>* hold = facTree->giveNode(inFacID);
    vector<int> adHold = hold->key.getAdvisees();
    for (int i = 0; i <= adHold.size(); ++i) {
      if (adHold[i] == inStudId) {
        adHold.erase(adHold.begin() + i);
        return true;
      }
      else {
        cout << "That student wasn't in the advisor's list" << endl;
        return false;
      }
    }
  }
  else {
    cout << "That faculty member does not exist" << endl;
  }
}

//extra
void Execute::setEmptyStudAdv(int inStudID) {
  TreeNode<Student>* holdStud = studTree->giveNode(inStudID);
  holdStud->key.setAdvisorID(facTree->root->key.getFacID());
}
