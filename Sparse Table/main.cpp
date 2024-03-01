#include "SparseTable.h"

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    SparseTable<int> st(v, [](int a, int b) { return min(a, b); });

    for (int i = 0; i < v.size(); ++i) {
        for (int j = i; j < v.size(); ++j) {
            cout << i << " " << j << ": " << st.query(i, j) << "\n";
        }
    }
    return 0;
}
