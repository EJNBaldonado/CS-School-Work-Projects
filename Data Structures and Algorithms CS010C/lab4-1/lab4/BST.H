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
 * Filename : BST.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */

#ifndef BST_H_
#define BST_H_

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

class BST {

private:
  struct BinaryNode {

    int value;  //key
    BinaryNode* left;
    BinaryNode* right;
   
   
    int depth;
    int height;
    int inorder_num;
    int preorder_num;
    int postorder_num; //finish
    BinaryNode(int& v) : value(v), left(NULL), right(NULL) {}
    static BinaryNode* insert(int v, BinaryNode* t) {
      if(t == NULL){
	      t = new BinaryNode(v);
      }
      else if (v < t->value)
	      t->left = insert(v, t->left);
      else if (v > t->value)
	      t->right = insert(v, t->right);
      else {
        //t->value = v; // previous
	      cout << "ERROR: Tried to insert node already in tree" << endl;
      }
      return t;
    }
    
    static BinaryNode* remove(int v, BinaryNode* t) {
      if(t) {
	      if(v < t->value)
	        t->left = remove(v, t->left);
	      else if(t->value < v)
	        t->right = remove(v, t->right);
	      else if(t->left != NULL && t->right != NULL) {
	        t->value = find_min(t->right)->value;
	        t->right = remove(t->value, t->right);
	    } 
	      
	      else {
	       if(t-> value != v){
	         cout << "ERROR: Tried to remove node not in tree" << endl;
	       }
	       BinaryNode* oldNode = t;
	       t = (t->left != NULL) ? t->left : t->right;
	       delete oldNode;
	      }
      }
      return t;
    }
    
    static BinaryNode* find_min(BinaryNode* t) {
      if(t == NULL)
	      return NULL;
      if(t->left == NULL)
	      return t;
      return find_min(t->left);
    }

  };

public:
  ofstream outDot;
  BST(): root(NULL) {}
  ~BST() { destructorBST(root); }
  
  void destructorBST( BinaryNode* t ){
    if (t != NULL) {
      destructorBST(t->left);
      destructorBST(t->right);
      delete t;
    }
  }
  
  void insert(int v) { root = BinaryNode::insert(v, root); }
  void remove(int v) { root = BinaryNode::remove(v, root); }
  
  void display() { display(root); }
  void display( BinaryNode* t ) {
    // in-order traversal with indented display.
    static int depth = 0;
    ++depth;
    if ( t == NULL ) return;
    if ( t->right != NULL ) display(t->right);
    for( int i = 0; i != depth; ++i )
      cout << " ";
    cout << t->value << " " << endl;
    if ( t->left != NULL )
      display(t->left);
    --depth;
  }
  
  void inorder() { inorder(root); }
  void inorder( BinaryNode* t ) {
    // in-order traversal and update inorder_num as expected
    static int inord_num = 0;
    if (t == NULL) return;
    if ( t->left != NULL ) inorder(t->left);
    ++inord_num;
    t->inorder_num = inord_num;
    if ( t->right != NULL )
      inorder(t->right);
  }
  
  void writeInorder() {
      outDot.open("output.dot");
      outDot << "digraph G {\n";
      writeInorder1(root);
      writeInorder2(root);
      outDot << "\n }";
      outDot.close(); 
  }
  void writeInorder1( BinaryNode* t ){
    static char nodeChar = 'a';
    
    if (t == NULL) return;
    
    queue<BinaryNode*> Q;
    Q.push(t);
    
    while(!Q.empty()){
      BinaryNode* curr = Q.front();
      outDot << nodeChar << " [color = red, peripheries=2, style = filled, label =\"key=" << curr->value << ", in =" << curr->inorder_num << "\"];\n";
      ++nodeChar;
      if(curr->left != NULL) Q.push(curr->left);
      if(curr->right != NULL) Q.push(curr->right);
      Q.pop();
    }
  }
  
  void writeInorder2( BinaryNode* t ){
    static char nodeChar = 'a';
    static char nodeCharNext = 'a';
    if (t == NULL) return;
    
    queue<BinaryNode*> Q;
    Q.push(t);
    
    while(!Q.empty()){
      BinaryNode* curr = Q.front();
      
      if(curr->left == NULL && curr->right == NULL){
          ++nodeChar;
          Q.pop();
          continue;
      }
      
      if(curr->left != NULL){
        Q.push(curr->left);
        ++nodeCharNext;
        outDot << nodeChar << " -> " << nodeCharNext << ";\n";
      }
      
      if(curr->right != NULL){
        Q.push(curr->right);
        ++nodeCharNext;
        outDot << nodeChar << " -> " << nodeCharNext << ";\n";
        }
      ++nodeChar;
      Q.pop();
    }
  }
  
 void preorder() { preorder(root); }
 void preorder( BinaryNode* t ) {
    // pre-order traversal and update preorder_num as expected
    static int preord_num = 0;
    if (t == NULL) return;
    ++preord_num;
    t->preorder_num = preord_num;
    if ( t->left != NULL) preorder(t->left);
    if (t->right != NULL) preorder(t->right);
 }
 
 void writePreorder() {
      outDot.open("output.dot");
      outDot << "digraph G {\n";
      writePreorder1(root);
      writePreorder2(root);
      outDot << "\n }";
      outDot.close();
 }
 
