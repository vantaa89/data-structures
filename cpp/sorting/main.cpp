#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sorting.hpp"

using namespace std;

void generate_random_array(int * arr, int size, int max=INT_MAX){
    srand(clock());
    for(int i = 0; i < size; ++i){
        arr[i] = rand() % max;
    }
}

bool check_sorted(int * arr, int arr_size){
    for(int i = 0; i < arr_size-1; ++i){
        if (arr[i+1] < arr[i]) return false;
    }
    return true;
}

int main(){
    const int arr_size = 100000;
    int * arr = new int[arr_size];
    int start_time;

    cout << "=== O(n^2) Sorting Algorithms ===" << endl;

    cout << "Selection Sort" << ": \t";
    generate_random_array(arr, arr_size);
    start_time = clock();
    sort::selection(arr, arr_size);
    cout << double(clock() - start_time) / CLOCKS_PER_SEC << " s" << endl;;
    assert(check_sorted(arr, arr_size));

    cout << "Bubble Sort" << ": \t\t";
    generate_random_array(arr, arr_size);
    start_time = clock();
    sort::bubble(arr, arr_size);
    cout << double(clock() - start_time) / CLOCKS_PER_SEC << " s" << endl;;
    assert(check_sorted(arr, arr_size));

    cout << "Insertion Sort" << ": \t";
    generate_random_array(arr, arr_size);
    start_time = clock();
    sort::insertion(arr, arr_size);
    cout << double(clock() - start_time) / CLOCKS_PER_SEC << " s" << endl;;
    assert(check_sorted(arr, arr_size));

    cout << "=== O(nlogn) Sorting Algorithms ===" << endl;

    cout << "Merge Sort" << ": \t\t";
    generate_random_array(arr, arr_size);
    start_time = clock();
    sort::merge(arr, arr_size);
    cout << double(clock() - start_time) / CLOCKS_PER_SEC << " s" << endl;;
    assert(check_sorted(arr, arr_size));

    cout << "Heap Sort" << ": \t\t";
    generate_random_array(arr, arr_size);
    start_time = clock();
    sort::heap(arr, arr_size);
    cout << double(clock() - start_time) / CLOCKS_PER_SEC << " s" << endl;;
    assert(check_sorted(arr, arr_size));

    cout << "Quick Sort" << ": \t\t";
    generate_random_array(arr, arr_size);
    start_time = clock();
    sort::quick(arr, arr_size);
    cout << double(clock() - start_time) / CLOCKS_PER_SEC << " s" << endl;;
    assert(check_sorted(arr, arr_size));

    delete[] arr;
    return 0;
}

