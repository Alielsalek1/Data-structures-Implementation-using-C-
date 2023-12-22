#include "DSU.cpp"

int main() {
    DSU<int> dsu(10);
    dsu.unite(5, 10);
    cout << dsu.find(5) << " " << dsu.find(10);
    return 0;
}