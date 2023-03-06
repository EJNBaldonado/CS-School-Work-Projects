#include <time.h>
#include "Node.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;


void linearProbe(){
    
    srand(time(NULL));
    
    vector<Node*> RandNodes(10007);
    unsigned int collisions = 0;
    int i = 0;
    cout << "Linear probe test: " << endl;
    while (i < 2500){
        Node* curr = new Node(rand());
        if (RandNodes.at(curr->getSum() % RandNodes.size()) == NULL){
            RandNodes.at(curr->getSum() % RandNodes.size()) = curr;
        }
        
        else {
            unsigned int insertIndex = curr->getSum() % RandNodes.size();
            while (RandNodes.at(insertIndex) != NULL){
                insertIndex++;
                collisions++;
                if (insertIndex >= RandNodes.size()){
                    insertIndex = 0;
                }
            }
            RandNodes.at(insertIndex) = curr;
        }
        ++i;
    }
    
    cout << "25 percent of 10007 successfully inserted." << endl;
    cout << "At 25 percent of 10007 there are " << collisions << " collisions." << endl;
    
    while (i < 5000){
        Node* curr = new Node(rand());
        if (RandNodes.at(curr->getSum() % RandNodes.size()) == NULL){
            RandNodes.at(curr->getSum() % RandNodes.size()) = curr;
        }
        
        else {
            unsigned int insertIndex = curr->getSum() % RandNodes.size();
            while (RandNodes.at(insertIndex) != NULL){
                insertIndex++;
                collisions++;
                if (insertIndex >= RandNodes.size()){
                    insertIndex = 0;
                }
            }
            RandNodes.at(insertIndex) = curr;
        }
        ++i;
    }
    
    cout << "50 percent of 10007 successfully inserted." << endl;
    cout << "At 50 percent of 10007 there are " << collisions << " collisions." << endl;
    
     while (i < 7500){
        Node* curr = new Node(rand());
        if (RandNodes.at(curr->getSum() % RandNodes.size()) == NULL){
            RandNodes.at(curr->getSum() % RandNodes.size()) = curr;
        }
        
        else {
            unsigned int insertIndex = curr->getSum() % RandNodes.size();
            while (RandNodes.at(insertIndex) != NULL){
                insertIndex++;
                collisions++;
                if (insertIndex >= RandNodes.size()){
                    insertIndex = 0;
                }
            }
            RandNodes.at(insertIndex) = curr;
        }
        ++i;
    }
    
    cout << "75 percent of 10007 successfully inserted." << endl;
    cout << "At 75 percent of 10007 there are " << collisions << " collisions." << endl;
    
        while (i < 9000){
        Node* curr = new Node(rand());
        if (RandNodes.at(curr->getSum() % RandNodes.size()) == NULL){
            RandNodes.at(curr->getSum() % RandNodes.size()) = curr;
        }
        
        else {
            unsigned int insertIndex = curr->getSum() % RandNodes.size();
            while (RandNodes.at(insertIndex) != NULL){
                insertIndex++;
                collisions++;
                if (insertIndex >= RandNodes.size()){
                    insertIndex = 0;
                }
            }
            RandNodes.at(insertIndex) = curr;
        }
        ++i;
    }
    
    cout << "90 percent of 10007 successfully inserted." << endl;
    cout << "At 90 percent of 10007 there are " << collisions << " collisions." << endl;
    
        
    return;
    
}

void quadraticProbe(){
    
    srand(time(NULL));
    
    vector<Node*> RandNodes(10007);
    unsigned int collisions = 0;
    int i = 0;
    cout << "Quadratic probe test: " << endl;
    while (i < 2500){
        Node* curr = new Node(rand());
        if (RandNodes.at(curr->getSum() % RandNodes.size()) == NULL){
            RandNodes.at(curr->getSum() % RandNodes.size() ) = curr;
        }
        
        else {
            unsigned int square = 0;
            int insertIndex = curr->getSum() % RandNodes.size();
            while (RandNodes.at(insertIndex) != NULL){
                ++square;
                insertIndex = (insertIndex + square + square * square) % RandNodes.size();
                collisions++;
            }
            RandNodes.at(insertIndex) = curr;
        }
        ++i;
    }
    
    cout << "25 percent of 10007 successfully inserted." << endl;
    cout << "At 25 percent of 10007 there are " << collisions << " collisions." << endl;
    
    while (i < 5000){
        Node* curr = new Node(rand());
        if (RandNodes.at(curr->getSum() % RandNodes.size()) == NULL){
            RandNodes.at(curr->getSum() % RandNodes.size()) = curr;
        }
        
        else {
            unsigned int square = 0;
            int insertIndex = curr->getSum() % RandNodes.size();
            while (RandNodes.at(insertIndex) != NULL){
                ++square;
                insertIndex = (insertIndex + square + square * square) % RandNodes.size();
                collisions++;
            }
            RandNodes.at(insertIndex) = curr;
        }
        ++i;
    }
    
    cout << "50 percent of 10007 successfully inserted." << endl;
    cout << "At 50 percent of 10007 there are " << collisions << " collisions." << endl;
    
     while (i < 7500){
        Node* curr = new Node(rand());
        if (RandNodes.at(curr->getSum() % RandNodes.size()) == NULL){
            RandNodes.at(curr->getSum() % RandNodes.size()) = curr;
        }
        
        else {
            unsigned int square = 0;
            int insertIndex = curr->getSum() % RandNodes.size();
            while (RandNodes.at(insertIndex) != NULL){
                ++square;
                insertIndex = (insertIndex + square + square * square) % RandNodes.size();
                collisions++;
            }
            RandNodes.at(insertIndex) = curr;
        }
        ++i;
    }
    
    cout << "75 percent of 10007 successfully inserted." << endl;
    cout << "At 75 percent of 10007 there are " << collisions << " collisions." << endl;
    
        while (i < 9000){
        Node* curr = new Node(rand());
        if (RandNodes.at(curr->getSum() % RandNodes.size()) == NULL){
            RandNodes.at(curr->getSum() % RandNodes.size()) = curr;
        }
        
        else {
            unsigned int square = 0;
            int insertIndex = curr->getSum() % RandNodes.size();
            while (RandNodes.at(insertIndex) != NULL){
                ++square;
                insertIndex = (insertIndex + square + square * square) % RandNodes.size();
                collisions++;
            }
            RandNodes.at(insertIndex) = curr;
        }
        ++i;
    }
    
    cout << "90 percent of 10007 successfully inserted." << endl;
    cout << "At 90 percent of 10007 there are " << collisions << " collisions." << endl;
    
        
    return;
}

