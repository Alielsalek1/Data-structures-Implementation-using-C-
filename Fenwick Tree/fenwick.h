#ifndef FENWICK_TREE_FENWICK_H
#define FENWICK_TREE_FENWICK_H

#include <bits/stdc++.h>
using namespace std;

class fenwick {
private:
    vector<int> tree;
    int get(int pos);
public:
    fenwick(int);
    void update(int pos, int val);
    int query(int l, int r);
    void clear();
};

#include "fenwick.cpp"

#endif
