
#include <iostream>
#include "Node.h"
//A class for a hash table that holds students
class HashTable{
 public:
  HashTable();
  void add();
  void remove(int id);
  void addRandom(int number);
  void print();
 private:
  void add(Student* student);
  void expand();
  int getKey(Student* student);
  Node** array;
  int size;
};
