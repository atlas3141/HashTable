

#include "HashTable.h"


HashTable::HashTable(){
  array = new Node*[100];
  size = 100;
}
void HashTable::add(){
  add(new Student());
}
void HashTable::remove(int id){
  for (int i = 0; i < size; i++){
    Node* current = array[i];
    if (current){
      if (current->data()->getId() == id){
	array[i] = NULL;
	delete current;
      }
      else{
	Node* last = current;
	current = current->getNext();
	while(current){
	  if (current->data()->getId() == id){
	    last->setNext(current->getNext());
	    delete current;
	  }
	  current = current->getNext();
	}
      }
    }
  }
}
void HashTable::addRandom(){
  
}
void HashTable::print(){
  for (int i = 0; i < size; i++){
    Node* current = array[i];
    while(current){
      current->data()->print();
      current = current->getNext();
    }
  }
}
void HashTable::add(Student* student){
  int key = getKey(student);
  if(array[key]){
    Node* current = array[key];
    int collisionCount = 1;
    while(current->getNext()){
      collisionCount ++;
      current = current->getNext();
    }
    current->setNext(new Node(student));
    if(collisionCount >= 3){
      expand();
    }
  }
  else{
    array[key] = new Node(student);
  }
}
void HashTable::expand(){
  Node** old = array;
  array = new Node*[size*2 + 1];
  int oldSize = size;
  size = size*2+1;
  cout << "newSize" << endl;
  for (int i = 0; i < oldSize; i++){
    Node* current = old[i];
    while(current){
      add(current->data());
      current = current->getNext();
    }
  }
  delete old;
}
int HashTable::getKey(Student* student){
  int toReturn = student->getId();
  return toReturn %size;
}
int HashTable::getKey(Student* student, int tableSize){
  int toReturn = student->getId();
  return toReturn % tableSize;
}
