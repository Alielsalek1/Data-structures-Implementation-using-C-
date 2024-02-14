#ifndef INC_2D_FENWICK_TREE_FENWICK2D_H
#define INC_2D_FENWICK_TREE_FENWICK2D_H

#include <bits/stdc++.h>
using namespace std;

class fenwick2D {
private:
    vector<vector<int>> tree;
    int get(int x, int y);
public:
    fenwick2D(int n, int m);
    void update(int x, int y, int val);
    int query(int x1, int y1, int x2, int y2); // x2, y2 > x1, y1
    void clear();
};

#include "fenwick2D.cpp"

#endif
