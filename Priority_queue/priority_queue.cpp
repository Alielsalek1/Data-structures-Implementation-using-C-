#include "priority_queue.h"

template<typename T>
void PQ<T>::clear() {
    data.clear();
}
template<typename T>
int PQ<T>::size() {
    return data.size();
}
template<typename T>
bool PQ<T>::empty() {
    return data.empty();
}
template<typename T>
T PQ<T>::top() {
    return data[0];
}
template<typename T>
void PQ<T>::swim_up(int ind) {
    // swap the element with its parent until it is in the right position in the heap
    while (ind != 0) {
        if ((ind & 1) && data[(ind - 1) / 2] < data[ind]) { // left child
            swap(data[ind], data[(ind - 1) / 2]);
            ind = (ind - 1) / 2;
        }
        else if (ind % 2 == 0 && data[(ind - 2) / 2] < data[ind]) { // right child
            swap(data[ind], data[(ind - 2) / 2]);
            ind = (ind - 2) / 2;
        }
        else
            break;
    }
}
template<typename T>
void PQ<T>::swim_down(int ind) {
    // Prioritizing the left heap to maintain the complete binary tree structure in case of equality of both children
    while (2 * ind + 1 < data.size()) {
        // break in case the node is in the right position
        if (data[ind] >= data[2 * ind + 1] && (2 * ind + 2 < data.size() && data[ind] >= data[2 * ind + 2]))
            break;
        if (2 * ind + 2 < data.size() && data[2 * ind + 2] > data[2 * ind + 1]) { // right child
            swap(data[ind], data[2 * ind + 2]);
            ind = 2 * ind + 2;
        } else { // left child
            swap(data[ind], data[2 * ind + 1]);
            ind = 2 * ind + 1;
        }
    }
}
template<typename T>
void PQ<T>::insert(T val) {
    // pushing the new element to the end of the array, then using "swim_up" we put it in the right position in the heap
    data.push_back(val);
    swim_up(data.size() - 1);
}
template<typename T>
void PQ<T>::poll() {
    // swapping the element in the root with the last element,
    // then using "swim_down" we put the old node in the right position in the heap
    swap(data[0], data[data.size() - 1]);
    data.pop_back();
    swim_down(0);
}
