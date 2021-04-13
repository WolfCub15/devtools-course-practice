// Copyright 2021 Volkova Anastasia

#ifndef MODULES_KRUSKAL_ALGORITHM_INCLUDE_KRUSKAL_ALGORITHM_H_
#define MODULES_KRUSKAL_ALGORITHM_INCLUDE_KRUSKAL_ALGORITHM_H_

#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef std::pair<int, int> edge;

class Graph{
private:
    int n;
    std::vector<std::pair<int, edge>> G;
    std::vector<std::pair<int, edge>> MST;
    std::vector<int> parent;
    void make_set(int x);
    int find_set(int i);
    void union_set(int a, int b);
public:
    Graph();
    Graph(const int n);
    Graph(const Graph& tmp);
    Graph& operator=(const Graph& tmp);
    ~Graph();
    void addEdge(const int x, const int y, const int w);
    void Kruskal();
    void printMST();
    int get_n() const;
    std::vector<std::pair<int, edge>> get_G() const;
    std::vector<std::pair<int, edge>> get_MST() const;
    std::vector<int> get_parent() const;
};

#endif  // MODULES_KRUSKAL_ALGORITHM_INCLUDE_KRUSKAL_ALGORITHM_H_
