#ifndef UNWEIGHTED_GRAPH_H_
#define UNWEIGHTED_GRAPH_H_

#include <cstdint>
#include "graph.hpp"


// template<typename T>
class UnweightedGraph
{
public:
    UnweightedGraph() = default;
    virtual ~UnweightedGraph() = default;

    void clear();
    void add(uint32_t node_1, uint32_t node_2);
    bool contains(uint32_t node_1, uint32_t node_2);

private:
    Graph<uint32_t> adjacents_;

};

#endif /* UNWEIGHTED_GRAPH_H_ */