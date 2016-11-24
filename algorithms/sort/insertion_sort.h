#ifndef SORT_H
#define SORT_H

template<class T>
void insertion_sort(T a[], int length)
{
    int key;
    int j;
    for(int i = 1; i < length; ++i){
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
