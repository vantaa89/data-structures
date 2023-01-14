#include "avl.hpp"

template<typename T, typename U>
int AVLTree<T, U>::get_height(AVLNode<T, U> * node){
    if (node == nullptr) return 0;
    return node->height;
}

template<typename T, typename U>
int AVLTree<T, U>::get_balance(AVLNode<T, U> * node){
    if (node == nullptr) return 0;
    return get_height(node->left) - get_height(node->right);
}

template<typename T, typename U>
AVLNode<T, U> * AVLTree<T, U>::rotate_left(AVLNode<T, U> * node){
    AVLNode<T, U> * new_root = node->right;
    node->right = new_root->left;
    new_root->left = node;
    node->height = 1 + std::max(this->get_height(node->left), this->get_height(node->right));
    new_root->height = 1 + std::max(this->get_height(new_root->left), this->get_height(new_root->right));
    return new_root;
}

template<typename T, typename U>
AVLNode<T, U> * AVLTree<T, U>::rotate_right(AVLNode<T, U> * node){
    AVLNode<T, U> * new_root = node->left;
    node->left = new_root->right;
    new_root->right = node;
    node->height = 1 + std::max(this->get_height(node->left), this->get_height(node->right));
    new_root->height = 1 + std::max(this->get_height(new_root->left), this->get_height(new_root->right));
    return new_root;
}

template<typename T, typename U>
AVLNode<T, U> * AVLTree<T, U>::insert(AVLNode<T, U> * node, const T& key, const U& value){
    if (node == nullptr){
        return new AVLNode<T, U>(key, value);
    } else if (node->key == key){
        node->value = value;
        return node;
    } else if (node->key < key){
        node->right = this->insert(node->right, key, value);
    } else if (node->key > key){
        node->left = this->insert(node->left, key, value);
    }

    // balancing
    node->height = 1 + std::max(this->get_height(node->left), this->get_height(node->right));
    int b = this->get_balance(node);
    if (b > 1 && node->left->key > key){    // LL
        return this->rotate_right(node);
    }
    if (b > 1 && node->left->key < key){    // LR
        node->left = rotate_left(node->left);
        return this->rotate_right(node);
    }
    if (b < -1 && node->right->key < key){  // RR
        return this->rotate_left(node);
    }
    if (b < -1 && node->right->key > key){   // RL
        node->right = rotate_right(node->right);
        return this->rotate_left(node);
    }
    return node;
}

template<typename T, typename U>
U AVLTree<T, U>::search(AVLNode<T, U> * node, const T& key) const{
    if(node == nullptr){
        return "";
    } else if (node->key == key){
        return node->value;
    } else if (node->key < key){
        return this->search(node->right, key);
    } else{
        return this->search(node->left, key);
    }
}

template<typename T, typename U>
AVLNode<T, U> * AVLTree<T, U>::remove(AVLNode<T, U> * node, const T& key){
    if (node == nullptr){
        std::cout << "Null pointer Error" << std::endl;
        return nullptr;
    } else if (node->key == key){
        return this->remove_node(node);
    } else if (node->key > key){
        node->left = this->remove(node->left, key);
    } else{
        node->right = this->remove(node->right, key);
    }
    node->height = 1 + std::max(this->get_height(node->left), this->get_height(node->right));
    int b = this->get_balance(node);
    if (b > 1 && node->left->key > key){    // LL
        return this->rotate_right(node);
    }
    if (b > 1 && node->left->key < key){    // LR
        node->left = rotate_left(node->left);
        return this->rotate_right(node);
    }
    if (b < -1 && node->right->key < key){  // RR
        return this->rotate_left(node);
    }
    if (b < -1 && node->right->key > key){   // RL
        node->right = rotate_right(node->right);
        return this->rotate_left(node);
    }
    return node;
}

template<typename T, typename U>
AVLNode<T, U> * AVLTree<T, U>::remove_node(AVLNode<T, U> * node){
    if (node->left == nullptr && node->right == nullptr) {
        return nullptr;
    } else if (node->left == nullptr) {
        return node->right;
    } else if (node->right == nullptr) {
        return node->left;
    } else {
        auto temp = this->take_max(node->left);
        node->left = temp.first;
        AVLNode<T, U> * max_left = temp.second;
        max_left->left = node->left; max_left->right = node->right;

        node = max_left;
        node->height = 1 + std::max(this->get_height(node->left), this->get_height(node->right));
        int b = this->get_balance(node);
        if (b > 1 && this->get_height(node->left->left) >= this->get_height(node->left->right)){    // LL
            return this->rotate_right(node);
        }
        if (b > 1 && this->get_height(node->left->left) < this->get_height(node->left->right)){    // LR
            node->left = rotate_left(node->left);
            return this->rotate_right(node);
        }
        if (b < -1 && this->get_height(node->right->left) <= this->get_height(node->right->right)){  // RR
            return this->rotate_left(node);
        }
        if (b < -1 && this->get_height(node->right->left) > this->get_height(node->right->right)){   // RL
            node->right = rotate_right(node->right);
            return this->rotate_left(node);
        }
        return node;
    }
}

template<typename T, typename U>
std::pair<AVLNode<T, U> *, AVLNode<T, U>*> AVLTree<T, U>::take_max(AVLNode<T, U> * node){
    if (node->right == nullptr)
        return std::make_pair(nullptr, node);
    else{
        auto temp = this->take_max(node->right);
        node->right = temp.first;
        AVLNode<T, U> * deleted_node = temp.second;
        return std::make_pair(node, deleted_node);
    }
}

template<typename T, typename U>
void AVLTree<T, U>::insert(const T& key, const U& value){
    this->root = this->insert(this->root, key, value);
}

template<typename T, typename U>
bool AVLTree<T, U>::remove(const T& key){
    if(this->search(key).length() == 0) 
        return false;
    this->root = this->remove(this->root, key);
    return true;
}

template<typename T, typename U>
U AVLTree<T, U>::search(const T& key){
    return this->search(this->root, key);
}

template<typename T, typename U>
bool AVLNode<T, U>::is_avl() {
    if(this->left) {
        if(this->left->key >= this->key) return false;
        if(!this->left->is_avl()) return false;
    }
    if(this->right) {
        if(this->right->key <= this->key) return false;
        if(!this->right->is_avl()) return false;
    }
    if(this->left && this->right && this->left == this->right) 
        return false;
    return true;
}

template<typename T, typename U>
bool AVLTree<T, U>::is_avl(){
    return this->root->is_avl();
}

template<typename T, typename U>
std::ostream& operator << (std::ostream& os, AVLNode<T, U> * node){
    if (node == nullptr) return os;
    os << node->left;
    os << node->key << ": " << node->value << "\n";
    os << node->right;
    return os;
}

template<typename T, typename U>
AVLTree<T, U>::~AVLTree(){
    this->remove_all(root);
}

template<typename T, typename U>
void AVLTree<T, U>::remove_all(AVLNode<T, U> * node) {
    if  (node == nullptr) 
        return;
    this->remove_all(node->left);
    this->remove_all(node->right);
    delete node;
}

template<typename T, typename U>
std::ostream& operator << (std::ostream& os, AVLTree<T, U> & tree){
    os << tree.root;
    return os;
}

