#ifndef BINARY_SEARCH_H__
#define BINARY_SEARCH_H__

#include <iostream>

template<typename T>
int binary_search(T *arr, size_t n, T goal)
{
    int low = 0;
    int high = n - 1;
    int mid;
    while(low <= high){
        //mid = (low + high) / 2;
        mid = low + (high - low) / 2;
        if(arr[mid] < goal)
            low = mid + 1; // arr[mid] != goal
        else if(arr[mid] > goal)
            high = mid - 1; // arr[mid] != goal
        else
            return mid;
    }
    return -2; // index begin at 0, -2 + 1 = -1
}


#endif // binayr_search_h__
