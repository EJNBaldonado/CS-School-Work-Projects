#ifndef _PQ_ZERO_H_
#define _PQ_ZERO_H_

#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;

template< class Item > 
class pq_zero {
private:
  vector<Item> heap; // The heap expands/shrinks to fit data
  typedef int indx;  // index with heap
  map<Item,indx> index;  // records each Item's place in heap
  map<Item,float> priority; // records each Item's priority
 
  void percolate_up( indx i ){
      while ( i > 0 && priority[ heap.at(i) ] < priority[ heap.at(getParent(i)) ] ){
        swap(heap.at(i), heap.at(getParent(i)));
        index.insert(pair<Item, indx>(heap.at(i), getParent(i)));
        index.insert(pair<Item, indx>(heap.at(getParent(i)), i)); 
        i = getParent(i);
      }
  }
  
  void percolate_down( indx i ){
     
     indx minInd = i;
     indx left = getLeftChild( i );
     if( left < static_cast<indx>(heap.size()) && priority[heap.at(left)] < priority[ heap.at(minInd) ]){
       minInd = left;
     }
     
     indx right = getRightChild( i );
     if (right < static_cast<indx>(heap.size()) && priority[ heap.at(right) ] < priority[ heap.at(minInd) ]) {
        minInd = right;
     }
     
     if ( i != minInd) {
       swap(heap.at(i), heap.at(minInd));
       index.insert(pair<Item, indx>( heap.at(i), minInd));
       index.insert(pair<Item, indx>( heap.at(minInd), i));
       percolate_down(minInd);
     }
  }
  
public: 
  indx getParent( indx ind ) {return (ind - 1) / 2;}
  indx getLeftChild( indx ind ) {return ((2 * ind) + 1);}
  indx getRightChild( indx ind ) {return ((2 * ind) + 2);}
  
  int size( ) const {return heap.size();}
    
  bool empty( ) const {return heap.empty();}
  
  const Item& top( ) const {
      return heap.at(0);
  }
  
  void pop( ) {
      heap.at(0) = heap.at(heap.size() - 1);
      heap.pop_back();
      percolate_down(0);
  }
  
  void push( const Item& w, float prio ){

     heap.push_back(w);
     index.insert( pair<Item, indx>( w, static_cast<indx>(heap.size() - 1)) );
     priority.insert( pair<Item, float>( w, prio ) );
     
     percolate_up(static_cast<indx>(heap.size() - 1));
  }
  
};

#endif