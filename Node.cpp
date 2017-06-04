#include <iostream>
#include <string.h>
#include "Node.h"


using namespace std;

Node::Node(Student* s){
  next = NULL;
  
  studentpointer = s;
}
//deconstructor, clear memory
Node::~Node(){
  delete studentpointer;
}
//returns a pointer to the next node
Node* Node::getNext(){
  return next;
}
//sets the pointer to the next node
void Node::setNext(Node* n){
  next = n;
}
//returns a pointer to the Student class
Student* Node::data(){
  return studentpointer;
}