void cubicProbe(){
    
    srand(time(NULL));
    
    vector<Node*> RandNodes(10007);
    unsigned int collisions = 0;
    int i = 0;
    cout << "Cubic probe test: " << endl;
    while (i < 2500){
        Node* curr = new Node(rand());
        if (RandNodes.at(curr->getSum() % RandNodes.size()) == NULL){
            RandNodes.at(curr->getSum() % RandNodes.size() ) = curr;
        }
        
        else {
            unsigned int cube = 0;
            int insertIndex = curr->getSum() % RandNodes.size();
            while (RandNodes.at(insertIndex) != NULL){
                ++cube;
                insertIndex = (insertIndex + cube + cube * cube * cube) % RandNodes.size();
                collisions++;
            }
            RandNodes.at(insertIndex) = curr;
        }
        ++i;
    }
    
    cout << "25 percent of 10007 successfully inserted." << endl;
    cout << "At 25 percent of 10007 there are " << collisions << " collisions." << endl;
    
    while (i < 5000){
        Node* curr = new Node(rand());
        if (RandNodes.at(curr->getSum() % RandNodes.size()) == NULL){
            RandNodes.at(curr->getSum() % RandNodes.size()) = curr;
        }
        
        else {
            unsigned int cube = 0;
            int insertIndex = curr->getSum() % RandNodes.size();
            while (RandNodes.at(insertIndex) != NULL){
                ++cube;
                insertIndex = (insertIndex + cube + cube * cube * cube) % RandNodes.size();
                collisions++;
            }
            RandNodes.at(insertIndex) = curr;
        }
        ++i;
    }
    
    cout << "50 percent of 10007 successfully inserted." << endl;
    cout << "At 50 percent of 10007 there are " << collisions << " collisions." << endl;
    
     while (i < 7500){
        Node* curr = new Node(rand());
        if (RandNodes.at(curr->getSum() % RandNodes.size()) == NULL){
            RandNodes.at(curr->getSum() % RandNodes.size()) = curr;
        }
        
        else {
            unsigned int cube = 0;
            int insertIndex = curr->getSum() % RandNodes.size();
            while (RandNodes.at(insertIndex) != NULL){
                ++cube;
                insertIndex = (insertIndex + cube + cube * cube * cube) % RandNodes.size();
                collisions++;
            }
            RandNodes.at(insertIndex) = curr;
        }
        ++i;
    }
    
    cout << "75 percent of 10007 successfully inserted." << endl;
    cout << "At 75 percent of 10007 there are " << collisions << " collisions." << endl;
    
        while (i < 9000){
        Node* curr = new Node(rand());
        if (RandNodes.at(curr->getSum() % RandNodes.size()) == NULL){
            RandNodes.at(curr->getSum() % RandNodes.size()) = curr;
        }
        
        else {
            unsigned int cube = 0;
            int insertIndex = curr->getSum() % RandNodes.size();
            while (RandNodes.at(insertIndex) != NULL){
                ++cube;
                insertIndex = (insertIndex + cube + cube * cube * cube) % RandNodes.size();
                collisions++;
            }
            RandNodes.at(insertIndex) = curr;
        }
        ++i;
    }
    
    cout << "90 percent of 10007 successfully inserted." << endl;
    cout << "At 90 percent of 10007 there are " << collisions << " collisions." << endl;
    
        
    return;
}

 int main(){


linearProbe();

cout << endl;
cout << " ---------------------- " << endl;


quadraticProbe();

cout << endl;
cout << " ---------------------- " << endl;

cubicProbe();


return 0;
} 