#include "AVL.h"

// Basic BST functions
template<typename T>
AVL<T>::~AVL() {
    this->clear();
}
template<typename T>
void AVL<T>::clear() {
    if (root == nullptr) return;
    // Traditional BFS Algorithm
    queue<Node<T>*> q;
    q.push(root);
    while (!q.empty()) {
        Node<T>* front = q.front();
        q.pop();
        if (front->left != nullptr) q.push(front->left);
        if (front->right != nullptr) q.push(front->right);
        delete front;
    }
    root = nullptr;
    num_nodes = 0;
}
template<typename T>
int AVL<T>::size() {
    return this->num_nodes;
}
template<typename T>
typename AVL<T>::template Node<T> *AVL<T>::get_parent(T val) {
    // We cannot get a parent for the root node
    if (this->root == nullptr || val == this->root->val) return nullptr;
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
bool AVL<T>::find(T val) {
    // if the parent has a child with the required value, return true
    Node<T> *par = this->get_parent(val);
    // if a node has no parent, this means it might be the root or nonexistent

    if (par == nullptr) return (root != nullptr && root->val == val);
    return ((par->left != nullptr && par->left->val == val) || (par->right != nullptr && par->right->val == val));
}

// Insertion
template<typename T>
typename AVL<T>::template Node<T>* AVL<T>::insert(Node<T>* curr, T val) {
    if (curr == nullptr) return new Node<T>(val);

    if (val > curr->val) curr->right = insert(curr->right, val);
    else curr->left = insert(curr->left, val);

    update(curr);
    return balance(curr);
}
template<typename T>
void AVL<T>::insert(T val) {
    // as we do not allow duplicates, we return if we found the value
    if (this->find(val)) return;
    this->num_nodes++;
    this->root = insert(this->root, val);
}

// Removal
template<typename T>
typename AVL<T>::template Node<T> *AVL<T>::get_left_most(Node<T> *curr) {
    Node<T>* itr = curr;
    while (itr->left != nullptr) itr = itr->left;
    return itr;
}
template<typename T>
void AVL<T>::remove_right(Node<T> *&par, Node<T> *&child, T val) {
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
void AVL<T>::remove_left(Node<T> *&par, Node<T> *&child, T val) {
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
void AVL<T>::remove_no_children(Node<T> *&par, Node<T> *&child, T val) {
    // if the node is a leaf node, delete it and assign the parent root to nullptr
    if (par->right->val == val) par->right = nullptr;
    else par->left = nullptr;
    delete child;
    child = nullptr;
}
template<typename T>
void AVL<T>::remove_with_children(Node<T> *&curr) {
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
template <typename T>
void AVL<T>::remove(T val, Node<T> *par, Node<T> *child) {
    if (val == child->val) {
        if (child->left == nullptr && child->right == nullptr) remove_no_children(par, child, val);
        else if (child->left == nullptr) remove_right(par, child, val);
        else if (child->right == nullptr) remove_left(par, child, val);
        else remove_with_children(child);
    } else {
        if (child->left != nullptr && val < child->val) remove(val, child, child->left);
        else remove(val, child, child->right);
        update(child);
        child = balance(child);
    }
}
template<typename T>
void AVL<T>::remove(T val) {
    // if the node isn't there, then there is no operation to make
    if (!this->find(val)) return;
    this->num_nodes--;
    this->remove(val, nullptr, this->root);
}

// AVL-tree balance
template<typename T>
typename AVL<T>::template Node<T>* AVL<T>::balance(Node<T>*& curr) {
    // determine the node is left heavy or right heavy & also, determine also for the child to see where to balance
    if (curr->balance_factor == -2) {
        if (curr->left->balance_factor < 0) return left_left(curr);
        else return left_right(curr);
    } else if (curr->balance_factor == 2) {
        if (curr->right->balance_factor < 0) return right_left(curr);
        else return right_right(curr);
    }
    return curr;
}
template<typename T>
typename AVL<T>::template Node<T>* AVL<T>::left_left(Node<T>*& curr) {
    return right_rotation(curr);
}
template<typename T>
typename AVL<T>::template Node<T>* AVL<T>::left_right(Node<T>*& curr) {
    curr->left = left_rotation(curr->left);
    return left_left(curr);
}
template<typename T>
typename AVL<T>::template Node<T>* AVL<T>::right_right(Node<T>*& curr) {
    return left_rotation(curr);
}
template<typename T>
typename AVL<T>::template Node<T>* AVL<T>::right_left(Node<T>*& curr) {
    curr->right = right_rotation(curr->right);
    return right_right(curr);
}
template<typename T>
typename AVL<T>::template Node<T>* AVL<T>::right_rotation(Node<T> *curr) {
    /* getting the parent and the left child for the desired node to balance
       1 - assign the current node left child to be the child's right node
       2 - assign the right node for the child to be the current node (its parent)
       3 - assign the current node's parent (if exists) to be the child's new parent */
    Node<T>* par = get_parent(curr->val); // the current node parent
    Node<T>* child = curr->left; // current node's child
    curr->left = child->right; // step 1
    child->right = curr; // step 2

    // step 3
    if (par != nullptr) {
        // as we do not know whether is it a left or a right child
        if (par->left != nullptr && par->left == curr) par->left = child;
        else par->right = child;
    }
    update(curr), update(child); // updating both nodes heights and balance factors
    return child; // as now the child is the parent's son, we return it
}
template<typename T>
typename AVL<T>::template Node<T>* AVL<T>::left_rotation(Node<T> *curr) {
    /* getting the parent and the left child for the desired node to balance
       1 - assigning the current node's right child to be the child's left node
       2 - assigning the child's left node to be the current node (its parent)
       3 - assign the current node's parent (if exists) to be the child's new parent */
    Node<T>* par = get_parent(curr->val); // the current node parent
    Node<T>* child = curr->right; // current node's child
    curr->right = child->left; // step 1
    child->left = curr; // step 2

    // step 3
    if (par != nullptr) {
        // as we do not know whether is it a left or a right child
        if (par->left != nullptr && par->left == curr) par->left = child;
        else par->right = child;
    }
    update(curr), update(child);  // updating both nodes heights and balance factors
    return child;  // as now the child is the parent's son, we return it
}
template <typename T>
void AVL<T>::update(Node<T> *&curr) {
    int lh = -1, rh = -1;
    if (curr->left != nullptr) lh = curr->left->height;
    if (curr->right != nullptr) rh = curr->right->height;

    curr->height = 1 + max(lh, rh);
    curr->balance_factor = rh - lh;
}

// Iterator Functions
template<typename T>
AVL<T>::Iterator::Iterator(AVL<T>& bst, std::function<void(AVL<T>&, Node<T>*, std::deque<T>&)> func) : bst(bst), traversal_function(func) {
    if (bst.root != nullptr) traversal_function(bst, bst.root, nodes);
}
template<typename T>
T& AVL<T>::Iterator::operator*() {
    return nodes.front();
}
template<typename T>
typename AVL<T>::Iterator& AVL<T>::Iterator::operator++() {
    if (!nodes.empty()) nodes.pop_front();
    return *this;
}
template<typename T>
bool AVL<T>::Iterator::operator!=(const Iterator& other) {
    return !nodes.empty() || !other.nodes.empty();
}
template<typename T>
typename AVL<T>::Iterator AVL<T>::begin(std::function<void(AVL<T>&, Node<T>*, std::deque<T>&)> traversal_function) {
    return Iterator(*this, traversal_function);
}
template<typename T>
typename AVL<T>::Iterator AVL<T>::end() {
    return Iterator(*this, traversal_empty);
}

// types of BST traversals
template<typename T>
void AVL<T>::traversal_in_order(AVL<T>& bst, Node<T>* curr, std::deque<T>& nodes) {
    if (curr == nullptr) return;
    traversal_in_order(bst, curr->left, nodes);
    nodes.push_back(curr->val);
    traversal_in_order(bst, curr->right, nodes);
}
template<typename T>
void AVL<T>::traversal_pre_order(AVL<T>& bst, Node<T>* curr, std::deque<T>& nodes) {
    if (curr == nullptr) return;
    nodes.push_back(curr->val);
    traversal_pre_order(bst, curr->left, nodes);
    traversal_pre_order(bst, curr->right, nodes);
}
template<typename T>
void AVL<T>::traversal_post_order(AVL<T>& bst, Node<T>* curr, std::deque<T>& nodes) {
    if (curr == nullptr) return;
    traversal_post_order(bst, curr->left, nodes);
    traversal_post_order(bst, curr->right, nodes);
    nodes.push_back(curr->val);
}
template<typename T>
void AVL<T>::traversal_level_order(AVL<T>& bst, Node<T>* curr, std::deque<T>& nodes) {
    if (curr == nullptr) return;
    // Traditional BFS Algorithm
    queue<Node<T>*> q;
    q.push(curr);
    while (!q.empty()) {
        Node<T>* front = q.front();
        q.pop();
        nodes.push_back(front->val);
        if (front->left != nullptr) {
            q.push(front->left);
        }
        if (front->right != nullptr) q.push(front->right);
    }
}