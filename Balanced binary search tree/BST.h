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
    int num_nodes = 0;
    // helper functions
    Node<T> *get_parent(T val);
    Node<T> *get_left_most(Node<T>* curr);
    void remove_right(Node<T> *&par, Node<T> *&child, T val);
    void remove_left(Node<T> *&par, Node<T> *&child, T val);
    void remove_no_children(Node<T> *&par, Node<T> *&child, T val);
    void remove_with_children(Node<T> *&curr);
public:
    // Basic functions
    void insert(T val);
    void remove(T val);
    bool find(T val);
    int size();
    // Iterators
    class Iterator {
    private:
        /* to iterate on a Binary Tree, We get the desired type of traversal
           then we put all values in a deque then manage the iterators with it
           overloading the (++, *, !=) Basics needed for iteration */
        deque<T> nodes;
        function<void(BST<T>&, Node<T>*, deque<T>&)> traversal_function;
        BST<T>& bst;  // Used a reference to the BST
    public:
        Iterator(BST<T>& bst, function<void(BST<T>&, Node<T>*, deque<T>&)> func);
        T& operator*();
        Iterator& operator++();
        bool operator!=(const Iterator& other);
    };
    // overloading begin and end
    Iterator begin(function<void(BST<T>&, Node<T>*, deque<T>&)> traversal_function = traversal_in_order);
    Iterator end();
    // all types of traversals
    static void traversal_in_order(BST<T>& bst, Node<T>* curr, deque<T>& nodes);
    static void traversal_pre_order(BST<T>& bst, Node<T>* curr, deque<T>& nodes);
    static void traversal_post_order(BST<T>& bst, Node<T>* curr, deque<T>& nodes);
    static void traversal_level_order(BST<T>& bst, Node<T>* curr, deque<T>& nodes);
    static void traversal_empty(BST<T>& bst, Node<T>* curr, deque<T>& nodes) {}
};

#endif
