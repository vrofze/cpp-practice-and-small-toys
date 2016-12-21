#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <iostream>

#ifndef SWAP_FUNCTION
#define SWAP_FUNCTION
template<typename T>
void swap(T& m, T& n)
{
    T temp = m;
    m = n;
    n = temp;
}
#endif // swap_function

template<typename T>
size_t partition(T *arr, int p, int r)
{
    T x = arr[r]; // use arr[r] as flag
    int i = p - 1;
    for(int j = p; j < r; ++j)
        if(arr[j] < x){ // use < instand of <=
            ++i;
            swap(arr[i], arr[j]);
        }
    swap(arr[i + 1], arr[r]); // place arr[r] to the middle
    return i + 1;
}

template<typename T>
void quick_sort(T *arr, int p, int r)
{
    if(p < r){
        int q = partition(arr, p, r);
        quick_sort(arr, p, q - 1);
        quick_sort(arr, q + 1, r);
    }
}

template<typename T>
void quick_sort(T *arr, size_t length)
{
    quick_sort(arr, 0, length - 1);
}

#endif
