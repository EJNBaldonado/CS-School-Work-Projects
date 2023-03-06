/**
 * Course: CS010C Summer 2021
 *
 * First Name: Eugene
 * Last Name: Baldonado
 * Username: ebald009
 * email address: ebald009@ucr.edu
 *
 *
 * Assignment: assn4
 * Filename : Node.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
 
#include <string>

using namespace std;

#ifndef __NODE_H_
#define __NODE_H_

class Node {
public:
 	Node();
	Node(char ch, int cnt){ c = ch; count = cnt; left = NULL; right = NULL; bits = "";}
	Node(Node* leftCh, Node* rightCh, char ch, int cnt){ left = leftCh; right = rightCh; c = ch; count = cnt; bits = "";} 
	~Node(){
	    if( left != NULL ){
	        delete left;
	    }
	    if ( right != NULL ) {
	        delete right;
	    }
	}
  Node* left;
  Node* right;
  char c;
  int count;
  string bits;
};

#endif /* NODE_H_ */
