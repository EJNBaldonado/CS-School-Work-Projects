/**
 * Course: CS010C Summer 2021
 *
 * First Name: Eugene
 * Last Name: Baldonado
 * Username: ebald009
 * email address: ebald009@ucr.edu
 *
 *
 * Assignment: lab4
 * Filename : main.cc
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */

#include "BST.H"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {
  
  if(argc != 2) {
    cerr << "Usage error: expected <executable> <mode>" << endl;
    exit(1);
  }
  
  string cmd = "";
  int key = -1;
  BST t;
  string mode = argv[1];
  
  // ofstream you will use to write to file output.dot
  // currently an empty output.dot gets written into pwd
 ofstream ofs("output.dot");
  if(!ofs) {
    cout << "output.dot could not be opened." << endl;
    exit(1);
  } 
  
  for(;;) {
    cin >> cmd;
    if(cmd == "insert") {
      cin >> key;
      t.insert(key);
    }
    else if(cmd == "remove") {
      cin >> key;
      t.remove(key);
    }
    else if(cmd == "dotty") {
      // implement code here that will produce the correct dot file
      if(mode == "height"){
        t.height();
        t.writeHeight();
      }
    
      if(mode == "preorder"){
        t.preorder();
        t.writePreorder();
      } 
      
      if(mode == "inorder"){
        t.inorder();
        t.writeInorder();
      }
      
      if(mode == "postorder"){
        t.postorder();
        t.writePostorder();
      }
      // based on the user's preference (mode), i.e., preorder, postorder,
      // inorder, node height
    }
    else if(cmd == "display") t.display();
    else if(cmd == "end") break;
    else
      cout << cmd << ", not found, try again." << endl;
  }
  // close ofstream
  ofs.close();
  cout << "Good bye!" << endl;
  return 0;
}
