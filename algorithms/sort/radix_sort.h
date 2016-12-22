#ifndef RADIX_SORT_H
#define RADIX_SORT_H

#include <iostream>

int get_digital(int num, int index)
{
    int dev = 1;
    for(int i = 1; i<index; ++i)
        dev *= 10;
    return (num / dev) % 10;
}

void counting_sort(int *in_arr, int n, int index)
{
    int *out_arr = new int[n];
    int *count = new int[10]; // as a bucket
    for(int i = 0; i <= 9; ++i)
        count[i] = 0;  // init count[]

    int digital;
    for(int i = 0; i < n; ++i){ // count digital
        digital = get_digital(in_arr[i], index);
        count[digital] = count[digital] + 1;
    }

    for(int i = 0; i < 10; ++i)
        count[i] = count[i - 1] + count[i];

    for(int i = n - 1; i >= 0; --i){
        digital = get_digital(in_arr[i], index);
        out_arr[count[digital] - 1] = in_arr[i]; // index begin at 0 !!!
        --count[digital];
    }

    for(int i = 0; i < n; ++i)
        in_arr[i] = out_arr[i];
    delete[] out_arr;
}

void radix_sort(int *arr, int n)
{
    for(int index = 1; index <= 3; ++index)
        counting_sort(arr, n, index);
}

#endif
