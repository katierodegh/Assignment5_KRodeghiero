#include<iostream>
using namespace std;

#ifndef GENQUEUE_H
#define GENQUEUE_H

template <class Q>
class GenQueue{
  public:
    GenQueue(); //defaul
    GenQueue(int maxSize); //overload constructor
    ~GenQueue();

    //core functions
    void insert(Q d); //enqueue
    Q remove(); //dequeue

    //aux functions
    Q peek();
    bool isFull();
    bool isEmpty();
    unsigned int getSize(); //means it can only be 0 - where ever
    void printArray();

  private:
      int front; //AKA head
      int rear; //AKA tail
      int mSize;
      unsigned int numElements;

      Q *myQueue; //pointer to a char - array
};

template <class Q>
GenQueue<Q>::GenQueue() {
  myQueue = new Q[128];
  mSize = 128;
  front = 0;
  rear = 0;
  numElements = 0;
}

template <class Q>
GenQueue<Q>::GenQueue(int maxSize) {
  myQueue = new Q[maxSize];
  mSize = maxSize;
  front = 0;
  rear  = 0;
  numElements = 0;
}

template <class Q>
GenQueue<Q>::~GenQueue(){
  delete myQueue;
}

template <class Q>
void GenQueue<Q>::insert(Q d) {
  //check if full before proceeding this is it
  if (isFull()) {
    throw ("queue is full");
  }
  myQueue[rear++] = d; //circular queue because starting at 0
  rear = (rear) % mSize; //circular queue
  numElements++;
}

template <class Q>
Q GenQueue<Q>::remove() {
  //make sure not empty before proceeding this is it
  if (isEmpty()) {
    throw ("queue is empty, can't remove");
  }
  Q c ='\0'; //this is null
  c = myQueue[front++];
  front = (front) % mSize; //circular queue
  --numElements;
  return c;
}

template <class Q>
Q GenQueue<Q>::peek() {
  return myQueue[front];
}

template <class Q>
bool GenQueue<Q>::isFull() {
  return (numElements == mSize);
}

template <class Q>
bool GenQueue<Q>::isEmpty()
{
  return(numElements == 0);
}

template <class Q>
unsigned int GenQueue<Q>::getSize() {
  return numElements;
}

template <class Q>
void GenQueue<Q>::printArray()
{
  cout << "Q SIZE: " << getSize() << endl;
  cout << "Front: " << front << endl;
  cout << "Rear: " << rear << endl;

  for(int i = 0; i < mSize; ++i) {
    cout << "Q["<< i << "]: " << myQueue[i];
    if (i != mSize - 1) {
      cout << " | ";
    }
  }
}

#endif
