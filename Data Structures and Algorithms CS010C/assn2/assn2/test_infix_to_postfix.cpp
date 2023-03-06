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
 * Filename : test_infix_to_postfix.cpp
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

void InfixToPostfix(string expr) {
    //input: infix expression
    //output: postfix expression
    Stack<char> S;
    
    for (unsigned int i = 0; i < expr.size(); ++i){
        if(isdigit(expr.at(i))){
            cout << expr.at(i);
        }
        
        if(!isdigit(expr.at(i)) && expr.at(i) != '*' && expr.at(i) != '/' && expr.at(i) != '+' && expr.at(i) != '-' && expr.at(i) != '(' && expr.at(i) != ')'){
            cout << ' ';
        }
        
        if(expr.at(i) == '*' || expr.at(i) == '/' || expr.at(i) == '+' || expr.at(i) == '-'){ 
            // Finish making if statements based on precedence of expressions
            // Or if left paren is hit
            if(expr.at(i) == '*' || expr.at(i) == '/'){
                cout << ' ';
                S.push(expr.at(i));
            }
            
            if(expr.at(i) == '+' || expr.at(i) == '-'){
                cout << ' ';
                while(!S.is_empty() && S.top() != '('){
                    //cout << S.top() << ' ';
                    cout << ' ' << S.top(); 
                    S.pop();
                }
                cout << ' ';
                S.push(expr.at(i));
            }
        }
        if(expr.at(i) == '('){
                S.push(expr.at(i));
        }
            
        if(expr.at(i) == ')'){
                while(S.top() != '('){ // used to be OR check this
                    //cout << S.top() << ' ';
                    cout << ' ' << S.top();
                    S.pop();
                }
                if(S.top() == '('){
                    S.pop();
                }
        }
    }
   
    while (!S.is_empty()){
        cout << ' ' << S.top();
        S.pop();
    }
}          
            
            
           /* if(expr.at(i) == '*' || expr.at(i) == '/'){
                while(S.top() != '+' || S.top() != '-'){
                    S.push(expr.at(i));
                        if(expr.at(i) == '('){
                            S.push(expr.at(i));
                        }
                        if(expr.at(i) == ')'){
                            while(!S.is_empty() || S.top() != '('){
                                cout << S.top() << ' ';
                                S.pop();
                            }
                            if(S.top() == '('){
                                S.pop();
                            }
                        }
                }
            }
            */
            
        
 int main(int argc, char* argv[]){
  if (argc != 2) {
    cerr << "Usage error, expected: ./inf2post infix1.txt \n";
    exit(1);
  }
  
    string listFile = argv[1];
    ifstream infs;
    infs.open(listFile);
    string toString = "";
    string finalInfix = "";
    if(!infs.is_open()){
        cout << "Error opening " << listFile << endl;
        infs.close();
        exit(1);
    }
    while(infs >> toString){
        finalInfix = finalInfix + toString;
    }
    infs.close();
    
    InfixToPostfix(finalInfix);

return 0;  
}
