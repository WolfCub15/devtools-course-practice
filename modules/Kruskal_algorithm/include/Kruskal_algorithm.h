// Copyright 2021 Volkova Anastasia

#ifndef MODULES_KRUSKAL_ALGORITHM_INCLUDE_KRUSKAL_ALGORITHM_H_
#define MODULES_KRUSKAL_ALGORITHM_INCLUDE_KRUSKAL_ALGORITHM_H_

#include <iostream>
#include <vector>
#include <algorithm>

typedef std::pair<int, int> edge;

class Graph{
private:
    int n;
    std::vector<std::pair<int, edge>> G;
    std::vector<std::pair<int, edge>> MST;
    std::vector<int> parent;
public:
    Graph(int n);
    void addEdge(int x, int y, int w);
    void Kruskal();
    void printMST();
	int get_n();
    std::vector<std::pair<int, edge>> get_G();
	std::vector<std::pair<int, edge>> get_MST();
	std::vector<int> get_parent();
	void make_set(int x);
    int find_set(int i);
    void union_set(int a, int b);
};

#endif  // MODULES_KRUSKAL_ALGORITHM_INCLUDE_KRUSKAL_ALGORITHM_H_
