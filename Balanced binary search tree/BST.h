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
    class Iterator {
    private:
        deque<T> nodes;
        function<void(BST<T>&, Node<T>*, deque<T>&)> traversal_function;
        BST<T>& bst;  // Used a reference to the BST
    public:
        Iterator(BST<T>& bst, function<void(BST<T>&, Node<T>*, deque<T>&)> func);
        T& operator*();
        Iterator& operator++();
        bool operator!=(const Iterator& other);
    };
    Iterator begin(function<void(BST<T>&, Node<T>*, deque<T>&)> traversal_function = traversal_in_order);
    Iterator end();
    static void traversal_in_order(BST<T>& bst, Node<T>* curr, deque<T>& nodes);
    static void traversal_pre_order(BST<T>& bst, Node<T>* curr, deque<T>& nodes);
    static void traversal_post_order(BST<T>& bst, Node<T>* curr, deque<T>& nodes);
    static void traversal_level_order(BST<T>& bst, Node<T>* curr, deque<T>& nodes);
    static void traversal_empty(BST<T>& bst, Node<T>* curr, deque<T>& nodes) {}
};

#endif
