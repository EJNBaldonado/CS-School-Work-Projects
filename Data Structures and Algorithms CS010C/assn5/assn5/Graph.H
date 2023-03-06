/*
 * cs014_20sumA
 * Graph.H
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <list>
#include <queue>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "Vertex.H"

using namespace std;

class Graph {
public:
    ofstream outDot;
    
    Graph(){}
    
    Graph(ifstream& ifs){ 
        build_graph(ifs);
    }
    
    ~Graph(){}
    
    void build_graph(ifstream& ifs){ 
        int numVertex;
        int numEdges;
        string vLabel;
        string startV;
        string endV;
        
        ifs >> numVertex;
        ifs >> numEdges;
        
        while (numVertex > 0){
            ifs >> vLabel;
            Vertex curr;
            curr.label = vLabel;
            vertices.push_back(curr);
            numVertex--;
        }
        
        vector<Vertex>::iterator itr;
        int vPos = 0;
        int sPos;
        int fPos;
        
        while ( ifs >> startV && ifs >> endV && numEdges > 0){
            vPos = 0;
            for (itr = vertices.begin(); itr != vertices.end(); ++itr){
                if (itr->label == startV){
                    sPos = vPos;
                }
                if (itr->label == endV){
                    fPos = vPos;
                }
                ++vPos;
            }
            vertices.at(sPos).neighbors.push_back(fPos);
            numEdges--;
        }
    }
    
    void output_graph(){
        vector<Vertex>::iterator vItr;
        
        outDot.open("graph.dot");
        
        outDot << "diGraph G {\n\n";
        outDot << "rankdir = \"LR\"; \n \n";
        outDot << "// nodes \n";
        
        for (vItr = vertices.begin(); vItr != vertices.end(); ++vItr){
            outDot << vItr->label << " [color = red, peripheries=2, style = filled, label = \"" << vItr->label << ' ' << vItr->distance << "\"];\n";
        }
        outDot << "\n // edges \n";
        for (vItr = vertices.begin(); vItr != vertices.end(); ++vItr){
                list<int>::iterator nItr;
                for (nItr = vItr->neighbors.begin(); nItr != vItr->neighbors.end(); ++nItr){
                    if(vertices.at(*nItr).distance - vItr->distance == 1){
                        outDot << vItr->label << "->" << vertices.at(*nItr).label << "[color=purple];\n";
                    }
                    else{
                    outDot << vItr->label << "->" << vertices.at(*nItr).label << "[color=blue];\n";
                    }
                }
        }
        outDot << '}';
        outDot.close();
    }
    
    void bfs(){ 
        queue<int> frontierQ;   //VERTEX THATS FIRST PUSHED IN (AT 0)
        
        for (unsigned int i = 0; i < vertices.size(); ++i){
            vertices.at(i).distance = 100000;
        }
        frontierQ.push(0);
        vertices.at(0).distance = 0;
        
        while ( !frontierQ.empty() ){
            int pVert = frontierQ.front();
            frontierQ.pop();
            list<int>::iterator nItr;
            for (nItr = vertices.at(pVert).neighbors.begin(); nItr != vertices.at(pVert).neighbors.end(); ++nItr){
                if(vertices.at(*nItr).distance == 100000){
                    vertices.at(*nItr).distance = vertices.at(pVert).distance + 1;
                    frontierQ.push(*nItr);
                }
            }
        }
    }
    
private:
    vector<Vertex> vertices;
};

#endif /* GRAPH_H_ */