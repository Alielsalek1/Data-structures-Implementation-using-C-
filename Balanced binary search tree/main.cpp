#include <bits/stdc++.h>
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
    bst.remove(10);

    return 0;
}
