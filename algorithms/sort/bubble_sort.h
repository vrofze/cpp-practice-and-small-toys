#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

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
#endif  // swap_function

template<typename T>
void bubble_sort(T arr[], size_t length)
{
    for(size_t i = 0; i < length - 1; ++i)
        for(size_t j = 0; j < length - 1 - i; ++j)
            if(arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}


#endif
