#include "BST.h"

template<typename T>
typename BST<T>::template Node<T> *BST<T>::get_parent(T val) {
    // We cannot get a parent for the root node
    if (val == this->root->val || this->root == nullptr) return nullptr;
    /* as we iterate if we found a child which is equal to the value, we return its parent
       else if the child is a nullptr we return the parent for insert */
    Node<T> *itr = this->root;
    while (true) {
        if (val > itr->val && itr->right != nullptr) {
            if (itr->right->val == val) return itr;
            itr = itr->right;
        }
        else if (val < itr->val && itr->left != nullptr) {
            if (itr->left->val == val) return itr;
            itr = itr->left;
        }
        else return itr;
    }
}
template<typename T>
bool BST<T>::find(T val) {
    // if the parent has a child with the required value, return true
    Node<T> *par = this->get_parent(val);
    // if a node has no parent, this means it might be the root or nonexistent
    if (par == nullptr) return (root->val == val);
    return (par->left != nullptr && par->left->val == val || par->right->val == val);
}
template<typename T>
void BST<T>::insert(T val) {
    Node<T> *new_node = new Node(val);
    // if there is no root, assign the new node to be the root
    if (this->root == nullptr) return void(this->root = new_node);
    // as we do not allow duplicates, we just ignore it
    Node<T> *par = this->get_parent(val);
    if (val > par->val) par->right = new_node;
    else if (val < par->val) par->left = new_node;
}
template<typename T>
typename BST<T>::template Node<T> *BST<T>::get_left_most(Node<T> *curr) {
    Node<T>* itr = curr;
    while (itr->left != nullptr) itr = itr->left;
    return itr;
}
template<typename T>
void BST<T>::remove_right(Node<T> *&par, Node<T> *&child, T val) {
    // special case if we are deleting the root node
    if (par == nullptr) this->root = child->right;
    else {
        /* in case of only having a right node, we assign a new successor to the parent instead of child
       the new one will be the child->right, and we delete the leftover child */
        if (par->right != nullptr && par->right->val == val) par->right = child->right;
        else par->left = child->right;
    }
    delete child;
}
template<typename T>
void BST<T>::remove_left(Node<T> *&par, Node<T> *&child, T val) {
    if (par == nullptr) this->root = child->left;
    else {
        /* if we only have a left node, we assign a new successor to the parent instead of child
       the new one will be the child->left, and we delete the leftover child */
        if (par->right != nullptr && par->right->val == val) par->right = child->left;
        else par->left = child->left;
    }
    delete child;
}
template<typename T>
void BST<T>::remove_no_children(Node<T> *&par, Node<T> *&child, T val) {
    // if the node is a leaf node, delete it and assign the parent root to nullptr
    if (par->right->val == val) par->right = nullptr;
    else par->left = nullptr;
    delete child;
}
template<typename T>
void BST<T>::remove_with_children(Node<T> *&curr) {
    /* in case of having both right and left in your subtree,
       we go to the right subtree and dig as far as possible to the left
       as this method satisfies the BST invariant
       as this node is greater than the left one and smaller than the right one of the original
       we swap the two nodes and then call the method which removes nodes when you only have a right subtree */
    Node<T> *left_most = get_left_most(curr->right);
    Node<T> *left_parent = get_parent(left_most->val);
    swap(left_most->val, curr->val);
    if (left_most->right != nullptr)
        this->remove_right(left_parent, left_most, left_most->val);
    else this->remove_no_children(left_parent, left_most, left_most->val);
}
template<typename T>
void BST<T>::remove(T val) {
    // if the node isn't there, then there is no operation to make
    if (!this->find(val)) return;
    Node<T> *par = this->get_parent(val);
    Node<T> *child;
    // if the parent is a nullptr, this means the current node is the root node
    if (par != nullptr) child = (par->left != nullptr && val == par->left->val ? par->left : par->right);
    else child = root;

    if (child->left == nullptr && child->right == nullptr)
        remove_no_children(par, child, val);
    else if (child->left == nullptr)
        remove_right(par, child, val);
    else if (child->right == nullptr)
        remove_left(par, child, val);
    else
        remove_with_children(child);
}

