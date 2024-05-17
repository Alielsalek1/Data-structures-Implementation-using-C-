#include "SegTree.h"

int main() {
    SegTree<int> tree([](int a, int b) { return min(a, b); }, INT_MAX, {1, 2, 3, 4, 5, 6});
    cout << tree.query(0, 1) << "\n";
    tree.update(0, 9);
    cout << tree.query(0, 3) << "\n";
    tree.query(0, 0);
    cout << tree.query(0, 0) << "\n";
    return 0;
}
