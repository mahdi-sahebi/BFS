#include <queue>
#include <map>
#include <algorithm>
#include "bfs/bfs.hpp"


using namespace std;


vector<uint32_t> BFS::findPath(const UnweightedGraph& graph, uint32_t nodeSrc, uint32_t nodeDst)
{
  map<uint32_t, bool> isVisited;// TODO(MN): Using NodeID = uint32_t
  for (const auto& edge: graph) {
    isVisited[edge.first] = false;
  }

  map<uint32_t, uint32_t> parents;


  queue<uint32_t> nodeQueue;
  nodeQueue.emplace(nodeSrc);
  isVisited[nodeSrc] = true;

  bool enable = true;

  while (enable && !nodeQueue.empty()) {
    const auto curNode = nodeQueue.front();
    nodeQueue.pop();

    const auto adjacents = graph.find(curNode)->second;
    for (const auto& [adjacent, exist] : adjacents) {
        if (0 == exist)// TODO(MN): Must not be. must had been removed
          continue;

        if (isVisited[adjacent]) {
            continue;
        }

        parents[adjacent] = curNode;

        if (adjacent == nodeDst) {
          enable = false;
          break;
        }

        isVisited[adjacent] = true;
        nodeQueue.emplace(adjacent);
    }
  }


  vector<uint32_t> path;

  if (parents.size()) {
    path.emplace_back(nodeDst);

    uint32_t node = nodeDst;
    while (true) {
      const auto itr = parents.find(node);
      if (cend(parents) == itr) {
        break;
      }

      node = itr->second;
      path.emplace_back(node);
    }

    reverse(begin(path), end(path));
    return path;
  }

  return path;
}

