#include <cstdint>
#include <vector>
#include <gtest/gtest.h>


Test(BFS, Simple1)
{
    UnweightedGraph graph;
    BFS bfs;

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

Test(BFS, Simple2)
{
    UnweightedGraph graph;
    BFS bfs;

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

Test(BFS, Simple3)
{
    UnweightedGraph graph;
    BFS bfs;

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

Test(BFS, Closed1)
{
    UnweightedGraph graph;
    BFS bfs;

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

Test(BFS, Closed2)
{
    UnweightedGraph graph;
    BFS bfs;

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

int main()
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}