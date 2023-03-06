#include "Tree.h"
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

void Tree::insert ( const string &t ){
   root = insert( t, root ); 
}

bool Tree::search ( const string &t) {
    return search( t, root );
}

void Tree::inOrder() {
    inOrder(root);
    cout << endl;
}

void Tree::postOrder() {
    postOrder(root);
    cout << endl;
} 

void Tree::preOrder() {
    preOrder(root);
    cout << endl;
}

string Tree::largest() {
    return largest(root);
}

string Tree::smallest() {
    return smallest(root);
}

int Tree::height( const string &t) {
    if (!search(t)){
        return -1;
    }
    else {
        Node* LocNode = LocationNode( t, root );
        return this->findHeight(LocNode);
    }
}
                    
Node* Tree::LocationNode( const string &v, Node* t ){
    if (t) {
        if(t->getStr() == v) return t;
        else if ( v < t->getStr() ) return LocationNode(v, t->left);
        else if ( v > t->getStr() ) return LocationNode(v, t->right);
        }
    return t;
}

int Tree::findHeight( Node* t ){
    if (t == NULL){
        return -1;
    }
    int leftH = 0;
    int rightH = 0;
    int finalH;
    if(t->left != NULL) {
        leftH = findHeight(t->left) + 1;
    }
    if(t->right != NULL) {
        rightH = findHeight(t->right) + 1;
    }
    if(leftH >= rightH){
        finalH = leftH;
    }
    else{
        finalH = rightH;
    }
    return finalH;
}


void Tree::remove(const string &t) {
    if(!search(t)){
       return; 
    }
    
    Node* locNode = LocationNode(t, root);
    if(locNode->getCnt() > 1){
        locNode->setCnt(locNode->getCnt() - 1);
        return;
    }
    else{
       root = remove(t, root);
    }
}

  
void Tree::printTreeSideways() {
    printTreeSideways( root );
}

  void Tree::destructTree( Node* t ){
    if (t != NULL){
    destructTree(t->left);
    destructTree(t->right);
    t->setCnt(0);
    t = NULL;
    }
  }