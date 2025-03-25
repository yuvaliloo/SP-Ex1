#include "Algorithms.hpp"
#include "Queue.hpp"

// Constructor: Store reference to the Graph object
Algorithms::Algorithms(Graph& g) : graph(g) {}

// Recursive DFS utility function that constructs the tree
void Algorithms::DFSUtil(int vertex, bool visited[], Graph& dfsTree) {
    visited[vertex] = true;

    // Explore all neighbors
    for (int i = 0; i < graph.getNumVertices(); ++i) {
        if (graph.isEdge(vertex, i) && !visited[i]) {
            dfsTree.addEdge(vertex, i, graph.getWeight(vertex, i)); // Add edge to DFS tree
            DFSUtil(i, visited, dfsTree);
        }
    }
}

// Depth-First Search (DFS) - Returns a spanning tree as a new Graph
Graph Algorithms::DFS(int start) {
    Graph dfsTree(graph.getNumVertices()); // New graph for DFS tree
    bool* visited = new bool[graph.getNumVertices()]{false};

    DFSUtil(start, visited, dfsTree);

    delete[] visited;
    return dfsTree;  // Return DFS spanning tree
}

// Breadth-First Search (BFS) - Returns a spanning tree as a new Graph
Graph Algorithms::BFS(int start) {
    Graph bfsTree(graph.getNumVertices()); // New graph for BFS tree
    bool* visited = new bool[graph.getNumVertices()]{false};
    
    Queue q;
    q.enqueue(start);
    visited[start] = true;

    while (!q.isEmpty()) {
        int vertex = q.peek();
        q.dequeue();

        for (int i = 0; i < graph.getNumVertices(); ++i) {
            if (graph.isEdge(vertex, i) && !visited[i]) {
                visited[i] = true;
                bfsTree.addEdge(vertex, i, graph.getWeight(vertex, i)); // Add edge to BFS tree
                q.enqueue(i);
            }
        }
    }

    delete[] visited;
    q.~Queue();
    return bfsTree;  // Return BFS spanning tree
}
