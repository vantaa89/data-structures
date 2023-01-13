#include "bst.h"

template <typename T>
TreeNode<T>::TreeNode(T item, TreeNode<T> * left, TreeNode<T> * right){
    this->item = item;
    this->left = left;
    this->right = right;
}

template <typename T>
TreeNode<T> * TreeNode<T>::search(T x){
    if (this == nullptr || this->item == x){
        return this;
    }
    else if (x < this->item){
        return this->left.search(x);
    }
    else {
        return this->right.search(x);
    }
}

template <typename T>
void TreeNode<T>::remove(T x){

}

template <typename T>
TreeNode<T> * TreeNode<T>::insert_item(T x){
    TreeNode<T> * ret;
    if (this == nullptr) {
        ret = new TreeNode(x);
        return ret;
    }
    else if (x < this->item){
        this->left = this->left->insert_item(x);
    }
    else {
        this->right = this->right->insert_item(x);
    }
    return this;
}

template <typename T>
TreeNode<T> * TreeNode<T>::search_item(T x){
    if (this == nullptr) {
        return nullptr;
    }
    else if (x == this->item){
        return this;
    }
    else if (x < this->item){
        return this->left.search_item(x);
    }
    else {
        return this->right.search_item(x);
    }
    return this;
}

template <typename T>
TreeNode<T> * TreeNode<T>::remove_item(T x) {
    TreeNode<T> * ret;
    if (this == nullptr) {
        return nullptr;
    } else if (this->item == x){
        ret = this->remove_node();
        return ret;
    } else if (x < this->item) {
        this->left = this->left->remove_item(x);
        return this;
    } else {
        this->right = this->right->remove_item(x);
        return this;
    }
    
}

template <typename T>
TreeNode<T> * TreeNode<T>::remove_node() {
    if (this->left == nullptr && this->right == nullptr){   // no children
        return nullptr;
    } 
    else if (this->left == nullptr){    // only right child
        return this->right;
    }
    else if (this->right == nullptr) {  // only left child
        return this->left;
    }
    else {  // have both children
        // what replaced the current node is the greatest element of the left subtree
        // or the least element of the right subtree
        auto temp = this->right->remove_min_item();
        T min_item = temp.first; 
        TreeNode<T> * node = temp.second;
        this->item = min_item;
        this->right = node;
        return this;
    }
}

template <typename T>
std::pair<T, TreeNode<T>*> TreeNode<T>::remove_min_item(){
    if (this->left == nullptr){
        return std::make_pair(this->item, this->right);
    } else {
        auto temp = this->left->remove_min_item();
        T min_item = temp.first;
        TreeNode<T> * node = temp.second;
        this->left = node;
        return std::make_pair(min_item, this);
    }
}



// Member functions of BinarySearchTree<T>

template <typename T>
void BinarySearchTree<T>::insert(T x) {
    this->root = this->root->insert_item(x);
}

template <typename T>
TreeNode<T> * BinarySearchTree<T>::search(T x) {
    return this->root->search_item(x);
}

template <typename T>
void BinarySearchTree<T>::remove(T x) {
    this->root = this->root->remove_item(x);
}

