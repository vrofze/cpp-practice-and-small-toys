#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#define LEFT(x) (x << 1)
#define RIGHT(x) ((x << 1) + 1)

#include <iostream>

#ifndef BUBBLE_SORT_H
template<typename T>
void swap(T &n, T &m)
{
    T temp = n;
    n = m;
    m = temp;
}
#endif

template<typename T>
void max_heapify(T *arr, size_t i, size_t length)
{
    size_t l = LEFT(i);
    size_t r = RIGHT(i);

    T largest;
    if(l <= length && arr[l] > arr[i])
        largest = l;
    else
        largest = i;
    if(r <= length && arr[r] > arr[largest]) // arr[r] equals arr[largest]!!!
        largest = r;

    if(largest != i){
        swap(arr[i], arr[largest]);
        max_heapify(arr, largest, length);
    }
}

template<typename T>
void build_max_heap(T *arr, size_t length)
{
    for(size_t i = length / 2; i >= 1; --i)
        max_heapify(arr, i, length);
}

template<typename T>
void heap_sort(T *arr, size_t length)
{
    T *temp_arr = new T[length + 1];
    for(size_t i = 0; i < length; ++i) // heap begins at 1 not 0
        temp_arr[i + 1] = arr[i];

    build_max_heap(temp_arr, length);

    size_t heap_size = length;
    for(int i = length; i >= 2; --i){
        swap(temp_arr[1], temp_arr[i]);
        --heap_size;
        max_heapify(temp_arr, 1, heap_size); // always max_heapify in 1!!!
    }

    for(size_t i = 0; i < length; ++i)
        arr[i] = temp_arr[i + 1];

    delete temp_arr;
}

#endif
