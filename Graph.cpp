#include "Graph.hpp"

Graph::Graph(int vertices) : numVertices(vertices){ //making a graph using edge and weight matrices(just cause it easier and less complex)
    relationMatrix = new int*[numVertices];
    weightMatrix = new int*[numVertices];

    for (int i = 0; i < numVertices; ++i) {
        relationMatrix[i] = new int[numVertices];
        weightMatrix[i] = new int[numVertices];

        for (int j = 0; j < numVertices; ++j) {
            relationMatrix[i][j] = 0;  
            weightMatrix[i][j] = 0;   
        }
    }
}

Graph::~Graph() {
    for (int i = 0; i < numVertices; ++i) {
        delete[] relationMatrix[i];
        delete[] weightMatrix[i];
    }
    delete[] relationMatrix;
    delete[] weightMatrix;
}


void Graph::addEdge(int u, int v, int weight) {
    if (u >= numVertices || v >= numVertices) {
        std::cerr << "Error: Invalid vertices for adding edge." << std::endl;
        return;
    }

    relationMatrix[u][v] = 1;       
    weightMatrix[u][v] = weight;     

    
    relationMatrix[v][u] = 1;   
    weightMatrix[v][u] = weight; 
    
}

void Graph::removeEdge(int u, int v) {
    if (u >= numVertices || v >= numVertices) {
        std::cerr << "Error: Invalid vertices for removing edge." << std::endl;
        return;
    }

    relationMatrix[u][v] = 0;       
    weightMatrix[u][v] = 0;          

    relationMatrix[v][u] = 0;   
    weightMatrix[v][u] = 0;      

}

bool Graph::isEdge(int u, int v) const {
    return relationMatrix[u][v] == 1;  
}

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