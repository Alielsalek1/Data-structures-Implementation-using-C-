#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Queue {
private:
    list<T> data;
    int num_elements = 0;
public:
    void enqueue(T val);
    void dequeue();
    T front();
    bool empty();
    int size();
};

#include "Queue.cpp"

#endif
