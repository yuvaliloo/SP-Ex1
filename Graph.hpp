#ifndef GRAPH_HPP  
#define GRAPH_HPP
#include <iostream>

class Graph {
private:
    int** relationMatrix;  // matrix to track edge existence (0 or 1)
    int** weightMatrix;    // matrix to track edge weights
    int numVertices;       // Number of vertices

    
    

public:
    Graph(int vertices);  
    ~Graph();  
    int getNumVertices();
    int getWeight(int u, int v);
    void addEdge(int u, int v, int weight);  
    void removeEdge(int u, int v);           
    void print_graph() const;                    
    bool isEdge(int u, int v) const;         
};
#endif
