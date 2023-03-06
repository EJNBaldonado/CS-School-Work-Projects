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
 * Filename : Huffman.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#ifndef HUFFMAN_H_
#define HUFFMAN_H_

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include "pq_zero.h"
#include "Node.h"

using namespace std;

class Huffman {
public:
  Huffman();
  
  
  Huffman(const string& inputFile){
    
    ifstream inFS;
    inFS.open(inputFile);
    
    if (!inFS.is_open()){
      cout << "Error opening: " << inputFile;
      return;
    }
    char InChar;
    InChar = inFS.get();
    while (InChar != EOF){
      mymap[InChar]++;
      InChar = inFS.get();
    }
  
    inFS.close();
  BuildPQ();
  }
  
  
  ~Huffman(){ 
    root = NULL;
  }
  
  void PrintCharFrequencies(){ // prints char=>char_frequency   
    map<char, int>::iterator itr;
    char c;
    int freq;
    for (itr = mymap.begin(); itr != mymap.end(); itr++){
      c = itr->first;
      freq = itr->second;
      
      if( c == '\n') {
        cout << "\\n" << " => " << freq << endl;
      }
      
      else {
        cout << c << " => " << freq << endl;
      }
    }
  }
  
  void BuildPQ(){ // adds Nodes to priority queue with frequency counts
    map<char,int>::iterator itr;
    char c;
    int freq;
    for (itr = mymap.begin(); itr != mymap.end(); itr++){
      c = itr->first;
      freq = itr->second;
      Node* curr = new Node(c, freq);
      pq.push( curr, curr->count );
    }
  }
  
  
  void BuildHuffmanTree(){ // combines lowest count nodes into Huffman Tree //JUNK VALUE = '*'
      Node* leftChild;
      Node* rightChild;;
      while(pq.size() != 1){  
        rightChild = pq.top();
        pq.pop();
        leftChild = pq.top();
        pq.pop();
        Node* parent = new Node(leftChild, rightChild, '*' , leftChild->count + rightChild->count);
        pq.push(parent, leftChild->count + rightChild->count);
      }
      root = pq.top();
  }
  
  void SetBitsPerChar(){ // calls private function
    SetBitsPerChar( root );
  }
 
  void DisplayPrefixTree(){ // optional, calls private function
    DisplayPrefixTree( root );
  }
  
  void SetBitCodes(){  // postorder traversal, calls private function
    SetBitCodes( root );
  }
  
  void Stats(){ // prints the num bits used: non-compressed/compressed format
    cout << "Without compression, 8-bit character:" << endl << endl;
    map<char,int>::iterator itr;
    char c;
    int freq;
    string bitString;
    int total = 0;
     
     for (itr = mymap.begin(); itr != mymap.end(); itr++){
      c = itr->first;
      freq = itr->second;
      total = freq * 8 + total;
      /*
            if( c == '\n') {
        cout << "\\n" << " => " << freq << endl;
      }
      
      else {
        cout << c << " => " << freq << endl;
      }
      */
      if ( c == '\n' ){
        cout << "\\n" << " occurs " << freq << " times. Cost of: " << freq * 8 << " bits. ";
        cout << " Total so far: " << total << " bits." << endl << endl;
      }
      else {
        cout << c << " occurs " << freq << " times. Cost of: " << freq * 8 << " bits. ";
        cout << " Total so far: " << total << " bits." << endl << endl;
      }
     }
     
     cout << "Total bits = " << total << endl << endl << endl << endl;
     
    total = 0;
    cout << "Huffman codes used for lossless compression:" << endl << endl;
    for (itr = mymap.begin(); itr != mymap.end(); itr ++){
      c = itr->first;
      freq = itr->second;
      bitString = mymap_compress[c];
      total = freq * bitString.size() + total;
      if ( c == '\n' ){
        cout << "\\n" << " occurs " << freq << " times." << " Bit sequence: " << bitString << ". Cost of: " << bitString.size() << " bits.";
        cout <<  " Total so far: " << total << " bits." << endl << endl; 
      }
      else {
        cout << c << " occurs " << freq << " times." << " Bit sequence: " << bitString << ". Cost of: " << bitString.size() << " bits.";
        cout <<  " Total so far: " << total << " bits." << endl << endl;
      }
    }
    cout << "Total bits = " << total << endl;
  }
  
  void BitMap(){  // prints char, bitstream
    map<char,int>::iterator itr;
    char c;
    string bitString;
     
     for (itr = mymap.begin(); itr != mymap.end(); itr++){
      c = itr->first;
      bitString = mymap_compress[c];
      if( c == '\n' ){
        cout << "\\n" << ',' << bitString << endl;
      }
      else{
        cout << c << ',' << bitString << endl;
      }
     }
    
  }
  
  //void PrintMessage(); //prints original message in huffman codes
  
private:
  list<string> message_list; // stores multiple input files if needed
  string message;      // stores a single input file
  map<char,int> mymap; // maps frequency "count" indexed by char 'c'
  map<char,string> mymap_compress; // maps frequency "count" to bitstream
  pq_zero<Node*> pq;   // binary heap priority queue stores nodes with priority
  Node* root; // root of prefix tree
  
  
  void DisplayPrefixTree(Node* t){ // optional, use for debugging, display tree
    static int numDepth = 0;
    ++numDepth;
    if ( t == NULL ) return;
    if ( t->right != NULL ) DisplayPrefixTree( t->right );
    for (int i = 1; i != numDepth; ++i){
      cout << "    ";
    }
    cout << t->c << "=>" << t->count << "=>" << t->bits << endl << endl;
    if ( t->left != NULL ) DisplayPrefixTree(t->left);
    --numDepth;
  }
  
  void SetBitCodes(Node* n){ // sets string bits for leaf nodes
      if (n == NULL) return;
      if (n->left != NULL){
        n->left->bits = n->bits + "0";
        SetBitCodes(n->left);
      }
      if (n->right != NULL){
        n->right->bits = n->bits + "1";
        SetBitCodes(n->right);
      }
  }
  
  void SetBitsPerChar(Node* n){ // maps bitstream to char
      if (n == NULL) return;
      
      if (n->left != NULL){
        mymap_compress[n->left->c] = n->left->bits;
        SetBitsPerChar(n->left);
      }
      
      if (n->right != NULL){
        mymap_compress[n->right->c] = n->right->bits;
        SetBitsPerChar(n->right);
      }
      
  }
  
};

#endif /* HUFFMAN_H_ */