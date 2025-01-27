#ifndef ALGORITHMS_BFS_H_
#define ALGORITHMS_BFS_H_

#include <cstdint>
#include <vector>
#include "graph/graph.hpp"
#include "graph/unweighted_graph.hpp"// TODO(MN): Delete


class BFS
{
public:
    virtual ~BFS() = default;

    // TODO(M)N: Use Graph as base of all types of graphs
    std::vector<uint32_t> findPath(const UnweightedGraph& graph, uint32_t nodeSrc, uint32_t nodeDst);

private:

};

#endif /* ALGORITHMS_BFS_H_ */
