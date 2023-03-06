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
 * Filename : main.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
 
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Huffman.h"

using namespace std;

int main(int argc, char* argv[]) {
  
  if (argc != 2) {
    cerr << "Usage error, expected: ./a.out *.txt\n";
    exit(1);
  }
  
  string input_file = argv[1];
  Huffman h(input_file);
  h.BuildHuffmanTree();
  h.PrintCharFrequencies(); 
  h.SetBitCodes();
  h.SetBitsPerChar();
  h.Stats();
  h.BitMap();
  //h.DisplayPrefixTree(); // SANITY CHECK
  
  return 0;
}