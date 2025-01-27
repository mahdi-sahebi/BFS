#include <iterator>
#include "graph/unweighted_graph.hpp"

using namespace std;

// template<typename T>
void UnweightedGraph::clear()
{
    adjacents_.clear();
}

// template<typename T>
void UnweightedGraph::add(uint32_t node_1, uint32_t node_2)
{
    // TODO(MN): Check existance and throw exception
    adjacents_[node_1] = node_2;
    adjacents_[node_2] = node_1;
}

bool UnweightedGraph::contains(uint32_t node_1, uint32_t node_2)
{
    const auto itr = adjacents_.find(node_1);
    return (itr != end(adjacents_)) && (itr->second == node_2);
}

