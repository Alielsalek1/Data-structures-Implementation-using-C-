#include "BST.cpp"
using namespace std;

int main() {
    BST<int> bst;
    bst.insert(3);
    bst.insert(3);
    bst.insert(1);
    bst.insert(5);
    bst.insert(10);
    bst.insert(7);
    bst.insert(20);
    bst.insert(25);
    bst.remove(25);
    cout << bst.size() << "\n";
    BST<int>::Iterator it = bst.begin();

    // Iterate over the BST using the iterator
    while (it != bst.end()) {
        cout << *it << " ";
        ++it;
    }
    cout << "\n";
    for (auto i : bst) {
        cout << i << " ";
    }
    return 0;
}
