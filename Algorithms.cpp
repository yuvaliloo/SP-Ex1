#include "Algorithms.hpp"
#include "Queue.hpp"

Algorithms::Algorithms(Graph& g) : graph(g) {} //made it so the Alogrithms class is given a graph, upon which we will perform the algorithms

struct Edge{
    int u,v,weight;
};
void Algorithms::DFSUtil(int vertex, bool visited[], Graph& dfsTree) {
    visited[vertex] = true;

    for (int i = 0; i < graph.getNumVertices(); ++i) {
        if (graph.isEdge(vertex, i) && !visited[i]) {
            dfsTree.addEdge(vertex, i, graph.getWeight(vertex, i)); 
            DFSUtil(i, visited, dfsTree);
        }
    }
}

Graph Algorithms::DFS(int start) {
    Graph dfsTree(graph.getNumVertices()); 
    bool* visited = new bool[graph.getNumVertices()]{false};

    DFSUtil(start, visited, dfsTree);

    delete[] visited;
    return dfsTree;  
}

Graph Algorithms::BFS(int start) {
    Graph bfsTree(graph.getNumVertices()); 
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
                bfsTree.addEdge(vertex, i, graph.getWeight(vertex, i)); 
                q.enqueue(i);
            }
        }
    }

    delete[] visited;
    q.~Queue();
    return bfsTree;  
}

Graph Algorithms::Dijkstra(int source)
{
    int V = graph.getNumVertices();

    int dist[V];
    bool visited[V];
    int parent[V];

    for (int i = 0; i < V; ++i) {
        dist[i] = 2147483647; // simulating infinity
        visited[i] = false;
        parent[i] = -1; 
    }

    dist[source] = 0;

    for (int count = 0; count < V - 1; ++count) {
        int u = -1;

        for (int i = 0; i < V; ++i) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        }

        visited[u] = true;

        for (int v = 0; v < V; ++v) {
            if (graph.isEdge(u,v) && !visited[v]) {
                int alt = dist[u] + graph.getWeight(u,v);
                if (alt < dist[v]) {
                    dist[v] = alt;
                    parent[v] = u;
                }
            }
        }
    }

    Graph tree(V);
    

    for (int v = 0; v < V; ++v) {
        int u = parent[v];
        if (u != -1) {
            int w = graph.getWeight(u,v);
            tree.addEdge(u, v, w);
        }
    }

    return tree;
}

Graph Algorithms::Prim(){
    int V = graph.getNumVertices();

    int parent[V];      
    int key[V];         
    bool inMST[V];      

    for (int i = 0; i < V; ++i) {
        key[i] = 2147483647;
        inMST[i] = false;
        parent[i] = -1;
    }

    key[0] = 0; 

    for (int count = 0; count < V - 1; ++count) {
        int u = -1;
        for (int v = 0; v < V; ++v) {
            if (!inMST[v] && (u == -1 || key[v] < key[u]))
                u = v;
        }

        inMST[u] = true;

        for (int v = 0; v < V; ++v) {
            if (graph.isEdge(u,v) && !inMST[v] && graph.getWeight(u,v) < key[v]) {
                key[v] = graph.getWeight(u,v);
                parent[v] = u;
            }
        }
    }

    Graph mst(V);

    for (int v = 1; v < V; ++v) {
        int u = parent[v];
        if (u != -1) {
            mst.addEdge(u, v, graph.getWeight(u,v));
        }
    }

    return mst;
}

void makeSet(int parent[], int rank[], int n) {
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int find(int parent[], int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

void unite(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

Graph Algorithms::Kruskal(){
    int V = graph.getNumVertices();
    Edge edges[V * V];
    int edgeCount = 0;

    for (int i = 0; i < V; ++i) {
        for (int j = i + 1; j < V; ++j) {
            if (graph.isEdge(i,j)) {
                edges[edgeCount++] = { i, j, graph.getWeight(i,j) };
            }
        }
    }

    // sort edges by weight using bubble sort (simple, avoiding std::sort)
    for (int i = 0; i < edgeCount - 1; ++i) {
        for (int j = 0; j < edgeCount - i - 1; ++j) {
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    int parent[V], rank[V];
    makeSet(parent, rank, V);

    Graph mst(V);

    int edgesAdded = 0;

    for (int i = 0; i < edgeCount && edgesAdded < V - 1; ++i) {
        int u = edges[i].u;
        int v = edges[i].v;

        int setU = find(parent, u);
        int setV = find(parent, v);

        if (setU != setV) {
            mst.addEdge(u, v, edges[i].weight);
            unite(parent, rank, setU, setV);
            edgesAdded++;
        }
    }

    return mst;
}