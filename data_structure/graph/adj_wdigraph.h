#ifndef ADJ_WDIGRAPH_H
#define ADJ_WDIGRAPH_H

#include "graph.h"

#include <iostream>

template<class T>
class MyIterator: public vertex_iterator<T>
{
public:
    MyIterator(T* the_row, T the_no_edge, int num_of_vertices)
        : row(the_row), no_edge(the_no_edge), n(num_of_vertices), vertex(1)
        { }
    ~MyIterator() { }

    int next(T& the_weight)
        {
            for(int j = vertex; j <= n; ++j)
                if(row[j] != no_edge){
                    vertex = j + 1;
                    the_weight = row[j];
                    return j;
                }
            vertex = n + 1;
            return 0;
        }
    int next()
        {
            for(int j = vertex; j <= n; ++j)
                if(row[j] != no_edge){
                    vertex = j + 1;
                    return j;
                }
            vertex = n + 1;
            return 0;
        }

protected:
    T* row;
    T no_edge;
    int n;
    int vertex;
};

template<class T>
class AdjacencyWDigraph: public graph<T>
{
public:
    AdjacencyWDigraph(int num_of_vertices = 0, T the_no_edges = 0);
    ~AdjacencyWDigraph();

    int num_of_vertices() const
        {
            return n;
        }
    int num_of_edges() const
        {
            return e;
        }
    bool exists_edge(int, int) const;
    void insert_edge(int, int, T);
    void erase_edge(int, int);
    bool check_vertex(int the_vertex) const
        {
            return the_vertex < 1 && the_vertex > n;
        }
    int degree(int) const;
    int in_degree(int) const;
    int out_degree(int) const;

    bool directed() const
        {
            return true;
        }
    bool weighted() const
        {
            return true;
        }
    MyIterator<T>* iterator(int the_vertex)
        {
            check_vertex(the_vertex);
            return new MyIterator<T>(a[the_vertex], no_edge, n);
        }

protected:
    int n;  // num of vertices
    int e;  // num of edges
    T **a;
    T no_edge;
};

template<class T>
AdjacencyWDigraph<T>::AdjacencyWDigraph(int num_of_vertices, T the_no_edges)
{
    if(num_of_vertices < 0){
        std::cout << "adjacencywdigraph" << std::endl;
        throw "num of vertices error!";
    }

    n = num_of_vertices;
    e = 0;
    no_edge = the_no_edges;
    a = new T*[n];
    for(int i = 0; i < n + 1; ++i)
        a[i] = new T[n + 1];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            a[i][j] = no_edge;
}

template<class T>
AdjacencyWDigraph<T>::~AdjacencyWDigraph()
{
    for(int i = 0; i <= n; ++i)
        delete[] a[i];
    delete[] a;
    a = 0;
}

template<class T>
bool AdjacencyWDigraph<T>::exists_edge(int v1, int v2) const
{
    if(v1 < 1 || v2 < 1 || v1 > n || v2 < n || a[v1][v2] == no_edge)
        return false;
    else
        return true;
}

template<class T>
void AdjacencyWDigraph<T>::insert_edge(int v1, int v2, T weight)
{
    if(v1 < 1 || v2 < 1 || v1 > n || v2 > n || v1 == v2){
        std::cout << "insert edge" << std::endl;
        throw "edge illegal";
    }

    if(a[v1][v2] == no_edge)
        ++e;
    a[v1][v2] = weight;
}

template<class T>
void AdjacencyWDigraph<T>::erase_edge(int v1, int v2)
{
    if(v1 < 1 || v2 < 1 || v1 > n || v2 > n || a[v1][v2] != no_edge){
        a[v1][v2] = no_edge;
        --e;
    }
}

template<class T>
int AdjacencyWDigraph<T>::degree(int vertex) const
{
    throw "undefined method!";
}

template<class T>
int AdjacencyWDigraph<T>::in_degree(int vertex) const
{
    check_vertex(vertex);

    int sum = 0;
    for(int i = 0; i <= n; ++i){
        if(a[i][vertex] != no_edge)
            ++sum;
    }
    return sum;
}

template<class T>
int AdjacencyWDigraph<T>::out_degree(int vertex) const
{
    check_vertex(vertex);

    int sum = 0;
    for(int i = 0; i < n; ++i){
        if(a[vertex][i] != no_edge)
            ++sum;
    }
    return sum;
}

#endif
