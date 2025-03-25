#include "Graph.hpp"

// 📌 Constructor: Initialize the relation and weight matrices
Graph::Graph(int vertices) : numVertices(vertices){
    relationMatrix = new int*[numVertices];
    weightMatrix = new int*[numVertices];

    for (int i = 0; i < numVertices; ++i) {
        relationMatrix[i] = new int[numVertices];
        weightMatrix[i] = new int[numVertices];

        // Initialize both matrices: no edges, weight = 0
        for (int j = 0; j < numVertices; ++j) {
            relationMatrix[i][j] = 0;  // No edges initially
            weightMatrix[i][j] = 0;    // No edge weights initially
        }
    }
}

// 📌 Destructor: Clean up the allocated memory
Graph::~Graph() {
    for (int i = 0; i < numVertices; ++i) {
        delete[] relationMatrix[i];
        delete[] weightMatrix[i];
    }
    delete[] relationMatrix;
    delete[] weightMatrix;
}

// 📌 Resize the relation and weight matrices when a new vertex is added


// 📌 Add an edge between u and v with a given weight
void Graph::addEdge(int u, int v, int weight) {
    if (u >= numVertices || v >= numVertices) {
        std::cerr << "Error: Invalid vertices for adding edge." << std::endl;
        return;
    }

    relationMatrix[u][v] = 1;       // Set the relation matrix entry to 1 (edge exists)
    weightMatrix[u][v] = weight;     // Set the weight of the edge

    
    relationMatrix[v][u] = 1;   // For undirected graphs, set reverse edge
    weightMatrix[v][u] = weight; // Set reverse edge weight
    
}

// 📌 Remove an edge between u and v
void Graph::removeEdge(int u, int v) {
    if (u >= numVertices || v >= numVertices) {
        std::cerr << "Error: Invalid vertices for removing edge." << std::endl;
        return;
    }

    relationMatrix[u][v] = 0;       // Set the relation matrix entry to 0 (no edge)
    weightMatrix[u][v] = 0;          // Set the weight to 0 (no weight)

    relationMatrix[v][u] = 0;   // For undirected graphs, remove reverse edge
    weightMatrix[v][u] = 0;      // Set reverse edge weight to 0

}

// 📌 Check if an edge exists between u and v
bool Graph::isEdge(int u, int v) const {
    return relationMatrix[u][v] == 1;  // Return true if there is an edge
}

// 📌 Display the graph's adjacency and weight matrices
void Graph::print_graph() const {
    std::cout << "Relation Matrix (0 = no edge, 1 = edge exists):\n";
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            std::cout << relationMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\nWeight Matrix (Edge weights):\n";
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            std::cout << weightMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int Graph::getNumVertices()
{
    return numVertices;
}

int Graph::getWeight(int u,int v)
{
    return weightMatrix[u][v];
}