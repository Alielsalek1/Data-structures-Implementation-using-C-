#include "Queue.h"

template <typename T>
void Queue<T>::enqueue(T val) {
    data.push_back(val);
    num_elements++;
}
template <typename T>
void Queue<T>::dequeue() {
    data.pop_front();
    num_elements--;
}
template <typename T>
T Queue<T>::front() {
    return data.front();
}
template <typename T>
bool Queue<T>::empty() {
    return !num_elements;
}
template <typename T>
int Queue<T>::size() {
    return num_elements;
}
