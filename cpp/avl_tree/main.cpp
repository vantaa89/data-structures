#include <iostream>
#include <string>
#include <cassert>
#include "avl.cpp"

using namespace std;

int main(){
    cout << "===== AVL Tree Tests =====" << endl;
    AVLTree<int, string> avl;

    cout << "Insertion/Deletion: ";
    avl.insert(16545, "yeonnamdong");
    assert(avl.is_avl());
    avl.insert(54312, "sinsadong");
    assert(avl.is_avl());

    avl.insert(11243, "sillimdong");
    assert(avl.is_avl());
    avl.insert(66443, "bongcheondong");
    assert(avl.is_avl());
    avl.insert(55443, "jungangdong");
    assert(avl.is_avl());
    avl.insert(32340, "banpodong");
    assert(avl.is_avl());
    avl.insert(33450, "dobongdong");
    assert(avl.is_avl());
    avl.insert(25234, "samseongdong");  
    assert(avl.is_avl());  
    avl.remove(54312);
    assert(avl.is_avl());
    avl.insert(54155, "gurodong");
    assert(avl.is_avl());
    avl.insert(51211, "banghwadong");
    assert(avl.is_avl());
    
    avl.remove(11243);
    assert(avl.is_avl());

    cout << "All Clear" << endl;

    cout << "\nPrint Inorder" << endl;
    cout<<"_________________________"<<endl;
    cout << avl;

    cout<<"\nSearch"<<endl;
    cout<<"_________________________"<<endl;
    cout<<"search 54155: "<<avl.search(54155)<<endl;
    //print 0 if none
    cout<<"search 12345:"<<avl.search(12345)<<endl;
    cout<<"search 11243:"<<avl.search(11243)<<endl; //removed

    cout << "Test Completed" << endl;    
    return 0;
}
