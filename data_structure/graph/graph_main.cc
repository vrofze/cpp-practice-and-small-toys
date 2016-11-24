#include "adj_wdigraph.h"

#include <iostream>

int main()
{
    AdjacencyWDigraph<int> graph(5);
    graph.insert_edge(1, 2, 1);
    graph.insert_edge(2, 1, 1);
    graph.insert_edge(1, 3, 1);
    graph.insert_edge(3, 1, 1);
    graph.insert_edge(1, 4, 1);
    graph.insert_edge(4, 1, 1);
    graph.insert_edge(1, 5, 1);
    graph.insert_edge(5, 1, 1);
    graph.insert_edge(2, 3, 1);
    graph.insert_edge(3, 2, 1);
    graph.insert_edge(3, 4, 1);
    graph.insert_edge(4, 3, 1);
    int reach[6];
    for(int i = 0; i < 6; ++i)
        reach[i] = 0;
    std::cout << "bfs:";
    graph.bfs(1, reach, 233);
    std::cout << std::endl;
    for(int i = 0; i < 6; ++i)
        reach[i] = 0;
    std::cout << "dfs:";
    graph.dfs(1, reach, 233);
    return 0;
}
