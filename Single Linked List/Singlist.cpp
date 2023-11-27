#include "Singlist.h"

template <typename T>
Singlist<T>::Singlist() {
    //constructing the list with the head equals to NULL as a significance for an empty list
    this->head = NULL;
}
template <typename T>
bool Singlist<T>::empty() {
    // if the head is NULL this indicates that there are no data and the list is empty.
    return (this->head == NULL);
}
template <typename T>
int Singlist<T>::length() {
    // iterating on the list and adding to the counter every time we find an element
    int cnt = 0;
    for (const auto &i : *this) cnt++;
    return cnt;
}
template <typename T>
void Singlist<T>::insert_front(T data) {
    // if the head is NULL it means that the list is empty.
    if (this->head == NULL)
        this->head = new Node<T>(data);
    else {
        /* else we are constructing a new node, making its link the head,
       so it links to the old head node and making it the new head */
        Node<T>* new_node = new Node<T>(data, this->head);
        this->head = new_node;
    }
}
template <typename T>
void Singlist<T>::insert_back(T data) {
    Node<T>* new_node = new Node<T>(data); // the new node to add
    // if the head is NULL, which means the list is empty just add the node without linkers
    if (this->head == NULL)
        this->head = new_node;
    else {
        // iterate till you reach the end node and modify its link to the new node
        Node<T>* end = this->head;
        while (end->link != NULL)
            end = end->link;
        end->link = new_node;
    }
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
