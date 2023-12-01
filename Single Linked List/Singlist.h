#ifndef SINGLY_LINKED_LIST_SINGLIST_H
#define SINGLY_LINKED_LIST_SINGLIST_H
#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Singlist {
private:
    template <typename X>
    class Node {
    public:
        T data;
        Node *link;
        Node(T data, Node<X>* link = nullptr) : data(data), link(link) {}
    };
    Node<T>* head = nullptr;
public:
    Singlist();
    ~Singlist();
    void insert_front(T data);
    void insert_back(T data);
    void pop_back();
    void pop_front();
    void insert_at(T data, int position);
    void remove_at(int position);
    void clear();
    int length();
    bool empty();
    void reverse();
    Singlist& operator=(Singlist<T> &other);
    class Iterator {
    private:
        Node<T>* current;
    public:
        Iterator(Node<T>* start) : current(start) {}
        T& operator*();
        Iterator& operator++();
        bool operator!=(const Iterator& other) const;
    };
    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }
};

#endif