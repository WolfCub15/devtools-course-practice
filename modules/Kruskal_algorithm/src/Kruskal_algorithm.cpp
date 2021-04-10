// Copyright 2021 Volkova Anastasia

#include "include/Kruskal_algorithm.h"

Graph::Graph(int size) {
	n = size;
    parent.resize(n,0);
    G.clear();
    MST.clear();
    for (int i = 0; i < n; ++i) {
        make_set(i);
    }
}

void Graph::addEdge(int x, int y, int w) {
    G.emplace_back(make_pair(w, edge(x, y)));
}

void Graph::make_set(int x) {
    parent[x] = x;
}

int Graph::find_set(int i) {
    if (i == parent[i]) return i;
    return parent[i] = find_set(parent[i]);
}
 
void Graph::union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if(rand() & 1) swap(a,b);
    if(a != b) parent[a] = parent[b];
}

int Graph::get_n(){
    return n;
}

std::vector<int> Graph::get_parent(){
    return parent;
}

std::vector<std::pair<int, edge>> Graph::get_MST(){
    return MST;
}

std::vector<std::pair<int, edge>> Graph::get_G(){
    return G;
}

void Graph::Kruskal() {
	int a, b;
    sort(G.begin(), G.end());
    for (auto i : G) {
        a = find_set(i.second.first);
        b = find_set(i.second.second);
        if (a != b) {
            MST.emplace_back(i);
            union_set(a, b);
        }
    }
}

void Graph::printMST() {
    for (int i = 0; i < MST.size(); i++) {
        cout << "( " << MST[i].second.first << " - " << MST[i].second.second << " ) : " << MST[i].first << '\n';
    }
}

