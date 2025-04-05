#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.hpp"
#include "Algorithms.hpp"
#include "Graph.hpp"

TEST_CASE("Graph Initialization") {
    Graph g(5); 
    CHECK(g.getNumVertices() == 5);
}

TEST_CASE("Adding Edges") {
    Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 5);

    CHECK(g.isEdge(0, 1) == true);
    CHECK(g.getWeight(0, 1) == 10);
    CHECK(g.isEdge(1, 2) == true);
    CHECK(g.getWeight(1, 2) == 5);
    CHECK(g.isEdge(2, 3) == false); 
}

TEST_CASE("BFS Traversal") {
    Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 4, 1);

    Algorithms alg(g);
    Graph bfsTree = alg.BFS(0);  

    CHECK(bfsTree.isEdge(0, 1) == true);
    CHECK(bfsTree.isEdge(0, 2) == true);
    CHECK(bfsTree.isEdge(1, 3) == true);
    CHECK(bfsTree.isEdge(2, 4) == true);
}

TEST_CASE("DFS Traversal") {
    Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 4, 1);

    Algorithms alg(g);
    Graph dfsTree = alg.DFS(0);  

    CHECK(dfsTree.isEdge(0, 1) == true);
    CHECK(dfsTree.isEdge(1, 3) == true);
    CHECK(dfsTree.isEdge(0, 2) == true);
    CHECK(dfsTree.isEdge(2, 4) == true);
}
TEST_CASE("Dijkstra shortest paths") {
    Graph g(4); 

    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 1);

    Algorithms alg(g);
    Graph tree = alg.Dijkstra(0);

    CHECK(tree.isEdge(0,1));
    CHECK(tree.isEdge(1,2));
    CHECK(tree.isEdge(2,3));
    CHECK(tree.getWeight(0,1) == 1);
    CHECK(tree.getWeight(1,2) == 2);
    CHECK(tree.getWeight(2,3) == 1);
}

TEST_CASE("Prim's minimum spanning tree") {
    Graph g(4);

    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    Algorithms alg(g);
    Graph tree = alg.Prim();

    int totalWeight = 0;
    for (int i = 0; i < 4; ++i)
        for (int j = i + 1; j < 4; ++j)
            if (tree.isEdge(i,j))
                totalWeight += tree.getWeight(i,j);

    CHECK(totalWeight == 19);
    CHECK(tree.isEdge(2,3));
    CHECK(tree.isEdge(0,3));
    CHECK(tree.isEdge(0,1));
}

TEST_CASE("Kruskal's minimum spanning tree") {
    Graph g(4);

    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    Algorithms alg(g);
    Graph tree = alg.Kruskal();

    int totalWeight = 0;
    for (int i = 0; i < 4; ++i)
        for (int j = i + 1; j < 4; ++j)
            if (tree.isEdge(i,j))
                totalWeight += tree.getWeight(i,j);

    CHECK(totalWeight == 19);
    CHECK(tree.isEdge(2,3));
    CHECK(tree.isEdge(0,3));
    CHECK(tree.isEdge(0,1));
}
