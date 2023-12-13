#include "Doublist.h"
template <typename T>
Doublist<T>::~Doublist() {
    // Implement the destructor
}
template <typename T>
void Doublist<T>::insert_front(T val) {
    Node<T>* new_node = new Node<T>(val);
    if (head == nullptr) {
        // if the list is empty, assign the head and the tail to the new node
        this->head = new_node;
        this->tail = new_node;
    } else {
        // updating the front of the new_node and the head
        new_node->front = this->head;
        this->head->back = new_node;
        this->head = new_node;
    }
    size++;
}
template <typename T>
void Doublist<T>::insert_back(T val) {
    Node<T>* new_node = new Node<T>(val);
    if (head == nullptr) {
        // if the list is empty, assign the head and the tail to the new node
        this->head = new_node;
        this->tail = new_node;
    }
    else {
        // updating the front and back of the nodes
        new_node->back = this->tail;
        this->tail->front = new_node;
        this->tail = new_node;
    }
    size++;
}
template <typename T>
void Doublist<T>::pop_back() {
    if (!size) throw runtime_error("cannot pop from and empty list");
    if (size == 1) {
        // case of only 1 Node
        delete head;
        head = nullptr, tail = nullptr;
    } else {
        Node<T>* new_tail = this->tail->back;
        delete this->tail; // remove the current tail
        // assign tail to its previous node and assign its front linker to NULL
        this->tail = new_tail;
        this->tail->front = nullptr;
    }
    size--;
}
template <typename T>
void Doublist<T>::pop_front() {
    if (!size) throw runtime_error("cannot pop from and empty list");
    if (size == 1) {
        // case of only 1 node
        delete head;
        head = nullptr, tail = nullptr;
    } else {
        Node<T>* new_head = this->head->front;
        delete this->head; // remove the current head
        // assigning the head its next node and updating its back to nullptr
        this->head = new_head;
        this->head->back = nullptr;
    }
    size--;
}
template <typename T>
void Doublist<T>::insert_at(T val, int pos) {
    // Implement the insert_at function
}

template <typename T>
void Doublist<T>::remove_at(int pos) {
    // Implement the remove_at function
}

template <typename T>
void Doublist<T>::clear() {

}

template <typename T>
int Doublist<T>::length() {
    return size;
}
template <typename T>
bool Doublist<T>::empty() {
    return !size;
}

template <typename T>
void Doublist<T>::reverse() {
    // Implement the reverse function
}

template <typename T>
Doublist<T>& Doublist<T>::operator=(Doublist<T> &other) {
    // Implement the assignment operator
}

template <typename T>
T& Doublist<T>::Iterator::operator*() {
    // Implement the Iterator's dereference operator
}

template <typename T>
typename Doublist<T>::Iterator& Doublist<T>::Iterator::operator++() {
    // Implement the Iterator's prefix increment operator
}

template <typename T>
bool Doublist<T>::Iterator::operator!=(const Iterator &other) {
    // Implement the Iterator's inequality operator
}

template <typename T>
typename Doublist<T>::Iterator Doublist<T>::begin() {
    // Implement the begin function
}

template <typename T>
typename Doublist<T>::Iterator Doublist<T>::end() {
    // Implement the end function
}