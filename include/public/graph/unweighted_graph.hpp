#ifndef UNWEIGHTED_GRAPH_H_
#define UNWEIGHTED_GRAPH_H_

#include <cstdint>
#include "graph.hpp"


template<typename T>
class UnweightedGraph
{
public:
    UnweightedGraph() = default;
    virtual ~UnweightedGraph() = default;

    void clear();
    void add(T node_1, T node_2);
    bool contains(T node_1, T node_2);

private:
    Graph<T> adjacents_;

};

#endif /* UNWEIGHTED_GRAPH_H_ */