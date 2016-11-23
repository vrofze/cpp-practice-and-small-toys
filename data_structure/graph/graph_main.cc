#include "adj_wdigraph.h"

#include <iostream>

int main()
{
    AdjacencyWDigraph<int> graph(4);
    graph.insert_edge(1, 2, 1);
    graph.insert_edge(2, 1, 1);
    graph.insert_edge(1, 3, 1);
    graph.insert_edge(3, 1, 1);
    graph.insert_edge(1, 4, 1);
    graph.insert_edge(4, 1, 1);
    graph.insert_edge(2, 3, 1);
    graph.insert_edge(3, 2, 1);
    graph.insert_edge(3, 4, 1);
    graph.insert_edge(4, 3, 1);
    int reach[5];
    graph.bfs(1, reach, 233);
    return 0;
}
