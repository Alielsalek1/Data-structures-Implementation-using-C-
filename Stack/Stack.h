#ifndef STACK_STACK_H
#define STACK_STACK_H

#include <list>
#include <iostream>
using namespace std;

template<typename T>
class Stack {
private:
    list<T> data;
    int num_elements = 0;
public:
    T top();
    void push(T val);
    void pop();
    bool empty();
    int size();
};

#include "Stack.cpp"

#endif
