

#include "Graph.hpp"

class Algorithms {
private:
    Graph& graph;  // Reference to original graph
    void DFSUtil(int vertex, bool visited[], Graph& dfsTree);

public:
    Algorithms(Graph& g);  // Constructor

    Graph DFS(int start);  // Returns DFS tree as a Graph
    Graph BFS(int start);  // Returns BFS tree as a Graph
};

