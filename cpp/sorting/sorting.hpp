#ifndef SORTING_H
#define SORTING_H
#include <vector>
#include <queue>

namespace sort{
    template<typename T>
    void selection(T * arr, int size){
        for(int i = size-1; i > 0; --i){
            int max_idx = 0;
            int max_val = arr[0];
            for(int j = 1; j <= i; ++j){
                if(arr[j] > max_val){
                    max_val = arr[j];
                    max_idx = j;
                }
            }
            std::swap(arr[i], arr[max_idx]);
        }
    }

    template<typename T>
    void insertion(T * arr, int size){
        for(int i = 1; i < size; ++i){
            int j = i - 1;
            T new_item = arr[i];

            while(0 <= j && new_item < arr[j]){
                arr[j+1] = arr[j];
                --j;
            }
            arr[j+1] = new_item;
        }
    }

    template<typename T>
    void bubble(T * arr, int size){
        for(int i = 0; i < size-1; ++i){
            for(int j = 0; j < size-i-1; ++j){
                if(arr[j] > arr[j+1]){
                    std::swap(arr[j], arr[j+1]);
                }
            }
        }
    }

    namespace mergesort {
        template<typename T>
        void merge_lists(T * arr, int begin, int mid, int end){
            int p1 = begin, p2 = mid + 1;
            int * temp = new int[end-begin+1];
            int cnt = 0;
            while(p1 <= mid && p2 <= end){
                if(arr[p1] < arr[p2]){
                    temp[cnt++] = arr[p1++];
                } else{
                    temp[cnt++] = arr[p2++];
                }
            }
            while (p1 <= mid){
                temp[cnt++] = arr[p1++];
            }
            while (p2 <= end){
                temp[cnt++] = arr[p2++];
            }
            for(int i = 0; i < cnt; ++i){
                arr[begin + i] = temp[i];
            }
            delete[] temp;
        }

        template<typename T>
        void merge_sort(T * arr, int begin, int end){
            if(begin >= end) return;
            int mid = (begin + end) / 2;
            merge_sort(arr, begin, mid);
            merge_sort(arr, mid+1, end);
            merge_lists(arr, begin, mid, end);
        }
    };

    template<typename T>
    void merge(T* arr, int size){
        mergesort::merge_sort(arr, 0, size-1);
    }

    template<typename T>
    void heap(T * arr, int size){
        std::priority_queue<T> pq;
        for(int i = 0; i < size; ++i){
            pq.push(-arr[i]);
        }
        for(int i = 0; i < size; ++i){
            arr[i] = -pq.top();
            pq.pop();
        }
    }


    namespace quicksort{
        template<typename T>
        int partition(T * arr, int from, int to){
            int standard = arr[to];
            int i = from - 1;
            for (int j = from; j < to; ++j){
                if (arr[j] < standard) {
                    std::swap(arr[++i], arr[j]);
                }
            }
            std::swap(arr[i+1], arr[to]);
            return i + 1;
        }

        template<typename T>
        void quick_sort(T * arr, int from, int to){
            if (from >= to) return;
            int p = partition(arr, from, to);
            quick_sort(arr, from, p-1);
            quick_sort(arr, p+1, to);
        }

        
    };

    template<typename T>
    void quick(T * arr, int size){
        quicksort::quick_sort(arr, 0, size-1);
    }


};
#endif