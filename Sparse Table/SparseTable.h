#ifndef SPARSE_TABLE_SPARSETABLE_H
#define SPARSE_TABLE_SPARSETABLE_H

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class SparseTable {
private:
    vector<vector<T>> table;
    function<T(T, T)> operation;
    void build(const vector<T>& v);
public:
    int size;
    int LG; // highest power of 2 smaller than the size of the table
    SparseTable(const vector<T>& v, const function<T(T, T)>& op);
    T query(int l, int r);
};

#include "SparseTable.cpp"

#endif //SPARSE_TABLE_SPARSETABLE_H
