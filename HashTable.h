
#include <iostream>
#include "Node.h"

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
  int getKey(Student* student, int tableSize);
  Node** array;
  int size;
};
