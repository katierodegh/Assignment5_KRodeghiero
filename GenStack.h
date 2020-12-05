// Katie Rodeghiero
// CPSC350 - 02

#include<iostream>
using namespace std;

#ifndef GENSTACK_H
#define GENSTACK_H

template <class S>
class GenStack{
  public:
    GenStack(); //default
    GenStack(int maxSize); //overload
    ~GenStack();//destructor

    void push(S* data); //add to the stack
    S pop(); //remove from the stack
    S peek(); //look at the top

    bool isFull();
    bool isEmpty();
    int getSize();

    int top;
    int mSize;

    S* myArray; //this is a pointer to the array

};

template <class S>
GenStack<S>::GenStack(){ //default constructer
  myArray = new S[16]; //this creates an array on the heap
  mSize = 16;
  top = -1;
}

template <class S>
GenStack<S>::GenStack(int maxSize){ //overload constructer
  myArray = new S[maxSize]; //this creates an array on the heap
  mSize = maxSize;
  top = -1;
}

template <class S>
GenStack<S>::~GenStack(){ //destructor
  delete myArray;
}

template <class S>
void GenStack<S>::push(S* data){
  if(!isFull()) {
    myArray[++top] = *data;
  }
}

template <class S>
S GenStack<S>::pop(){ //remove from the top of the stack
  if (isEmpty()) {
    cout << "Stack is empty" << endl;
    S* hi  = new S();
    return *hi;
  }
  else{
    return myArray[top--];
  }
}

template <class S>
S GenStack<S>::peek() { //peak at the top of the stack
  if (isEmpty()) {
    cout << "Stack is empty" << endl;
    return '\0';
  }
  else
    return myArray[top];
}

template <class S>
bool GenStack<S>::isFull(){
  return (top == mSize - 1);
}

template <class S>
bool GenStack<S>::isEmpty(){
  return (top == -1);
}

template <class S>
int GenStack<S>::getSize() {
  return top + 1;
}

#endif
