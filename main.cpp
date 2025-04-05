#include <iostream>
#include "Graph.hpp"
#include "Algorithms.hpp"

//simple implementation of the algorithms from the exercise

int main() {
    Graph g(5);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 7);
    g.addEdge(2, 4, 3);
    g.addEdge(3, 4, 1);

    Algorithms alg(g);

    Graph dfsTree = alg.DFS(0);
    std::cout << "DFS Tree built.\n";
    dfsTree.print_graph();

    Graph bfsTree = alg.BFS(0);
    std::cout << "\nBFS Tree built.\n";
    bfsTree.print_graph();

    Graph dijkstraTree = alg.Dijkstra(0);
    std::cout << "\nDijkstra Tree built.\n";
    dijkstraTree.print_graph();

    Graph primMST = alg.Prim();
    std::cout << "\nPrim MST built.\n";
    primMST.print_graph();

    Graph kruskalMST = alg.Kruskal();
    std::cout << "\nKruskal MST built.\n";
    kruskalMST.print_graph();
    return 0;
}
