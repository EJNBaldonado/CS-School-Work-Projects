/*
 * cs10c_sum21
 * main.cpp
 */


#include "Graph.H"

int main(int argc, char* argv[]) {

    if(argc != 2) {
      cerr << "Usage error: expected <executable> <input>" << endl;
      exit(1);
    }
    
    ifstream ifs(argv[1]);
    if(!ifs) {
      cerr << "Input file not found." << endl;
      exit(1);
    }

    Graph g(ifs);
    ifs.close();
    g.bfs();
    g.output_graph();
    cout << "The End." << endl;

    return 0;
}