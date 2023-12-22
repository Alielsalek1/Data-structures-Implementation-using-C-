#include "Doublist.h"

// Basic Functions
template <typename T>
Doublist<T>::~Doublist() {
    this->clear();
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
    if (pos > this->length() || pos < 0) throw runtime_error("Cannot insert at this position");
    if (pos == 0) return void(this->insert_front(val));
    if (pos == this->length()) return void(this->insert_back(val));
    // iterating with 2 iterators till position and inserting the Node
    pos--;
    Node<T>* new_node = new Node<T>(val);
    Node<T>* itr1 = this->head;
    Node<T>* itr2 = this->head->front;
    while (pos--) itr1 = itr1->front, itr2 = itr2->front;
    // inserting the Node and updating the front of the first and back of the second
    itr1->front = new_node;
    itr2->back = new_node;
    // assigning the front and back of the new node
    new_node->back = itr1, new_node->front = itr2;
    this->size++;
}
template <typename T>
void Doublist<T>::remove_at(int pos) {
    if (pos >= this->length() || pos < 0) throw runtime_error("Cannot insert at this position");
    if (pos == 0) return void(this->pop_front());
    else if (pos == this->length() - 1) return void(this->pop_back());
    // we will 2 iterators 1 is the back of the node and the other one is its front
    pos--;
    Node<T>* itr1 = this->head;
    Node<T>* itr2 = this->head->front->front;
    while (pos--) itr1 = itr1->front, itr2 = itr2->front;
    // deleting the desired node and assigning it to nullptr
    delete itr1->front;
    itr1->front = nullptr;
    // updating the iterators pointers
    itr1->front = itr2;
    itr2->back = itr1;
    this->size--;
}
template <typename T>
void Doublist<T>::clear() {
    Node<T>* itr = this->head;
    while (itr != nullptr) {
        Node<T>* rem = itr;
        itr = itr->front;
        delete rem;
    }
    this->size = 0;
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
    Node<T>* itr = this->head;
    while (itr != nullptr) {
        // iterating through the list and swapping the front and the back
        swap(itr->back, itr->front);
        itr = itr->back;
    }
    // also swapping the head and the tail as we start from the head
    swap(head, tail);
}

// Iterators
template <typename T>
T& Doublist<T>::Iterator::operator*() {
    return this->curr->data;
}
template <typename T>
typename Doublist<T>::Iterator& Doublist<T>::Iterator::operator++() {
    this->curr = this->curr->front;
    return *this;
}
template <typename T>
bool Doublist<T>::Iterator::operator!=(const Iterator &other) {
    return(this->curr != other.curr);
}
template <typename T>
typename Doublist<T>::Iterator Doublist<T>::begin() {
    return Iterator(head);
}
template <typename T>
typename Doublist<T>::Iterator Doublist<T>::end() {
    return Iterator(nullptr);
}