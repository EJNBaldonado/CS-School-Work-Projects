/**
 * Course: CS010C Summer 2021
 *
 * First Name: Eugene
 * Last Name: Baldonado
 * Username: ebald009
 * email address: ebald009@ucr.edu
 *
 *
 * Assignment: assn2
 * Filename : test_postfix.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
 
#include "Stack.h"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

double RPN(string expr){
    // input: postfix expression
    // output: result of evalutation of postfix expression
    Stack<double> S;
    char op = ' ';
    string holdNum = "";
    double insToS;
    double b;
    double a;
    double result;
    string::iterator it;
    
    for(it = expr.begin(); it < expr.end(); it++){
        if(isdigit(*it)){
            holdNum = holdNum + *it;
        }
        else if(isblank(*it)){
            if(holdNum != ""){
            insToS = atof(holdNum.c_str());
            S.push(insToS);
            holdNum = "";
            }
        }
        else {
            op = *it;
            b = S.top();
            S.pop();
            a = S.top();
            S.pop();
            
            if(op == '*'){
                S.push(a * b);
            }
            
            if(op == '/'){
                S.push(a / b);
            }
            
            if(op == '+'){
                S.push(a + b);
            }
            
            if(op == '-'){
                S.push(a - b);
            }
        }
    }
    while (!S.is_empty()){
        result = S.top();
        S.pop();
    }
return result;
}

int main(int argc, char* argv[]){
  if (argc != 2) {
    cerr << "Usage error, expected: ./rpn postfix1.txt \n";
    exit(1);
  }
  
    string listFile = argv[1];
    ifstream infs;
    infs.open(listFile);
    string finalPostfix = "";
    if(!infs.is_open()){
        cout << "Error opening " << listFile << endl;
        infs.close();
        exit(1);
    }
    getline(infs, finalPostfix);
    infs.close();
    
    cout << RPN(finalPostfix);

return 0;  
}