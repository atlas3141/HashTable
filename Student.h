#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string.h>


//Student class, it has four different variables for the name, student id, and gpa......
class Student{
 public:
  Student();
  Student(int newId, char* first, char* last, float newGpa);
  ~Student();
  void print();
  int getId();
  float getGpa();
 private:
  char* firstName;
  char* lastName;
  int id;
  float gpa;
};

#endif
