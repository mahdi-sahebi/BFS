#include <cstdint>
#include <vector>
#include <gtest/gtest.h>
#include "graph/unweighted_graph.hpp"


TEST(BFS, Simple1)
{
    UnweightedGraph<uint32_t> graph;
    BFS<uint32_t> bfs;

    graph.add(0, 1);
    graph.add(0, 2);
    graph.add(1, 3);
    graph.add(2, 4);
    graph.add(3, 5);

    const vector<int32_t> path = bfs.findPath(graph, 0, 4);
    /* Path: {0, 2, 4} */
    EXPECT_EQ(path.size(), 3);
    EXPECT_EQ(path[0], 0);
    EXPECT_EQ(path[1], 2);
    EXPECT_EQ(path[2], 4);
}

TEST(BFS, Simple2)
{
    UnweightedGraph<uint32_t> graph;
    BFS<uint32_t> bfs;

    graph.add(0, 1);
    graph.add(0, 2);
    graph.add(1, 3);
    graph.add(2, 4);
    graph.add(3, 5);

    const vector<int32_t> path = bfs.findPath(graph, 0, 5);
    /* Path: {0, 1, 3, 5} */
    EXPECT_EQ(path.size(), 4);
    EXPECT_EQ(path[0], 0);
    EXPECT_EQ(path[1], 1);
    EXPECT_EQ(path[2], 3);
    EXPECT_EQ(path[3], 5);
}

TEST(BFS, Simple3)
{
    UnweightedGraph<uint32_t> graph;
    BFS<uint32_t> bfs;

    graph.add(0, 1);
    graph.add(0, 2);
    graph.add(1, 3);
    graph.add(2, 4);
    graph.add(3, 5);

    const vector<int32_t> path = bfs.findPath(graph, 3, 3);
    /* Path: {3} */
    EXPECT_EQ(path.size(), 1);
    EXPECT_EQ(path[0], 3);
}

TEST(BFS, Closed1)
{
    UnweightedGraph<uint32_t> graph;
    BFS<uint32_t> bfs;

    graph.add(0, 1);
    graph.add(0, 5);
    graph.add(1, 2);
    graph.add(2, 3);
    graph.add(3, 4);
    graph.add(4, 5);

    const vector<int32_t> path = bfs.findPath(graph, 0, 5);
    /* Path: {0, 5} */
    EXPECT_EQ(path.size(), 2);
    EXPECT_EQ(path[0], 0);
    EXPECT_EQ(path[1], 5);
}

TEST(BFS, Closed2)
{
    UnweightedGraph<uint32_t> graph;
    BFS<uint32_t> bfs;

    graph.add(0, 1);
    graph.add(0, 5);
    graph.add(1, 2);
    graph.add(2, 3);
    graph.add(3, 4);
    graph.add(4, 5);

    const vector<int32_t> path = bfs.findPath(graph, 5, 0);
    /* Path: {5, 0} */
    EXPECT_EQ(path.size(), 2);
    EXPECT_EQ(path[0], 5);
    EXPECT_EQ(path[1], 0);
}

TEST(BFS, Grid1)
{
    UnweightedGraph<uint32_t> graph;
    BFS<uint32_t> bfs;

    /*
    1  1  0  1  1
    1  0  1  1  0
    1  1  1  0  1
    0  0  1  1  1
    1  1  1  0  1
    */
    graph.add({ 0,  1}, { 3,  4}, { 0,  5}, { 3,  8}, { 7,  8}, { 5, 10}, 
              {10, 11}, {11, 12}, { 7, 12}, {12, 17}, {17, 18}, {18, 19}, 
              {14, 19}, {20, 21}, {21, 22}, {17, 22}, {19, 24}});

    const vector<int32_t> path = bfs.findPath(graph, 0, 4);
    /* Path: {0, 5, 10, 11, 12, 7, 8, 3, 4} */
    EXPECT_EQ(path.size(), 9);
    EXPECT_EQ(path[0], 0);
    EXPECT_EQ(path[1], 5);
    EXPECT_EQ(path[2], 10);
    EXPECT_EQ(path[3], 11);
    EXPECT_EQ(path[4], 12);
    EXPECT_EQ(path[5], 7);
    EXPECT_EQ(path[6], 8);
    EXPECT_EQ(path[7], 3);
    EXPECT_EQ(path[8], 4);
}

TEST(BFS, Grid2)
{
    UnweightedGraph<uint32_t> graph;
    BFS<uint32_t> bfs;

    /*
    1  1  0  1  1
    1  0  1  1  0
    1  1  1  0  1
    0  0  1  1  1
    1  1  1  0  1
    */
    graph.add({ 0,  1}, { 3,  4}, { 0,  5}, { 3,  8}, { 7,  8}, { 5, 10}, 
              {10, 11}, {11, 12}, { 7, 12}, {12, 17}, {17, 18}, {18, 19}, 
              {14, 19}, {20, 21}, {21, 22}, {17, 22}, {19, 24}});


    const vector<int32_t> path = bfs.findPath(graph, 1, 20);
    /* Path: {1, 0, 5, 10, 11, 12, 17, 22, 21, 20} */
    EXPECT_EQ(path.size(), 10);
    EXPECT_EQ(path[0], 1);
    EXPECT_EQ(path[1], 0);
    EXPECT_EQ(path[2], 5);
    EXPECT_EQ(path[3], 10);
    EXPECT_EQ(path[4], 11);
    EXPECT_EQ(path[5], 12);
    EXPECT_EQ(path[6], 17);
    EXPECT_EQ(path[7], 22);
    EXPECT_EQ(path[8], 21);
    EXPECT_EQ(path[9], 20);
}

TEST(BFS, Grid3)
{
    UnweightedGraph<uint32_t> graph;
    BFS<uint32_t> bfs;

    /*
    1  1  0  1  1
    1  0  1  1  0
    1  1  1  0  1
    0  0  1  1  1
    1  1  1  0  1
    */
    graph.add({ 0,  1}, { 3,  4}, { 0,  5}, { 3,  8}, { 7,  8}, { 5, 10}, 
              {10, 11}, {11, 12}, { 7, 12}, {12, 17}, {17, 18}, {18, 19}, 
              {14, 19}, {20, 21}, {21, 22}, {17, 22}, {19, 24}});

    const vector<int32_t> path = bfs.findPath(graph, 14, 4);
    /* Path: {14, 19, 18, 17, 12, 7, 8, 3, 4} */
    EXPECT_EQ(path.size(), 9);
    EXPECT_EQ(path[0], 14);
    EXPECT_EQ(path[1], 19);
    EXPECT_EQ(path[2], 18);
    EXPECT_EQ(path[3], 17);
    EXPECT_EQ(path[4], 12);
    EXPECT_EQ(path[5], 7);
    EXPECT_EQ(path[6], 8);
    EXPECT_EQ(path[7], 3);
    EXPECT_EQ(path[8], 4);
}

int main()
{
    testing::InitGoogleTEST();
    return RUN_ALL_TESTS();
}