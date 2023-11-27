#ifndef SINGLY_LINKED_LIST_SINGLIST_H
#define SINGLY_LINKED_LIST_SINGLIST_H
#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Node {
public:
    T data;
    Node *link;
    Node(T data, Node<T>* link = nullptr) : data(data), link(link) {}
};

template<typename T>
class Singlist {
private:
    Node<T>* head = nullptr;
public:
    Singlist();
    ~Singlist();
    void insert_front(T data);
    void insert_back(T data);
    void pop_back();
    void pop_front();
    void remove(T req);
    int length();
    bool empty();
    void reverse();
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