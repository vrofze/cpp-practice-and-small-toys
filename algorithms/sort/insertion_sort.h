#ifndef SORT_H
#define SORT_H

#include <iostream>

template<class T>
void insertion_sort(T a[], size_t length)
{
    int key;
    int j;
    for(size_t i = 1; i < length; ++i){
        key = a[i];
        j = i - 1;
        while(j >= 0 && key < a[j]){
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = key;
    }
}

#endif
