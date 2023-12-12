#include "BST.cpp"
using namespace std;

int main() {
    BST<int> bst;
    bst.insert(3);
    bst.insert(2);
    bst.insert(1);
    bst.insert(5);
    bst.insert(10);
    bst.insert(7);
    bst.insert(20);
    bst.insert(25);

    BST<int>::Iterator it = bst.begin(BST<int>::traversal_pre_order);

    // Iterate over the BST using the iterator
    while (it != bst.end()) {
        cout << *it << " ";
        ++it;
    }
    return 0;
}
