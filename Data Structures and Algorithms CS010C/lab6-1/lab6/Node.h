#include <string>

using namespace std;

#ifndef _NODE_H_
#define _NODE_H_

class Node{
    private:
    Node* next;
    int asciiSum;
    string word;
    
    public:
        Node();
        
        ~Node();
        
        Node(int value) { asciiSum = value; next = NULL; }
        
        Node(int value, string w){ asciiSum = value; word = w; next = NULL; }
        
        Node* getNext(){ return next; }
        
        int getSum(){ return asciiSum; }
        
        string getWord(){ return word; }
        
        void append(Node* insertNode){
            Node* temp = this;
            while (temp->next != NULL){
                temp = temp->next;
            }
            temp->next = insertNode;
        }
        
};

#endif