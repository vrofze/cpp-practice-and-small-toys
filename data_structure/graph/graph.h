#ifndef GRAPH_H
#define GRAPH_H

template<class T>
class edge
{
    
};

template<class T>
class vertex_iterator
{
    
};

template<class T>
class graph
{
public:
    virtual ~graph() { }

    virtual int num_of_vertices() const = 0;
    virtual int num_of_edges() const = 0;
    virtual bool exists_edge(int, int) const = 0;
    virtual void insert_edge(edge<T>*) = 0;
    virtual void erase_edge(int, int) = 0;
    virtual int degree(int) const = 0;
    virtual int in_degree(int) const = 0;
    virtual int out_degree(int) const = 0;

    virtual bool directed() const = 0;
    virtual bool weighted() const = 0;
    virtual vertex_iterator<T>* iterator(int) = 0;
};

#endif
