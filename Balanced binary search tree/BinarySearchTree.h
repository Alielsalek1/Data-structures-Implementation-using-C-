#ifndef BALANCED_BINARY_SEARCH_TREE_BINARYSEARCHTREE_H
#define BALANCED_BINARY_SEARCH_TREE_BINARYSEARCHTREE_H

template <typename T>
class BinarySearchTree {
private:
    template<typename X>
    class Node {
        X val;
        Node *left = nullptr; //Smaller
        Node *right = nullptr; //Greater
        Node(X val) : val(val) {}
    };
    Node<T> *root;
    int size;
public:
    BinarySearchTree() {};
    void insert(T val);
    void remove(T val);
    void preorder_traversal();
    void inorder_traversal();
    void postorder_traversal();
    void levelorder_traversal();
    bool has(T val);
    class Iterator {
    private:
        Node<T> *current;
    public:
        Iterator(Node<T>* start) : current(start) {}
        T& operator*();
        Iterator operator++();
        bool operator !=(const Iterator& other) const;
    };
    Iterator begin() {return Iterator(root);}
    Iterator end() {return Iterator(nullptr);}
};

#endif
