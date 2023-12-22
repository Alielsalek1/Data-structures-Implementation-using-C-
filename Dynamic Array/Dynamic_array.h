#include <bits/stdc++.h>
using namespace std;

#ifndef DYNAMIC_ARRAY_DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_DYNAMIC_ARRAY_H

template<typename T>
class Dynamic_array {
private:
    T* data;
    int all_size;
    int last = 0;
    void extend_array();
public:
    Dynamic_array(int num_elements = 100);
    ~Dynamic_array();
    void clear();
    void push_back(T val);
    void pop_back();
    void reverse();
    T back();
    bool empty();
    int size();
    int capacity();
    T& operator [](int index);
};

#endif
