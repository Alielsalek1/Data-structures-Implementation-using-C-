#ifndef SINGLY_LINKED_LIST_SINGLIST_H
#define SINGLY_LINKED_LIST_SINGLIST_H
#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Node {
private:
    T data;
    Node *link;
public:
    Node(T data, Node<T>* link = NULL);
};

template<typename T>
class Singlist {
private:
    Node<T>* head = NULL;
public:
    Singlist() {};
    ~Singlist();
    void insert_front(T data);
    void insert_back(T data);
    void pop_back();
    void pop_front();
    void remove(T req);
    int length();
    bool empty();
    void reverse();
    Node<T> back();
    Node<T> front();
    bool count();
};

#endif