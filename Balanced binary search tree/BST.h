#ifndef BALANCED_BINARY_SEARCH_TREE_BST_H
#define BALANCED_BINARY_SEARCH_TREE_BST_H

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BST {
private:
    template<typename X>
    class Node {
    public:
        X val;
        Node *left = nullptr; //Smaller
        Node *right = nullptr; //Greater
        Node(X val) : val(val) {}
    };
    Node<T> *root = nullptr;
    Node<T> *get_parent(T val);
    Node<T> *get_left_most(Node<T>* curr);
    void remove_right(Node<T> *&par, Node<T> *&child, T val);
    void remove_left(Node<T> *&par, Node<T> *&child, T val);
    void remove_no_children(Node<T> *&par, Node<T> *&child, T val);
    void remove_with_children(Node<T> *&curr);
public:
    void insert(T val);
    void remove(T val);
    bool find(T val);
//    void preorder_traversal();
//    void inorder_traversal();
//    void postorder_traversal();
//    void levelorder_traversal();
//    class Iterator {
//    private:
//        Node<T> *current;
//    public:
//        Iterator(Node<T>* start) : current(start) {}
//        T& operator*();
//        Iterator operator++();
//        bool operator !=(const Iterator& other) const;
//    };
//    Iterator begin() {return Iterator(root);}
//    Iterator end() {return Iterator(nullptr);}
};

#endif
