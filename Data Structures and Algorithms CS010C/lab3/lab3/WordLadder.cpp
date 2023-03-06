/**
 * Course: CS010C Summer 2021
 *
 * First Name: Eugene
 * Last Name: Baldonado
 * Username: ebald009
 * email address: ebald009@ucr.edu
 *
 *
 * Assignment: lab3
 * Filename : WordLadder.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
 
#include "WordLadder.h"
#include <list>
#include <stack>
#include <queue>
#include <iostream>
#include <stdexcept>

using namespace std;

WordLadder::WordLadder(){
    list<string> dict;
}

WordLadder::WordLadder(const string& listFile){
    ifstream infs;
    infs.open(listFile);
    string words = "";
    if(!infs.is_open()){
        cout << "Error opening " << listFile << endl;
        infs.close();
        exit(1);
    }
    while(infs >> words){
        dict.push_back(words);
    }
    infs.close();
  }

  WordLadder::~WordLadder(){
  }

void WordLadder::printDictionary(){
    for (list<string>::iterator it = dict.begin(); it != dict.end(); ++it){
        cout << ' ' << *it;
    }
}

void WordLadder::outputLadder(const string& start, const string& end){
    stack<string> wordStack;
    queue< stack<string> > queueStack;
    wordStack.push(start);
    queueStack.push(wordStack);
    while(queueStack.empty() == false){
        for(list<string>::iterator it = dict.begin(); it != dict.end(); ++it){
           if(offByOne(queueStack.front().top(), *it)){
                if(*it == end){
                    queueStack.front().push(*it);
                    outputLadder(queueStack.front(), end);
                    return;
                }
                else{
                    stack<string> copyStack = queueStack.front();
                    copyStack.push(*it);
                    it = dict.erase(it);                
                    --it;
                    queueStack.push(copyStack);
                }
            }
        }
             queueStack.pop();
    }
        cout << "No Ladder found!" << endl;
        return;
}

bool WordLadder::offByOne(const string& s1, const string& s2){
    int diff = 0;
    for(unsigned int i = 0; i < s1.size(); ++i){
        if(s1.at(i) != s2.at(i)){
            ++diff;
            if(diff > 1){
                return false;
            }
        }
    }
    
    if(diff != 1){
        return false;
    }
    else{
        return true;
    }
}

void WordLadder::outputLadder(stack<string>& s, const string& start){
    cout << start;
    cout << endl;
    s.pop();
    while(!s.empty()){
        cout << s.top();
        cout << endl;
        s.pop();
    }
}