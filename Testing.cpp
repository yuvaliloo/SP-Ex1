#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.hpp"
#include "Algorithms.hpp"
#include "Graph.hpp"

TEST_CASE("Graph Initialization") {
    Graph g(5); // Assume the constructor takes the number of vertices
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
    CHECK(g.isEdge(2, 3) == false); // Edge should not exist
}

TEST_CASE("BFS Traversal") {
    Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 4, 1);

    Algorithms alg(g);
    Graph bfsTree = alg.BFS(0);  // Assume BFS returns a tree

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
    Graph dfsTree = alg.DFS(0);  // Assume DFS returns a tree

    CHECK(dfsTree.isEdge(0, 1) == true);
    CHECK(dfsTree.isEdge(1, 3) == true);
    CHECK(dfsTree.isEdge(0, 2) == true);
    CHECK(dfsTree.isEdge(2, 4) == true);
}