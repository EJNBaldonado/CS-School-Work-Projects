/**
 * Course: CS010C Summer 2021
 *
 * First Name: Eugene
 * Last Name: Baldonado
 * Username: ebald009
 * email address: ebald009@ucr.edu
 *
 *
 * Assignment: assn2
 * Filename : Stack.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#ifndef STACK_H_
#define STACK_H_

#define CAPACITY 100
#include <stdexcept>

using namespace std;

typedef int T;

template <class T>
class Stack {
public:
  int t; // type must be int, index into array
  T S[CAPACITY];
  Stack() { t = -1; }

  void push(T value) {
    if(size() == CAPACITY){
        throw overflow_error("Stack overflow");
    }
        t++;
        S[t] = value;
  }

  void pop() {
    if(is_empty()){
        throw underflow_error("Pop called on empty stack");
    }
    t--;
  }

  T& top() {
    if(is_empty()){
      throw underflow_error("Top called on empty stack");
    }
     return S[t];
  }

  bool is_empty() {
       return (t < 0);
  }

  unsigned int size() const {
   return t + 1;
  }

};

#endif /* STACK_H_ */