 void writePreorder1( BinaryNode* t ) {
    static char nodeChar = 'a';
    
    if (t == NULL) return;
    
    queue<BinaryNode*> Q;
    Q.push(t);
    
    while(!Q.empty()){
      BinaryNode* curr = Q.front();
      outDot << nodeChar << " [color = orange, peripheries=2, style = filled, label =\"key=" << curr->value << ", in =" << curr->preorder_num << "\"];\n";
      ++nodeChar;
      if(curr->left != NULL) Q.push(curr->left);
      if(curr->right != NULL) Q.push(curr->right);
      Q.pop();
    }
 }
 
 void writePreorder2( BinaryNode* t ) {
    static char nodeChar = 'a';
    static char nodeCharNext = 'a';
    if (t == NULL) return;
    
    queue<BinaryNode*> Q;
    Q.push(t);
    
    while(!Q.empty()){
      BinaryNode* curr = Q.front();
      
      if(curr->left == NULL && curr->right == NULL){
          ++nodeChar;
          Q.pop();
          continue;
      }
      
      if(curr->left != NULL){
        Q.push(curr->left);
        ++nodeCharNext;
        outDot << nodeChar << " -> " << nodeCharNext << "[color=blue];\n";
      }
      
      if(curr->right != NULL){
        Q.push(curr->right);
        ++nodeCharNext;
        outDot << nodeChar << " -> " << nodeCharNext << "[color=blue];\n";
        }
      ++nodeChar;
      Q.pop();
    }
 }
 
 void postorder() { postorder(root); }
 void postorder( BinaryNode* t ) {
   // post-order traversal and update postorder_num as expected
   static int postord_num = 0;
   if (t == NULL) return;
   if(t->left != NULL) postorder(t->left);
   if(t->right != NULL) postorder(t->right);
   ++postord_num;
   t->postorder_num = postord_num;
 }
 
 void writePostorder() {
      outDot.open("output.dot");
      outDot << "digraph G {\n";
      writePostorder1(root);
      writePostorder2(root);
      outDot << "\n }";
      outDot.close();
 }
 
 void writePostorder1( BinaryNode* t ){
    static char nodeChar = 'a';
    
    if (t == NULL) return;
    
    queue<BinaryNode*> Q;
    Q.push(t);
    
    while(!Q.empty()){
      BinaryNode* curr = Q.front();
      outDot << nodeChar << " [color = purple, peripheries=2, style = filled, label =\"key=" << curr->value << ", in =" << curr->postorder_num << "\"];\n";
      ++nodeChar;
      if(curr->left != NULL) Q.push(curr->left);
      if(curr->right != NULL) Q.push(curr->right);
      Q.pop();
    }
 }
 
 void writePostorder2( BinaryNode* t ){
    static char nodeChar = 'a';
    static char nodeCharNext = 'a';
    if (t == NULL) return;
    
    queue<BinaryNode*> Q;
    Q.push(t);
    
    while(!Q.empty()){
      BinaryNode* curr = Q.front();
      
      if(curr->left == NULL && curr->right == NULL){
          ++nodeChar;
          Q.pop();
          continue;
      }
      
      if(curr->left != NULL){
        Q.push(curr->left);
        ++nodeCharNext;
        outDot << nodeChar << " -> " << nodeCharNext << ";\n";
      }
      
      if(curr->right != NULL){
        Q.push(curr->right);
        ++nodeCharNext;
        outDot << nodeChar << " -> " << nodeCharNext << ";\n";
        }
      ++nodeChar;
      Q.pop();
    }
 }
 
 
 void height() { BinaryNode* curr = root; curr->height = setHeight(curr); }
 int setHeight( BinaryNode* t){
   // traversal through node and update height as expected
    if (t == NULL) return 0;
    
    int leftH = 0;
    int rightH = 0;
    
    if(t->left != NULL) {
      leftH = setHeight(t->left) + 1;
    }
    
    if(t->right != NULL) {
      rightH = setHeight(t->right) + 1;
    }
    
    if(leftH >= rightH){
      t->height = leftH;
    }
    else { 
      t->height = rightH;
    }
    
    return t->height;
 }
   
  void  writeHeight() {
      outDot.open("output.dot");
      outDot << "digraph G {\n";
      writeHeight1(root);
      writeHeight2(root);
      outDot << "\n }";
      outDot.close();
  }
  
  void writeHeight1( BinaryNode* t ) {
    static char nodeChar = 'a';
    
    if (t == NULL) return;
    
    queue<BinaryNode*> Q;
    Q.push(t);
    
    while(!Q.empty()){
      BinaryNode* curr = Q.front();
      outDot << nodeChar << " [color = lightblue, peripheries=2, style = filled, label =\"key=" << curr->value << ", in =" << curr->height << "\"];\n";
      ++nodeChar;
      if(curr->left != NULL) Q.push(curr->left);
      if(curr->right != NULL) Q.push(curr->right);
      Q.pop();
    }
  }
  
  void writeHeight2( BinaryNode* t ) {
    static char nodeChar = 'a';
    static char nodeCharNext = 'a';
    if (t == NULL) return;
    
    queue<BinaryNode*> Q;
    Q.push(t);
    
    while(!Q.empty()){
      BinaryNode* curr = Q.front();
      
      if(curr->left == NULL && curr->right == NULL){
          ++nodeChar;
          Q.pop();
          continue;
      }
      
      if(curr->left != NULL){
        Q.push(curr->left);
        ++nodeCharNext;
        outDot << nodeChar << " -> " << nodeCharNext << ";\n";
      }
      
      if(curr->right != NULL){
        Q.push(curr->right);
        ++nodeCharNext;
        outDot << nodeChar << " -> " << nodeCharNext << ";\n";
        }
      ++nodeChar;
      Q.pop();
    }
  }
  
  private:
    BinaryNode* root;
};

#endif /* BST_H_ */

