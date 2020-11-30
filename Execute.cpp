#include "BST.h"
#include "Execute.h"
#include<iostream>
using namespace std;

Execute::Execute() {
    //job of this is to get the trees
  //studTree;
  //facTree;
}

void Execute::printStuds() {
  studTree->recPrint(); //need it to print the whole student
}

void Execute::printFac() {
  facTree->recPrint(); //need it to print the whole faculty
}

void Execute::printStudID(int inID) {
  //facTree->recPrint(); //need it to print the whole faculty
}

void Execute::printFacID(int inID) {
  //facTree->recPrint(); //need it to print the whole faculty
}
