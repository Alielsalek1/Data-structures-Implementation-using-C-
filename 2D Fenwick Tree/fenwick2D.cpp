#include "fenwick2D.h"

// Make sure to check the fenwick tree before checking out this
// it is the same logic but applied on a 2D grid

fenwick2D::fenwick2D(int n, int m) {
    tree.resize(n + 1);
    for (auto &i : tree)
        i.resize(m + 1);
}
int fenwick2D::get(int x, int y) {
    int sum = 0;
    for (; x; x -= (x & -x))
        for (int i = y; i; i -= (i & -i))
            sum += tree[x][i];
    return sum;
}
void fenwick2D::update(int x, int y, int val) {
    int diff = val - query(x, y, x, y);
    x++, y++;
    for (; x < tree.size(); x += (x & -x))
        for (int i = y; i < tree[0].size(); i += (i & -i))
            tree[x][i] += diff;
}
int fenwick2D::query(int x1, int y1, int x2, int y2) {
    x1++, y1++, x2++, y2++;
    return get(x2, y2) - get(x2, y1 - 1) - get(x1 - 1, y2) + get(x1 - 1, y1 - 1);
}
void fenwick2D::clear() {
    for (auto &i : tree) fill(i.begin(), i.end(), 0);
}