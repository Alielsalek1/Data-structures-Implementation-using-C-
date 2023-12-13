#ifndef DOUBLY_LINKED_LIST_DOUBLIST_H
#define DOUBLY_LINKED_LIST_DOUBLIST_H

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Doublist {
private:
    template <typename X>
    class Node {
    public:
        T data;
        Node *back = nullptr;
        Node *front = nullptr;
        Node(T data) : data(data), back(nullptr), front(nullptr) {}
        Node(T data, Node<X> *back, Node<X> *front) : data(data), back(back), front(front) {}
    };
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    int size = 0;
public:
    ~Doublist();
    void insert_front(T val);
    void insert_back(T val);
    void pop_back();
    void pop_front();
    void insert_at(T val, int pos);
    void remove_at(int pos);
    void clear();
    int length();
    bool empty();
    void reverse();
    Doublist& operator=(Doublist<T> &other);
    class Iterator {
    private:
        Node<T>* curr;
    public:
        Iterator(Node<T>* start) : curr(start) {}
        T& operator*();
        Iterator& operator++();
        bool operator!=(const Iterator &other);
    };
    Iterator begin();
    Iterator end();
};

#endif
