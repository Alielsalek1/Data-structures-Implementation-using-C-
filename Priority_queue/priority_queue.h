#ifndef PRIORITY_QUEUES_PRIORITY_QUEUE_H
#define PRIORITY_QUEUES_PRIORITY_QUEUE_H

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class PQ { // MaxHeap (Binary Heap)
private:
    vector<T> data; // equivalent to dynamic array
    void swim_up(int ind);
    void swim_down(int ind);
public:
    void insert(T val);
    void poll();
    int size();
    void clear();
    bool empty();
    T top();
};

#include "priority_queue.cpp"

#endif
