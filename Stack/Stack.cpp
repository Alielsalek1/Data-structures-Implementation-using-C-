#include "Stack.h"

template<typename T>
void Stack<T>::push(T val) {
    data.push_front(val);
    num_elements++;
}
template<typename T>
void Stack<T>::pop() {
    if (!num_elements) throw runtime_error("cannot delete from an empty stack");
    data.pop_front();
    num_elements--;
}
template<typename T>
T Stack<T>::top() {
    return data.front();
}
template<typename T>
bool Stack<T>::empty() {
    return !num_elements;
}
template<typename T>
int Stack<T>::size() {
    return num_elements;
}