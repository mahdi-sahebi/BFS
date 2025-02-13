#ifndef UNWEIGHTED_GRAPH_H_
#define UNWEIGHTED_GRAPH_H_

#include <cstdint>
#include <vector>
#include "graph.hpp"


class UnweightedGraph : public Graph
{
public:
    UnweightedGraph() = default;
    virtual ~UnweightedGraph() = default;

//    void clear() noexcept;
//    uint32_t getCount() const noexcept;

    void add(std::pair<uint32_t, uint32_t> edge);
    void add(uint32_t node_1, uint32_t node_2);
    void add(std::vector<std::pair<uint32_t, uint32_t>> edges);
    // TODO(MN): remove

    bool contains(uint32_t node_1, uint32_t node_2) noexcept;
    bool contains(std::pair<uint32_t, uint32_t> edge) noexcept;

private:

};

#endif /* UNWEIGHTED_GRAPH_H_ */
