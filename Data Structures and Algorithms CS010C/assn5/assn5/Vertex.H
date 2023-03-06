/*
 * cs014_20sumA
 * Vertex.H
 */

#ifndef VERTEX_H_
#define VERTEX_H_

#include <string>
#include <list>

using namespace std;

class Vertex {
public:
    Vertex(){ distance = 100000; label = ""; }
    ~Vertex(){}
    string label;
    int distance;
    list<int> neighbors;
};

#endif /* VERTEX_H_ */