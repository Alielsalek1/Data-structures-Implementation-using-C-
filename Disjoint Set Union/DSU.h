#include <bits/stdc++.h>
using namespace std;

#ifndef DSU_DSU_H
#define DSU_DSU_H

template<typename T>
class DSU {
private:
    // Those can be made public if you need to use them
    vector<int> par;
    vector<int> rank; // stores the height of the tree for each set
public:
    DSU(int n);
    T find(T val);
    void unite(T x, T y);
};

#include "DSU.cpp"

#endif
// Most Important Usage for the DSU Data Structure (Minimum Spanning Tree)

//struct edge {
//    int u, v, weight;
//    bool operator<(const edge& other) const {
//        return weight < other.weight;
//    }
//};
//vector<edge> kruskal(vector<edge> &edges, int n) {
//    sort(edges.begin(), edges.end());
//    vector<edge> mst; //minimum spanning tree
//    DSU dsu(n);
//    for (auto &edge : edges) {
//        if (dsu.unite(edge.v, edge.u)) // boolean dsu return false if both are united true if we performed the op
//            mst.push_back(edge);
//    }
//    return mst;
//}