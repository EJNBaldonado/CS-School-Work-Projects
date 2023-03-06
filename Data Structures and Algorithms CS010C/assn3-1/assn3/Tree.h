#ifndef __TREE_H
#define __TREE_H

#include "Node.h"

using namespace std;

class Tree {

private:
  Node *root;

private:
  void preOrder( Node* t ){
      if ( t == NULL ) return;
      cout << t->getStr() << '(' << t->getCnt() << ')' << ", ";
      if ( t->left != NULL ) preOrder(t->left);
      if ( t-> right != NULL ) preOrder(t->right);
  }
  
  void inOrder ( Node* t ){
      if ( t == NULL ) return;
      if ( t->left != NULL ) inOrder(t->left);
      cout << t->getStr() << '(' << t->getCnt() << ')' << ", "; // PRINT OUT FUNCTION
      if ( t->right != NULL ) inOrder(t->right);
  }
  
  void postOrder ( Node* t ){
      if ( t == NULL ) return;
      if ( t->left != NULL ) postOrder(t->left);
      if ( t->right != NULL ) postOrder(t->right);
      cout << t->getStr() << '(' << t->getCnt() << ')' << ", ";
  }
  
  static Node* insert(string v, Node* t){
      if ( t == NULL){
          t = new Node(v);
      }
      else if ( v < t->getStr() ) t->left = insert(v, t->left);
      else if ( v > t->getStr() ) t->right = insert(v, t->right);
      else {
          if (v == t->getStr() ){             
              t->setCnt(t->getCnt() + 1);
              return t;
          }
      }
      return t;
  }
  
  string largest( Node* t) {
      if( t == NULL ){
          return "";
      }
      if( t->right == NULL){
          return t->getStr();
      }
      return largest(t->right);
  }
  
  string smallest( Node* t ) {
      if( t == NULL ){
          return "";
      }
      if(t->left == NULL){
          return t->getStr();
      }
      return smallest(t->left);
  }
  
  bool search( string v, Node* t ){
      if(t) {
        if(t->getStr() == v){
          return true;
        }
        else if( v < t->getStr() ) return search(v, t->left);
        else if( v > t->getStr() ) return search(v, t->right);
      }
        return false;
  }
  
  static Node* smallestNode( Node* t){ 
    if(t == NULL) return NULL;
    if(t->left == NULL) return t;
    return smallestNode(t->left);
  }
  
   static Node* remove(string v, Node* t){  
      if (t == NULL) return t;
      if (v < t->getStr()) t->left = remove(v, t->left);
      else if (v > t->getStr()) t->right = remove(v, t->right);
      else{
        if(t->left == NULL && t->right == NULL)
        return NULL;
        else if (t->left == NULL){
          Node* temp = t->left;
          t->~Node();
          return temp;
        }
        else if (t->right == NULL){
          Node* temp = t->right;
          t->~Node();
          return temp;
        }
        Node* temp = smallestNode( t );
        t->setStr(temp->getStr());
        t->right = remove(v, t->right);
      }
      return t;
  } 
  
  void printTreeSideways( Node* t ){
    static int numDepth = 0;
    ++numDepth;
    if ( t == NULL ) return;
    if ( t->right != NULL ) printTreeSideways( t->right );
    for (int i = 1; i != numDepth; ++i )
      cout << "     ";
    cout << t->getStr() << '(' << t->getCnt() << ')' << endl << endl;
    if ( t->left != NULL )
      printTreeSideways(t->left);
    --numDepth;
  }
  

public:
  Tree(){ root = NULL; }
  void insert( const string &t );
  bool search( const string &t );
  void inOrder( );
  void postOrder( );
  void preOrder( );
  string largest( );
  string smallest( );
  int height( const string & );
  void remove( const string & );

  // Add any additional variables/functions here
  Node* LocationNode ( const string &v, Node* t );
  int findHeight( Node* t );
  void printTreeSideways( );
  ~Tree(){ destructTree( root ); }
  void destructTree( Node* t );

};


#endif