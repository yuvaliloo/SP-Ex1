

#include "Graph.hpp"

class Algorithms {
private:
    Graph& graph;  // reference to original graph
    void DFSUtil(int vertex, bool visited[], Graph& dfsTree);

public:
    Algorithms(Graph& g);  

    Graph DFS(int start);  // returns DFS tree as a graph
    Graph BFS(int start);  // returns BFS tree as a graph
    Graph Dijkstra(int start); // returns a weighted tree based of shortest paths from starting vertex
    Graph Kruskal(); // returns MST using kruskal's algorithm
    Graph Prim(); // returns MST using prim's algorithm
};

