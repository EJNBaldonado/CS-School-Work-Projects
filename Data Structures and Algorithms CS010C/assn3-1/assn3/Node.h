#ifndef __NODE_H
#define __NODE_H

#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

class Node {

private:
  string str;
  int count;

public:
  Node* left;
  Node* right;
  string getStr();
  int getCnt();
  void setCnt(int c);
  void setStr(string s);

public:
  Node ( string s ) { left = right = NULL; count = 1; str = s; };
  Node ( ) { left = right = NULL; count = 0; };
  ~Node ( );
  

  // Add any additional variables/functions here
  const Node& operator=(const Node& right);
};

#endif
