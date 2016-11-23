#ifndef GRAPH_H
#define GRAPH_H

#include "../queue/array_queue.h"
#include <iostream>

template<class T>
class vertex_iterator
{
public:
    virtual ~vertex_iterator() { }

    virtual int next() = 0;
    virtual int next(T&) = 0;
};

template<class T>
class graph
{
public:
    virtual ~graph() { }

    virtual int num_of_vertices() const = 0;
    virtual int num_of_edges() const = 0;
    virtual bool exists_edge(int, int) const = 0;
    virtual void insert_edge(int, int, T) = 0;
    virtual void erase_edge(int, int) = 0;
    virtual int degree(int) const = 0;
    virtual int in_degree(int) const = 0;
    virtual int out_degree(int) const = 0;

    virtual bool directed() const = 0;
    virtual bool weighted() const = 0;
    virtual vertex_iterator<T>* iterator(int) = 0;
    virtual void bfs(int, int[], int);
};

template<class T>
void graph<T>::bfs(int v, int reach[], int label)
{
    ArrayQueue<int> queue;
    reach[v] = label;
    queue.push(v);
    std::cout << v << " ";
    while(!queue.empty()){
        int w = queue.pop();

        vertex_iterator<T> *iw = iterator(w);
        int u;
        while((u = iw->next()) != 0)
            if(reach[u] == 0){
                queue.push(u);
                reach[u] = label;
                std::cout << u << " ";
            }
        delete iw;
    }
}

#endif
