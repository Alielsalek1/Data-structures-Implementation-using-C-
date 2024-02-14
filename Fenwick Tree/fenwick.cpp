#include "fenwick.h"

fenwick::fenwick(int n) {
    tree.resize(n + 1); //fenwick tree must be one based
}
int fenwick::get(int pos) {
    int sum = 0;
    //the update in the for loop removes the least significant bit in the binary representation
    for (; pos; pos -= (pos & -pos))
        sum += tree[pos];
    return sum;
}
int fenwick::query(int l, int r) {
    if (l > r) //ensuring the l value is the smaller one
        swap(l, r);
    if (l < 0 || r >= tree.size()) //ensuring values are in range of the vector
        throw runtime_error("query out of bounds");
    l++, r++; //fenwick tree must be one based
    return get(r) - get(l - 1);
}
void fenwick::update(int pos, int val) {
    int diff = val - query(pos, pos); //changing the value at position 'pos'
    pos++;
    //updating all prefixes that contain pos by constantly adding the lease significant bit
    for (; pos < tree.size(); pos += (pos & -pos))
        tree[pos] += diff;
}
void fenwick::clear() {
    std::fill(tree.begin(), tree.end(), 0);
}
