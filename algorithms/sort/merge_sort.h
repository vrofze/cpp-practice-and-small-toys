#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <climits>
#include <iostream>

template<typename T>
void merge(T arr[], size_t p, size_t q, size_t r)
{
    size_t n1 = q - p + 1, n2 = r - q;
    T l1[n1 + 1], l2[n2 + 1];
    for(size_t i = 0; i < n1; ++i )
        l1[i] = arr[p + i];
    for(size_t i = 0; i < n2; ++i)
        l2[i] = arr[q + i + 1];
    l1[n1] = INT_MAX;
    l2[n2] = INT_MAX;

    size_t m = 0, n = 0;
    for(size_t i = p; i <= r; ++i){
        if(l1[m] <= l2[n]){
            arr[i] = l1[m];
            m++;
        }
        else {
            arr[i] = l2[n];
            n++;
        }
    }
}

template<typename T>
void merge_sort(T arr[], size_t p, size_t r)
{
    if(p < r){
        size_t q = (p + r) / 2;
        merge_sort(arr, p, q);
        merge_sort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

template<typename T>
void merge_sort(T arr[], size_t length)
{
    merge_sort(arr, (size_t)0, length - 1);
}

#endif
