#include "Node.h"
#include <iostream>

using namespace std;

Node::~Node ( ) {

  if ( right ) {
    delete right;
  }

  if ( left ) {
    delete left;
  }

}

//------------------------------------------------------------------------


string Node::getStr(){
  return this->str;
}

int Node::getCnt(){
  return this->count;
}

void Node::setCnt(int c){
  this->count = c;
}
void Node::setStr(string s){
  this->str = s;
}

const Node&
Node::operator=( const Node& right ) {
  if ( &right != this ) {
    this->str = right.str;
    this->count = right.count;
  }
  return *this;
} 