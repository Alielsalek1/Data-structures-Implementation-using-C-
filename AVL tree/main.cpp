#include "AVL.cpp"
using namespace std;

int main() {
    AVL<int> a;
    a.insert(4);
    a.insert(2);
    a.insert(5);
    a.insert(1);
    a.insert(6);
    a.insert(0);
    a.remove(5);
    for (auto i : a) {
        cout << i << " ";
    }
    return 0;
}
