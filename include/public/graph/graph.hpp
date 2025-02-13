#ifndef GRAPH_H_
#define GRAPH_H_

#include <cstdint>
#include <map>

using NodeID = uint32_t;
using Graph = std::map<NodeID, std::map<NodeID, uint32_t>>;


#endif /* GRAPH_H_ */
