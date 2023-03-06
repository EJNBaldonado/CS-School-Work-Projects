#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include "Node.h"

using namespace std;

void processFile1(string);  //KEY ADDS ALL ASCII VALUES

void processFile2(string);  //KEY ADDS FIRST 3 ASCII VALUES WITH MULTIPLICATION

void processFile3(string);  //KEY ADDS ALL ASCII VALUES W/IMPLEMENTATION OF HORNERS RULE

void processFile4(string);  //CUSTOM KEY, TREATS STRING AS 32-BIT INT RESULT, EACH NEW CHAR A DIGIT IN BASE 16

void print(vector<Node*>);

void printStats(vector<Node*>);



int main (int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage error, expected: ./a.out *.txt\n";
        exit(1);
    }
    
    string inputFile = argv[1];
    
    
    processFile1(inputFile);
    
    cout << endl << " ------------------------------ " << endl << endl;
    
    processFile2(inputFile);
    
    cout << endl << " ------------------------------ " << endl << endl;
    
    processFile3(inputFile);
    
    cout << endl << " ------------------------------ " << endl << endl;
    
    processFile4(inputFile);
    
    return 0;
} 








void processFile1(string inputFile){
    ifstream inFS;
    inFS.open(inputFile);
    
    if (!inFS.is_open()){
        cout << "Error opening: " << inputFile;
        return;
    }
    
    string word;
    vector<Node*> wordAscii(10); // HASH MAP
    
    while (inFS >> word){
        int sum = 0;
        for (unsigned int i = 0; i < word.size(); ++i){
            sum = sum + word.at(i);
        }
        Node* curr = new Node(sum, word);
        
        if (wordAscii.at(sum % wordAscii.size()) == NULL){
            wordAscii.at(sum % wordAscii.size()) = curr;
        }
        else {
            wordAscii.at(sum % wordAscii.size())->append(curr);
        }
    }
    
    inFS.close();
    
    cout << "First hash table key: Adding all ascii values of word" << endl;
    
    print(wordAscii);
    printStats(wordAscii);
}

//---------------------------------------------------------------------


void processFile2(string inputFile){
    ifstream inFS;
    inFS.open(inputFile);
    
    if (!inFS.is_open()){
        cout << "Error opening: " << inputFile;
        return;
    }
    
    string word;
    vector<Node*> wordAscii(10); // HASH MAP
    
    while (inFS >> word){
        int sum = 0;
        sum = word.at(0) + 27 * word.at(1) + 729 * word.at(2);
        Node* curr = new Node(sum, word);
        
        if (wordAscii.at(sum % wordAscii.size()) == NULL){
            wordAscii.at(sum % wordAscii.size()) = curr;
        }
        else {
            wordAscii.at(sum % wordAscii.size())->append(curr);
        }
    }
    
    inFS.close();
    
    cout << "Second hash table key: Adding first 3 ascii values of word (A(0) + A(1) * 27 + A(2) * 729)" << endl;
    
    print(wordAscii);
    printStats(wordAscii);
}

//---------------------------------------------------------------------


void processFile3(string inputFile){
    ifstream inFS;
    inFS.open(inputFile);
    
    if (!inFS.is_open()){
        cout << "Error opening: " << inputFile;
        return;
    }
    
    string word;
    vector<Node*> wordAscii(10); // HASH MAP
    
    while (inFS >> word){
        int sum = 0;
        
        for (unsigned int i = 0; i < word.size(); ++i){
            sum = sum + word.at(i) * pow(37, i);
        }
        
        Node* curr = new Node(sum, word);
        
        if (wordAscii.at(sum % wordAscii.size()) == NULL){
            wordAscii.at(sum % wordAscii.size()) = curr;
        }
        else {
            wordAscii.at(sum % wordAscii.size())->append(curr);
        }
    }
    
    inFS.close();
    
    cout << "Third hash table key: Adding ascii values of word with Horner's rule" << endl;
    
    print(wordAscii);
    printStats(wordAscii);
}

//---------------------------------------------------------------------


void processFile4(string inputFile){
    ifstream inFS;
    inFS.open(inputFile);
    
    if (!inFS.is_open()){
        cout << "Error opening: " << inputFile;
        return;
    }
    
    string word;
    vector<Node*> wordAscii(10); // HASH MAP
    
    while (inFS >> word){
        int sum = 0;
        int g;
        
        for (unsigned int i = 0; i < word.size(); ++i){             //SETTING KEY YIELDS 32 - BIT INTEGER VALUE
            sum = ( sum << 4 ) + (word.at(i));                      //TAKES CHARACTER AND SHIFTS RESULT TO LEFT BY 4 BITS AND ADDS NEW CHAR
            g = sum & 0xF0000000L;
            if (g != 0){
                sum = sum ^ (g >> 24);                              //IF ANY WOULD BE SHIFTED OFF LEFT END, IS BROUGHT BACK AORUND THE RIGHT END AND COMBINED W RESULT
            }
            sum = sum & ~g;
        }
        
        Node* curr = new Node(sum, word);
        
        if (wordAscii.at(sum % wordAscii.size()) == NULL){
            wordAscii.at(sum % wordAscii.size()) = curr;
        }
        else {
            wordAscii.at(sum % wordAscii.size())->append(curr);
        }
    }
    
    inFS.close();
    
    cout << "Fourth hash table key: Adding ascii values of word by adding char and shifting bits " << endl;
    
    print(wordAscii);
    printStats(wordAscii);
}

//---------------------------------------------------------------------


void print(vector<Node*> wordAscii){
    for (unsigned int i = 0; i < wordAscii.size(); ++i){
        cout << i << ": ";
        Node* temp = wordAscii.at(i);
        while ( temp != NULL){
            cout << temp->getWord() << ", "; //"=>" << temp->getSum() << ", " ;
            temp = temp->getNext();
        }
        cout << endl;
    }
    cout << endl;
}

//---------------------------------------------------------------------


void printStats(vector<Node*> wordAscii) {
    int sumCollision = 0;
    int max = 0;
    double sumLength = 0.0;
    
    for (unsigned int i = 0; i < wordAscii.size(); ++i) {
        Node* temp = wordAscii.at(i);
        int currCollision = -1;
        int length = 0;
        
        if(temp == NULL) {
            currCollision = 0;
        }
        
        while (temp != NULL) {
            temp = temp->getNext();
            currCollision++;
            length++;
        }
        
        sumCollision = sumCollision + currCollision;
        
        if (length > max) {
            max = length;
        }
        sumLength = sumLength + length;
    }
    cout << "Total Collisions: " << sumCollision << endl;
    cout << "Max Length: " << max << endl;
    cout << "Average: " << sumLength / static_cast<double>(wordAscii.size()) << endl;
}