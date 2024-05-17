#include "SegTree.h"

template <typename T>
SegTree<T>::SegTree(function<T(T, T)> op, T IDENTITY, vector<T> v) : combine(op), IDENTITY(IDENTITY) {
    /* if oldn is not a perfect power of 2, apply ceil to it
       as the segment tree must be a perfect power of 2 */
    int oldn = v.size();
    if (__builtin_popcount(oldn) != 1) n = 1 << (__lg(oldn) + 1);
    else n = oldn;

    /* resizing a tree to be a prefect power of 2
       we multiply n by 2, so we get the actual size for the binary tree
       EX: n = 8, our size will be 15
       As we divide the level by 2 as we go upwards */
    tree.resize(n << 1, IDENTITY);

    // assigning base elements to the tree
    for (int i = 0; i < oldn; ++i) tree[i + n] = v[i];
    // filling the fillers with IDENTITY
    for (int i = oldn; i < n; ++i) tree[i + n] = IDENTITY;
    // the 2 children are 2 * index and 2 * index + 1 for our 1-based binary tree
    for (int i = n - 1; ~i; --i) tree[i] = combine(tree[i << 1], tree[i << 1 | 1]);
}

template <typename T>
void SegTree<T>::update(int point, T val) {
    update(point, val, 1, 0, n - 1);
}

template <typename T>
T SegTree<T>::query(int ql, int qr) {
    return query(ql, qr, 1, 0, this->n - 1);
}

template <typename T>
void SegTree<T>::update(int point, T val, int ind, int sl, int sr) {
    /* point: the index which we wish to update (0-based)
       val: the new value to assign to the node
       ind: our index in the binary tree
       sl and sr: the ranges we are responsible for at the node */

    // reached the leaf node
    if (sl == point && sr == point) return void(tree[ind] = val);

    // outside the range state
    if (point > sr || sl > point) return;

    // intersecting state
    int mid = (sl + sr) / 2;
    // go to the left and right children
    update(point, val, ind << 1, sl, mid);
    update(point, val, ind << 1 | 1, mid + 1, sr);

    // update after the end of the recursion
    tree[ind] = combine(tree[ind << 1], tree[ind << 1 | 1]);
}

template <typename T>
T SegTree<T>::query(int ql, int qr, int ind, int sl, int sr) {
    /* ql & qr: the range we want to query (0-based)
       val: the new value to assign to the node
       ind: our index in the binary tree
       sl and sr: the ranges we are responsible for at the node */

    // the segment is totally inside our range
    if (ql <= sl && sr <= qr)  return tree[ind];

    // the segment is outside the range
    if (ql > sr || sl > qr) return IDENTITY;

    // the segment intersects, so we go to both children
    int mid = (sl + sr) / 2;
    return combine(query(ql, qr, ind << 1, sl, mid), query(ql, qr, ind << 1 | 1, mid + 1, sr));
}