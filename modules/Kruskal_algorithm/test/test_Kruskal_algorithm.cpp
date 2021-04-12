// Copyright 2021 Volkova Nastya

#include <gtest/gtest.h>
#include <tuple>
#include "include/Kruskal_algorithm.h"


TEST(Kruskal_algorithm, Сonstructor) {
    Graph g;
    
    ASSERT_EQ(0, g.get_n());
    ASSERT_EQ(0, g.get_parent().size());
    ASSERT_EQ(0, g.get_G().size());
    ASSERT_EQ(0, g.get_MST().size());
}

TEST(Kruskal_algorithm, TheNumberOfVertices) {
    Graph g(10);
    ASSERT_EQ(10, g.get_n());
}

TEST(Kruskal_algorithm, CopyConstructor) {
    Graph g(5);
    g.addEdge(0, 1, 3);
    g.addEdge(0, 2, 1);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 4, 3);
    g.addEdge(2, 3, 2);
    g.addEdge(3, 4, 4);
    g.Kruskal();

    Graph g_copy(g);
	
    ASSERT_EQ(g.get_n(), g_copy.get_n());
    ASSERT_EQ(g.get_G(), g_copy.get_G());
    ASSERT_EQ(g.get_MST(), g_copy.get_MST());
    ASSERT_EQ(g.get_parent(), g_copy.get_parent());
}

TEST(Kruskal_algorithm, AssignmentOperator) {
    Graph g(5);
    g.addEdge(0, 1, 3);
    g.addEdge(0, 2, 1);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 4, 3);
    g.addEdge(2, 3, 2);
    g.addEdge(3, 4, 4);
    g.Kruskal();

    Graph g_copy = g;
	
    ASSERT_EQ(g.get_n(), g_copy.get_n());
    ASSERT_EQ(g.get_G(), g_copy.get_G());
    ASSERT_EQ(g.get_MST(), g_copy.get_MST());
    ASSERT_EQ(g.get_parent(), g_copy.get_parent());
}

TEST(Kruskal_algorithm, AddEdgeToGraph) {
    Graph g(2);
    g.addEdge(0, 1, 10);
    std::vector<std::pair<int, edge>> gr = g.get_G();
    int x = gr[0].second.first;
    int y = gr[0].second.second;
    int w = gr[0].first;
    ASSERT_EQ(0, x);
    ASSERT_EQ(1, y);
    ASSERT_EQ(10, w);

}

TEST(Kruskal_algorithm, ParentMakeSet) {
    Graph g(10);
    std::vector<int> p = g.get_parent();
    for(int i = 0; i < 10; ++i){
        ASSERT_EQ(i, p[i]);
    }
}

TEST(Kruskal_algorithm, TheNumberOfEdges) {
    Graph g(4);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 3);
    std::vector<std::pair<int, edge>> gr = g.get_G();
    ASSERT_EQ(4, gr.size());
}

TEST(Kruskal_algorithm, KruskalAlgorithmN5) {
    Graph g(5);
    g.addEdge(0, 3, 5);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 3);
    g.addEdge(2, 1, 6);
    g.addEdge(2, 3, 1);
    g.addEdge(4, 1, 3);
    g.addEdge(4, 2, 2);
    g.addEdge(4, 3, 2);
    g.Kruskal();
    std::vector<std::pair<int, edge>> mst = g.get_MST();
    
    ASSERT_EQ(0, mst[0].second.first);
    ASSERT_EQ(1, mst[0].second.second);
    ASSERT_EQ(1, mst[0].first);
    
    ASSERT_EQ(2, mst[1].second.first);
    ASSERT_EQ(3, mst[1].second.second);
    ASSERT_EQ(1, mst[1].first);
    
    ASSERT_EQ(4, mst[2].second.first);
    ASSERT_EQ(2, mst[2].second.second);
    ASSERT_EQ(2, mst[2].first);
    
    ASSERT_EQ(0, mst[3].second.first);
    ASSERT_EQ(2, mst[3].second.second);
    ASSERT_EQ(3, mst[3].first);
}

TEST(Kruskal_algorithm, KruskalAlgorithmN4) {
    Graph g(4);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 3);
    g.Kruskal();
    std::vector<std::pair<int, edge>> mst = g.get_MST();
    
    ASSERT_EQ(0, mst[0].second.first);
    ASSERT_EQ(3, mst[0].second.second);
    ASSERT_EQ(1, mst[0].first);
    
    ASSERT_EQ(0, mst[1].second.first);
    ASSERT_EQ(1, mst[1].second.second);
    ASSERT_EQ(2, mst[1].first);
    
    ASSERT_EQ(2, mst[2].second.first);
    ASSERT_EQ(3, mst[2].second.second);
    ASSERT_EQ(3, mst[2].first);
}
