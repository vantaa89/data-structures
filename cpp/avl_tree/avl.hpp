#ifndef AVL_H
#define AVL_H

#include <iostream>

template <typename T, typename U>
class AVLNode{
public:
    T key;
    U value;
    AVLNode<T, U> * left;
    AVLNode<T, U> * right;
    int height;
    bool is_avl();
    AVLNode<T, U> (const T& key, const U& value): key(key), value(value), left(nullptr), right(nullptr), height(1) {};
};

template <typename T, typename U> class AVLTree;
template<typename T, typename U> std::ostream& operator << (std::ostream& os, AVLTree<T, U> & tree);
template <typename T, typename U>
class AVLTree{
private:
    AVLNode<T, U> * root;
    int get_height(AVLNode<T, U> * node);
    int get_balance(AVLNode<T, U> * node);
    AVLNode<T, U> * rotate_left(AVLNode<T, U> * node);
    AVLNode<T, U> * rotate_right(AVLNode<T, U> * node);
    AVLNode<T, U> * insert(AVLNode<T, U> * node, const T& key, const U& value);
    U search(AVLNode<T, U> * node, const T& key) const;
    AVLNode<T, U> * remove(AVLNode<T, U> * node, const T& key);
    AVLNode<T, U> * remove_node(AVLNode<T, U> * node);
    std::pair<AVLNode<T, U> *, AVLNode<T, U>*> take_max(AVLNode<T, U> * node);
    void remove_all(AVLNode<T, U> * node);
    
public:
    AVLTree(): root(nullptr) {};
    ~AVLTree();
    bool is_avl();
    void insert(const T& key, const U& value);
    U search(const T& key);
    bool remove(const T& key);

    friend std::ostream& operator << <> (std::ostream& os, AVLTree<T, U> & tree);
};

template<typename T, typename U>
std::ostream& operator << (std::ostream& os, AVLNode<T, U> * node);
template<typename T, typename U>
std::ostream& operator << (std::ostream& os, AVLTree<T, U> & tree);

#endif