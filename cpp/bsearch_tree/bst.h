#ifndef BST_H
#define BST_H

#include <utility>

template <typename T>
class TreeNode {
public:
    T item;
    TreeNode * left;
    TreeNode * right;
public:
    TreeNode(T item, TreeNode<T> * left = nullptr, TreeNode<T> * right = nullptr);
    TreeNode<T> * search(T x);
    void remove(T x);
    TreeNode<T> * insert_item(T x);
    TreeNode<T> * search_item(T x);
    TreeNode<T> * remove_item(T x);
    TreeNode<T> * remove_node();
    std::pair<T, TreeNode<T>*> remove_min_item();
};

template <typename T>
class BinarySearchTree {
private:
    TreeNode<T> * root;
public:
    BinarySearchTree(): root(nullptr) {};
    ~BinarySearchTree() {};
    TreeNode<T> * search(T x);
    void insert(T x);
    void remove(T x);
};

#endif