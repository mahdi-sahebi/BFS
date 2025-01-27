#include <iterator>
#include "graph/unweighted_graph.hpp"

using namespace std;

template<typename T>
void UnweightedGraph<T>::clear()
{
    adjacents_.clear();
}

template<typename T>
void UnweightedGraph<T>::add(T node_1, T node_2)
{
    // TODO(MN): Check existance and throw exception
    adjacents_[node_1] = node_2;
    adjacents_[node_2] = node_1;
}

template<typename T>
bool UnweightedGraph<T>::contains(T node_1, T node_2)
{
    const auto itr = adjacents_.find(node_1);
    return (itr != end(adjacents_)) && (itr->second == node_2);
}

