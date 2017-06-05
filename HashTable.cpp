#include "HashTable.h"
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;


//HashTable.h, A hashTable class for students that grows, adds, deletes and randomly adds
HashTable::HashTable(){ 
  //constructor, initializes junk
  array = new Node*[100];
  size = 100;
}
void HashTable::add(){
  //adds if its just a basic student
  add(new Student());
}
void HashTable::remove(int id){
  //looks through the array and deletes a node if it has the same id
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
void HashTable::addRandom(int newCount){
  //opens up two files of first and last names
  //picks a random name gpa and ID and creates a student off  of it

  char* firsts[100];
  char* seconds[100];
  ifstream firstStream;
  ifstream secondStream;
  firstStream.open("firsts.txt");
  secondStream.open("seconds.txt");
  if (firstStream.is_open() && secondStream.is_open()){
    int i = 0;
    char newInput[30];
    firstStream >> newInput;
    firsts[i] = strdup(newInput);
    i++;
    while(firstStream.peek() != '\n' && !firstStream.eof()){
      firstStream >> newInput;
      firsts[i] = strdup(newInput);
      i++;
      
    }
    int j = 0;
    secondStream >> newInput;
    seconds[j] = strdup(newInput);
    j++;
    while(secondStream.peek() != '\n' && !secondStream.eof()){
      secondStream >> newInput;    
      seconds[j] = strdup(newInput);
      j++;
    }
    int id;
    char* first;
    char* second;
    float gpa;
    
    
    for(int k = 0; k < newCount; k++){
      id = 1000 + rand()%9000;
      first = firsts[rand()%i];
      second = seconds[rand()%j];
      gpa = float(rand()%400)/100;
      add(new Student(id,first,second,gpa));
 
    }
  }
}
void HashTable::print(){
  //iterates through the entire array and prints
  for (int i = 0; i < size; i++){
    Node* current = array[i];
    while(current){
      current->data()->print();
      current = current->getNext();
    }
  }
}
void HashTable::add(Student* student, bool checkCollisions){
  int key = getKey(student);
  if(array[key]){
    Node* current = array[key];
    int collisionCount = 1;
    while(current->getNext()){
      collisionCount ++;
      current = current->getNext();
    }
    current->setNext(new Node(student));
    if(collisionCount >= 3 && checkCollisions){
      expand();
    }
  }
  else{
    array[key] = new Node(student);
  }
}
void HashTable::expand(){
  //doubles the size of the array +1 to give it an offset
  Node** old = array;
  array = new Node*[size*2 + 1];
  int oldSize = size;
  size = size*2+1;
  for (int i = 0; i < oldSize; i++){
    Node* current = old[i];
    while(current){
      add(current->data(),false);
      current = current->getNext();
    }
  }
  delete old;
}
int HashTable::getKey(Student* student){
  //Simple Hash function
  int toReturn = student->getId();
  return toReturn %size;
}
