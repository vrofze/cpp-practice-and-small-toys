#ifndef COUNTING_SORT
#define COUNTING_SORT

#include <iostream>

template<typename T>
T find_max(T *arr, size_t length)
{
    T max = arr[1];
    for(size_t i = 0; i < length; ++i)
        if(arr[i] > max)
            max = arr[i];
    std::cout << max << std::endl;
    return max;
}

template<typename T>
void counting_sort(T *in_arr, int n)
{
    T *out_arr = new T[n];
    T max = find_max(in_arr, n);
    int *count = new int[max + 1];
    for(int i = 0; i <= max; ++i)
        count[i] = 0;
    for(int i = 0; i < n; ++i)
        count[in_arr[i]] = count[in_arr[i]] + 1;
    for(int i = 0; i <= max; ++i)
        count[i] = count[i] + count[i - 1];

    for(int i = n - 1; i >= 0; --i){
        out_arr[count[in_arr[i]] - 1] = in_arr[i];// index begin at 0
        --count[in_arr[i]];
    }

    for(int i = 0; i < n; ++i)
        in_arr[i] = out_arr[i];
    delete[] out_arr;
}

#endif // counting_sort
