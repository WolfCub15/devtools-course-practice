// Copyright 2021 Volkova Anastasia

#include "include/Kruskal_algorithm.h"

Graph::Graph() : n(0) {
    G.clear();
    MST.clear();
    parent.resize(0);
}

Graph::Graph(const int size = 0) {
    n = size;
    parent.resize(n,0);
    G.clear();
    MST.clear();
    for (int i = 0; i < n; ++i) {
        make_set(i);
    }
}

Graph::Graph(const Graph& tmp) : n(tmp.get_n()),
                                 G(tmp.get_G()),
								 MST(tmp.get_MST()),
								 parent(tmp.get_parent()) {}

Graph& Graph::operator=(const Graph& tmp) {
    n = tmp.get_n();
	G = tmp.get_G();
	MST = tmp.get_MST();
	parent = tmp.get_parent();
	return *this;
}

Graph::~Graph() {
    parent.clear();
	G.clear();
    MST.clear();
}

void Graph::addEdge(const int x, const int y, const int w) {
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

int Graph::get_n() const {
    return n;
}

std::vector<int> Graph::get_parent() const {
    return parent;
}

std::vector<std::pair<int, edge>> Graph::get_MST() const {
    return MST;
}

std::vector<std::pair<int, edge>> Graph::get_G() const {
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
