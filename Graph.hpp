#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>

class Graph {
private:
    int** relationMatrix;  // Matrix to track edge existence (0 or 1)
    int** weightMatrix;    // Matrix to track edge weights
    int numVertices;       // Number of vertices

    
    

public:
    Graph(int vertices);  // Constructor
    ~Graph();  // Destructor

    void addEdge(int u, int v, int weight);  // Add an edge
    void removeEdge(int u, int v);           // Remove an edge
    void print_graph() const;                    // Display the graph
    bool isEdge(int u, int v) const;         // Check if an edge exists
};

#endif // GRAPH_HPP