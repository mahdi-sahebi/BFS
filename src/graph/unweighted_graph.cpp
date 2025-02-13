#include <iterator>
#include "graph/unweighted_graph.hpp"

using namespace std;

//void UnweightedGraph::clear() noexcept
//{
//    this->clear();
//}

//uint32_t UnweightedGraph::getCount() const noexcept
//{
//    return size();
//}

void UnweightedGraph::add(pair<uint32_t, uint32_t> edge)
{
    // TODO(MN): Check existance and throw exception
    (*this)[edge.first][edge.second] = 1;
    (*this)[edge.second][edge.first] = 1;
}

void UnweightedGraph::add(uint32_t node_1, uint32_t node_2)
{
  // TODO(MN): Check existance and throw exception
  (*this)[node_1][node_2] = 1;
  (*this)[node_2][node_1] = 1;
}

void UnweightedGraph::add(std::vector<std::pair<uint32_t, uint32_t>> edges)
{
  for (const auto edge: edges) {
      add(edge);
  }
}

bool UnweightedGraph::contains(uint32_t node_1, uint32_t node_2) noexcept
{
    const auto firstItr = this->find(node_1);
    if (firstItr == this->end()) {
      return false;
    }

    const auto secondsItr = firstItr->second.find(node_2);
    if (secondsItr == firstItr->second.end()) {
      return false;
    }

    if (secondsItr->second != 1) {
      return false;
    }

    return true;
}

bool UnweightedGraph::contains(pair<uint32_t, uint32_t> edge) noexcept
{
    return contains(edge.first, edge.second);
}

