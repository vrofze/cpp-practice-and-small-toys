#ifndef ADJ_WDIGRAPH_H
#define ADJ_WDIGRAPH_H

#include "graph.h"

#include <iostream>

template<class T>
class AdjacencyWDigraph: public graph<T>
{
public:
    AdjacencyWDigraph();
    ~AdjacencyWDigraph();

    int num_of_vertices() const;
    int num_of_edges() const;
    bool exists_edge(int, int) const;
    void insert_edge(edge<T>*);
    void erase_edge(int, int);
    int degree(int) const;
    int in_degree(int) const;
    int out_degree(int) const;

    bool directed() const;
    bool weighted() const;
    vertex_iterator<T>* iterator(int);

protected:
    int n;  // num of node
    int e;  // num of edges
    T **a;
    T no_edge;
};

#endif
