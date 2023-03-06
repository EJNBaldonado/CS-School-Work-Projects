#include <iostream>
#include <cstdlib>
#include <cassert>
#include "MyList.h"
//#include "Node.h"


using namespace std;


  MyList::MyList(){
      head = nullptr; //Default constructor
  }
 
  /* Copy constructor. Constructs a list from a passed in MyList object, e.g. MyList l1(l2);
  Performs a deep-copy, where memory separate from the argument object is allocated from the heap,
  using the keyword new.
  */
  MyList::MyList(const MyList& str){
    head = nullptr;
    Node* pos = str.head;
       while (pos != nullptr) {
        push_back(pos->value);
        pos = pos->next;
       }
  }
  
  /* Constructs a list from a passed in string object, 
  e.g. string username = "FLYNN"; MyList l1(username) */
  MyList::MyList(const string& str){
    head = nullptr;
    for(unsigned int i = 0; i < str.length(); ++i){
      push_back(str.at(i));
    }
  }
  
  // Constructs a list from a passed in string literal, e.g. MyList l1("Red pill, or Blue pill?");
  MyList::MyList(const char* str){
    head = nullptr;
   // char* ptr = str;
    for(char i = *str; i; i = *++str){
      push_back(i);
    }
  }
  
  // Destructor
  MyList::MyList::~MyList(){
    while(head){
		Node* temp = head;
		head = head->next;
		delete temp;
  	}	
  }

  /* Mutators */
  
  //Inserts value at the front of the list
  void MyList::push_front(char value){
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;
      if(head == nullptr){
        head = newNode;
      }
      else{
        Node* sucNode = head;
        head = newNode;
        head->next = sucNode;
      }
  }
  
  // Inserts value at the back of the list
  void MyList::push_back(char value){
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;
    if(head == nullptr){
        head = newNode;
        return;
    }
    else {
      Node* pos = head;
        while (pos->next != nullptr){
          pos = pos->next;
        }
      pos->next = newNode;
    }
  }
  
  // Removes the first item from the list. No action on empty list
  void MyList::pop_front(){
      if (head == nullptr){
        return;
      }
      else {
        Node* temp = head;
        head = head->next;
        delete temp;
      }
  }
  
  // Removes the last item from the list. No action on empty list.
  void MyList::pop_back(){
      if (head == nullptr){
        return;
      }
      Node* nodeDel = head->next;
      Node* prevDel = head;
      if(nodeDel == nullptr){     //If only item on the list is head item
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
      }
      while (nodeDel->next != nullptr){
        prevDel = prevDel->next;
        nodeDel = nodeDel->next;
      }
      prevDel->next = nullptr;
      delete nodeDel;
  }
  
  /* Swaps the value of the nodes at positions i and j.
  Program should take no action if i or j is out of bounds */
  void MyList::swap(int i, int j){
      if (i < 0 || i > size() - 1 || j < 0 || j > size() - 1 || i == j){    // EDGE CASES or if i and j are same pos (does nothing)
        return;
      }
      
      Node* pos1 = head;
      Node* pos2 = head;
      for(int a = 0; a < i; ++a){       // Pointer to each positions
        pos1 = pos1->next;
      }
      for(int b = 0; b < j; ++b){
        pos2 = pos2->next;
      }
      
      char value1 = pos1->value;
      char value2 = pos2->value;
      pos1->value = value2;             // Swap nodes values
      pos2->value = value1;
  }
  
  /* Inserts a node with value at position i in the list. 
  Program should abort via an assert statements if i is out-of-bounds. */
  void MyList::insert_at_pos(int i, char value){
      assert(i > 0 || i < size() - 1);
      if(head == nullptr){
        push_front(value);
        return;
      }
      if(i == 0){
        push_front(value);
        return;
      }
      
      Node* newNode = new Node;
      newNode->value = value;
      Node* pos = head->next;
      Node* prevPos = head;
      for(int a = 0; a < i - 1; ++a){
        prevPos = pos;
        pos = pos->next;
      }
      prevPos->next = newNode;
      newNode->next = pos;
  }
  
  // Reverses the items in the list
  void MyList::reverse(){
      if(size() == 1){
        return;
      }
      Node* pos = head;
      char arr[size()];
      for (int i = 0; i < size(); ++i){
        arr[i] = pos->value;
        pos = pos->next;
      }
      pos = head;
      for(int i = size() - 1; i >= 0; --i){
        pos->value = arr[i];
        pos = pos->next;
      }
  }

  /* Accessors */
  
  // Returns the number of nodes in the list
  int  MyList::size()const{
      if(head == nullptr){
        return 0;
      }
      int count = 0;
      Node* pos = head;
      while(pos != nullptr){
        pos = pos->next;
        ++count;
      }
      return count;
  }
  
  // Prints the contents of the list
  void MyList::print()const{
    Node* pos = head;
    if(head == nullptr){
      cout << "Empty list" << endl;
      return;
    }
    else {
      while (pos != nullptr){
        cout << pos->value << ", ";
        pos = pos->next;
      }
      cout << endl;
    }
    return;
  }
  
  /* Finds the position of the first occurrence of a character value in the list and returns that position.
  If the character is not in the list the function returns -1 */
  int  MyList::find(char value)const{
    if(head == nullptr){
      return -1;
    }
    int pos = 0;
    Node* posNode = head;
    while (posNode != nullptr){
      if(posNode->value == value){
        return pos;
      }
      ++pos;
      posNode = posNode->next;
    }
    return -1;
  }
  
  /* Finds the position of the first occurrence of MyList query_str in the list and return that position.
  If query_str is not in the list, function returns -1 */
  int  MyList::find(MyList& query_str)const{
    if(query_str.size() > size()){
      return -1;
    }
    else{
      Node* pos = head;
      Node* prevPos;
      Node* pos2 = query_str.head;
      int posNum = 0;
      int pos2Num = 0;
      int queryLength = query_str.size();
      while(pos != nullptr){
        if(pos->value == pos2->value){
          prevPos = pos;
          while(prevPos){
            if(pos2->value == prevPos->value){
              pos2 = pos2->next;
              prevPos = prevPos->next;
              ++pos2Num;
            }
            else{
              pos2Num = 0;
              pos2 = query_str.head;
              break;
            }
           if (pos2Num == queryLength){   
            return posNum;
            }
          }
        }
        ++posNum;  
        pos = pos->next;
      }
    }
    return -1;
  }

  /* Operator overloaders */
  
  /* Overloaded assignment operator. 
  Assigns the contents rhs (r-value) list to lhs (l-value) list, e.g. l1 = l2;
  Check for self-assignment. */
  MyList& MyList::operator=(const MyList& str){
      Node* pos = this->head;
      Node* pos2 = str.head;
      while(pos2 != nullptr){
        pos->value = pos2->value;
        pos = pos->next;
        pos2 = pos2->next;
      }
      pos->next = nullptr;
      return *this;
  }
  
  /* Overloaded [] operator. Returns writable reference to memory location for list l1 at l1[i].
  Program should abort via assert statement if i is out-of-bounds. */
  char& MyList::operator[](const int i){
      assert(i >= 0 || i < size());
      Node* pos = head;
      for (int a = 0; a < i; ++a){
        pos = pos->next;
      }
      return pos->value;
  }
  
  // Concatenates two lists together, for example, l1 + l2
  MyList MyList::operator+(const MyList& str){
    Node* strStart = str.head;
    while(strStart != nullptr){
      this->push_back(strStart->value);
      strStart = strStart->next;
    }
    return *this;
  }

  /* Newly assigned functions */
  
  // Checks whether list object (implicit) contains a palindrome
  bool MyList::is_palindrome()const{
      bool isPalindrome = false;
      Node* pos = head;
      int posNum = 0;
      MyList rhs = *this;
      rhs.reverse();
      Node* pos2 = rhs.head;
      int pos2Num = size() - 1;
      
      while (posNum < pos2Num){
        if (pos->value != pos2->value){
          return isPalindrome;
        }
        pos = pos->next;
        pos2 = pos2->next;
        ++posNum;
        --pos2Num;
      }
      
      if (posNum == pos2Num){
        if (pos->value != pos2->value){
          return isPalindrome;
        }
        else{
          isPalindrome = true;
          return isPalindrome;
        }
      }
      else if (posNum > pos2Num){
        isPalindrome = true;
        return isPalindrome;
      }
      
  return isPalindrome;
  }
  
  // Merges two sorted lists A and B into implicit object. HINT: A and B are passed-by-copy.
  void MyList::merge_list(MyList A, MyList B){
    Node* pos1 = A.head;
    Node* pos2 = B.head;
    /*
    while(pos1 != nullptr || pos2 != nullptr){
      while(pos1->value < pos2->value && pos1 != nullptr){
        this->push_back(pos1->value);
        pos1 = pos1->next;
      }
      while(pos2->value <= pos1->value && pos2 != nullptr){
        this->push_back(pos2->value);
        pos2 = pos2->next;
      }
    } */
    while(1){
      if(pos1 == nullptr){
        push_back(pos2->value);
        pos2 = pos2->next;
        break;
      }
      if(pos2 == nullptr){
        push_back(pos1->value);
        pos1 = pos1->next;
        break;
      }
      if(pos1->value <= pos2->value){
        push_back(pos1->value);
        pos1 = pos1->next;
      }
      else {
        push_back(pos2->value);
        pos2 = pos2->next;
      }
    }
  }
  
  /* Removes all instances of char c from implicit list object, e.g. remove all commas (',').
  Returns true if at least one instance of char c is in the list, false otherwise. */
  bool MyList::remove_char(char c){
      Node* prevPos = nullptr;
      Node* pos = this->head;
      bool charRemoved = false;
     
     /* if(pos == nullptr){
        return charRemoved;
      }
      else{
        while(pos->value == c){
          Node* tmp = pos;
          pos = pos->next;
          delete tmp;
          head = pos;
          prevPos = pos;
          pos = pos->next;
          charRemoved = true;
        }
      }
      if(pos == nullptr){
        return charRemoved;
      }
      while(pos != nullptr){
        if(pos->value == c){
          Node* temp = pos;
          prevPos->next = pos->next;
          pos = pos->next;
          delete temp;
          charRemoved = true;
        }
        else{
        pos = pos->next;
        prevPos = pos-> next;
        }
      } */
      //while(pos != nullptr){
        if(pos != nullptr && pos->value == c){
          if(pos == head){
            this->head = this->head->next;
            delete pos;
            charRemoved = true;
            pos = this->head;
          }
        }
        while (pos != nullptr){
        while(pos != nullptr && pos->value != c){
              prevPos = pos;
              pos = pos->next;
        }
              if (pos == nullptr){
                return charRemoved;
              }
              else if (pos->value == c){
                prevPos->next = pos->next;
               delete pos;
               charRemoved = true;
               pos = prevPos->next;
              }
        }
       /* }
        else{
          pos = pos->next;
        }
      } */
      return charRemoved;
  }
  
  // Returns the first node's value.
  char MyList::front()const{
    if(head != nullptr){
      return head->value;
    }
    return 'x';
  }