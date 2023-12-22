#ifndef AVL_TREE_AVL_H
#define AVL_TREE_AVL_H

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class AVL {
private:
    template<typename X>
    class Node {
    public:
        X val;
        int height = 0;
        int balance_factor = 0;
        Node *left = nullptr; //Smaller
        Node *right = nullptr; //Greater
        Node(X val) : val(val) {}
    };
    Node<T> *root = nullptr;
    int num_nodes = 0;
    // helper functions
    Node<T> *get_parent(T val);
    Node<T>* insert(Node<T> *curr, T val);
    Node<T> *get_left_most(Node<T>* curr);
    void remove_right(Node<T> *&par, Node<T> *&child, T val);
    void remove_left(Node<T> *&par, Node<T> *&child, T val);
    void remove_no_children(Node<T> *&par, Node<T> *&child, T val);
    void remove_with_children(Node<T> *&curr);
    void remove(T val, Node<T> *par, Node<T> *child);
    void update(Node<T> *&curr);
    Node<T>* balance(Node<T> *&curr);
    Node<T>* left_left(Node<T> *&curr);
    Node<T>* right_right(Node<T> *&curr);
    Node<T>* right_left(Node<T> *&curr);
    Node<T>* left_right(Node<T> *&curr);
    Node<T>* left_rotation(Node<T> *curr);
    Node<T>* right_rotation(Node<T> *curr);
public:
    ~AVL();
    // Basic functions
    void insert(T val);
    void remove(T val);
    bool find(T val);
    int size();
    void clear();
    // Iterators
    class Iterator {
    private:
        /* to iterate on a Binary Tree, We get the desired type of traversal
           then we put all values in a deque then manage the iterators with it
           overloading the (++, *, !=) Basics needed for iteration */
        deque<T> nodes;
        function<void(AVL<T>&, Node<T>*, deque<T>&)> traversal_function;
        AVL<T>& bst;  // Used a reference to the BST
    public:
        Iterator(AVL<T>& bst, function<void(AVL<T>&, Node<T>*, deque<T>&)> func);
        T& operator*();
        Iterator& operator++();
        bool operator!=(const Iterator& other);
    };
    Iterator begin(function<void(AVL<T>&, Node<T>*, deque<T>&)> traversal_function = traversal_in_order);
    Iterator end();
    // all types of traversals
    static void traversal_in_order(AVL<T>& bst, Node<T>* curr, deque<T>& nodes);
    static void traversal_pre_order(AVL<T>& bst, Node<T>* curr, deque<T>& nodes);
    static void traversal_post_order(AVL<T>& bst, Node<T>* curr, deque<T>& nodes);
    static void traversal_level_order(AVL<T>& bst, Node<T>* curr, deque<T>& nodes);
    static void traversal_empty(AVL<T>& bst, Node<T>* curr, deque<T>& nodes) {}
};
#endif