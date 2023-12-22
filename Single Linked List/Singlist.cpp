#include "Singlist.h"

template <typename T>
Singlist<T>::~Singlist() {
    this->clear();
}
template <typename T>
bool Singlist<T>::empty() {
    // if the head is nullptr, this indicates that there are no data and the list is empty.
    return (this->head == nullptr);
}
template <typename T>
int Singlist<T>::length() {
    return size;
}
template <typename T>
void Singlist<T>::clear() {
    if (this->head == nullptr) return;
    Node<T>* itr = this->head;
    while (itr != nullptr) {
        // deleting every node as we advance
        Node<T>* temp = itr;
        itr = itr->link;
        delete temp;
    }
    this->head = nullptr;
    size = 0;
}
template <typename T>
void Singlist<T>::insert_front(T data) {
    // if the head is nullptr it means that the list is empty.
    if (this->head == nullptr)
        this->head = new Node<T>(data);
    else {
        /* else we are constructing a new node, making its link the head,
       so it links to the old head node and making it the new head */
        Node<T>* new_node = new Node<T>(data, this->head);
        this->head = new_node;
    }
    size++;
}
template <typename T>
void Singlist<T>::insert_back(T data) {
    Node<T>* new_node = new Node<T>(data); // the new node to add
    // if the head is NULL, which means the list is empty just add the node without linkers
    if (this->head == nullptr)
        this->head = new_node;
    else {
        // iterate till you reach the end node and modify its link to the new node
        Node<T>* end = this->head;
        while (end->link != nullptr)
            end = end->link;
        end->link = new_node;
    }
    size++;
}
template <typename T>
void Singlist<T>::insert_at(T data, int position) {
    if (position > this->size || position < 0) throw runtime_error("cannot remove at this position");

    if (!position) return void(this->insert_front(data));
    /* iterating with 2 iterators, one lags the other by one
       until the itr reaches the required position */
    Node<T>* itr = this->head;
    Node<T>* prev = nullptr;
    while (itr != nullptr && position--) {
        prev = itr;
        itr = itr->link;
    }
    /* inserting the data between the prev and itr,
       updating the prev link and then the new_node link to point to the itr*/
    Node<T>* new_node = new Node<T>(data);
    prev->link = new_node;
    new_node->link = itr;
    size++;
}
template <typename T>
void Singlist<T>::remove_at(int position) {
    if (position >= this->size || position < 0) throw runtime_error("cannot remove at this position");
    // if we are deleting the first node, call pop_front
    if (!position) return void(this->pop_front());
    /* iterating with 2 iterators, one lags the other by one
       until the itr reaches the required position */
    Node<T>* itr = this->head;
    Node<T>* prev = nullptr;
    while (itr != nullptr && position--) {
        prev = itr;
        itr = itr->link;
    }
    /* updating the prev link and deleting the node */
    prev->link = itr->link;
    delete itr;
    size--;
}
template <typename T>
void Singlist<T>::pop_back() {
    if (this->head == nullptr) throw runtime_error("cannot delete from an empty list");
    /* iterate till you have 2 nodes the last and the last - 1
       now we assign the linker for the last - 1 to nullptr and delete the last */
    Node<T>* last = this->head;
    Node<T>* before_last = nullptr;
    while (last->link != nullptr) {
        before_last = last;
        last = last->link;
    }
    /* if you have only 1 node, then you delete it
       and assign the head to nullptr */
    if (last == this->head) {
        delete this->head;
        head = nullptr;
    } else {
        before_last->link = nullptr;
        delete last;
    }
    size--;
}
template <typename T>
void Singlist<T>::pop_front() {
    if (this->head == nullptr) throw runtime_error("cannot delete from an empty list");
    /* declare a new head which is the link of the head node
       then we delete the head, and we assign it to the new head a */
    Node<T>* new_head = this->head->link;
    delete this->head;
    this->head = new_head;
    size--;
}
template <typename T>
void Singlist<T>::reverse() {
    if (this->head == nullptr) throw runtime_error("cannot reverse an empty list");
    if (this->head->link != nullptr) {
        /* Having three iterators current_node, next_node, previous_node
           updating the next, reversing the link,
           then we assign previous_node to current_node and current_node to the next_node */
        Node<T>* prev = nullptr;
        Node<T>* next = this->head;
        Node<T>* curr = this->head;
        while (curr != nullptr) {
            next = next->link;
            curr->link = prev;
            prev = curr;
            curr = next;
        }
        this->head = prev;
    }
}
template <typename T>
Singlist<T>& Singlist<T>::operator=(Singlist<T> &other) {
    this->clear();
    // copy elements from the other list
    for (const auto &i : other)
        this->insert_back(i);
    return *this;
}
// overloading iterators to be able to loop on the list
/* in the context of iteration on the single linked list,
   we have to overload 3 operators:
   1- the '*' (dereference) as it dereferences the pointers to
   make it return the data I want to print in some class.
   2- the '++' (updater) as it is our updater from the current node to the next
   3- the '!=' (non-equality) as it serves to compare the current pointer
   to the .end() pointer to know when the loops break

   we also overloaded the .begin() and the .end() to know our start and end */
template <typename T>
T& Singlist<T>::Iterator::operator*() {
    return this->current->data;
}
template <typename T>
typename Singlist<T>::Iterator& Singlist<T>::Iterator::operator++() {
    // going to the next node by making the current node the link
    this->current = this->current->link;
    return *this;
}
template <typename T>
bool Singlist<T>::Iterator::operator!=(const Iterator& other) const{
    return this->current != other.current;
}
