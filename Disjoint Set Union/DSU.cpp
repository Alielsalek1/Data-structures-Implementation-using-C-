#include "DSU.h"

template<typename T>
DSU<T>::DSU(int n) {
    par.resize(n + 1);
    rank.resize(n + 1, 0);
    iota(par.begin(), par.end(), 0); // filling the parent from 0 to 1
}
template<typename T>
T DSU<T>::find(T val) {
    // recursive function to get the parent of the desired node
    if (par[val] != val) par[val] = find(par[val]); // path compression heuristic
    return par[val];
}
template<typename T>
void DSU<T>::unite(T x, T y) {
    x = find(x); // assigning x to its parent
    y = find(y); // assigning y to its parent

    if (x == y) return; // if they both have the same parent

    // assigning the one with smaller rank (size) to the bigger one (rank heuristic)
    if (rank[y] > rank[x]) swap(x, y);
    rank[x] += rank[y];
    par[y] = x;
}
