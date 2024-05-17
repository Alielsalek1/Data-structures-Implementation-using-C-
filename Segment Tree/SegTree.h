#ifndef SEGMENT_TREE_SEGTREE_H
#define SEGMENT_TREE_SEGTREE_H

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class SegTree {
private:
    int n;
    T IDENTITY;
    vector<T> tree;
    function<T(T, T)> combine;
    void update(int point, T val, int ind, int sl, int sr);
    T query(int ql, int qr, int ind, int sl, int sr);
public:
    SegTree(function<T(T, T)> combine, T IDENTITY, vector<T> v);
    void update(int point, T val);
    T query(int ql, int qr);
};

#include "SegTree.cpp"

#endif