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
        Iterator(BST<T>& bst, function<void(BST<T>&, Node<T>*, deque<T>&)> func) : bst(bst), traversal_function(func) {
            if (bst.root != nullptr) traversal_function(bst, bst.root, nodes);
        }
        T& operator*() {
            return nodes.front();
        }
        Iterator& operator++() {
            if (!nodes.empty()) nodes.pop_front();
            return *this;
        }
        bool operator!=(const Iterator& other) const {
            return !nodes.empty() || !other.nodes.empty();
        }
    };
    Iterator begin(function<void(BST<T>&, Node<T>*, deque<T>&)> traversal_function) {
        return Iterator(*this, traversal_function);
    }
    Iterator end() {
        return Iterator(*this, traversal_empty);
    }
    static void traversal_in_order(BST<T>& bst, Node<T>* curr, deque<T>& nodes) {
        if (curr == nullptr) return;
        traversal_in_order(bst, curr->left, nodes);
        nodes.push_back(curr->val);
        traversal_in_order(bst, curr->right, nodes);
    }
    static void traversal_pre_order(BST<T>& bst, Node<T>* curr, deque<T>& nodes) {
        if (curr == nullptr) return;
        nodes.push_back(curr->val);
        traversal_pre_order(bst, curr->left, nodes);
        traversal_pre_order(bst, curr->right, nodes);
    }
    static void traversal_post_order(BST<T>& bst, Node<T>* curr, deque<T>& nodes) {
        if (curr == nullptr) return;
        traversal_post_order(bst, curr->left, nodes);
        traversal_post_order(bst, curr->right, nodes);
        nodes.push_back(curr->val);
    }
    static void traversal_level_order(BST<T>& bst, Node<T>* curr, deque<T>& nodes) {
        if (curr == nullptr) return;
        queue<Node<T>*> q;
        q.push(curr);
        while (!q.empty()) {
            Node<T>* front = q.front();
            q.pop();
            nodes.push_back(front->val);
            if (front->left != nullptr) {
                q.push(front->left);
            }
            if (front->right != nullptr) q.push(front->right);
        }
    }
    static void traversal_empty(BST<T>& bst, Node<T>* curr, deque<T>& nodes) {
        // Do nothing for an empty traversal
    }
};

#endif
