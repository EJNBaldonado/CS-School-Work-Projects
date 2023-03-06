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
 * Filename : main.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
#include <iostream>
#include <vector>
#include "Stack.h"
#include <stdexcept>

using namespace std;

int main() {

  Stack<int> n;
  string name = "NEO";
  Stack<string> s;
  try {
    s.is_empty() ? cout << "\nEmpty stack\n" : cout  << "Non-empty stack\n";

    n.push(1);          //WORKS
    n.push(2);
    n.push(3);
    n.push(4);
    n.push(5);
    s.push(name);
    s.push(name);
    s.push(name);
    s.push(name);
    s.push(name);

    s.push(name); // Raises overflow exception, 1st catch block.

  } catch(overflow_error& e) {
    cerr << "Overflow Exception: "<< e.what() << endl;
  } catch(...) {
    cerr << "Whoops! Catch-all block, terminating program.\n";
  }

  try {
    cout << s.top() << endl;
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
  } catch(underflow_error& e) {
    cerr << "Underflow Exception: "<< e.what() << endl;
  } catch(...) {
    cerr << "Default Exception.\n";
  }

  vector<int> myvector(10);
  cout << myvector.at(20); // vector::at throws an out-of-range
  try {
    cout << myvector.at(20); // vector::at throws an out-of-range
  } catch(out_of_range& e) {
    cerr << "Out of range error: "<< e.what() << endl;
  } catch(...) {
    cerr << "Default Exception.\n";
  }

  //cout << myvector.at(20); // vector::at throws an out-of-range

  try {
    s.top(); // Raises underflow exception, 1st catch block.
  } catch(underflow_error& e) {
    cerr << "Underflow Exception: "<< e.what() << endl;
  } catch(...) {
    cerr << "Default Exception.\n";
  }

  cout << "\nThe program flow continues...\n";
  cout << "The \"return 0;\" statement will cause the program to exit.\n";

  return 0;
}