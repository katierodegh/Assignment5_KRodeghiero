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

    void push(S data);
    S pop();
    S peek();

    bool isFull();
    bool isEmpty();
    int getSize();

    int top;
    int mSize;

    S* myArray; //this is a pointer

};

template <class S>
GenStack<S>::GenStack(){ //default constructer
  myArray = new S[128]; //this is on the heap
  mSize = 128;
  top = -1;
}

template <class S>
GenStack<S>::GenStack(int maxSize){ //overload constructer
  myArray = new S[maxSize]; //this is on the heap
  mSize = maxSize;
  top = -1;
}

template <class S>
GenStack<S>::~GenStack(){ //destructor
  delete myArray;
}

template <class S>
void GenStack<S>::push(S data){
  //check is full before procededing
  myArray[++top] = data;
}

template <class S>
S GenStack<S>::pop(){
  if (isEmpty()) {
    cout << "Stack is empty" << endl;
    return '\0';
  }
  else
    return myArray[top--];
}

template <class S>
S GenStack<S>::peek() {
  //cheack if empty
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
