#ifndef ALGORITHMS_BFS_H_
#define ALGORITHMS_BFS_H_

#include <cstdint>
#include <vector>
#include "graph/graph.hpp"


class BFS
{
public:
    virtual ~BFS() = default;

    std::vector<uint32_t> findPath(const Graph<uint32_t>& graph, uint32_t nodeSrc, uint32_t nodeDst);

private:

};

#endif /* ALGORITHMS_BFS_H_ */