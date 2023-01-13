#include <iostream>
#include "bst.cpp"

using namespace std;


int main(void){
    cout << "=== Test for Binary Search Tree Implementation ===" << endl;
    BinarySearchTree<int> bst;
    bst.insert(10);
    bst.insert(20);
    bst.insert(5);
    bst.insert(80);
    bst.insert(90);
    bst.insert(75);
    bst.insert(30);
    bst.insert(77);
    bst.insert(15);
    bst.insert(40);
    bst.remove(20);
    bst.remove(20);
}